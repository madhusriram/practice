#include <stdio.h>
#include <stdlib.h>

// initial implementation O(Logn)
int *searchRange(int *arr, int arr_len, int target) {
	int *index = malloc(sizeof(int) * 2);
	index[0] = -1;
	index[1] = -1;

	for (int i = 0; i < arr_len; i++) {
		if (arr[i] == target) {
			index[0] = i;
			while (i < arr_len) {
				if (arr[i] > target) {
					index[1] = i - 1;
					return index;
				}
				i++;
			}
			index[1] = i;
			return index;
		}
	}
	return index;
}

int main() {
	int target;
	
	printf("Enter target to search: ");
	scanf("%d", &target);

	int arr_len;
	printf("Enter array length: ");
	scanf("%d", &arr_len);

	int *arr = malloc(sizeof(int) * arr_len);
	int i;
	printf("Enter array: ");
	for (i = 0; i < arr_len; i++) {
		scanf("%d", &arr[i]);
	}

	int *index = searchRange(arr, arr_len, target);

	printf("%d %d\n", index[0], index[1]);

	return 0;
}
