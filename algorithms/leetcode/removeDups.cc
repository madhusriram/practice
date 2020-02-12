#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

using namespace std;

// [0,0,1,1,1,2,2,3,3,4]
// [0,1,2,3,4] = 5
// solve it using the two pointer method
// return the length of the duplicate-less array and modify the array in-place
int removeDups(int *arr, int arr_len) {
	int new_len = 0;
	int j = 0;

	for (int i = 0; i < arr_len; ) {
		char cur = arr[i];
		new_len++;
		for (j = i; j < arr_len; j++) {
			if (cur != arr[j]) {
				break;
			}
		}
		i = j;
	}
	return new_len;
}

int main() {
	int arr_len;
	
	printf("Enter array length: ");
	scanf("%d", &arr_len);

	int *arr;
	arr = (int *)malloc(sizeof(int) * arr_len);

	printf("Enter array values\n");
	for (int i = 0; i < arr_len; i++) {
		scanf("%d", &arr[i]);
	}	

	int new_len = removeDups(arr, arr_len);
	printf("Duplicate-less array length: %d\n", new_len);

	return 0;
}
