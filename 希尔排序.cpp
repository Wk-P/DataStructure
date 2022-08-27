#include "array.h"

void shell_sort(int *arr, int size) {
	for (int interval = size / 2; interval > 0; interval /= 2) {
		for (int i = interval; i < size; i++) {
			int temp = arr[i];
			int j = i - interval;
			for (; j >= 0 && arr[j] > temp; j -= interval) {
				arr[j + interval] = arr[j];
			}
			arr[j + interval] = temp;
		}
	}
}

int main() {
	IntArray* array = create_arr();
	shell_sort(array->arr, array->size);
	return 0;
}