/*  LV Marlowe
    SDEV-345: Data Structures & Algorithms
    Week 5: Assignment
    27 Sept 2024
    This header file defines the PrintSystem class,
    which generates the print jobs.
-------------------------------------------------- */

#pragma once
#include <vector>
#include <random>
#include "Printer.h"

using namespace std;

class PrintSystem {
public:
    PrintSystem(int numPrinters);
    void start(); // Starts the job generation

private:
    vector<Printer> printers;  // Uses vector for number of printers

    // Mersenne Twister for generating random number of pages 
    // (https://cplusplus.com/reference/random/mt19937/)
    mt19937 gen;  

    // Uniformly distributes page count when generating page numbers 
    // (https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution)
    uniform_int_distribution<> pageDist;  
    int jobNumber;  // Tracks job numbers

    // Private helper methods
    void generatePrintJob(); // Method to generate print job with random number of pages
    string getJobSizeCategory(int pages) const; // Method to categorize job size
    Printer& getLowestLoadPrinter(); // Method to find shortest printer queue
    bool allJobsCompleted() const;  // Method to check if all jobs are completed
};
