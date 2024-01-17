#include "./TimedTask.h"
using namespace std;

namespace sdds
{
    void TimedTask::startClock()
    {
        startTime = std::chrono::steady_clock::now();
    }
    void TimedTask::stopClock()
    {
        endTime = std::chrono::steady_clock::now();
    }
    void TimedTask::addTask(const char *taskName)
    {
        timedTasks[noOfRecords].taskName = taskName;
        timedTasks[noOfRecords].timeUnit = "nanoseconds";
        timedTasks[noOfRecords].taskDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
        noOfRecords++;
    }
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