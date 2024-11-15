/*  LV Marlowe
    SDEV-345: Data Structures & Algorithms
    Week 5: Assignment
    27 Sept 2024
    This header file defines the PrintJob class,
    which manages and tracks the print jobs.
-------------------------------------------------- */

#pragma once
#include <chrono>

using namespace std;

class PrintJob {
public:
    PrintJob(int jobNumber, int pages);

    // Getters
    int getJobNumber() const;
    int getPages() const;
    int getPagesRemaining() const;

    // Updates pagesRemaining
    void decrementPagesRemaining();

    // Methods for tracking job duration
    void setStartTime();
    chrono::system_clock::time_point getStartTime() const;

private:
    // Keeps implementation details private
    int jobNumber;
    int pages;
    int pagesRemaining;

    // Tracks job assignment start time 
    // (https://cplusplus.com/reference/chrono/time_point/)
    chrono::system_clock::time_point startTime;  
};