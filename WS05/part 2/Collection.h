#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_

#include <iostream>
#include <string>
#include <exception>

namespace sdds
{
    template <typename T>
    class Collection
    {
        std::string collectionName{};
        T *array{nullptr};
        size_t arraySize{};
        void (*collectionObserver)(const Collection<T> &, const T &){};

    public:
        Collection(){};
        Collection(const std::string &name)
        {
            collectionName = name;
        }
        Collection(const Collection &) = delete;
        Collection &operator=(const Collection &) = delete;
        ~Collection()
        {
            delete[] array;
            array = nullptr;
        }
        const std::string &name() const
        {
            return collectionName;
        }
        size_t size() const
        {
            return arraySize;
        }
        void setObserver(void (*observer)(const Collection<T> &, const T &))
        {
            collectionObserver = observer;
        }
        Collection<T> &operator+=(const T &item)
        {
            bool found = false;
            if (size() >= 1)
            {

                for (int i = 0; size_t(i) < size() && !found; i++)
                {
                    if (array[i].title() == item.title())
                    {
                        found = true;
                    }
                }
                if (!found)
                {
                    T *proxy = new T[arraySize + 1];
                    for (int i = 0; size_t(i) < arraySize; i++)
                    {
                        proxy[i] = array[i];
                    }
                    proxy[arraySize] = item;
                    arraySize++;
                    delete[] this->array;
                    array = proxy;
                    if (collectionObserver)
                    {

                        (*collectionObserver)(*this, item);
                    }
                }
            }
            else
            {
                array = new T[arraySize + 1];
                array[arraySize] = item;
                arraySize++;
                if (collectionObserver)
                {
                    (*collectionObserver)(*this, item);
                }
            }
            return *this;
        }
        T &operator[](size_t idx) const
        {
            return idx < size() ? array[idx] : throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(size()) + "] items.");
        }
        T *operator[](const std::string &title) const
        {
            bool found = false;
            T *retunValue = nullptr;
            for (size_t i = 0; i < arraySize && !found; i++)
            {
                if (array[i].title() == title)
                {
                    found = true;
                    retunValue = &array[i];
                }
            }
            return retunValue;
        }
        friend std::ostream &operator<<(std::ostream &os, const Collection &rightHand)
        {
            for (int i = 0; size_t(i) < rightHand.size(); i++)
            {
                os << rightHand.array[i];
            }
            return os;
        }
    };
}
#endif