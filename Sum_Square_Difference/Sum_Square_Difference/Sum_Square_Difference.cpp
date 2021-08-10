// Sum_Square_Difference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

long long sumSquareDifference(long long input)
{
    long long result{ 0 };
    long long squareofSum{ 0 };
    long long sumOfNaturalSquares{ 0 };

    while (input != 0)
    {


        sumOfNaturalSquares += (input * input);
        squareofSum += input;

        --input;
    }

    squareofSum *= squareofSum;
    result = squareofSum - sumOfNaturalSquares;

    return result;
}

int main() {
    int t;
    std::cin >> t;
    for (int a0 = 0; a0 < t; a0++) {
        long long n;
        std::cin >> n;

        std::cout << sumSquareDifference(n) << '\n';


    }
    return 0;
}