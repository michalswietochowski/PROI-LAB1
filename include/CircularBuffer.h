//
//  CircularBuffer.h
//  PROI-LAB1
//
//  Created by Michał Świętochowski on 05.11.2013.
//  Copyright (c) 2013 Michal Swietochowski. All rights reserved.
//

#ifndef __PROI_LAB1__CircularBuffer__
#define __PROI_LAB1__CircularBuffer__

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

typedef struct {
    int intVal;
    float floatVal;
    string stringVal;
} Element;

class CircularBuffer
{
    /**
     * size of buffer
     */
    int size;
    /**
     * oldest element index
     */
    int start;
    /**
     * elements count
     */
    int count;
    /**
     * vector of elements
     */
    Element *elements;
    
public:
    CircularBuffer(int size);
    
    /*
     * Getters
     */
    int getSize() { return size; }
    int getStart() { return start; }
    int getCount() { return count; }
    Element* getElements() { return elements; }
    
    /**
     * Write to buffer
     * @param Element element
     * @return void
     */
    void write(Element &element);
    /**
     * Read from buffer
     * @return Element
     */
    Element* read();
    /**
     * Clears the buffer and resets pointers
     * @return void
     */
    void clear();
    /**
     * Tells if buffer is empty
     * @return int
     */
    int isEmpty();
    /**
     * Tells if buffer is full
     * @return int
     */
    int isFull();
    /**
     * Represent buffer as string to print in console
     * @return string
     */
    string toString();
};

ostream & operator<< (ostream &output, CircularBuffer &buffer);

#endif /* defined(__PROI_LAB1__CircularBuffer__) */
