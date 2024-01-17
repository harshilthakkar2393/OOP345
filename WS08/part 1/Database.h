#ifndef SDDS_DATABASE_H
#define SDDS_DATABASE_H
#define MAX_SIZE 20
#include <iostream>
#include<memory>
#include<iomanip>
#include<fstream>
namespace sdds
{
    enum class Err_Status
    {
        Err_Success,
        Err_NotFound,
        Err_OutOfMemory,
    };
    class Database
    {
        static std::shared_ptr<Database> d;
        unsigned int noOfRecords{};
        std::string keys[MAX_SIZE]{};
        std::string values[MAX_SIZE]{};
        std::string fileName;
        Database(){};
        Database(const std::string &filename);
    public:
        static std::shared_ptr<Database> getInstance(const std::string &filename);
        Err_Status GetValue(const std::string &key, std::string &value);
        Err_Status SetValue(const std::string &key, const std::string &value);
        ~Database();
    };
}
#endif