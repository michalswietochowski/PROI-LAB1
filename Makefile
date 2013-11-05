# Warsaw University of Technology
# The Faculty of Electronics and Information Technology
#
# Object-Oriented Programming Lab 1 - Circular Buffer
#
# Makefile
#
# @author Michal Swietochowski 

# compiler
CXX=g++

# dirs
BINDIR=bin
BUILDDIR=build
SRCDIR=src

# target
TARGET=$(BINDIR)/cb

# settings
CXXFLAGS=-g
INC=-I include
SOURCES=$(SRCDIR)/main.cpp $(SRCDIR)/CLI.cpp $(SRCDIR)/CircularBuffer.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(INC) -o $(TARGET) $(SOURCES)

clean:
	rm -rf bin/*

.PHONY: all clean
