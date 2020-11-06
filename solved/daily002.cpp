/*
    Given an array of integers, return a new array such that each element at index i 
    of the new array is the product of all the numbers in the original array except the one at i.

    For example, if our input was [1, 2, 3, 4, 5], the expected output would be 
    [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

    Follow-up: what if you can't use division?
*/

#include <iostream>
#include <vector>

int main(){
    std::vector<int> vect = {1, 2, 3, 4, 5};
    std::vector<int> productVect;
    
    for (int i = 0; i < vect.size(); i++){
        int product = 1;
        for (int j = 0; j < vect.size(); j++){
            if (j == i) continue;
            product *= vect[j];
        }
        productVect.push_back(product);
    }

    std::cout << "The new list is ";
    for (const auto &i : productVect){
        std::cout << i << ", ";
    }std::cout << std::endl;

    return 0;
}