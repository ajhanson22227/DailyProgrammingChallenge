/*
Given an arithmetic expression in Reverse Polish Notation, write a program to evaluate it.

The expression is given as a list of numbers and operands. 
For example: [5, 3, '+'] should return 5 + 3 = 8.

For example, [15, 7, 1, 1, '+', '-', '/', 3, '*', 2, 1, 1, '+', '+', '-'] should return 5, 
since it is equivalent to ((15 / (7 - (1 + 1))) * 3) - (2 + (1 + 1)) = 5.

You can assume the given expression is always valid.

*/



/*
    IDEAS:
        Have a int function that accepts the string
*/

#include <iostream>
#include <vector>

union operands
{
    /* data */
    int number;
    char operand;
};

int evaluate(std::vector<char> vect){
    for (auto dig : vect){
        std::cout << dig << "\n";
    }
    return 5;
}

int main(){

    std::cout << evaluate({11,'+',3}) << "\n";
    return 0;
}