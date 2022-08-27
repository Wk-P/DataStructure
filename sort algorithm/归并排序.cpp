#include "array.h"

/*  有序子列的合并 
	双指针排序
*/

int* merge_sort(int *arr, int size) {
	int mid = size / 2, i = 0, j = mid, k = 0;
	int *a = new int[size];
	for (int m = 0; m < size; m++) {
		a[m] = 0;
	}
	bubble_sort(arr, i, mid);
	bubble_sort(arr, mid, size);
	print_array(arr, size);
	while (i < mid && j < size) {
		if (arr[i] > arr[j]) {
			a[k++] = arr[j++];
		}
		else {
			a[k++] = arr[i++];
		}
	}
	while (i < mid && k < size) {
		a[k++] = arr[i++];
	}
	while (j < size && k < size) {
		a[k++] = arr[j++];
	}
	return a;
}

int main() {
	IntArray* arr = create_arr();
	arr->arr = merge_sort(arr->arr, arr->size);
	print_IntArray(arr);
	return 0;
}