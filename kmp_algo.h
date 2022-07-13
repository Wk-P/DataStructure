#pragma once
#include <iostream>
#include <iomanip>

int* _next_array(char* str, int size) {
	int* next = new int[size];
	for (int p = 0; p < size; p++) {
		next[p] = 0;
	}
	int i = 0, j = 1;
	while (j < size) {
		if (i == 0 || str[i] == str[j]) {
			next[j++] = i++;
		}
		else {
			i = next[i];
		}
	}
	next[0] = -1;
	return next;
}

void _print(char* str, int* next, int size) {
	std::cout << " str: ";
	for (int i = 0; i < size; i++) {
		std::cout << std::setw(2) << std::setfill(' ') << str[i] << "|";
	}
	std::cout << std::endl;
	std::cout << "next: ";
	for (int i = 0; i < size; i++) {
		std::cout << std::setw(2) << std::setfill(' ') << next[i] << "|";
	}
	std::cout << std::endl;
}

void _print(char* str, int index1, int index2, int size) {
	if (index1 < 0 || index2 > size) { std::cout << "Error!" << std::endl; return; }
	for (int i = 0; i < index1; i++) {
		std::cout << str[i];
	}
	std::cout << "\"";
	for (int i = index1; i < index2 + 1;i++) {
		std::cout << str[i];
	}
	std::cout <<  "\"" << std::endl;
}

int kmp_match(char* str_m, char* str_p, int size_m, int size_p) {
	if (size_m < size_p || size_m <= 0 || size_p <= 0 || !str_m || !str_p) return -1;

	int* next = _next_array(str_p, size_p);
	// i 控制主串, j 控制模式串
	int i = 0, j = 0;

	while (i < size_m) {
		if (j == -1||str_m[i] == str_p[j]) {
			if (j == size_p - 1) {
				return i - j;
			}
			i++, j++;
		}
		else {
			j = next[j];
		}
	}
	return -1;
}