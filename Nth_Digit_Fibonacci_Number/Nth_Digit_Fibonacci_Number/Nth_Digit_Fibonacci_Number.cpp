#include <cmath>
#include <math.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int testRuns{};
    std::cin >> testRuns;

    for (int i{}; i < testRuns; ++i)
    {
        int inputs{};
        std::cin >> inputs;

        std::cout << std::ceil((std::log10(5) / 2 + inputs - 1) / std::log10((1 + std::sqrt(5)) / 2)) << '\n';
    }
    return 0;
}
