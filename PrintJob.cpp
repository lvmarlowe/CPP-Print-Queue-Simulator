/*  LV Marlowe
    SDEV-345: Data Structures & Algorithms
    Week 5: Assignment
    27 Sept 2024
    This implementation file implements the PrintJob
    class, which manages and track the print jobs. It
    requires PrintJob.h to run.
-------------------------------------------------- */

#include "PrintJob.h"

using namespace std;

PrintJob::PrintJob(int jobNumber, int pages)
    : jobNumber(jobNumber), pages(pages), pagesRemaining(pages) {}

// Getter methods
int PrintJob::getJobNumber() const { return jobNumber; }
int PrintJob::getPages() const { return pages; }
int PrintJob::getPagesRemaining() const { return pagesRemaining; }

// Method to update pagesRemaining
void PrintJob::decrementPagesRemaining() { --pagesRemaining; }

// Methods for tracking job duration
void PrintJob::setStartTime() { startTime = chrono::system_clock::now(); }
chrono::system_clock::time_point PrintJob::getStartTime() const { return startTime; }
