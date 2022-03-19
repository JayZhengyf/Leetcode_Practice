/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
	struct ListNode* small = malloc(sizeof(struct ListNode));
	struct ListNode* smallHead  = small;
	struct ListNode* large = malloc(sizeof(struct ListNode));
	struct ListNode* largetHead = large;
	
	while (head != NULL) {
		if (head->val < x) {
			small->next = head;
			small = small->next;
		} else {
			large->next = head;
			large = large->next;
		}
		head = head->next;
	}
	large->next = NULL;
	small->next = largetHead->next;
	return smallHead->next;
}