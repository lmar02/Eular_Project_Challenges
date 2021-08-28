#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

//going to try to redo this challenge so that I can use this struct insead. 

/*
struct nameAndScore
{
    std::string name{};
    int nameScore{};

    nameAndScore(std::string tName)
    {
        name = tName;

        for(char c: tName)
        {
            nameScore += (c-64);
        }
    }
};*/

int nameScore(std::string name, int pos)
{
    int total{ 0 };

    for (char c : name)
    {
        total += (c - 64);

    }
    total *= pos;
    return total;
}

int main() {
    //std::vector<nameAndScore> names{};
    std::vector<std::string> names{};

    //this stores and gets the number of test cases
    int t{};
    std::cin >> t;

    //this for loop takes t and loops through to collect all names 
    for (int i{}; i < t; ++i)
    {

        std::string initialInput{};
        std::cin >> initialInput;

        //stores the string in the vector
        names.push_back(initialInput);

    }

    //sort the vector in alphabetical order
    std::sort(names.begin(), names.end());

    // gets the number of test cases to compare to the vector.
    int i{};
    std::cin >> i;

    //loops throught the number of test cases, collects the name to look up, finds its index and then does the calculation to find the answer and prints it. 
    for (int j{ 0 }; j < i; ++j)
    {
        std::string fName{};
        std::cin >> fName;

        size_t pos = std::distance(names.begin(), std::find(names.begin(), names.end(), fName));
        int iPos = static_cast<int>(pos);

        std::cout << nameScore(fName, iPos + 1) << '\n';
    }


    return 0;
}
