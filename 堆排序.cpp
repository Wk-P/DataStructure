#include "array.h"

void heap_sort(int *arr, int size) {
	for (; size > 1; size--) {
		// 每次排除最后一个元素重新建立大顶堆
		for (int i = size / 2 - 1; i >= 0; i--) {
			// 对每个 i 结点进行大顶堆数据交换
			if (i * 2 + 2 == size || arr[i * 2 + 2] == arr[i * 2 + 1]) {
				if (arr[i] < arr[i * 2 + 1]) {
					int temp = arr[i];
					arr[i] = arr[i * 2 + 1];
					arr[i * 2 + 1] = temp;
				}
			}
			else {
				if (arr[i * 2 + 2] < arr[i * 2 + 1]) {
					if (arr[i] < arr[i * 2 + 1]) {
						int temp = arr[i];
						arr[i] = arr[i * 2 + 1];
						arr[i * 2 + 1] = temp;
					}
				}
				else {
					if (arr[i] < arr[i * 2 + 2]) {
						int temp = arr[i];
						arr[i] = arr[i * 2 + 2];
						arr[i * 2 + 2] = temp;
					}
				}
			}
		}
		// 建立大顶堆完毕，交换堆顶元素和当前堆的堆底元素
		int temp = arr[0];
		arr[0] = arr[size - 1];
		arr[size - 1] = temp;
	}
}

int main() {
	intarray_sort(&heap_sort);
	return 0;
}