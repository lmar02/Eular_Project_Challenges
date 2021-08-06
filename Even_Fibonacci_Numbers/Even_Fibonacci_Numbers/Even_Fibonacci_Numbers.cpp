// Even_Fibonacci_Numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
  
        int t;
        std::cin >> t;
        for (int a0 = 0; a0 < t; a0++) {
            long n, first{ 0 }, second{ 1 }, sum{ 0 }, sumeven{ 0 };
            std::cin >> n;

            while (second < n)
            {
                sum = first + second;
                first = second;
                second = sum;
                if (sum % 2 == 0 && sum < n) {
                    sumeven += sum;

                }

            }

            printf("%ld \n", sumeven);


        }
       
    }

