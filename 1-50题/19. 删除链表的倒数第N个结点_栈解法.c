/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 栈解法

// 栈的结点结构
struct Stack {
	struct ListNode* val;
	struct Stack* next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	// 哑结点
	struct ListNode* dummy = malloc(sizeof(struct ListNode));
	// 在head结点之前添加一个哑结点dummy
	dummy->val = 0, dummy->next = head;
	struct Stack* stk = NULL;
	struct ListNode* cur = dummy;
	// 将链表元素全部入栈
	while (cur) {
		struct Stack* tmp = malloc(sizeof(struct Stack));
		tmp->val = cur, tmp->next = stk;
		stk = tmp;
		cur = cur->next;
	}
	// 栈中的前n个元素出栈
	for (int i = 0; i < n; i++) {
		struct Stack* tmp = stk->next;
		free(stk);
		stk = tmp;
	}
	
	// 此时stk结点指向目标结点的前驱节点
	struct ListNode* prev = stk->val;
	prev->next = prev->next->next;
	struct ListNode* ans = dummy->next;
	free(dummy);
	return ans;
}

