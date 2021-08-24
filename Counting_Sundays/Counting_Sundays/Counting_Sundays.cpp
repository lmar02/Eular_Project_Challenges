#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//this takes the current date and sees what day it is. then returns an integer to say what day it is 0 = saturday and friday = 6.
unsigned int getWeekday(unsigned long long year, unsigned int month, unsigned int day)
{
    if (month <= 2)
    {
        month += 12;
        --year;
    }

    return(day + 13 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
}

int main() {

    int testRuns{};

    std::cin >> testRuns;

    for (int i{ 0 }; i < testRuns; ++i)
    {
        long long yearOne;
        long long yearTwo;
        int monthOne;
        int monthTwo;
        int dayOne;
        int dayTwo;
        //gets and store the input yeasr days and months. 
        std::cin >> yearOne >> monthOne >> dayOne;
        std::cin >> yearTwo >> monthTwo >> dayTwo;

        // just in case the cases were inputed incorrectly. No clue if this will happen here. 
        if (yearTwo < yearOne || (yearOne == yearTwo && monthOne > monthTwo))
        {
            std::swap(yearOne, yearTwo);
            std::swap(monthOne, monthTwo);
            std::swap(dayOne, dayTwo);
        }

        //this is here so we can skip the current month if we are not at the beginning. 
        long long currentYear{ yearOne };
        int currentMonth{ monthOne };

        if (dayOne > 1)
        {
            ++currentMonth;

            if (currentMonth > 12)
            {
                currentMonth -= 12;
                ++currentYear;
            }
        }

        // since the sunday cycles every 2800 years, this shortens the loop and automaticlaly adds all the sumdays that fall on the 1st of the month. 

        int totalSundaysOnFirstDayOfMonth{};
        while (currentYear + 2800 < yearTwo)
        {
            currentYear += 2800;
            totalSundaysOnFirstDayOfMonth += 4816;
        }

        //this starts looping through the months and years and counting how many sundays fall on the first of the month. It calls getWeekday to find if a specific date falls on which day. 

        while (currentMonth < monthTwo || currentYear < yearTwo)
        {
            if (getWeekday(currentYear, currentMonth, 1) == 1)
            {
                ++totalSundaysOnFirstDayOfMonth;
            }
            ++currentMonth;

            if (currentMonth > 12)
            {
                currentMonth -= 12;
                ++currentYear;
            }
        }
        if (getWeekday(currentYear, currentMonth, 1) == 1)
        {
            ++totalSundaysOnFirstDayOfMonth;
        }
        //prints out answer.
        std::cout << totalSundaysOnFirstDayOfMonth << '\n';
    }
    return 0;
}
