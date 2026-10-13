CXX = g++
CXXFLAGS_RELEASE = -O3 -Wall -std=c++17 -DNDEBUG
CXXFLAGS_DEBUG = -g -O0 -Wall -std=c++17

TARGET_RELEASE = trig_calc
TARGET_DEBUG = trig_calc_debug
SRC = main.cpp

all: release debug

release: $(TARGET_RELEASE)

$(TARGET_RELEASE): $(SRC)
	$(CXX) $(CXXFLAGS_RELEASE) $(SRC) -o $(TARGET_RELEASE) -lm

debug: $(TARGET_DEBUG)

$(TARGET_DEBUG): $(SRC)
	$(CXX) $(CXXFLAGS_DEBUG) $(SRC) -o $(TARGET_DEBUG) -lm

clean:
	rm -f $(TARGET_RELEASE) $(TARGET_DEBUG) *.o
