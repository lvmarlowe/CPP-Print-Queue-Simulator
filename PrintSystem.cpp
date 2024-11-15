/*  LV Marlowe
    SDEV-345: Data Structures & Algorithms
    Week 5: Assignment
    27 Sept 2024
    This implementation file implements the PrintSystem
    class, which generates the print jobs. It requires
    Printer.h to run.
-------------------------------------------------- */

#include "PrintSystem.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>

PrintSystem::PrintSystem(int numPrinters)

    // Generates truly random number of pages from 1 through 60
    // (https://en.cppreference.com/w/cpp/numeric/random/random_device)
    : gen(std::random_device{}()), pageDist(1, 60), jobNumber(1) {

    // Initializes printers
    for (int i = 0; i < numPrinters; ++i) {
        printers.emplace_back(i + 1);
    }
}

void PrintSystem::start() {

    // Limits job generation to 5 minutes in seconds
    const int JOB_GENERATION_LIMIT = 5 * 60;
    int elapsedSeconds = 0;
    bool generating = true;

    // Repeats until finished generating jobs or all jobs are complete
    while (generating || !allJobsCompleted()) {
        if (generating && elapsedSeconds % 30 == 0) {
            generatePrintJob();
        }

        // Generates a new job every 30 seconds during generation period
        if (elapsedSeconds % 7 == 0) {

            // Prints a page from each printer every 7 seconds
            for (auto& printer : printers) {
                printer.printPage();
            }
        }

        // Pauses this thread for 1 second to simulate real time 
        // (https://en.cppreference.com/w/cpp/thread/sleep_for)
        this_thread::sleep_for(chrono::seconds(1));
        elapsedSeconds++;

        // Stops generating jobs after 5 minutes
        if (elapsedSeconds >= JOB_GENERATION_LIMIT && generating) {
            generating = false;
            cout << "\n***** 5 minutes elapsed. Stopping new job generation. *****\n" << endl;
        }
    }
    cout << "\n***** All jobs completed. Simulation ended. *****" << endl;
}

// Method to generate a new print job
void PrintSystem::generatePrintJob() {
    int pages = pageDist(gen);  // Generates random number of pages
    string jobSize = getJobSizeCategory(pages);

    cout << "\n>>> Received " << jobSize << " print job " << jobNumber << " with " << pages << " pages. <<<\n" << endl;

    // Assigns job to shortest printer queue and increases job number
    Printer& selectedPrinter = getLowestLoadPrinter();
    selectedPrinter.addJob(PrintJob(jobNumber, pages));

    cout << "<<< Assigned job " << jobNumber << " to printer " << selectedPrinter.getId() << ". >>>\n" << endl;
    
    jobNumber++;
}

// Method to categorize job size based on page count
std::string PrintSystem::getJobSizeCategory(int pages) const {
    if (pages <= 10) return "small";
    else if (pages <= 25) return "medium";
    else if (pages <= 50) return "large";
    return "very large";
}

// Method to find the printer with the lowest total pages in queue
Printer& PrintSystem::getLowestLoadPrinter() {
    return *std::min_element(printers.begin(), printers.end(),
        [](const Printer& a, const Printer& b) { return a.getTotalPages() < b.getTotalPages(); });
}

// Method to check if all jobs have completed
bool PrintSystem::allJobsCompleted() const {
    return std::all_of(printers.begin(), printers.end(),
        [](const Printer& p) { return !p.hasJobs(); });
}
