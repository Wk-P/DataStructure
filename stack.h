#pragma once

typedef struct Stack{
	int data;
	int* top;	// 栈顶下一个地址
	int* base;	// 栈底
	int size;
} Stack;


bool init_stack(Stack* s);
bool push(Stack* s, int data);
int pop(Stack* s);
bool clear(Stack* s);
bool destroy_stack(Stack* s);
void for_stack(Stack* s);
