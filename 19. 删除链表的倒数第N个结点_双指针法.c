/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
/*
双指针法的实质：两个指针first、second，经过变换，最终中间间隔n，
当first指向最后一个结点时，second就指向目标结点的前驱节点
（有dummy结点时，first初始指向head，second初始指向dummy）
或second指向目标结点（无dummy结点，两指针初始都是在head）
*/
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode* dummy = malloc(sizeof(struct ListNode));
	dummy->val = 0, dummy->next = head;
	// first从head出发
	// second从dummy出发
	struct ListNode* first = head;
	struct ListNode* second = dummy;
	// first结点先走n步
	for (int i = 0; i < n; i++) {
		first = first->next;
	}
	// first和second结点共同移动
	// 直到first指向NULL
	while (first) {
		first = first->next;
		second = second->next;
	}
	// second此时指向目标结点的前驱节点
	second->next = second->next->next;
	struct ListNode* ans = dummy->next;
	free(dummy);
	return ans;
	
}