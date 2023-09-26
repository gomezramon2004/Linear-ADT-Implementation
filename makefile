CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = main
LNKDIR = linkedList

SRCS = main.cpp \
		$(LNKDIR)/linkedList.cpp

EXECUTABLE = a.out

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)

.PHONY: all run clean