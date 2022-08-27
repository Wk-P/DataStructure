#include "array.h"

void selection_sort1(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		int min = i;
		int j = i + 1;
		for (; j < size; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		if (min == i) {
			continue;
		}
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

void selection_sort2(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		// 判定是否需要交换
		if (min == i) {
			continue;
		} else {
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

int main() {
	intarray_sort(&selection_sort);
	return 0;

}
