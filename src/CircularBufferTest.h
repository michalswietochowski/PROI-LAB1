//
//  CircularBufferTest.h
//  PROI-LAB1
//
//  Created by Michał Świętochowski on 07.11.2013.
//  Copyright (c) 2013 Michal Swietochowski. All rights reserved.
//

#ifndef __PROI_LAB1__CircularBufferTest__
#define __PROI_LAB1__CircularBufferTest__

#include <iostream>
#include <limits>
#include "CircularBuffer.h"

const unsigned int BUFFER_SIZE = 10;

using namespace std;

class CircularBufferTest
{
    /**
     * Buffer object
     */
    CircularBuffer buffer;
public:
    /**
     * Constructor
     */
    CircularBufferTest(CircularBuffer &buffer) : buffer(buffer) { };
    /**
     * Run buffer tests
     */
    void runTests();
};

#endif /* defined(__PROI_LAB1__CircularBufferTest__) */
