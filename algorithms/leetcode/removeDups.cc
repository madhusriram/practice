#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

using namespace std;

// [0,0,1,1,1,2,2,3,3,4]
// [0,1,2,3,4]
// solve it using the two pointer method
void removeDups(int *arr, int arr_len) {
}

int main() {
	int arr_len;
	
	printf("Enter array length: ");
	scanf("%d", &arr_len);

	int *arr;
	arr = malloc(sizeof(int) * arr_len);

	printf("Enter array values\n");
	for (int i = 0; i < arr_len; i++) {
		scanf("%d", &arr[i]);
	}	

	removeDups(arr, arr_len);

	return 0;
}
