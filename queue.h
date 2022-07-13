#pragma once

typedef struct Queue {
	int* front;
	int* rear;
	int size;
} Queue;

Queue* create_queue() {
	Queue* q = new Queue;
	q->front = 0;
	q->rear = q->front;
	q->size = 0;
	return q;
}

bool init_queue(Queue* q) {
	if (!q) return false;
	if (q->size) return false;
	q->front = new int;
	q->rear = q->front;
	q->size = 0;
	return true;
}

bool push(Queue* q, int data) {
	if (!q || !q->front) return false;
	if (!q->size) {
		*(q->front) = data;
	}
	else {
		*(q->rear++) = data;
	}
	q->size++;
	return true;
}

int pop(Queue* q) {
	if (!q || !q->size) return false;
	int ret = *(q->front);
	if (q->size == 1) {
		q->front = 0;
		q->rear = q->front;
		q->size--;
	} else {
		q->front++;
		q->size--;
	}
	return ret;
}

bool get_size(Queue* q) {
	return q->size;
}

/*查找元素省略...*/