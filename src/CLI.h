//
//  CLI.h
//  PROI-LAB1
//
//  Created by Michał Świętochowski on 05.11.2013.
//  Copyright (c) 2013 Michal Swietochowski. All rights reserved.
//

#ifndef __PROI_LAB1__CLI__
#define __PROI_LAB1__CLI__

#include "CircularBuffer.h"

using namespace std;

class CLI
{
    CircularBuffer buffer;
public:
    CLI(CircularBuffer &buffer) : buffer(buffer) { };
    
    void setBuffer(CircularBuffer &buffer);
    
    CircularBuffer getBuffer() { return this->buffer; }
    
    void showMenu();
};

#endif /* defined(__PROI_LAB1__CLI__) */
