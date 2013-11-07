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
    val = 16;
    Element element5;
    element5.intVal = val;
    cout << "7. CircularBuffer << Element(" << element5.intVal << ")..." << endl << endl;
    buffer << element5;
    
    //read
    Element element4;
    cout << "Read last two elements...";
    buffer >> element4;
    cout << " Results: " << element4.intVal;
    Element element6;
    buffer >> element6;
    cout << " " << element6.intVal << endl << endl;
    
    //test 8
    val = 32;
    cout << "8. CircularBuffer += int(" << val << ")..." << endl << endl;
    buffer += val;
    
    //test 9
    val = 64;
    Element element8;
    element8.intVal = val;
    cout << "9. CircularBuffer += Element(" << element8.intVal << ")..." << endl << endl;
    buffer << element8;
    
    //read
    Element element9;
    cout << "Read last two elements...";
    buffer >> element9;
    cout << " Results: " << element9.intVal;
    Element element10;
    buffer >> element10;
    cout << " " << element10.intVal << endl << endl;
    
    //test 10
    val = 128;
    cout << "10. CircularBuffer = CircularBuffer + int(" << val << ")..." << endl << endl;
    buffer = buffer + val;
    
    //test 11
    val = 256;
    cout << "11. CircularBuffer = int(" << val << ") + CircularBuffer..." << endl << endl;
    buffer = val + buffer;
    
    //test 12
    val = 512;
    Element element11;
    element11.intVal = val;
    cout << "12. CircularBuffer = CircularBuffer + Element(" << element11.intVal << ")..." << endl << endl;
    buffer = buffer + element11;
    
    //test 13
    val = 1024;
    Element element12;
    element12.intVal = val;
    cout << "13. CircularBuffer = Element(" << element12.intVal << ") + CircularBuffer..." << endl << endl;
    buffer = buffer + element12;
    
    cout << buffer << endl << endl;
    
    //test 14
    cout << "14. Clear buffer..." << endl;
    buffer.clear();
    
    cout << buffer << endl << endl;
    
    cout << endl << "Press ENTER to continue...";
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
}