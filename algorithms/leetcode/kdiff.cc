#include <stdio.h>

int findCountOfDiffPairs(int *arr, int arr_len, int diff) {

}

int main() {
	int diff;
	
	printf("Enter the diff to be found: ");
	scanf("%d", &diff);

	printf("Enter array length: ");
	scanf("%d", &arr_len);

	int i;
	printf("Enter array: ");
	for (i = 0; i < arr_len; i++) {
		scanf("%d", &arr[i]);
	}
	arr[i] = '\0';

	int paircount = findCountOfDiffPairs(arr, arr_len, diff);

	printf("Pair count: %d\n", paircount);

	return 0;
}
