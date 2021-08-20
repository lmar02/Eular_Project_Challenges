#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
//#include<bits/stdc++.h> 

//this function takes a vector of strings, that have been reversed to do long addition to find the sum of large numbers. 
void largeDigitSum(std::vector<std::string> reveresedinputs)
{
    //required variables
    std::string total{ "" };
    int carry{ 0 };

    //loops through the length of the strings
    for (int i{ 0 }; i < reveresedinputs[0].length(); ++i)
    {
        int sum{ 0 };
        //loops through the size of the vector so that each colomn can be added together
        for (int j{ 0 }; j < reveresedinputs.size(); ++j)
        {
            sum += ((reveresedinputs[j][i] - '0'));
            std::cerr << "sum: " << sum << '\n';

        }

        //this takes the previous carry and adds it to the sum
        sum += (carry);
        int remainder{ sum % 10 };
        total += ((remainder)+'0');
        carry = sum / 10;
        sum = 0;

        //this makes sure that this section of code is only used once the last iteration of the loop is reached. 
        if (carry != 0 && i == 49)
        {
            while (carry != 0)
            {
                remainder = carry % 10;
                total += ((remainder)+'0');
                std::cerr << "total: " << total << '\n';
                carry /= 10;
                std::cerr << "carry: " << carry << '\n';
            }
        }

        // at the end of the length of the numbers the final carry amount is added to the total string.
        if (i == reveresedinputs[0].length() - 1 && carry != 0)
        {
            // total.push_back(carry + '0');
        }
    }

    //this reverses the string so it is represented in the proper way
    std::reverse(total.begin(), total.end());


    //prints the required 10 digits of the answer. 
    std::string printTenDigits{ "" };
    for (int it{ 0 }; it < 10; ++it)
    {
        printTenDigits.push_back(total[it]);
    }
    std::cout << printTenDigits << '\n';


}

int main() {

    int i{};
    std::cin >> i;

    std::vector<std::string> reversedInputs;

    for (int it{ 0 }; it < i; ++it)
    {
        // gets the numbers and stores them as a string.
        std::string number{};
        std::cin >> number;

        //reverse the numbers so it is ready for the addition
        std::reverse(number.begin(), number.end());
        reversedInputs.push_back(number);

    }

    largeDigitSum(reversedInputs);



    return 0;
}
