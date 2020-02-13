#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

// https://leetcode.com/problems/find-the-duplicate-number/

// Should be O(1) extra space and implementation better than O(N^2)
// perform heap sort - O(Logn) and then use 2 pointer method: O(n) totalling O(nlogn)
int findDup(int *arr, int arr_len) {
    heapsort(arr, arr_len, 'a');
    int dup = -1;

    for (int i = 0; i < arr_len; i++) {
        if (i+1 > arr_len) {
            return dup;
        }
        if (arr[i] == arr[i+1]) {
            return arr[i];
        }
    }

}

int main() {
    int arr_len;
    printf("Enter array length: ");
    scanf("%d", &arr_len);

    int *arr = malloc(sizeof(int) * arr_len);
    printf("Enter array: ");
    
    for (int i = 0; i < arr_len; i++) {
        scanf("%d", &arr[i]);
    }

    int dup = findDup(arr, arr_len);
    printf("Duplicate number: %d", dup);

    return 0;
}