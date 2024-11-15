/*  LV Marlowe
    SDEV-345: Data Structures & Algorithms
    Week 5: Assignment
    27 Sept 2024
    This implementation file implements the
    ProgramManager class, which manages the execution
    of the printer queue simulation program. It
    requires ProgramManager.h to run.
 -------------------------------------------------- */

#include <iostream>
#include <limits>
#include "ProgramManager.h"

using namespace std;

void ProgramManager::run() {
    int numPrinters = getNumPrinters();
    PrintSystem printSystem(numPrinters);
    printSystem.start(); // Start the simulation
}

// Method to get and validate user input for number of printers
int ProgramManager::getNumPrinters() const {
    int numPrinters;
    while (true) {
        cout << "Enter the number of printers (1-4): ";
        if (cin >> numPrinters && numPrinters >= 1 && numPrinters <= 4) {
            return numPrinters;
        }
        cout << "Invalid input. Please enter a number between 1 and 4." << std::endl;

        // Clears error flags and ignores invalid input
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    }
}
