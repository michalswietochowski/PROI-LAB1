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
    /**
     * Buffer object
     */
    CircularBuffer buffer;
public:
    /**
     * Constructor
     * @param CircularBuffer& buffer buffer object
     */
    CLI(CircularBuffer &buffer) : buffer(buffer) { };
    
    /**
     * Set buffer object
     * @param CircularBuffer& buffer
     */
    void setBuffer(CircularBuffer &buffer);
    /**
     * Get buffer object
     * @return CircularBuffer
     */
    CircularBuffer getBuffer() { return this->buffer; }
  
    /**
     * Clears console screen
     * @return void
     */
    void clearScreen();
    /**
     * Runs loop showing menu and asking for choice
     * @return void
     */
    void showMenu();
    /**
     * Runs add to buffer action
     * @return void
     */
    void addElement();
    /**
     * Runs read from buffer action
     * @return void
     */
    void readElement();
    /**
     * Runs clear buffer action
     * @return void
     */
    void clearBuffer();
    /**
     * Prints prompt to press ENTER key and waits
     * @return void
     */
    void wait();
};

#endif /* defined(__PROI_LAB1__CLI__) */
