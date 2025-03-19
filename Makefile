CXX = g++
CXXFLAGS = -Wall -std=c++17 -g -o
TARGET = ex12
SRCS = Cartesian.cc Polar.cc ex12.cc

$(TARGET): $(SRCS)
		$(CXX) $(CXXFLAGS) $(TARGET) $(SRCS)

clean:
		rm -f $(TARGET)