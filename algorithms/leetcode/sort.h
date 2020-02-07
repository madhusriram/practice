// APIs for sorting techniques

#ifndef _SORT_H_
#define _SORT_H_

// heapsort
// 'a' for ascending order and 'd' for descending order
void heapsort(int *arr, int array_len, char sorting_order);

// build max heap and call extractMax 'k' times
int extractKLargest(int *arr, int array_len, int k);

#endif // _SORT_H_
