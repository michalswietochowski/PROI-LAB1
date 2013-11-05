//
//  CLI.cpp
//  PROI-LAB1
//
//  Created by Michał Świętochowski on 05.11.2013.
//  Copyright (c) 2013 Michal Swietochowski. All rights reserved.
//

#include <iostream>
#include "CLI.h"

void CLI::setBuffer(CircularBuffer &buffer)
{
    this->buffer = buffer;
}

void CLI::showMenu()
{
    cout << "Menu " << buffer.getSize() << endl;
}