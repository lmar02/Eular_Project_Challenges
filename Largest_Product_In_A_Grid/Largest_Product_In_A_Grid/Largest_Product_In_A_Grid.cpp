// Largest_Product_In_A_Grid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


long long findLargestProduct(int grid[20][20])
{
    long long sumTotalOld{ 1 };
    long long sumTotalNew{ 1 };
    for (int x{}; x < 20; ++x)
    {
        for (int y{}; y < 20; ++y)
        {


            long long leftSum{ 1 };
            long long rightSum{ 1 };
            long long upSum{ 1 };
            long long downSum{ 1 };
            long long diagLeftSum{ 1 };
            long long diagRightSum{ 1 };
            long long diagUpSum{ 1 };
            long long diagDownSum{ 1 };


            if (y - 3 > 0)
            {
                leftSum = (long long)grid[x][y] * grid[x][y - 1] * grid[x][y - 2] * grid[x][y - 3];
            }
            if (y + 3 < 20)
            {
                rightSum = (long long)grid[x][y] * grid[x][y + 1] * grid[x][y + 2] * grid[x][y + 3];
            }
            if (x - 3 > 0)
            {
                upSum = (long long)grid[x][y] * grid[x - 1][y] * grid[x - 2][y] * grid[x - 3][y];
            }
            if (x + 3 < 20)
            {
                downSum = (long long)grid[x][y] * grid[x + 1][y] * grid[x + 2][y] * grid[x + 3][y];

            }

            if (y - 3 > 0 && x - 3 > 0)
            {
                diagLeftSum = (long long)grid[x][y] * grid[x - 1][y - 1] * grid[x - 2][y - 2] * grid[x - 3][y - 3];
            }
            if (y + 3 < 20 && x + 3 < 20)
            {
                diagRightSum = (long long)grid[x][y] * grid[x + 1][y + 1] * grid[x + 2][y + 2] * grid[x + 3][y + 3];
            }
            if (x - 3 > 0 && y + 3 < 20)
            {
                diagUpSum = (long long)grid[x][y] * grid[x - 1][y + 1] * grid[x - 2][y + 2] * grid[x - 3][y + 3];
            }
            if (x + 3 < 20 && y - 3 > 0)
            {
                diagDownSum = (long long)grid[x][y] * grid[x + 1][y - 1] * grid[x + 2][y - 2] * grid[x + 3][y - 3];

            }




            if (leftSum > sumTotalNew)
            {
                sumTotalNew = leftSum;
            }

            if (rightSum > sumTotalNew)
            {
                sumTotalNew = rightSum;
            }
            if (upSum > sumTotalNew)
            {
                sumTotalNew = upSum;
            }
            if (downSum > sumTotalNew)
            {
                sumTotalNew = downSum;
            }


            if (diagLeftSum > sumTotalNew)
            {
                sumTotalNew = diagLeftSum;
            }

            if (diagRightSum > sumTotalNew)
            {
                sumTotalNew = diagRightSum;
            }
            if (diagUpSum > sumTotalNew)
            {
                sumTotalNew = diagUpSum;
            }
            if (diagDownSum > sumTotalNew)
            {
                sumTotalNew = diagDownSum;
            }




            if (sumTotalNew >= sumTotalOld)
            {
                //std::cout << sumTotalNew << ' ' << sumTotalOld << '\n';
                sumTotalOld = 1;
                sumTotalOld = sumTotalNew;
                sumTotalNew = 1;
            }
            else {
                sumTotalNew = 1;
            }
        }

    }
    return sumTotalOld;

}


int main() {

    int grid[20][20]{};
    for (int gridI{ 0 }; gridI < 20; ++gridI) {
        for (int gridJ{ 0 }; gridJ < 20; ++gridJ) {
            std::cin >> grid[gridI][gridJ];
        }
    }

    std::cout << findLargestProduct(grid) << '\n';

    return 0;
}