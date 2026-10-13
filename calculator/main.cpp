#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;
// Функция вывода справки
void print_help() {
    cout << "          Тригонометрический калькулятор   ";
    cout << "Использование:";
    cout << "  ./trig_calc -o <операция> <угол>";
    cout << "Параметры:";
    cout << "  -o, --operation  Операция: sin или cos";
    cout << "  -m, --mode       Единица измерения: rad (радианы, по умолч.) или deg (градусы)";
    cout << "  -h, --help       Вывод данной справки";
    cout << "Примеры запуска:";
    cout << "  ./trig_calc -o sin 1.5708";
    cout << "  ./trig_calc --operation cos 60 --mode deg";
}

int main(int argc, char* argv[]) {
    // Вывод справки при запуске без параметров
    if (argc < 2) {
        print_help();
        return 0;
    }

    string operation = "";
    string mode = "rad"; // по умолчанию радианы
    vector<double> operands;
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "-h" || arg == "--help") {
            print_help();
            return 0;
        } else if (arg == "-o" || arg == "--operation") {
            if (i + 1 < argc) {
                operation = argv[++i];
            } else {
                cerr << "Ошибка: Не указано значение для параметра операции\n";
                return 1;
            }
        } else if (arg == "-m" || arg == "--mode") {
            if (i + 1 < argc) {
                mode = argv[++i];
            } else {
                cerr << "Ошибка: Не указано значение для режима измерения угла\n";
                return 1;
            }
        } else {
            try {
                operands.push_back(stod(arg));
            } catch (const exception&) {
                cerr << "Ошибка: Некорректное числовое значение операнда '" << arg << "'\n";
                return 1;
            }
        }
    }
    if (operation.empty()) {
        cerr << "Ошибка: Не задана операция (используйте ключ -o или --operation).\n";
        print_help();
        return 1;
    }
    if (operands.size() != 1) {
        cerr << "Ошибка: Для данной операции требуется ровно 1 операнд! Получено: " 
             << operands.size() << ".\n";
        return 1;
    }

    double angle = operands[0];
    double rad_angle = angle;

    if (mode == "deg") {
        rad_angle = angle * M_PI / 180.0;
    } else if (mode != "rad") {
        cerr << "Ошибка: Неизвестный режим '" << mode << "'. Допустимы: rad, deg.\n";
        return 1;
    }
    if (operation == "sin") {
        double result = sin(rad_angle);
        cout << "Результат sin(" << angle << " " << mode << ") = " << result << endl;
    } else if (operation == "cos") {
        double result = cos(rad_angle);
        cout << "Результат cos(" << angle << " " << mode << ") = " << result << endl;
    } else {
        cerr << "Ошибка: Неподдерживаемая операция '" << operation << "'. Используйте sin или cos.\n";
        return 1;
    }

    return 0;
}
