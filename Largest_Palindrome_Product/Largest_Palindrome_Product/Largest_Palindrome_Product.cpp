// Largest_Palindrome_Product.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{

    //this askes the program or person how many inputs to expect from it
        int i{};
        std::cin >> i;

        //The program takes that number and then loops through the program for each input the user or exterior propgram enters. 
        for (int it{ 0 }; it < i; ++it)
        {
            int number{};
            std::cin >> number;

            int copyNumber{};
            int reverseNumber{};
            int currentDigit{};
            int largestPali{};

            //this loops through numbers and multiples reduce and reduceSecond together to get sumOfReduce. 

            for (int reduce{ 999 }; reduce > 100; --reduce)
            {
                for (int reduceSecond{ 999 }; reduceSecond > 100; --reduceSecond)
                {

                    int sumOfReduce = reduce * reduceSecond;

                    //It checks to see if sumOfReduce is larger than the inputed number.If it is is skipps to the next loop.
                    if (sumOfReduce > number)
                    {
                        continue;
                    }
                    //if sumOfReduce is less than number it then checks to see if sumOfReduce is a palindrome. It does this by taking the value of sumOfReduce and flipping it and storing it in reverseNumber. 
                    else if (sumOfReduce < number)
                    {
                        copyNumber = sumOfReduce;
                        reverseNumber = 0;
                        currentDigit = 0;

                        do
                        {

                            currentDigit = copyNumber % 10;

                            reverseNumber = (reverseNumber * 10) + currentDigit;
                            copyNumber = copyNumber / 10;
                        } while (copyNumber != 0);



                        //If the reverse number matches sumOfReduce that means you have a palindrome. which means we then store the variable into largestPali. 
                        if (reverseNumber == sumOfReduce)
                        {
                            if (largestPali <= sumOfReduce)
                            {
                                largestPali = sumOfReduce;
                                
                            }


                        }
                    }
                }

            }

            //once we exit the loop we print out largestPali as it is the largest Palindrome Product that is less than the entered number. 
            std::cout << largestPali << '\n';


        }
       

}


