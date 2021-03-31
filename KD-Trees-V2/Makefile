INCLUDE := include
SRC     := src

CXX      = g++
CXXFLAGS = -std=c++11 -Wall -I$(INCLUDE)

KD-Trees: $(SRC)/*.cpp
	$(CXX) $(CXXFLAGS) -o KD-Trees $(SRC)/*.cpp

.PHONY: clean
clean:
	rm *.o KD-Trees
