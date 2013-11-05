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
    this->size = size + 1;
    this->start = 0;
    this->end = 0;
    this->elements = (Element *)calloc(this->size, sizeof(Element));
}