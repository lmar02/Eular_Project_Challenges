#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


//this stores the digits of the number provided.
struct LargeNumber : std::vector<int>
{
    //this is here so the max digit of a cell is 0 - 9
    int maxDigit{ 10 };

    LargeNumber(long long x = 0)
    {
        //this breaks appart the sum into its appropriate cells and stores it.
        do
        {
            push_back(x % maxDigit);
            x /= maxDigit;
        } while (x > 0);
    }

    //this multiplies a big number by an integer
    LargeNumber operator*(int factor)
    {
        long long carry{ 0 };


        //in each block by the number, multiply it and handle any overflow
        auto result = *this;
        for (auto& i : result)
        {
            carry += i * (long long)factor;
            i = carry % maxDigit;
            carry /= maxDigit;
        }
        //this stores any overflow within a new digit to be used in the next loop. 
        while (carry > 0)
        {
            result.push_back(carry % maxDigit);
            carry /= maxDigit;
        }

        //returns the result of the calcuation
        return result;
    };
};


int main() {

    //get max from user
    int input{};
    std::cin >> input;

    long maxSum{};

    //these loops go through both the exponants and bases and do the proper calculations to find the solution. 
    for (int base{ 1 }; base <= input; ++base)
    {
        LargeNumber power{ 1 };

        for (int exponent{ 1 }; exponent <= input; ++exponent)
        {
            // we now add together each digit of the sum of the exponant and base
            int sum{};

            for (auto digit : power)
            {
                sum += digit;
            }

            //if the new sum is larger than the old sum, than we override the old answer;
            if (maxSum < sum)
            {
                maxSum = sum;
            }

            //this creates the same base with the next exponent in the loop
            power = power * base;
        }
    }


    std::cout << maxSum << "\n";

    return 0;
}
