#ifndef SDDS_TIMEDTASK_H_
#define SDDS_TIMEDTASK_H_
#include<iostream>
#include<chrono>
#include<iomanip>
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
        int noOfRecords{};
        std::chrono::steady_clock::time_point startTime{};
        std::chrono::steady_clock::time_point endTime{};
        Task timedTasks[MAX_NO_OF_TASKS]{};
        public:
        TimedTask(){};
        void startClock();
        void stopClock();
        void addTask(const char* taskName);
        friend std::ostream &operator<<(std::ostream &os,const TimedTask& rightHand);
    };
}
#endif