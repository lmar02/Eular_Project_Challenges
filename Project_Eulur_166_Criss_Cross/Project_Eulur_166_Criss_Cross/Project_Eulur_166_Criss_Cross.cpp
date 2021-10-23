#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>



int main()
{

    //initial stored digit, whcih is initialized to 0
    int maxDigit{9};
    std::cin >> maxDigit;

    bool even{ (maxDigit + 1) % 2 == 0 };
    auto maxA{ even ? (maxDigit - 1) / 2 : maxDigit };


    int result{ 0 };
    //these foor loops are use to find the digits for a b c and d in the 4x4
    for (int a{ 0 }; a <= maxA; a++)
        for (int b{ 0 }; b <= maxDigit; b++)
            for (int c{ 0 }; c <= maxDigit; c++)
                for (int d{ 0 }; d <= maxDigit; d++)
                {
                    //this gets the original sum of the row to use in future calculations 
                    int sum{ a + b + c + d };

                    for (int e{ b }; e <= maxDigit; e++)
                        for (int f{ 0 }; f <= maxDigit; f++)
                            for (int g{ 0 }; g <= maxDigit; g++)
                            {
                                //sum of the second row
                                int h{ sum - e - f - g };
                                //if h is larger than maxdigit we move on to the next calculation. 
                                if (h > maxDigit || h < 0)
                                    continue;
                                //this loop is used to find the next few numbers in the 4x4 grid. 
                                for (int i{ 0 }; i <= maxDigit; i++)
                                {
                                    //this represents the sum of the first column
                                    int m{ sum - a - e - i };
                                    if (m > maxDigit || h < 0)
                                        continue;
                                    //sum of the diagnal for the first row
                                    int j{ sum - d - g - m };
                                    if (j > maxDigit || j < 0)
                                        continue;

                                    //finds sum of second column in group
                                    int n{ sum - b - f - j };
                                    if (n > maxDigit || n < 0)
                                        continue;

                                    for (int k{ 0 }; k <= maxDigit; k++)
                                    {
                                        // sum of third column
                                        int o{ sum - c - g - k };
                                        if (o > maxDigit || o < 0)
                                            continue;

                                        //sum of third row
                                        int l{ sum - i - j - k };
                                        if (l > maxDigit ||l < 0)
                                            continue;

                                        // sum of forth row
                                        int p{ sum - m - n - o };
                                        if (p > maxDigit || p < 0)
                                            continue;

                                        //check to make sure everything is correct, checks the diganal.
                                        if (sum != a + f + k + p)
                                            continue;

                                        ++result;
                                        if (b < e)
                                            ++result;
                                    }
                                }
                            }
                }

    if (even)
    {
        result *= 2;
    }

    std::cout << result << '\n';

    return 0;
}
