// Smallest_Multiple.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//this function is supposed to find the smallest multiple of numbers 1,2,3,4,5......to n.
int smallestMultipleFinder(int input)
{


    for (int i{ 1 }; i < 10000000; ++i)
    {
        int numberOfTrueRuns{};
        for (int divisibleNumber{ 1 }; divisibleNumber <= input; ++divisibleNumber)
        {
            if (i % divisibleNumber == 0)
            {
                ++numberOfTrueRuns;
            }

        }

        if (numberOfTrueRuns == input)
        {
            return i;
        }

    }
    return -1;
}
int main() {


    int cycles{};
    std::cin >> cycles;

    for (int i{}; i < cycles; ++i)
    {
        int input{};
        std::cin >> input;
        std::cout << smallestMultipleFinder(input) << '\n';
    }


    
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
