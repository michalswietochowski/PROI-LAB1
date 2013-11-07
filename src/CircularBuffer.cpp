//
//  CircularBuffer.cpp
//  PROI-LAB1
//
//  Created by Michał Świętochowski on 05.11.2013.
//  Copyright (c) 2013 Michal Swietochowski. All rights reserved.
//

#include "CircularBuffer.h"

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
