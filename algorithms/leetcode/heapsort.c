#include <stdio.h>

// Heap sort
//

const int ARRAY_LEN = 1000;

void printarr(int *arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

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
		int new_len = j - 1;
		buildMaxHeap(arr, j);
	}
}

int main() {
	int arr[ARRAY_LEN];
	int actual_arr_len;
	int i, j;

	printf("Enter array length: ");
	scanf("%d", &actual_arr_len);

	printf("Enter data to be sorted in ascending order: ");
	for (i = 0; i < actual_arr_len; i++) {
		scanf("%d", &arr[i]);
	}
	arr[i] = '\0';

	buildMaxHeap(arr, actual_arr_len);

	heapsort(arr, actual_arr_len);

	// print array
	printarr(arr, actual_arr_len);

	return 0;
}
