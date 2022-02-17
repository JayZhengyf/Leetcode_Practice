/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head) {
	// 设置一个哑结点 
	struct ListNode dummyHead;
	dummyHead.next = head;
	
	struct ListNode* temp = &dummyHead;
	while (temp->next != NULL && temp->next->next != NULL) {
		struct ListNode* node1 = temp->next;
		struct ListNode* node2 = temp->next->next;
		
		// 结点交换
		temp->next = node2;
		node1->next = node2->next;
		node2->next = node1;
		
		// temp结点向后移动两个结点
		// 进行下一轮交换
		temp = node1;
	}
	
	return dummyHead.next;
}