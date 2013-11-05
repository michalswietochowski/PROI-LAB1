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

typedef struct {
    int value;
} Element;

class CircularBuffer
{
    //maximum size of elements
    int size;
    //oldest element index
    int start;
    //index for new element
    int end;
    //vector of elements
    Element *elements;
public:
    CircularBuffer(int size);
    
    int getSize() { return size; }
};

#endif /* defined(__PROI_LAB1__CircularBuffer__) */
