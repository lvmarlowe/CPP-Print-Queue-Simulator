/*  LV Marlowe
    SDEV-345: Data Structures & Algorithms
    Week 5: Assignment
    27 Sept 2024
    This implementation file implements the Printer
    class, which creates printers and queue and simulates
    job printing and summarizing. It requires PrintJob.h
    to run.
-------------------------------------------------- */

#include "Printer.h"
#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;

Printer::Printer(int id) : id(id), totalPages(0) {}

void Printer::addJob(PrintJob job) {
    queue.push(move(job));  // Moves job into the queue
    totalPages += queue.back().getPages();  // Updates the total pages in queue
    queue.back().setStartTime();  // Sets start time for the job
}

// Method to simulate job printing
void Printer::printPage() {

    // Prints job at the front of the queue until the queue is empty
    if (!queue.empty()) {
        PrintJob& job = queue.front();
        job.decrementPagesRemaining();
        totalPages--;

        // Prints status message for each page printed
        cout << "Printer " << id << " printed page "
            << (job.getPages() - job.getPagesRemaining())
            << " of " << job.getPages()
            << " from job " << job.getJobNumber() << "." << endl;

        // Prints summary when job is completed and removes it from the queue
        if (job.getPagesRemaining() == 0) {
            printJobCompletionSummary(job);
            queue.pop();
        }
    }
}

// Method to print job completion summary
void Printer::printJobCompletionSummary(const PrintJob& job) const {
    auto endTime = chrono::system_clock::now(); // Gets job completion time

    // Calculates job duration from enqueueing to completion
    auto duration = chrono::duration_cast<chrono::seconds>(endTime - job.getStartTime());

    // Calculate minutes and seconds from duration
    int minutes = duration.count() / 60;
    int seconds = duration.count() % 60;

    cout << "\n=== Job Completion Summary ===\n";
    cout << "Job Number: " << job.getJobNumber() << "\n";
    cout << "Total Pages: " << job.getPages() << "\n";
    cout << "Time Taken: " << minutes << " minutes, " << seconds << " seconds\n";
    cout << "Average Print Speed: "
        << fixed << setprecision(2) // Sets decimal place to hundredths of a second

        // Calculates average number of pages printed per minute to track metrics
        << static_cast<double>(job.getPages()) / duration.count() * 60
        << " pages per minute\n";
    cout << "==============================\n" << endl;;
}

// Method to check if the printing queue is empty
bool Printer::hasJobs() const {
    return !queue.empty();
}

// Getter methods
int Printer::getTotalPages() const {
    return totalPages;
}

int Printer::getId() const {
    return id;
}
