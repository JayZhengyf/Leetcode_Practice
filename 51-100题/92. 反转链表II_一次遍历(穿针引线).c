struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
	struct ListNode* dummyNode = malloc(sizeof(struct ListNode));
	dummyNode->val = -1;
	dummyNode->next = head;
	
	struct ListNode* pre = dummyNode;
	for (int i = 0; i < left - 1; ++i) {
		pre = pre->next;
	}
	
	struct ListNode* cur = pre->next;
	struct ListNode* next;
	
	// 开始反转left到right的链表
	// right-left+1个元素需要操作right-left次
	
	for (int i = 0; i < right - left; ++i) {
		next = cur->next;
		cur->next = next->next;
		next->next = pre->next;
		pre->next = next;
	}
	
	return dummyNode->next;
}