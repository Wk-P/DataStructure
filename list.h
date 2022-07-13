typedef struct ListNode {
	int data;
	struct ListNode* next;
} ListNode;

bool is_empty(ListNode** head);
bool add_element(ListNode** head); // 尾插法
ListNode* search_element(ListNode** head, int target);
bool modify_element(ListNode** head, int index, int target);
bool delete_element(ListNode** head, int target);
void print_list(ListNode** head);