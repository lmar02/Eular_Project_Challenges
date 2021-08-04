// Special Pythagorean Triplet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


long long findTripletProduct(int n)
{
    int a{ 0 };
    int b{ 0 };
    int c{ 0 };


    for (a = n / 3; a > 1; --a)
    {
        for (b = n / 2; b > 1; --b)
        {
            c = n - a - b;

            if ((a * a + b * b == c * c) && ((a + b + c) == n) && a < b && b < c && a != 0 && b != 0 && c != 0)
            {

                return  a * b * c;
            }
            c = 0;

        }
    }

    return -1;

}

int main() {


    int t{};
    std::cin >> t;

    for (int ai{ 0 }; ai < t; ++ai)
    {
        int n{};
        std::cin >> n;

        std::cout << findTripletProduct(n) << '\n';



    }
    return 0;
}
