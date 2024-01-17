/*
======================================
 Workshop 2 Part 2
======================================
Module : TimedTask
-------------------------------------
Name: Harshil Dineshbhai Thakkar
Student ID: 160431219
Student Email: hthakkar8@myseneca.ca
Date: 28/01/2023
Section: NEE
-------------------------------------
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
======================================
*/

#ifndef SDDS_TIMEDTASK_H_
#define SDDS_TIMEDTASK_H_
#include <iostream>
#include <chrono>
#include <iomanip>
#define MAX_NO_OF_TASKS 10

using namespace std;
namespace sdds
{
    struct Task
    {
        std::string taskName{};
        std::string timeUnit{};
        std::chrono::steady_clock::duration taskDuration{};
    };
    class TimedTask
    {
        // ===================================
        // Private data members
        // ===================================
        int noOfRecords{};
        std::chrono::steady_clock::time_point startTime{};
        std::chrono::steady_clock::time_point endTime{};
        Task timedTasks[MAX_NO_OF_TASKS]{};

    public:
        // ===================================
        // Public member functions
        // ===================================

        // default constructor
        TimedTask(){};

        // starts the clock.
        void startClock();

        // stops the clock.
        void stopClock();

        // adds a new task and calculates the time taken for a task to complete.
        void addTask(const char *taskName);

        // operator overload :<< work with object of type TimedTask
        friend std::ostream &operator<<(std::ostream &os, const TimedTask &rightHand);
    };
}
#endif