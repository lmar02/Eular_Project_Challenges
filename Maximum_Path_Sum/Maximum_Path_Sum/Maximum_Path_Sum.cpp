// Maximum_Path_Sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>


int findLargestSumPath(std::vector<std::vector<int>> inputVector)
{
    //this loop starts with the second to last row, then compares two integers and figures out which is larger between [i+1][j] and [i+1][j+1]. It then adds this to the current postion and continues down the row. 
    //once its done with the current row, it regresses down the vector and starts the process over gain. Once it reached i=0, than it compares the last two integers figures out which is bigger and adds it to [0][0]. Then the funciton returns it to be printed. 

    for (int i{ (int)inputVector.capacity() - 2 }; i >= 0; --i)
    {
        //std::cout <<"i: " << i << '\n';
        for (int j{}; j < (int)inputVector[i].size(); j++)
        {
            //std::cout <<"j: " << j << '\n';
            inputVector[i][j] += std::max(inputVector[i + 1][j], inputVector[i + 1][j + 1]);
            //std::cout << inputVector[i][j] << '\n';
        }
    }

    return inputVector[0][0];
}


int main() {

    std::vector<std::vector<int>> inputVector;

    //gets number of test cases
    int t{};
    std::cin >> t;
    //loops through number of test cases
    for (int i{}; i < t; ++i) {

        //gets each row of the triangle
        int k{};
        std::cin >> k;
        //loops through each level of the triangle and stores it in the vector of vector ints
        std::vector<std::vector<int>> inputVector(k);

        for (int j{ 0 }; j < k; ++j)
        {

            for (int x{ 0 }; x <= j; ++x)
            {
                int temp{};
                std::cin >> temp;

                inputVector[j].push_back(temp);
                // std::cout << inputVector[j][x]<< '\n';
            }



        }
        //calls function to find the path with the largest sum
        std::cout << findLargestSumPath(inputVector) << '\n';


    }
    return 0;
}
