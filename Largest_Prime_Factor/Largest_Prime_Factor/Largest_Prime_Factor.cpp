// Largest_Prime_Factor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//this function takes the inout fron the user and uses it to find the max prime number of the number entered. 
long long findMaxPrie(long long number)
{

    long long maxPrimeNumber = 0;

    while (number % 2 == 0)
    {
        maxPrimeNumber = 2;
        number /= 2;
    }

    for (int i = 3; i <= std::sqrt(number); i += 2)
    {
        while (number % i == 0)
        {
            maxPrimeNumber = i;
            number /= i;
        }
    }

    if (number > 2)
    {
        maxPrimeNumber = number;
    }

    return maxPrimeNumber;
}

int main() {

    int i{};
    std::cin >> i;
    long long input;

    for (int j{ 0 }; j < i; ++j)
    {
        std::cin >> input;
        std::cout << findMaxPrie(input) << '\n';



    }



    return 0;
}