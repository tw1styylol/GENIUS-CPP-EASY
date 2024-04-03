#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Set
{
private:
    T* elements;
    int _size;
    int capacity;

public:
    Set() : elements(new T[10]), _size(0), capacity(10) {}

    Set(const Set<T>& other) : elements(new T[other.capacity]), _size(other._size), capacity(other.capacity)
    {
        for (int i = 0; i < _size; ++i) elements[i] = other.elements[i];
    }

    Set(const T& x) : elements(new T[1]), _size(1), capacity(1)
    {
        elements[0] = x;
    }

    ~Set()
    {
        delete[] elements;
    }

    Set(T* arr, int n) : elements(new T[n]), _size(n), capacity(n)
    {
        for (int i = 0; i < n; ++i) this->elements[i] = arr[i];
    }

    Set<T>& operator=(const Set<T>& other)
    {
        if (this != &other) {
            delete[] elements;
            _size = other._size;
            capacity = other.capacity;
            elements = new T[capacity];
            for (int i = 0; i < _size; ++i) elements[i] = other.elements[i];
        }
        return *this;
    }

    Set<T>& add(const T& x)
    {
        if (!contain(x)) {
            if (_size >= capacity) {
                capacity *= 2;
                T* newArr = new T[capacity];
                for (int i = 0; i < _size; ++i) {
                    newArr[i] = elements[i];
                }
                delete[] elements;
                elements = newArr;
            }
            elements[_size++] = x;
        }
        return *this;
    }

    Set<T>& addRange(T* arr, int n)
    {
        for (int i = 0; i < n; ++i) add(arr[i]);
        return *this;
    }

    Set<T>& remove(const T& x)
    {
        int index = -1;
        for (int i = 0; i < _size; ++i) {
            if (elements[i] == x) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            for (int i = index; i < _size - 1; ++i) {
                elements[i] = elements[i + 1];
            }
            --_size;
        }
        return *this;
    }

    Set<T>& clear()
    {
        _size = 0;
        return *this;
    }

    int size() const
    {
        return this->_size;
    }

    bool contain(const T& x) const
    {
        for (int i = 0; i < _size; ++i) {
            if (elements[i] == x) {
                return true;
            }
        }
        return false;
    }

    Set<T> set_union(const Set<T>& other) const
    {
        Set<T> result(*this);
        for (int i = 0; i < other._size; ++i) {
            result.add(other.elements[i]);
        }
        return result;
    }

    Set<T> intersect(const Set<T>& other) const
    {
        Set<T> result;
        for (int i = 0; i < _size; ++i) {
            if (other.contain(elements[i])) {
                result.add(elements[i]);
            }
        }
        return result;
    }

    Set<T> difference(const Set<T>& other) const
    {
        Set<T> result(*this);
        for (int i = 0; i < other._size; ++i) {
            result.remove(other.elements[i]);
        }
        return result;
    }

    void printOn(std::ostream& os) const
    {
        os << "Set{";
        for (int i = 0; i < _size; ++i) {
            os << ' ' << elements[i];
        }
        os << " }";
    }

    T* to_array() const
    {
        return elements;
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Set<T>& S)
{
    S.printOn(os);
    return os;
}