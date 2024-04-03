#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Set {
private:
    T* elements;
    int _size;
    int capacity;

public:
    Set();
    Set(const Set<T>& other);
    Set(const T& x);
    ~Set();
    Set(T* arr, int n);
    Set<T>& operator=(const Set<T>& other);
    Set<T>& add(const T& x);
    Set<T>& addRange(T* arr, int n);
    Set<T>& remove(const T& x);
    Set<T>& clear();
    int size() const;
    bool contain(const T& x) const;
    Set<T> set_union(const Set<T>& other) const;
    Set<T> intersect(const Set<T>& other) const;
    Set<T> difference(const Set<T>& other) const;
    void printOn(std::ostream& os) const;
    T* to_array() const;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Set<T>& S);
