/*
    Given an array of integers, return a new array where each element 
    in the new array is the number of smaller elements to the right of 
    that element in the original input array.

    For example, given the array [3, 4, 9, 6, 1], return [1, 1, 2, 1, 0]
*/

#include <iostream>

void printArray(int *array, int size){
    for (int i = 0; i < size; i++){
        std::cout << array[i] << "\n";
    }
}

void greaterRight(int *array, int size){
    int biggerSum;
    for (int i = 0; i < size; i++){
        biggerSum = 0;
        if ( i < size - 1){
            for (int j = i + 1; j < size; j++){
                if (array[j] < array[i]){
                    biggerSum++;
                }
            }
        }
        array[i] = biggerSum;
    }
}


int main(){
    int arr[5] = {5, 2, 60, 23, 92};
    int size = 5;

    greaterRight(arr, size);
    printArray(arr, size);

    return 0;
}