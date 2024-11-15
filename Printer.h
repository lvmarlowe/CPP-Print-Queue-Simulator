/*  LV Marlowe
    SDEV-345: Data Structures & Algorithms
    Week 5: Assignment
    27 Sept 2024
    This header file defines the Printer class,
    which creates the printers and queues and simulates
    job printing and summarizing. It requires PrintJob.h
    to run.
-------------------------------------------------- */

#pragma once
#include <queue>
#include "PrintJob.h"

using namespace std;

class Printer {
public:
    Printer(int id);

    // Public methods for interacting with the printer
    void addJob(PrintJob job);
    void printPage();
    bool hasJobs() const;
    int getTotalPages() const;
    int getId() const;

private:

    // Keeps implementation details private
    int id;
    queue<PrintJob> queue;  // Uses queue for FIFO
    int totalPages;  // Tracks total pages for load balancing

    // Private method to print job completion summary
    void printJobCompletionSummary(const PrintJob& job) const;
};
