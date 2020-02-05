#include <stdio.h>

// https://leetcode.com/problems/two-sum/

int ARRAY_LEN = 1000;

void buildMaxHeap(int *arr, int len) {                                          
    for (int i = (len / 2) - 1; i >= 0; i--) {                                  
        int leftchild = 2 * i + 1;                                              
        int rightchild = 2 * i + 2;                                             
        int largest = i;                                                        
                                                                                
        // if left child is larger                                              
        if (leftchild < len && arr[i] < arr[leftchild])                         
            largest = leftchild;                                                
                                                                                
        // if right child is larger                                             
        if (rightchild < len && arr[largest] < arr[rightchild]) {               
            largest = rightchild;                                               
        }                                                                       
                                                                                
        if (largest != i) {                                                     
            // swap logic                                                       
            int tmp = arr[largest];                                             
            arr[largest] = arr[i];                                              
            arr[i] = tmp;                                                       
                                                                                
            // re-build max-heap starting from i                                
            buildMaxHeap(arr, len);                                             
        }                                                                       
    }                                                                           
}                                                                               
                                                                                
void heapsort(int *arr, int len) {                                              
    for (int i = 0, j = len - 1; i != j; j--) {                                 
        // swap out max with the last element                                   
        int tmp = arr[j];                                                       
        arr[j] = arr[0];                                                        
        arr[0] = tmp;                                                           
                                                                                
        // re-heapify now!                                                      
        int new_len = j - 1;
        buildMaxHeap(arr, j);
    }                                                                           
} 

// calculate two sum using 2 pointers
void twoSum(int *arr, int len, int target_sum) {

	int i = 0, j = len - 1;

	while (i != j) {
		int res = arr[i] + arr[j];

		if (res == target_sum) {
			printf("There are 2 integers which add up to the sum and the indexes\n in the sorted array are: ");
			printf("[%d %d]\n", i, j);	
			break;
		}

		if (res > target_sum) {
			j--;
		} else {
			i++;
		}
	}

}

void printarray(int *arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
    int target_sum;
    int array_len;
    int array[ARRAY_LEN];

    printf("Enter array length: ");
    scanf("%d", &array_len);

    printf("Enter array of ints: ");
    int i = 0;
    for (; i < array_len; i++) {
        scanf("%d", &array[i]);
    }
    array[i] = '\0';

    printf("Enter target sum to find in the array: ");
    scanf("%d", &target_sum);

	// sort array
	buildMaxHeap(array, array_len);
	heapsort(array, array_len);
	printarray(array, array_len);
	
	twoSum(array, array_len, target_sum);

    return 0;
}
