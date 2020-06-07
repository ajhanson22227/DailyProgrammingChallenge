/*
	Given an array of integers, find the first missing positive integer in linear time and constant space. 
	In other words, find the lowest positive integer that does not exist in the array. 
	The array can contain duplicates and negative numbers as well.

	For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.
*/


#include <iostream>
#include <vector>
#include <set>

int missingPos(const int arr[], int size){
	std::set<int> ourSet;

	for (int i = 0; i < size; i++){
		if (arr[i] > 0){
			ourSet.insert(arr[i]);
		}
	}

	int lowest_pos = 1;
	for (auto x : ourSet){
		if (lowest_pos == x){
			lowest_pos++;
		}
		else
			break;
	}
	return lowest_pos;
}

int main(){

	int arr[] = {1, 2, 0};
	int size = sizeof(arr) / sizeof(arr[0]);

	missingPos(arr, size);
	std::cout << "Missing Pos: " << missingPos(arr, size) << "\n";




	return 0;
}