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

using namespace std;

int main()
{
    const unsigned int BUFFER_SIZE = 10;
    
    CircularBuffer buffer(BUFFER_SIZE);
    CLI cli(buffer);
    cli.showMenu();
 	return 0;
}
