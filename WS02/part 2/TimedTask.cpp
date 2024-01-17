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
#include "./TimedTask.h"
using namespace std;

namespace sdds
{
    // starts the clock.
    void TimedTask::startClock()
    {
        startTime = std::chrono::steady_clock::now();
    }

    // stops the clock.
    void TimedTask::stopClock()
    {
        endTime = std::chrono::steady_clock::now();
    }

    // adds a new task and calculates the time taken for a task to complete.
    void TimedTask::addTask(const char *taskName)
    {
        timedTasks[noOfRecords].taskName = taskName;
        timedTasks[noOfRecords].timeUnit = "nanoseconds";
        timedTasks[noOfRecords].taskDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
        noOfRecords++;
    }

    // operator overload :<< work with object of type TimedTask 
    std::ostream &operator<<(std::ostream &os, const TimedTask &rightHand)
    {
        os << "--------------------------" << endl;
        os << "Execution Times:" << endl;
        os << "--------------------------" << endl;
        for (int i = 0; i < rightHand.noOfRecords; i++)
        {
            os << setw(21) << setiosflags(ios::left) << rightHand.timedTasks[i].taskName << resetiosflags(ios::left);
            os << setw(13) << setiosflags(ios::right) << rightHand.timedTasks[i].taskDuration.count() << resetiosflags(ios::right) << " ";
            os << rightHand.timedTasks[i].timeUnit << endl;
        }
        os << "--------------------------" << endl;
        return os;
    }
}