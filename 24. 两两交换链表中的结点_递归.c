/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapPairs(struct ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	
	/*思考：head->next = swapPairs(newHead->next)
	和newHead->next = head 交换顺序会怎样？
	 
	答：如果先写newHead->next = head那么newhead的next就变了
	而swapPairs()需要使用原本的newHead的next
	因此，交换顺序后会产生一个死循环
	*/
	
	// newHead指向head->next
	struct ListNode* newHead = head->next;
	// head->next指向其余代码的head
	head->next = swapPairs(newHead->next);
	// newHead->next指向head
	newHead->next = head;	
	
	return newHead;
}