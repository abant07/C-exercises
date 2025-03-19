CXX = g++
CXXFLAGS = -Wall -std=c++17 -g -o
TARGET = ex8
SRCS = Vector.cc ex8.cc

all: $(TARGET)

$(TARGET): $(SRCS)
		$(CXX) $(CXXFLAGS) $(TARGET) $(SRCS)

clean:
		rm -f $(TARGET)