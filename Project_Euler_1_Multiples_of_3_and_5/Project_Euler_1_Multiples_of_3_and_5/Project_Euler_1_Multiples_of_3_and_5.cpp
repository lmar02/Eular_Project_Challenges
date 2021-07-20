// Project_Euler_1_Multiples_of_3_and_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
//In this program you will enter any integer. It will take that number and find all multiples of 3 and 5 that are less than the entered number and add them up and display the sum. 

#include <iostream>


//this function is responsible for finding all of the multiples of a specific number. (3, 5, and 15) Then it returns the sum of the multiples. 
long findingMutliples(long p, long n)
{
    return p * (n * (n + 1) / 2);
}


int main()
{
    int t;

    std::cout << "Please enter the numeber of test runs you want to do " << std::endl;
    std::cin >> t;

    for (int a0 = 0; a0 < t; a0++)
    {
        std::cout << "Please enter an interger that is a multiple of 10. This program will find all mutliples of 3 and 5 that are less than your entered number add them and display the sum. " << std::endl;
        int n;
        std::cin >> n;
        n -= 1;

        //cout<< calls findingmultiples for each of the required numbers 3 and 5 and adds them together. It then finds all mutliples of 15 and subtracts its sum from the total.This insures that specific multiples that are shared by 3 and 5 are not counted twice. 
        std::cout << findingMutliples(3, n / 3) + findingMutliples(5, n / 5) - findingMutliples(15, n / 15) << "\n";
    }

    return 0;
}

