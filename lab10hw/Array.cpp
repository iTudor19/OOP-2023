#include "Array.h"
#include "Compare.h"
#include <stdexcept>
#include <iostream>
#include <stdlib.h>


template<class T>
class Array
{
private:
    T* Data;
    int Size;
    Compare* Comparator;

public:
    Array(int size, Compare* comparator)
    {
        Size = size;
        Comparator = comparator;
        Data = new T[Size];
    }

    ~Array()
    {
        delete[] Data;
    }

    T& operator[](int index)
    {
        if (index < 0 || index >= Size)
        {
            throw std::out_of_range("Index out of range");
        }
        return Data[index];
    }

    int GetSize()
    {
        return Size;
    }

    ArrayIterator<T> begin()
    {
        return ArrayIterator<T>(Data);
    }

    ArrayIterator<T> end()
    {
        return ArrayIterator<T>(Data + Size);
    }

    class ArrayIterator
    {
    private:
        T* Ptr;

    public:
        ArrayIterator(T* ptr)
        {
            Ptr = ptr;
        }

        ArrayIterator& operator++()
        {
            Ptr++;
            return *this;
        }

        ArrayIterator& operator--()
        {
            Ptr--;
            return *this;
        }

        bool operator==(const ArrayIterator& other)
        {
            return Ptr == other.Ptr;
        }

        bool operator!=(const ArrayIterator& other)
        {
            return Ptr != other.Ptr;
        }

        T& operator*()
        {
            return *Ptr;
        }
    };
};