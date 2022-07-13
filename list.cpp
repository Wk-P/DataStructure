#include "list.h"
#include <iostream>

bool is_empty(ListNode** head) {
	if (!*head) {
		return true;
	}
	return false;
}

bool add_element(ListNode** head) { // 尾插法
	if (is_empty(head)) {
		*head = new ListNode;
		std::cout << "输入数据:";
		std::cin >> (*head)->data;
		(*head)->next = NULL;
		return true;
	}
	ListNode* temp = *head;
	ListNode* new_node = new ListNode;
	while (temp->next) {
		temp = temp->next;
	}
	std::cout << "输入数据:";
	std::cin >> new_node->data;
	temp->next = new_node;
	new_node->next = NULL;
	return true;
}

ListNode* search_element(ListNode** head, int target) {
	if (is_empty(head)) {
		return NULL;
	}
	ListNode* temp = *head;
	while (temp) {
		if (temp->data == target) {
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

bool modify_element(ListNode** head, int target, int new_data) {
	if (is_empty(head)) {
		return false;
	}
	ListNode* m_node = search_element(head, target);
	if (!m_node) return false;
	m_node->data = new_data;
	return true;
}

bool delete_element(ListNode** head, int target) {
	if (is_empty(head)) {
		return false;
	}
	if (!search_element(head, target)) {
		return false;
	}
	ListNode* temp = *head;
	if ((*head)->data == target) {
		delete *head;
		head = NULL;
		return true;
	}
	while (temp->next->data != target) {
		temp = temp->next;
	}
	ListNode* prev = temp;
	ListNode* _next = temp->next->next;
	prev->next = _next;
	delete temp->next;
	return true;
}

void print_list(ListNode** head) {
	if (is_empty(head)) {
		std::cout << "Empty!" << std::endl;
	}
	ListNode* temp = *head;
	while (temp) {
		std::cout << temp->data << " ---> ";
		temp = temp->next;
	}
	if (!temp) {
		std::cout << "NULL" << std::endl;
	}
	else {
		std::cout << "未知错误!" << std::endl;
	}
}