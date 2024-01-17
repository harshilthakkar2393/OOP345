#include "Database.h"
using namespace std;
namespace sdds
{

    std::shared_ptr<Database> Database::d = nullptr;
    Database::Database(const std::string &filename)
    {
        cout << "[" << this << "] Database(const std::string&)" << endl;
        std::ifstream fin(filename);
        fileName=filename;
        if(fin)
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
        fin.seekg(0, ios::beg);

        // extracting and storing values
        for (auto i = 0; size_t(i) < noOfRecords && i < MAX_SIZE && fin; i++)
        {
            fin >> keys[i];
            fin >> values[i];
            // replacing _ with " "(space)
            keys[i].replace(keys[i].find('_'), 1, " ");
        }
        fin.close();
        }
    }
    std::shared_ptr<Database> Database::getInstance(const std::string &filename)
    {
        if (d==nullptr)
        {
            Database::d = shared_ptr<Database>(new Database(filename));
        }
        return d;
    }
    Err_Status Database::GetValue(const std::string &key, std::string &value)
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
    Err_Status Database::SetValue(const std::string &key, const std::string &value)
    {
        bool isSaved = false;
        if (noOfRecords < MAX_SIZE)
        {
            keys[noOfRecords++] = key;
            values[noOfRecords++] = value;
            isSaved = true;
        }
        return isSaved ? Err_Status::Err_Success : Err_Status::Err_OutOfMemory;
    }
    Database::~Database()
    {
      cout<<"["<<this<<"] ~Database()"<<endl;  
      ofstream fout(fileName+".bkp.txt");
      for(auto i=0;size_t(i)<noOfRecords;i++)
      {
        fout<<left<<setw(25)<<keys[i];
        fout<<" ->"<<values[i]<<endl;
      }
      fout.close();
    }
}