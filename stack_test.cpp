#include <iostream>
#include "stack.h"

void _print(const char* output) {
	std::cout << output;
}

void _println(const char* output) {
	std::cout << output << std::endl;
}

void print_menu() {
	_println("-------------");
	_println("1. 创建栈");
	_println("2. 初始化栈");
	_println("3. 入栈");
	_println("4. 出栈");
	_println("5. 清空栈");
	_println("6. 销毁栈");
	_println("7. 遍历栈");
	_println("8. 退出");
	_println("-------------");
}

int main() {
	Stack* stack = NULL;
	int choose = 0;
	
	while (1) {
		print_menu();
		_print("输入序号:");
		std::cin >> choose;
		switch (choose) {
		case 1: {
			stack = new Stack;
			stack->base = 0;
			_println("创建栈成功!");
			break;
		}
		case 2: {
			if (init_stack(stack)) {
				_println("初始化成功!");
			}
			else {
				_println("初始化失败!");
			}
			break;
		}
		case 3: {
			int data = 0;
			_print("输入入栈数据:");
			std::cin >> data;
			if (push(stack, data)) {
				_println("入栈成功!");
			}
			else {
				_println("入栈失败!");
			}
			break;
		}
		case 4: {
			int _pop_data = pop(stack);
			if (_pop_data == -1) {
				_println("出栈失败!");
			}
			else {
				_print("出栈元素:");
				std::cout << _pop_data << std::endl;
			}
			break;
		}
		case 5: {
			if (clear(stack)) {
				_println("清空成功!");
			}
			else {
				_println("清空失败!");
			}
			break;
		}
		case 6: {
			if (destroy_stack(stack)) {
				_println("销毁成功!");
			}
			else {
				_println("销毁失败");
			}
			break;
		}
		case 7: {
			for_stack(stack);
			break;
		}
		case 8: {
			return 0;
		}
		default: {
			_println("请输入正确序号!");
		}
		}
	}
	return 0;
}