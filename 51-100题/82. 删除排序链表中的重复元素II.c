/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
	if (!head) {  // 链表为空
		return head;
	}
	
	struct ListNode* dummy = malloc(sizeof(struct ListNode));
	dummy->next = head;
	
	struct ListNode* cur = dummy;
	while (cur->next && cur->next->next) {
		if (cur->next->val == cur->next->next->val) {
			int x = cur->next->val;
			while (cur->next && cur->next->val == x) {
				cur->next = cur->next->next;
			}
		} else {
			cur = cur->next;
		}
	}
	return dummy->next;
}