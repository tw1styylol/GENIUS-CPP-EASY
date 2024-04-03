#include "functions.h"
#include <stdexcept>

template <typename T>
Set<T>::Set() : elements(nullptr), _size(0), capacity(0) {}

template <typename T>
Set<T>::Set(const Set<T>& other) : elements(new T[other.capacity]), _size(other._size), capacity(other.capacity) {
    for (int i = 0; i < _size; ++i) elements[i] = other.elements[i];
}

template <typename T>
Set<T>::Set(const T& x) : elements(new T[1]), _size(1), capacity(1) {
    elements[0] = x;
}

template <typename T>
Set<T>::~Set() {
    delete[] elements;
}

template <typename T>
Set<T>::Set(T* arr, int n) : elements(new T[n]), _size(n), capacity(n) {
    for (int i = 0; i < n; ++i) this->elements[i] = arr[i];
}

template <typename T>
Set<T>& Set<T>::operator=(const Set<T>& other) {
    if (this != &other) {
        delete[] elements;
        _size = other._size;
        capacity = other.capacity;
        elements = new T[capacity];
        for (int i = 0; i < _size; ++i) elements[i] = other.elements[i];
    }
    return *this;
}

template <typename T>
Set<T>& Set<T>::add(const T& x) {
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

template <typename T>
Set<T>& Set<T>::addRange(T* arr, int n) {
    for (int i = 0; i < n; ++i) add(arr[i]);
    return *this;
}

template <typename T>
Set<T>& Set<T>::remove(const T& x) {
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

template <typename T>
Set<T>& Set<T>::clear() {
    _size = 0;
    return *this;
}

template <typename T>
int Set<T>::size() const {
    return this->_size;
}

template <typename T>
bool Set<T>::contain(const T& x) const {
    for (int i = 0; i < _size; ++i) {
        if (elements[i] == x) {
            return true;
        }
    }
    return false;
}

template <typename T>
Set<T> Set<T>::set_union(const Set<T>& other) const {
    Set<T> result(*this);
    for (int i = 0; i < other._size; ++i) {
        result.add(other.elements[i]);
    }
    return result;
}

template <typename T>
Set<T> Set<T>::intersect(const Set<T>& other) const {
    Set<T> result;
    for (int i = 0; i < _size; ++i) {
        if (other.contain(elements[i])) {
            result.add(elements[i]);
        }
    }
    return result;
}

template <typename T>
Set<T> Set<T>::difference(const Set<T>& other) const {
    Set<T> result(*this);
    for (int i = 0; i < other._size; ++i) {
        result.remove(other.elements[i]);
    }
    return result;
}

template <typename T>
void Set<T>::printOn(std::ostream& os) const {
    os << "Set{";
    for (int i = 0; i < _size; ++i) {
        os << ' ' << elements[i];
    }
    os << " }";
}

template <typename T>
T* Set<T>::to_array() const {
    return elements;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Set<T>& S) {
    S.printOn(os);
    return os;
}
