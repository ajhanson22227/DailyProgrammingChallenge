/*
	Given an array of integers, return a new array such that each element at index i of the new array is the
	product of all the numbers in the original array except the one at i.

	For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24].
	If our input was [3, 2, 1], the expected output would be [2, 3, 6].

	Follow-up: what if you can't use division?
*/



#include <iostream>

int main(){

	int arr[] = {1, 2, 3, 4, 5};
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	int new_arr[arr_size];

	for (int i = 0; i < arr_size; i++){
		int product = 1;
		for (int j = 0; j < arr_size; j++){
			if (j == i)
				continue;
			product *= arr[j];
		}
		new_arr[i] = product;
	}

	for (int i = 0; i < arr_size; i++){
		std::cout << new_arr[i] << " ";
	}
	std::cout<< "\n";

	return 0;
}