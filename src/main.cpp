/**
 * Warsaw University of Technology
 * The Faculty of Electronics and Information Technology
 *
 * Object-Oriented Programming Lab 1 - Circular Buffer
 *
 * Main file
 *
 * @author Michal Swietochowski 
 */

#include <iostream>
#include "CLI.h"
#include "CircularBuffer.h"
#include "CircularBufferTest.h"

using namespace std;

int main(int argc, char *argv[])
{
    const unsigned int BUFFER_SIZE = 10;
    CircularBuffer buffer(BUFFER_SIZE);
    
    if (argc > 1) {
        if (argv[1] == string("test")) {
            CircularBufferTest tester(buffer);
            tester.runTests();
        } else {
            cout << "Usage:" << endl;
            cout << "cb [test]" << endl << endl;
            cout << " test - runs test on buffer class" << endl;
        }
    } else {
        CLI cli(buffer);
        cli.showMenu();
    }
 	return 0;
}
