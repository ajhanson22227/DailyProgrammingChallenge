/*
    Given a list of numbers and a number k, return whether any 
    two numbers from the list add up to k.

    For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

    Bonus: Can you do this in one pass?
*/

#include <iostream>
#include <vector>

int main(){
    std::vector<int> vect = {10, 15, 3, 7};
    int k = 17;
    int firstNum, secondNum;

    for (int i = 0; i < vect.size() -1; i++){
        for (int j = i + 1; j < vect.size(); j++){
            if (vect[i] + vect[j] == k){
                firstNum = vect[i];
                secondNum = vect[j];
                break;
            }
        }
    }

    for (int i = 0; i < vect.size(); i++){
        std::cout << vect[i] << " ";
    }std::cout << std::endl;

    if (firstNum > 0 && secondNum > 0){
        std::cout << firstNum << " and " << secondNum << " equals " << k << std::endl;
    }
    else{
        std::cout << k << " was not found in the list" << std::endl;
    }
    return 0;
}