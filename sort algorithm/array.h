#pragma once
#include <iostream>
using namespace std;

typedef struct IntArray {
	const char* name;
	int* arr;
	int size;
} IntArray;

void bubble_sort(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		int flag = 1; // 0:需要排序  1:不需要排序
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				flag = 0;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		if (flag) break;
	}
}

void bubble_sort(int* arr, int left, int right) {
	for (int i = left; i < right; i++) {
		int flag = 1; // 0:需要排序  1:不需要排序
		for (int j = left; j < right - i - 1 + left; j++) {
			if (arr[j] > arr[j + 1]) {
				flag = 0;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		if (flag) break;
	}
}

void print_array(int* arr, int size, const char* name = "arr") {
	cout << name << " = { ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "}" << endl;
}

void print_IntArray(IntArray* array) {
	cout << array->name << " = { ";
	for (int i = 0; i < array->size; i++) {
		cout << array->arr[i] << " ";
	}
	cout << "}" << endl;
}

IntArray* create_arr() {
	srand(time(NULL));
	IntArray* array = new IntArray;
	array->name = new char[128];
	//cout << "输入数组名字:"; cin >> array->name;
	array->name = "array";
	cout << "输入数组长度:"; cin >> array->size;
	array->arr = new int[array->size];
	for (int i = 0; i < array->size; i++) {
		array->arr[i] = rand() % 40 + 1;
	}
	return array;
}

void intarray_sort(void (*sort)(int*, int)) {
	IntArray* array = create_arr();
	print_IntArray(array);
	(*sort)(array->arr, array->size);
	print_IntArray(array);
}

IntArray* random_inorder_array() {
	IntArray* arr = create_arr();
	bubble_sort(arr->arr, arr->size);
	return arr;
}