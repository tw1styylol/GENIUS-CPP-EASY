#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Plural
{
private:
    T* elements;
    int _size;
    int capacity;

public:
    Plural() : elements(new T[10]), _size(0), capacity(10) {}

    Plural(const Plural<T>& other) : elements(new T[other.capacity]), _size(other._size), capacity(other.capacity)
    {
        for (int i = 0; i < _size; ++i) elements[i] = other.elements[i];
    }

    Plural(const T& x) : elements(new T[1]), _size(1), capacity(1)
    {
        elements[0] = x;
    }

    ~Plural()
    {
        delete[] elements;
    }

    Plural(T* arr, int n) : elements(new T[n]), _size(n), capacity(n)
    {
        for (int i = 0; i < n; ++i) this->elements[i] = arr[i];
    }

    Plural<T>& operator=(const Plural<T>& other)
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

    Plural<T>& add(const T& x)
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

    Plural<T>& addRange(T* arr, int n)
    {
        for (int i = 0; i < n; ++i) add(arr[i]);
        return *this;
    }

    Plural<T>& remove(const T& x)
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

    Plural<T>& clear()
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

    Plural<T> set_union(const Plural<T>& other) const
    {
        Plural<T> result(*this);
        for (int i = 0; i < other._size; ++i) {
            result.add(other.elements[i]);
        }
        return result;
    }

    Plural<T> intersect(const Plural<T>& other) const
    {
        Plural<T> result;
        for (int i = 0; i < _size; ++i) {
            if (other.contain(elements[i])) {
                result.add(elements[i]);
            }
        }
        return result;
    }

    Plural<T> difference(const Plural<T>& other) const
    {
        Plural<T> result(*this);
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
std::ostream& operator<<(std::ostream& os, const Plural<T>& S)
{
    S.printOn(os);
    return os;
}


// Barabaliuk Vladyvlav(ex 2)
int digits(int n)
{
    Plural<int> uniqueDigits;

    
    while (n > 0) 
    {
        int digit = n % 10; 
        uniqueDigits.add(digit);
        n /= 10; 
    }

    return uniqueDigits.size(); 
}

// Barabaliuk Vladyslav ex3
// for deleting dublicates
Plural<char> getUniqueLetters(const char* str)
{
    Plural<char> uniqueLetters;
    int len = strlen(str);
    for (int i = 0; i < len; ++i)
    {
        if (!uniqueLetters.contain(str[i]))
        {
            uniqueLetters.add(str[i]);
        }
    }
    return uniqueLetters;
}

// for letters that occur in the string at least twice
Plural<char> getRecurringLetters(const char* str)
{
    Plural<char> recurringLetters;
    Plural<char> uniqueLetters = getUniqueLetters(str);
    int len = strlen(str);
    for (int i = 0; i < uniqueLetters.size(); ++i) 
    {
        int count = 0;
        for (int j = 0; j < len; ++j) {
            if (uniqueLetters.to_array()[i] == str[j])
            {
                count++;
            }
        }
        if (count >= 2) 
        {
            recurringLetters.add(uniqueLetters.to_array()[i]);
        }
    }
    return recurringLetters;
}

// for letters that occut only one time
Plural<char> getSingleOccurrenceLetters(const char* str)
{
    Plural<char> singleOccurrenceLetters;
    Plural<char> uniqueLetters = getUniqueLetters(str);
    int len = strlen(str);
    for (int i = 0; i < uniqueLetters.size(); ++i)
    {
        int count = 0;
        for (int j = 0; j < len; ++j)
        {
            if (uniqueLetters.to_array()[i] == str[j])
            {
                count++;
            }
        }
        if (count == 1)
        {
            singleOccurrenceLetters.add(uniqueLetters.to_array()[i]);
        }
    }
    return singleOccurrenceLetters;
}



//Левицький Микола завдання 1 

int stringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
}

// Функція для підрахунку кількості цифр, знаків арифметичних операцій та дужок у рядку
void countChars(const char* str, int& digitsCount, int& operatorsCount, int& parenthesesCount) {
    digitsCount = operatorsCount = parenthesesCount = 0;
    int len = stringLength(str);
    for (int i = 0; i < len; ++i) {
        if (isdigit(str[i])) {
            ++digitsCount;
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            ++operatorsCount;
        }
        else if (str[i] == '(' || str[i] == ')') {
            ++parenthesesCount;
        }
    }
}

