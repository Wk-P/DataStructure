#include "list.h"
#include <iostream>
using namespace std;

void print_menu() {
	cout << "---------------" << endl;
	cout << "1. 创建列表" << endl;
	cout << "2. 添加元素" << endl;
	cout << "3. 查找元素" << endl;
	cout << "4. 修改元素" << endl;
	cout << "5. 删除元素" << endl;
	cout << "6. 输出列表" << endl;
	cout << "7. 退出" << endl;
	cout << "---------------" << endl;
}

int main() {\
	ListNode* head = NULL;
	while (1) {
		print_menu();

		int choose;
		cin >> choose;
		switch (choose) {
		case 1: {
			cout << "创建成功!" << endl;
			break;
		}
		case 2: {
			if (add_element(&head)) {
				cout << "添加成功!" << endl;
			}
			else {
				cout << "添加失败!" << endl;
			}
			break;
		}
		case 3: {
			int target = 0;
			cout << "输入要查找的元素:";
			cin >> target;
			ListNode* result = search_element(&head, target);
			if (!result) {
				cout << "没有该元素!" << endl;
			}
			else {
				cout << "存在该元素!地址为:" << result << endl;
			}
			break;
		}
		case 4: {
			int new_data = 0, target = 0;
			cout << "输入要修改的元素值:";
			cin >> target;
			cout << "输入新的元素值:";
			cin >> new_data;
			if (modify_element(&head, target, new_data)) {
				cout << "修改成功!" << endl;
			}
			else {
				cout << "修改失败!" << endl;
			}
			break;
		}
		case 5: {
			int target = 0;
			cout << "请输入要删除的元素:";
			cin >> target;
			if (!delete_element(&head, target)) {
				cout << "没有可删除的元素或元素不存在!" << endl;
			}
			else {
				cout << "元素已删除!" << endl;
			}
			break;
		}
		case 6: {
			print_list(&head);
			break;
		}
		case 7: {
			return 0;
			break;
		}
		default: { 
			cout << "请输入正确序号!" << endl;
			break; 
		}
		}
	}
	return 0;
}