#include "array.h"

int main() {
	IntArray *arr = create_arr();
	bubble_sort(arr->arr, arr->size);
	return 0;
}