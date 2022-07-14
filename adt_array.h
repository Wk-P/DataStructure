#pragma once

// 自定义一维数组

typedef struct Array {
	int* data;
	int size;
} Array;

bool init_array(Array* array, int size) {
	if (!size || !array) return false;
	array->data = new int[size];
	array->data = { 0 };
	array->size = size;
	return true;
}

bool destroy_array(Array* array) {
	if (!array) return false;
	delete array->data;
	delete array;
	return true;
}

bool _assign(Array* array, int index, int data) {
	array->data[index] = data;
}

int get_data(Array* array, int index) {
	return array->data[index];
}