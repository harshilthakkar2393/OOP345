/*
======================================
 Workshop 8 Part 2
======================================
Module : Database
-------------------------------------
Name: Harshil Dineshbhai Thakkar
Student ID: 160431219
Student Email: hthakkar8@myseneca.ca
Date: 26/03/2023
Section: NEE
-------------------------------------
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
======================================
*/

#ifndef SDDS_DATABASE_H
#define SDDS_DATABASE_H
#define MAX_SIZE 20
#include <iostream>
#include <memory>
#include <iomanip>
#include <fstream>
namespace sdds
{
    enum class Err_Status
    {
        Err_Success,
        Err_NotFound,
        Err_OutOfMemory,
    };
    template <typename T>
    class Database
    {
        static std::shared_ptr<Database> d;
        unsigned int noOfRecords{};
        std::string keys[MAX_SIZE]{};
        T values[MAX_SIZE]{};
        std::string fileName;
        Database(){};
        Database(const std::string &filename)
        {
            std::cout << "[" << this << "] Database(const std::string&)" << std::endl;
            std::ifstream fin(filename);
            fileName = filename;
            if (fin)
            {
                // calculating no of records
                while (fin)
                {
                    if (fin.get() == '\n')
                    {
                        noOfRecords++;
                    }
                }
                noOfRecords++;
                fin.clear();
                fin.seekg(0, std::ios::beg);

                // extracting and storing values
                for (size_t i = 0;i < noOfRecords && i < MAX_SIZE && fin; i++)
                {
                    fin >> keys[i];
                    fin >> values[i];
                    encryptDecrypt(values[i]);
                    // replacing _ with " "(space)
                    keys[i].replace(keys[i].find('_'), 1, " ");
                }
                fin.close();
            }
        }
        void encryptDecrypt(T &value)
        {
        }

    public:
        static std::shared_ptr<Database> getInstance(const std::string &filename);
       
        Err_Status GetValue(const std::string &key, T &value)
        {
            bool found = false;
            for (auto i = 0; i < MAX_SIZE && !found; i++)
            {
                if (keys[i] == key)
                {
                    value = values[i];
                    found = true;
                }
            }
            return found ? Err_Status::Err_Success : Err_Status::Err_NotFound;
        }
        Err_Status SetValue(const std::string &key, const T &value)
        {
            bool isSaved = false;
            if (noOfRecords < MAX_SIZE)
            {
                keys[noOfRecords] = key;
                values[noOfRecords++] = value;
                isSaved = true;
            }
            return isSaved ? Err_Status::Err_Success : Err_Status::Err_OutOfMemory;
        }
        ~Database()
        {
            std::cout << "[" << this << "] ~Database()" << std::endl;
            std::ofstream fout(fileName + ".bkp.txt");
            for (auto i = 0; size_t(i) < noOfRecords; i++)
            {
                encryptDecrypt(values[i]);
                fout << std::left << std::setw(25) << keys[i];
                fout << " -> " << values[i] << std::endl;
            }
            fout.close();
        }
    };
    template <typename T>
    std::shared_ptr<Database<T>> Database<T>::d = nullptr;
    template <typename T>
    std::shared_ptr<Database<T>> Database<T>::getInstance(const std::string &filename)
        {
            if (d == nullptr)
            {
                Database::d = std::shared_ptr<Database>(new Database(filename));
            }
            return d;
        }
    template <>
    void Database<std::string>::encryptDecrypt(std::string &value)
    {
        const char secret[]{"secret encryption key"};

        for (auto &c : value)
        {
            for (auto &k : secret)
            {
                c = c ^ k;
            }
        }
    }
    template <>
    void Database<long long>::encryptDecrypt(long long &value)
    {
        const char secret[]{"super secret encryption key"};
        char *c = reinterpret_cast<char *>(&value);
        for (size_t b = 0; b < sizeof(long long); b++)
        {

            for (auto &k : secret)
            {
                c[b] = c[b] ^ k;
            }
        }
    }

}
#endif