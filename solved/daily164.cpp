/*
    You are given an array of length n + 1 
    whose elements belong to the set {1, 2, ..., n}. 
    By the pigeonhole principle, there must be a duplicate. 
    Find it in linear time and space.
*/

#include <iostream>
#include <vector>
#include <cassert>


int findDuplicate(std::vector<int> vect, int size){
    int sum = 0;
    for (auto dig : vect){
        sum += dig;
    }

    int setSum = (size * (size + 1)) / 2;
    return sum - setSum;
}

int main(){
    
    assert (findDuplicate({1,2,3,3},3) == 3);
    assert (findDuplicate({1,2,2,3},3) == 2);
    assert (findDuplicate({1,2,3,3,4,5,6},6) == 3);
    assert (findDuplicate({1,2,3,4,5,1},5) == 1);
    assert (findDuplicate({1,2,2},2) == 2);


    return 0;
}