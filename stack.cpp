#include "stack.h"
#include <iostream>

bool init_stack(Stack* s) {
	if (!s) return false;
	if (s->size) return false;
	s->base = new int;
	s->top = s->base;
	s->size = 0;
	return true;
}

bool push(Stack* s, int data) {
	if (!s) return false;
	if (!s->base) return false;
	if (data == -1) return false;
	*(s->top) = data;
	s->top += 1;
	s->size++;
	return true;
}

int pop(Stack* s) {
	if (!s) return -1;
	if (!s->base) return -1;
	if (!s->size) return -1;
	s->top--;
	s->size--;
	int ret = (s->base)[s->size];
	return ret;
}

bool clear(Stack* s) {
	if (!s || !s->size) return false;
	if (!s->base) return false;
	s->size = 0;
	s->top = s->base;
	return true;
}

bool destroy_stack(Stack* s) {
	if (!s) return false;
	clear(s);
	s->base = 0;
	delete s;
	return true;
}

void for_stack(Stack* s) {
	if (!s || !s->size || !s->base) {
		std::cout << "栈为空!" << std::endl;
		return;
	}
	int* sp = s->base;
	while (sp != s->top) {
		std::cout << "+ ---- +" << std::endl;
		std::cout << "|  " << *sp << "  |" << std::endl;
		sp++;
	}
	std::cout << "+ ---- +" << std::endl;
}