#include  "array.h"

using namespace std;

void insertion_sort(int *arr, int size) {
	for (int i = 1; i < size; i++) {
		int temp = arr[i];
		int j = i - 1;
		for (; j >= 0 && arr[j] > temp; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}

int main() {
	IntArray* arr = create_arr();
	insertion_sort(arr->arr, arr->size);
	return 0;
}