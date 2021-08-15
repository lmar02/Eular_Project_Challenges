#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

std::vector<std::string> ones{ "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine" };

std::vector<std::string> eens{ "Ten","Eleven", "Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

std::vector<std::string> tens{ "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };

std::string numberToString(long long input)
{
    if (input < 10)
    {
        return ones[input];
    }
    else if (input < 20)
    {
        return eens[input - 10];
    }
    else if (input < 100)
    {
        return tens[input / 10] + ((input % 10 != 0) ? " " + numberToString(input % 10) : "");
    }
    else if (input < 1000)
    {
        return numberToString(input / 100) + " Hundred" + ((input % 100 != 0) ? " " + numberToString(input % 100) : "");
    }
    else if (input < 1000000)
    {
        return numberToString(input / 1000) + " Thousand" + ((input % 1000 != 0) ? " " + numberToString(input % 1000) : "");
    }
    else if (input < 1000000000)
    {
        return numberToString(input / 1000000) + " Million" + ((input % 1000000 != 0) ? " " + numberToString(input % 1000000) : "");
    }
    else if (input < 1000000000000)
    {
        return numberToString(input / 1000000000) + " Billion" + ((input % 1000000000 != 0) ? " " + numberToString(input % 1000000000) : "");
    }
    return "error";


}

int main() {

    int t{};
    std::cin >> t;
    for (int i{}; i < t; ++i) {
        long long n{};
        std::cin >> n;

        std::cout << numberToString(n) << '\n';


    }
    return 0;
}
