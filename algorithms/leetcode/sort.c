#include <stdio.h>

// 4 10 5 3 1                                                                   
// root is the highest value and all parents are larger than their children     
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
        buildMaxHeap(arr, j);                                                   
    }                                                                           
}  
