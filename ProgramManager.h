/*  LV Marlowe
    SDEV-345: Data Structures & Algorithms
    Week 5: Assignment
    27 Sept 2024
    This header file defines the ProgramManager class,
    which manages the execution of the printer queue
    simulation program. It requires Printer.h to run.
-------------------------------------------------- */

#pragma once
#include "PrintSystem.h"

class ProgramManager {
public:
    void run(); // Method to start the program, which is accessible to Main

private:
    int getNumPrinters() const; // Helper method for user input
};
