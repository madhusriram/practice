#include <stdio.h>
#include <stdlib.h>

// in-place moving of 0's to end of array
// 0 1 0 3 12
// O(n) time and O(1) space
void removeZeroes(int *arr, int len) {
	int *f = arr;
	int *s = arr;

	// start 2nd pointer from the second element
	if (*s != '\0')
		s++;

	for (int i = 0; i < len; i++) {
		if (*f == 0 && *s != 0) {
			int tmp = *s;
			*s = *f;
			*f = tmp;
			f++;
		} else if (*f != 0) {
			f++;
		}
		s++;
	}
}

int main() {
	int len;
	int *arr;
	int i;

	printf("Enter array length: ");
	scanf("%d", &len);

	arr = (int *)malloc(sizeof(int) * len);
	
	printf("Enter array filled with random 0's: ");
	for (i = 0; i < len; i++) {
		scanf("%d", &arr[i]);
	}

	// solves using remove-erase idiom
	//std::vector<int> v = {0, 1, 0, 3, 12};
	//v.erase(std::remove(v.begin(), v.end(), 0), v.end());

	removeZeroes(arr, len);

	printf("Zeroe's at the end of the array output: ");
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
