/*
    Given an array of integers, find the first missing positive integer in linear time 
    and constant space. In other words, find the lowest positive integer that does not 
    exist in the array. The array can contain duplicates and negative numbers as well.

    For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.
*/

#include <iostream>
#include <vector>

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void sort(std::vector<int> &vect){
    for (int i = 0; i < vect.size(); i++){
        for (int j = 0; j < vect.size(); j++){
            if (vect[i] < vect[j]) swap(vect[i], vect[j]);
        }
    }
}

int missingPos(std::vector<int> &vect){
    int pos = 1;
    for (const auto &i : vect){
        if (i == pos) pos++;
        else if (i > 0 && i != pos) break;
    }
    return pos;
}


int main(){
    std::vector<int> vect = {1,2,0};
    sort(vect);

    std::cout << missingPos(vect) << std::endl;
}