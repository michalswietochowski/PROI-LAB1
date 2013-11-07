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

/**
 * Buffer Element type
 */
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
    /**
     * Constructor
     * @param int size size of buffer
     */
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
    
    /**
     * Write int value to buffer
     * @param int value
     * @return CircularBuffer&
     */
    CircularBuffer& operator+=(int value);
    /**
     * Write Element to buffer
     * @param Element element
     * @return CircularBuffer&
     */
    CircularBuffer& operator+=(Element element);
};

/**
 * Shorthand for toString() method
 * @param ostream output
 * @param CircularBuffer& buffer
 * @return ostream&
 */
ostream& operator<<(ostream &output, CircularBuffer &buffer);
/**
 * Read Element from buffer
 * @param CircularBuffer buffer
 * @param Element& element
 * @return Element&
 */
Element& operator>>(CircularBuffer &buffer, Element &element);
/**
 * Write int value to buffer (other way - by << operator)
 * @param CircularBuffer buffer
 * @param int value
 * @return CircularBuffer
 */
CircularBuffer& operator<<(CircularBuffer &buffer, int value);
/**
 * Write Element to buffer (other way - by << operator)
 * @param CircularBuffer buffer
 * @param Element element
 * @return CircularBuffer
 */
CircularBuffer& operator<<(CircularBuffer &buffer, Element element);
/**
 * Write int value to buffer (other way - by + operator)
 * @param CircularBuffer buffer
 * @param int value
 * @return CircularBuffer
 */
CircularBuffer& operator+(CircularBuffer &buffer, int value);
/**
 * Write int value to buffer (other way - by + operator commutative)
 * @param int value
 * @param CircularBuffer buffer
 * @return CircularBuffer
 */
CircularBuffer& operator+(int value, CircularBuffer &buffer);
/**
 * Write Element to buffer (other way - by + operator)
 * @param CircularBuffer buffer
 * @param Element element
 * @return CircularBuffer
 */
CircularBuffer& operator+(CircularBuffer &buffer, Element element);
/**
 * Write Element to buffer (other way - by + operator commutative)
 * @param Element element
 * @param CircularBuffer buffer
 * @return CircularBuffer
 */
CircularBuffer& operator+(Element element, CircularBuffer &buffer);

#endif /* defined(__PROI_LAB1__CircularBuffer__) */
