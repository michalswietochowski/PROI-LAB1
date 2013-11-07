//
//  CircularBufferTest.cpp
//  PROI-LAB1
//
//  Created by Michał Świętochowski on 07.11.2013.
//  Copyright (c) 2013 Michal Swietochowski. All rights reserved.
//

#include "CircularBufferTest.h"

void CircularBufferTest::runTests()
{
    cout << "0. Initial buffer (test of << operator):" << endl << buffer << endl << endl;

    //test 1
    cout << "1. Trying to read from empty buffer...";
    Element* element;
    if ((element = buffer.read())) {
        cout << " Result: " << element->intVal << endl << endl;
    } else {
        cout << " Result: NULL" << endl << endl;
    }
    
    //test 2
    int val = 123;
    cout << "2. Write " << val << " using write() method..." << endl << endl;
    Element element2;
    element2.intVal = val;
    buffer.write(element2);
    
    //test 3
    cout << "3. Read using read() method... Result: " << buffer.read()->intVal << endl << endl;
    
    //test 4
    cout << "4. Filling buffer with integers (using write method)..." << endl;
    
    for (int i = 0; i < BUFFER_SIZE; i++) {
        Element element;
        element.intVal = i * 3;
        buffer.write(element);
    }
    
    cout << buffer << endl << endl;
    
    //test 5
    cout << "5. Reading all buffer elements (using read method)...";
    
    Element* element3 = buffer.read();
    while (element3) {
        cout << element3->intVal << ", ";
        element3 = buffer.read();
    };
    cout << endl << buffer << endl << endl;
    
    //test 6
    val = 8;
    cout << "6. CircularBuffer << int(" << val << ")..." << endl << endl;
    buffer << val;
    
    //test 7
    Element element4;
    cout << "7. CircularBuffer >> Element...";
    buffer >> element4;
    cout << " Result: " << element4.intVal << endl << endl;
    
    //test 8
    val = 16;
    Element element5;
    element5.intVal = val;
    cout << "8. CircularBuffer << Element(" << element5.intVal << ")..." << endl << endl;
    buffer << element5;
    
    
    //test 9
    Element element6;
    cout << "7. CircularBuffer >> Element...";
    buffer >> element6;
    cout << " Result: " << element6.intVal << endl << endl;
    
    cout << endl << "Press ENTER to continue...";
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
}