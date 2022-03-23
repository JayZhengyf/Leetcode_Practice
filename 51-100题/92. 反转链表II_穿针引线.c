/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 翻转链表
void reverseLinkedList(struct ListNode* head) {
	struct ListNode* pre = NULL;
	struct ListNode* cur = head;
	
	while (cur != NULL) {
		struct ListNode* next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
	// 设置一个哑节点
	struct ListNode* dummyNode = malloc(sizeof(struct ListNode));
	dummyNode->val = -1;
	dummyNode->next = head;
	
	// 让pre指向left-1
	struct ListNode* pre = dummyNode;
	for (int i = 0; i < left - 1; ++i) {
		pre = pre->next;
	}
	
	// 让rightNode指向right
	struct ListNode* rightNode = pre;
	for (int i = 0; i < right - left + 1; ++i) {
		rightNode = rightNode->next;
	}
	
	struct ListNode* leftNode = pre->next;
	struct ListNode* curr = rightNode->next;
	
	// 切出left到right的链表
	pre->next = NULL;
	rightNode->next = NULL;
	
	// 翻转left到right的链表
	reverseLinkedList(leftNode);
	
	// 重新连接上翻转后的链表
	pre->next = rightNode;
	leftNode->next = curr;
	
	return dummyNode->next;
}