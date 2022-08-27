#include "array.h"

void selection_sort(int *arr, int size) {
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

int main() {
	intarray_sort(&selection_sort);
	return 0;

}