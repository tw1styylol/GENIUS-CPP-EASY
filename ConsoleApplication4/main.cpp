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

    //Дурко Р ex 1

    
    const char* EXPRESSION = "2 * (3 + 4) - 5";

    // Підрахунок кількості цифр, операційних знаків, дужок та виразів у рядку
    int digitCount = countDigits(EXPRESSION);
    int operatorCount = countOperators(EXPRESSION);
    int bracketCount = countBrackets(EXPRESSION);
    int expressionCount = ArithmeticExpression(EXPRESSION);

    // Перевірка відповідності кількості дужок у рядку
    bool bracketsBalanced = checkBrackets(EXPRESSION);

    // Виведення результату
    std::cout << "Digits: " << digitCount << std::endl;
    std::cout << "Operators: " << operatorCount << std::endl;
    std::cout << "Brackets: " << bracketCount << std::endl;
    std::cout << "Arithmetic Expressions: " << expressionCount << std::endl;
    std::cout << "Brackets balanced: " << (bracketsBalanced ? "Yes" : "No") << std::endl;



        //ex6



        addVisit(0, 1);
        addVisit(0, 2);
        addVisit(1, 0);
        addVisit(2, 1);
        addVisit(2, 3);
        addVisit(3, 4);
        addVisit(4, 0);
        addVisit(4, 5);
        addVisit(4, 6);
        addVisit(5, 7);
        addVisit(6, 7);
        addVisit(7, 0);
        addVisit(7, 8);
        addVisit(8, 9);
        addVisit(9, 10);
        addVisit(10, 11);
        addVisit(11, 12);
        addVisit(12, 13);
        addVisit(13, 14);
        addVisit(14, 15);
        addVisit(15, 16);
        addVisit(16, 17);
        addVisit(17, 18);
        addVisit(18, 19);
        addVisit(19, 20);

        int minVisited = NUM_PEOPLE;
        for (int i = 0; i < NUM_PEOPLE; ++i) 
        {
            int visitedFriends = countVisitedFriends(i);
            if (visitedFriends < minVisited) 
            {
                minVisited = visitedFriends;
            }
        }

        std::cout << "The least visited guests:" << std::endl;
        for (int i = 0; i < NUM_PEOPLE; ++i) 
        {
            if (countVisitedFriends(i) == minVisited) 
            {
                std::cout << NAMES[i] << std::endl;
            }
        }

        std::cout << "Visited all friends:" << std::endl;
        for (int i = 0; i < NUM_PEOPLE; ++i) 
        {
            if (visitedAllFriends(i)) 
            {
                std::cout << NAMES[i] << std::endl;
            }
        }

        std::cout << "Close circle of three friends: " << (hasCloseCircleOfThree() ? "Yes" : "No") << std::endl;
        std::cout << "Close circle of four friends: " << (hasCloseCircleOfFour() ? "Yes" : "No") << std::endl;


        // Borysiuk Kostiantyn(ex 4)

        int n;
        std::cout << "Enter the value of n: ";
        std::cin >> n;
        std::cout << std::endl;

        Plural<int> prime_numbers = sieve_of_eratosthenes(n);

        std::cout << "Prime numbers up to " << n << ": " << prime_numbers << std::endl;
        std::cout << std::endl;

        // Borysiuk Kostiantyn(ex 5)

        Plural<Product> stores[3];

        stores[0].add(Product::BREAD).add(Product::BUTTER).add(Product::MILK).add(Product::FISH);
        stores[1].add(Product::BREAD).add(Product::CHEESE).add(Product::FISH).add(Product::BUTTER);
        stores[2].add(Product::MILK).add(Product::SUGAR).add(Product::COFFEE).add(Product::BREAD);

        Plural<Product> commonProducts = productsInEveryStore(stores, 3);
        std::cout << "Products available in every store: " << commonProducts << std::endl;
        std::cout << std::endl;


        Plural<Product> anyStoreProducts = productsInAnyStore(stores, 3);
        std::cout << "Products available in at least one store: " << anyStoreProducts << std::endl;
        std::cout << std::endl;


        Plural<Product> absentProducts = productsAbsentInAllStores(stores, 3);
        std::cout << "Products absent in all stores: " << absentProducts << std::endl;

    return 0;

}
