//
//  CircularBuffer.cpp
//  PROI-LAB1
//
//  Created by Michał Świętochowski on 05.11.2013.
//  Copyright (c) 2013 Michal Swietochowski. All rights reserved.
//

#include "CircularBuffer.h"

/**
 * Constructor
 * @param int size size of buffer
 */
CircularBuffer::CircularBuffer(int size)
{
    this->size = size;
    this->start = 0;
    this->count = 0;
    this->elements = (Element *)calloc(this->size, sizeof(Element));
}

/**
 * Write to buffer
 * @param Element element
 * @return void
 */
void CircularBuffer::write(Element &element)
{
    int end = (start + count) % size;
    elements[end] = element;
    
    if (count == size) {
        start = (start + 1) % size;
    } else {
        ++count;
    }
}

/**
 * Read from buffer
 * @return Element*
 */
Element* CircularBuffer::read()
{
    if (isEmpty()) {
        return NULL;
    }
    Element* element = &elements[start];
    start = (start + 1) % size;
    --count;
    return element;
}

/**
 * Clears the buffer and resets pointers
 * @return void
 */
void CircularBuffer::clear()
{
    this->start = 0;
    this->count = 0;
    free(this->elements);
    this->elements = (Element *)calloc(this->size, sizeof(Element));
}

/**
 * Tells if buffer is empty
 * @return int
 */
int CircularBuffer::isEmpty()
{
    return count == 0;
}

/**
 * Tells if buffer is full
 * @return int
 */
int CircularBuffer::isFull()
{
    return count == size;
}

/**
 * Represent buffer as string to print in console
 * @return string
 */
string CircularBuffer::toString()
{
    int padding = 5, margin = 1;
    int cellWidth = padding + 2 * margin;
    
    //create horizontal line
    string horizontalLine = "+-------+";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < cellWidth; j++) {
            horizontalLine.append("-");
        }
        horizontalLine.append("+");
    }
    horizontalLine.append("\n");
    
    //add horizontal line
    string bufferAsString = "";
    bufferAsString.append(horizontalLine);
    
    //indexes
    bufferAsString.append("| Index | ");
    
    for (int i = 0; i < size; i++) {
        char intStr[20];
        sprintf(intStr, "%5d", i);
        bufferAsString.append(intStr);
        bufferAsString.append(" | ");
    }
    bufferAsString.append("\n");
    bufferAsString.append(horizontalLine);
    
    //values
    bufferAsString.append("| Value | ");
    
    for (int i = 0; i < size; i++) {
        char intStr[20];
        sprintf(intStr, "%5d", elements[i].intVal);
        bufferAsString.append(intStr);
        bufferAsString.append(" | ");
    }
    bufferAsString.append("\n");
    bufferAsString.append(horizontalLine);
    
    //start
    bufferAsString.append("| Start | ");
    
    for (int i = 0; i < size; i++) {
        if (i == start) {
            bufferAsString.append("    ^");
        } else {
            bufferAsString.append("     ");
        }
        bufferAsString.append(" | ");
    }
    bufferAsString.append("\n");
    bufferAsString.append(horizontalLine);
    
    //size
    bufferAsString.append("\nSize = ");
    char intStr[20];
    sprintf(intStr, "%d", size);
    bufferAsString.append(intStr);
    
    //count
    bufferAsString.append(", Count = ");
    sprintf(intStr, "%d", count);
    bufferAsString.append(intStr);
    
    //empty
    bufferAsString.append(", Empty = ");
    if (isEmpty()) {
        bufferAsString.append("YES");
    } else {
        bufferAsString.append("NO");
    }
    
    //full
    bufferAsString.append(", Full = ");
    if (isFull()) {
        bufferAsString.append("YES");
    } else {
        bufferAsString.append("NO");
    }
    
    return bufferAsString;
}

/**
 * Write int value to buffer
 * @param int value
 * @return CircularBuffer&
 */
CircularBuffer& CircularBuffer::operator+=(int value)
{
    Element element;
    element.intVal = value;
    this->write(element);
    return *this;
}

/**
 * Write Element to buffer
 * @param Element element
 * @return CircularBuffer&
 */
CircularBuffer& CircularBuffer::operator+=(Element element)
{
    this->write(element);
    return *this;
}

/**
 * Shorthand for toString() method
 * @param ostream output
 * @param CircularBuffer& buffer
 * @return ostream&
 */
ostream& operator<<(ostream &output, CircularBuffer &buffer)
{
    return output << buffer.toString();
}

/**
 * Read Element from buffer
 * @param CircularBuffer buffer
 * @param Element& element
 * @return Element&
 */
Element& operator>>(CircularBuffer &buffer, Element &element)
{
    if (!buffer.isEmpty()) {
        element.intVal = buffer.read()->intVal;
    }
    return element;
}

/**
 * Write int value to buffer (other way - by << operator)
 * @param CircularBuffer buffer
 * @param int value
 * @return CircularBuffer
 */
CircularBuffer& operator<<(CircularBuffer &buffer, int value)
{
    buffer += value;
    return buffer;
}

/**
 * Write Element to buffer (other way - by << operator)
 * @param CircularBuffer buffer
 * @param Element element
 * @return CircularBuffer
 */
CircularBuffer& operator<<(CircularBuffer &buffer, Element element)
{
    buffer += element;
    return buffer;
}

/**
 * Write int value to buffer (other way - by + operator)
 * @param CircularBuffer buffer
 * @param int value
 * @return CircularBuffer
 */
CircularBuffer& operator+(CircularBuffer &buffer, int value)
{
    buffer += value;
    return buffer;
}

/**
 * Write int value to buffer (other way - by + operator commutative)
 * @param int value
 * @param CircularBuffer buffer
 * @return CircularBuffer
 */
CircularBuffer& operator+(int value, CircularBuffer &buffer)
{
    return buffer + value;
}

/**
 * Write Element to buffer (other way - by + operator)
 * @param CircularBuffer buffer
 * @param Element element
 * @return CircularBuffer
 */
CircularBuffer& operator+(CircularBuffer &buffer, Element element)
{
    buffer += element;
    return buffer;
}

/**
 * Write Element to buffer (other way - by + operator commutative)
 * @param Element element
 * @param CircularBuffer buffer
 * @return CircularBuffer
 */
CircularBuffer& operator+(Element element, CircularBuffer &buffer)
{
    return buffer + element;
}

