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

int stringLength(const char* str) 
{
    int length = 0;
    while (str[length] != '\0') 
    {
        ++length;
    }
    return length;
}

// Функція для підрахунку кількості цифр, знаків арифметичних операцій та дужок у рядку
void countChars(const char* str, int& digitsCount, int& operatorsCount, int& parenthesesCount) 
{
    digitsCount = operatorsCount = parenthesesCount = 0;
    int len = stringLength(str);
    for (int i = 0; i < len; ++i) 
    {
        if (isdigit(str[i])) 
        {
            ++digitsCount;
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') 
        {
            ++operatorsCount;
        }
        else if (str[i] == '(' || str[i] == ')') 
        {
            ++parenthesesCount;
        }
    }
}

//ДУРКО РОСТИСЛАВ ЗАВДАВННЯ 1-6//


// Функція для підрахунку кількості цифр у рядку
int countDigits(const char* EXPRESSION) 
{
    int digitCount = 0;
    while (*EXPRESSION) 
    {
        if (*EXPRESSION >= '0' && *EXPRESSION <= '9')
        {
            ++digitCount;
        }
        ++EXPRESSION;
    }
    return digitCount;
}

// Функція для підрахунку кількості операційних знаків у рядку
int countOperators(const char* expression) 
{
    int operatorCount = 0;
    while (*expression) 
    {
        if (*expression == '+' || *expression == '-' || *expression == '*' || *expression == '/' || *expression == '%') {
            ++operatorCount;
        }
        ++expression;
    }
    return operatorCount;
}

// Функція для підрахунку кількості дужок у рядку
int countBrackets(const char* expression) 
{
    int bracketCount = 0;
    while (*expression) 
    {
        if (*expression == '(' || *expression == ')') 
        {
            ++bracketCount;
        }
        ++expression;
    }
    return bracketCount;
}

// Функція для перевірки відповідності кількості дужок у рядку
bool checkBrackets(const char* expression) 
{
    int bracketBalance = 0;
    while (*expression) 
    {
        if (*expression == '(') 
        {
            ++bracketBalance;
        }
        else if (*expression == ')') 
        {
            --bracketBalance;
            if (bracketBalance < 0) 
            {
                return false; // більше закриваючих дужок, ніж відкриваючих
            }
        }
        ++expression;
    }
    return bracketBalance == 0; // повинна бути збалансована кількість дужок
}

int ArithmeticExpression(const char* EXPRESSION)
{
    int count = 0;
    while (*EXPRESSION)
    {
        if (*EXPRESSION == '+' || *EXPRESSION == '-' || *EXPRESSION == '*' || *EXPRESSION == '/' || *EXPRESSION == '%')
        {
            ++count;
        }
        ++EXPRESSION;
    }
    return count;
}



//ex 6
const int NUM_PEOPLE = 21;
const std::string NAMES[NUM_PEOPLE] = 
{
    "Olexa", "Yulia", "Kateryna", "Vitaliy", "Artemiy", "Markiyan", "Vladyslav", "Oleg", "Kseniya", "Olha",
    "Sofiya", "Andriy", "Ivan", "Yuriy", "Taras", "Kostyantyn", "Halyna", "Vasyl", "Solomiya", "Mykola", "Iryna"
};

bool visits[NUM_PEOPLE][NUM_PEOPLE] = {};

void addVisit(int host, int guest) 
{
    visits[host][guest] = true;
}

int countVisitedFriends(int person) 
{
    int count = 0;
    for (int i = 0; i < NUM_PEOPLE; ++i) 
    {
        if (visits[person][i]) 
        {
            ++count;
        }
    }
    return count;
}

bool visitedAllFriends(int person) 
{
    for (int i = 0; i < NUM_PEOPLE; ++i) 
    {
        if (i != person && !visits[person][i]) 
        {
            return false;
        }
    }
    return true;
}

bool hasCloseCircleOfThree() 
{
    for (int i = 0; i < NUM_PEOPLE; ++i) 
    {
        for (int j = 0; j < NUM_PEOPLE; ++j) 
        {
            for (int k = 0; k < NUM_PEOPLE; ++k) 
            {
                if (i != j && j != k && k != i &&
                    visits[i][j] && visits[j][k] && visits[k][i] &&
                    visits[i][k] == false && visits[j][i] == false && visits[k][j] == false) 
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool hasCloseCircleOfFour() 
{
    for (int i = 0; i < NUM_PEOPLE; ++i) 
    {
        for (int j = 0; j < NUM_PEOPLE; ++j) 
        {
            for (int k = 0; k < NUM_PEOPLE; ++k) 
            {
                for (int l = 0; l < NUM_PEOPLE; ++l) 
                {
                    if (i != j && j != k && k != l && l != i && i != k && j != l &&
                        visits[i][j] && visits[j][k] && visits[k][l] && visits[l][i] &&
                        visits[i][k] == false && visits[j][i] == false && visits[k][j] == false &&
                        visits[l][k] == false && visits[i][l] == false && visits[j][l] == false) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

// Borysiuk Kostiantyn(ex 4)

Plural<int> sieve_of_eratosthenes(int n)
{
    Plural<int> primes;

    bool* is_prime = new bool[n + 1];
    for (int i = 2; i <= n; ++i) {
        is_prime[i] = true;
    }

    for (int p = 2; p * p <= n; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.add(i);
        }
    }

    delete[] is_prime;

    return primes;
}

// Borysiuk Kostiantyn(ex 5)
enum class Product { BREAD, BUTTER, MILK, CHEESE, MEAT, FISH, SALT, SUGAR, TEA, COFFEE, WATER };


Plural<Product> productsInEveryStore(Plural<Product> stores[], int numStores) {
    Plural<Product> commonProducts = stores[0];
    for (int i = 1; i < numStores; ++i) {
        commonProducts = commonProducts.intersect(stores[i]);
    }
    return commonProducts;
}


Plural<Product> productsInAnyStore(Plural<Product> stores[], int numStores) {
    Plural<Product> anyStoreProducts = stores[0];
    for (int i = 1; i < numStores; ++i) {
        anyStoreProducts = anyStoreProducts.set_union(stores[i]);
    }
    return anyStoreProducts;
}

Plural<Product> productsAbsentInAllStores(Plural<Product> stores[], int numStores)
{
    Plural<Product> allProducts;
    for (int i = 0; i < numStores; ++i)
    {
        allProducts = allProducts.set_union(stores[i]);
    }

    Plural<Product> absentProducts;
    for (int i = 0; i < 11; ++i)
    {
        Product product = static_cast<Product>(i);
        if (!allProducts.contain(product))
        {
            absentProducts.add(product);
        }
    }

    return absentProducts;
}



void printProduct(std::ostream& os, Product product)
{
    switch (product) {
    case Product::BREAD:   os << "BREAD";   break;
    case Product::BUTTER:  os << "BUTTER";  break;
    case Product::MILK:    os << "MILK";    break;
    case Product::CHEESE:  os << "CHEESE";  break;
    case Product::MEAT:    os << "MEAT";    break;
    case Product::FISH:    os << "FISH";    break;
    case Product::SALT:    os << "SALT";    break;
    case Product::SUGAR:   os << "SUGAR";   break;
    case Product::TEA:     os << "TEA";     break;
    case Product::COFFEE:  os << "COFFEE";  break;
    case Product::WATER:   os << "WATER";   break;
    default:                os << "Unknown Product"; break;
    }
}

std::ostream& operator<<(std::ostream& os, Product product)
{
    printProduct(os, product);
    return os;
}
