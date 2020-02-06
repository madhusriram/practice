#include <stdio.h>

// 4 10 5 3 1                                                                   
// root is the highest value and all parents are larger than their children     
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

void buildMinHeap(int *arr, int arr_len, int root) {
		


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
