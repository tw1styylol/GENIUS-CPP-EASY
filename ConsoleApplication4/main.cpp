#include <iostream>
#include "functions.h"


int main()
{
    int a[5] = { 2, 8, 9, 3, 1 };
    Set<int> A(a, 5);
    std::cout << "A = " << A << " has size " << A.size() << '\n';

    for (int i = 0; i < A.size(); ++i) std::cout << ' ' << A.to_array()[i];
    std::cout << '\n';

    int b[4] = { 5, 3, 2, 0 };
    Set<int> B(b, 4);
    std::cout << "B = " << B << " has size " << B.size() << '\n';

    Set<int> C = A.set_union(B);
    std::cout << "A+B = " << C << " has size " << C.size() << '\n';
    A.remove(1);
    std::cout << "A = " << A << " has size " << A.size() << '\n';
    A.remove(0);
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

    for (int i = 3; i < 37; i += 5) A.add(i);
    std::cout << "A = " << A << " has size " << A.size() << '\n';

    Set<int> P = A.intersect(B);
    std::cout << "A*B = " << P << " has size " << P.size() << '\n';

    Set<int> Q = A.difference(B.add(33));
    std::cout << "A-B-{33} = " << Q << " has size " << Q.size() << '\n';

    Q.clear();
    std::cout << "Q = " << Q << " has size " << Q.size() << '\n';

    return 0;

}
