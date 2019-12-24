#include <iostream>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  

void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  

        int pi = partition(arr, low, high);   
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  


int main(){
	int arr[] = {10, 7, 4, 9, 12, 2};

	int arr_length = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, arr_length);

	for (int i = 0; i < arr_length; i++){
		std::cout << arr[i] << "\n";
	}

	bool flag_found = false;
	int sum_to_find;
	std::cin >> sum_to_find;

	for (int i = 0; i < arr_length-1; i++){
		for (int j = i + 1; j < arr_length; j++){
			if (arr[i] + arr[j] == sum_to_find){
				flag_found = true;
			}
		}
		if (flag_found)
			break;
	}
	if (flag_found)
		std::cout << "There are two numbers that total " << sum_to_find << "\n";
	else
		std::cout << "There are NOT any numbers that total " << sum_to_find << "\n";

	return 0;
}