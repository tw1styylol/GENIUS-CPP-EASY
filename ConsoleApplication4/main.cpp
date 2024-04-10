#include <iostream>
#include "functions.h"


int main()
{
    int a[5] = { 2, 8, 9, 3, 1 }; 
    Plural<int> A(a, 5);
    std::cout << "Create array A = " << A << " has size " << A.size() << '\n';
    std::cout << "Checking if the array(A) is displayed: {";
    for (int i = 0; i < A.size(); ++i) std::cout << ' ' << A.to_array()[i];
    std::cout << " }" << '\n';
    
    std::cout << std::endl;
    int b[4] = { 5, 3, 2, 0 };
    Plural<int> B(b, 4);
    std::cout << "Create array B = " << B << " has size " << B.size() << '\n';
    std::cout << "Checking if the array(B) is displayed: {";
    for (int i = 0; i < B.size(); ++i) std::cout << ' ' << B.to_array()[i] ;
    std::cout <<" }" << '\n';


    Plural<int> C = A.set_union(B);
    std::cout << std::endl;
    std::cout << "Start union: " << std::endl;
    std::cout << "A+B = " << C << " has size " << C.size() << '\n';
    std::cout << std::endl;
    std::cout << "Start removing: " << std::endl;
    A.remove(2);
    std::cout << "A = " << A << " has size " << A.size() << '\n';
    A.remove(9);
    std::cout << "A = " << A << " has size " << A.size() << '\n';
    A.remove(8);
    std::cout << "A = " << A << " has size " << A.size() << '\n';

    try
    {
        A.remove(10);
    }
    catch (const std::runtime_error& ex)
    {
        std::cout << ex.what() << '\n';
    }
    std::cout << std::endl;
    std::cout << "Adding new elements to plural:  " << std::endl;
    for (int i = 5; i < 43; i += 4) A.add(i);
    std::cout << "A = " << A << " has size " << A.size() << '\n';

    std::cout << std::endl;
    std::cout << "Start intersect: " << std::endl;
    Plural<int> ResultIntersect = A.intersect(B);
    std::cout << "A*B = " << ResultIntersect << " has size " << ResultIntersect.size() << '\n';

    std::cout << std::endl;
    std::cout << "Start difference: " << std::endl;
    Plural<int> DifferenceResult = A.difference(B);
    std::cout << "A-B = " << DifferenceResult << " has size " << DifferenceResult.size() << '\n';

    std::cout << std::endl;
    std::cout << "Start difference one element: " << std::endl;
    Plural<int> DifferenceResultOne = A.difference(B.add(33));
    std::cout << "A-{33} = " << DifferenceResultOne << " has size " << DifferenceResultOne.size() << '\n';

    std::cout << std::endl;
    DifferenceResult.clear();
    std::cout << "Clear plural = " << DifferenceResult << " has size " << DifferenceResult.size() << '\n';


    //Barabaliuk Vladyslav (ex 2)

    int number;
    std::cout << "Enter number: ";
    std::cin >> number;

    int result = digits(number); // Обчислюємо кількість різних цифр

    std::cout << "Count different numbers " << number << " : " << result << std::endl;

    std::cout << "-------------------------------------------" << std::endl;
    // Barabaliuk Vladyslav ex3
    const char* str = "abracadabra";

    std::cout << "First occurrence of each letter with preservation of their original order:: ";
    Plural<char> unique = getUniqueLetters(str);
    for (int i = 0; i < unique.size(); ++i)
    {
        std::cout << unique.to_array()[i];
    }
    std::cout << std::endl;

    std::cout << "All letters that occur in the string at least twice: ";
    Plural<char> recurring = getRecurringLetters(str);
    for (int i = 0; i < recurring.size(); ++i)
    {
        std::cout << recurring.to_array()[i];
    }
    std::cout << std::endl;

    std::cout << "All letters that occur only once: ";
    Plural<char> singleOccurrence = getSingleOccurrenceLetters(str);
    for (int i = 0; i < singleOccurrence.size(); ++i)
    {
        std::cout << singleOccurrence.to_array()[i];
    }
    std::cout << std::endl;

    //Левицький микола завдання 1
    std::cout << "______________________________________________________________-" << std::endl;
    std::cout << "Mykola Levytsky task 1" << std::endl;
   

    // введіть рядок арифметичного виразу
    const char* expression = "3 + 4 * (2 - 1)";

    int digitsCount, operatorsCount, parenthesesCount;
    countChars(expression, digitsCount, operatorsCount, parenthesesCount);

    std::cout << "Number of digits: " << digitsCount << std::endl;
    std::cout << "Number of operators: " << operatorsCount << std::endl;
    std::cout << "Number of parentheses: " << parenthesesCount << std::endl;

    // Перевірка відповідності кількості дужок у виразі
    if (parenthesesCount % 2 == 0) {
        std::cout << "Parentheses are balanced." << std::endl;
    }
    else {
        std::cout << "Parentheses are not balanced." << std::endl;
    }





    return 0;

}
