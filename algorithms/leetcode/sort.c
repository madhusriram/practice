#include <stdio.h>

// max heap has the property that each parent node is larger than its children
void buildMaxHeap(int *arr, int arr_len, int root) { 
    int largestindex = root;                                                        
    int leftindex = 2 * root + 1;                                              
    int rightindex = 2 * root + 2;                                             
                                                                                
    // if left child exists and is larger                                              
    if (leftindex < arr_len && arr[root] < arr[leftindex])                         
        largestindex = leftindex;                                                
                                                                                
    // if right child exists and is larger                                             
    if (rightindex < arr_len && arr[largestindex] < arr[rightindex])
        largestindex = rightindex;                                                                                        
                         
	// parent is no longer the larger	
    if (largestindex != root) {                                                     
        // swap logic                                                       
        int tmp = arr[largestindex];                                             
        arr[largestindex] = arr[root];                                              
        arr[root] = tmp;                                                       
                                                                                
        // re-build max-heap starting from i                                
        buildMaxHeap(arr, arr_len, largestindex);                                             
    }                                                                          
}                                                                               

// min heap has the property that each parent node is smaller than its children
void buildMinHeap(int *arr, int arr_len, int root) {
	int smallestindex = root;
	int leftindex = 2 * root + 1;
	int rightindex = 2 * root + 2;

	// if left child exists and is smaller
	if (leftindex < arr_len && arr[leftindex] < arr[root])
		smallestindex = leftindex;

	// if right child exists and is smaller
	if (rightindex < arr_len && arr[rightindex] < arr[smallestindex])
		smallestindex = rightindex;

	// if parent is no longer than the smallest
	if (smallestindex != root) {
		int tmp = arr[smallestindex];
		arr[smallestindex] = arr[root];
		arr[root] = tmp;

		// re-build min-heap starting from the new value at smallestindex
		buildMinHeap(arr, arr_len, smallestindex);
	}
}

void heapsort(int *arr, int len, char sorting_order) {
	for (int i = (len / 2) - 1; i >= 0; i--) {
		if (sorting_order == 'a')
			buildMaxHeap(arr, len, i);
		else 
			buildMinHeap(arr, len, i);
	}

	for (int i = 0, j = len - 1; i != j; j--) {                                 
		// swap out max with the last element                                   
		int tmp = arr[j];                                                       
		arr[j] = arr[0];                                                        
		arr[0] = tmp;
		
		if (sorting_order == 'a') {
			// re-heapify now!
			buildMaxHeap(arr, j, 0);
		} else {
			buildMinHeap(arr, j, 0);
		}
	}
}
