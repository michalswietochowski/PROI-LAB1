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

void CLI::setBuffer(CircularBuffer &buffer)
{
    this->buffer = buffer;
}

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

void CLI::clearBuffer()
{
    buffer.clear();
    cout << endl << "Buffer cleared." << endl;
    wait();
}

void CLI::wait()
{
    cout << endl << "Press ENTER to continue...";
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
}

void CLI::showMenu()
{
    int choice;
    
    do {
        clearScreen();
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

void CLI::clearScreen()
{
    for (int i = 0; i < 60; i++) {
        cout << endl;
    }
}