#include "Compare.h"
#include <stdexcept>
#include <iostream>
#include <stdlib.h>

class Compare
{
public:
    virtual int CompareElements(const void* e1, const void* e2) = 0;
};

template<class T>
class Array
{
private:
    T** List;
    int Capacity;
    int Size;

public:
    Array()
    {
        Capacity = 0;
        Size = 0;
        List = nullptr;
    }

    ~Array()
    {
        for (int i = 0; i < Size; i++)
        {
            delete List[i];
        }
        delete[] List;
    }

    Array(int capacity)
    {
        Capacity = capacity;
        Size = 0;
        List = new T * [Capacity];
    }

    Array(const Array<T>& otherArray)
    {
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (int i = 0; i < Size; i++)
        {
            List[i] = new T(*(otherArray.List[i]));
        }
    }

    T& operator[](int index)
    {
        if (index < 0 || index >= Size)
        {
            throw std::out_of_range("Index out of range");
        }
        return *(List[index]);
    }

    const Array<T>& operator+=(const T& newElem)
    {
        if (Size == Capacity)
        {
            throw std::out_of_range("Capacity exceeded");
        }
        List[Size] = new T(newElem);
        Size++;
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem)
    {
        if (index < 0 || index > Size)
        {
            throw std::out_of_range("Invalid index");
        }
        if (Size == Capacity)
        {
            throw std::out_of_range("Capacity exceeded");
        }
        for (int i = Size; i > index; i--)
        {
            List[i] = List[i - 1];
        }
        List[index] = new T(newElem);
        Size++;
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T>& otherArray)
    {
        if (index < 0 || index > Size)
        {
            throw std::out_of_range("Invalid index");
        }
        if (Size + otherArray.Size > Capacity)
        {
            throw std::out_of_range("Capacity exceeded");
        }
        for (int i = Size + otherArray.Size - 1; i >= index + otherArray.Size; i--)
        {
            List[i] = List[i - otherArray.Size];
        }
        for (int i = index; i < index + otherArray.Size; i++)
        {
            List[i] = new T(*(otherArray.List[i - index]));
        }
        Size += otherArray.Size;
        return *this;
    }

    const Array<T>& Delete(int index)
    {
        if (index < 0 || index >= Size)
        {
            throw std::out_of_range("Invalid index");
        }
        delete List[index];
        for (int i = index; i < Size - 1; i++)
        {
            List[i] = List[i + 1];
        }
        Size--;
        return *this;
    }
};