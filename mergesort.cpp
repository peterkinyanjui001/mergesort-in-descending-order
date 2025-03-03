#include <iostream>
using namespace std;

//create Merge function to merge two sorted subarrays in descending order
void merge(int arr[], int left, int middle, int right) {
	
	//determine size of the subarrays
	//middle-left gives the number of elements in the left.
	//add 1 to include the 1
	//right-1 gives the number of elements in the right 
    
	int num1 = middle - left + 1;
    int num2 = right - middle;
    
    //create temporary arrays to store right and left elements
    int L[num1], R[num2];
    
    //copy the elements in temporary arrays
    for (int i = 0; i < num1; i++)
        L[i] = arr[left + i];//left elements stored in the left subarray
    for (int i = 0; i < num2; i++)
        R[i] = arr[middle + 1 + i];//right elements stored in the right subarray
    
    //merge the sorted array in descending order
    int i = 0, j = 0, k = left;//Initialize indices for L[], R[], and arr[]
    
    while (i < num1 && j < num2) {
        if (L[i] >= R[j]) {  //pick the largest element in descending order
            arr[k] = L[i];//if L[i] >= R[j largest number(L[i]) goes into arr[k]
            i++;
        } else {
            arr[k] = R[j];//else R[j]is placed in arr[j]
            j++;
        }
        k++;//k keeps track of where to place the next sorted element in arr[]
    }
    
    while (i < num1) { // If left subarray has remaining elements
        arr[k] = L[i];//remaining elemnts in the left  are copied to arr[k]
        i++;
        k++;
    }
    
    while (j < num2) {// If right subarray has remaining elements
        arr[k] = R[j];//remaining elements in the R[j] are copied to arr[k]
        j++;
        k++;
    }
}

// recurson
void mergeSort(int arr[], int left, int right) {
// the function recursively divide the array until no element is left
//left ==right

    if (left < right) {//base case
        int middle = left + (right - left) / 2;//find the middle index
        
        mergeSort(arr, left, middle);//recursively sort the left elements
        mergeSort(arr, middle + 1, right);//recursively sort the right elements
        
        merge(arr, left, middle, right);//merge the sorted halves
    }
}

int main() {
    int arr[] = {4, 3, 5, 9, 8};//define the array with the right values
    int size = sizeof(arr) / sizeof(arr[0]);//calculate the array size
    
    mergeSort(arr, 0, size - 1);//sort the array with merge sort
    
    cout << "Sorted array in descending order: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";//print the sorted array
    }
    cout << endl;
    
    return 0;
}
