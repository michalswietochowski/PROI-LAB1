//
//  CLI.cpp
//  PROI-LAB1
//
//  Created by Michał Świętochowski on 05.11.2013.
//  Copyright (c) 2013 Michal Swietochowski. All rights reserved.
//

#include <iostream>
#include <limits>
#include "CLI.h"

/**
 * Set buffer object
 * @param CircularBuffer& buffer
 */
void CLI::setBuffer(CircularBuffer &buffer)
{
    this->buffer = buffer;
}

/**
 * Runs add to buffer action
 * @return void
 */
void CLI::addElement()
{
    Element element;
    cout << "Enter an integer and press Enter: " << flush;
    int result = 0;
    do {
        result = (cin >> element.intVal);
        
        if (!result) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again: " << flush;
        }
    } while (!result);
    
    buffer.write(element);
}

/**
 * Runs read from buffer action
 * @return void
 */
void CLI::readElement()
{
    Element* element;
    if ((element = buffer.read())) {
        cout << endl << "Read value: " << element->intVal << endl;
    } else {
        cout << endl << "Buffer is empty." << endl;
    }
    wait();
}

/**
 * Runs clear buffer action
 * @return void
 */
void CLI::clearBuffer()
{
    buffer.clear();
    cout << endl << "Buffer cleared." << endl;
    wait();
}

/**
 * Prints prompt to press ENTER key and waits
 * @return void
 */
void CLI::wait()
{
    cout << endl << "Press ENTER to continue...";
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
}

/**
 * Runs loop showing menu and asking for choice
 * @return void
 */
void CLI::showMenu()
{
    int choice;
    
    do {
        clearScreen();
        Element element;
        buffer = 159 + buffer;
        buffer >> element;
//        buffer << 15;
        cout << "Test: " << element.intVal << endl;
        cout << "Circular Buffer" << endl << endl;
        cout << buffer << endl << endl;
        cout << "1. Add element to buffer" << endl;
        cout << "2. Get first element from buffer" << endl;
        cout << "3. Clear buffer" << endl;
        cout << "0. Exit" << endl << endl;
        cout << "Choose option: ";
        cin >> choice;
        switch (choice) {
            case 0:
                cout << "Exiting." << endl;
                break;
            case 1:
                addElement();
                break;
            case 2:
                readElement();
                break;
            case 3:
                clearBuffer();
                break;
        }
    } while (choice);
}

/**
 * Clears console screen
 * @return void
 */
void CLI::clearScreen()
{
    for (int i = 0; i < 60; i++) {
        cout << endl;
    }
}