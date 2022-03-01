/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k) {
	// 处理特殊情况
	if (k  == 0 || head == NULL || head -> next == NULL) {
		return head;
	}
	int n = 1;  // 记录元素个数
	struct ListNode* iter = head;
	// 让iter指向最后一个元素
	while (iter -> next) {
		iter = iter->next;
		n++;
	}
	// 新链表的最后一个元素为原链表的第(n - (k mod n))个元素
	int add = n - (k % n);
	// 如果k为n的倍数，移动之后链表不变，故直接返回
	if (add == n) {
		return head;
	}
	// 将链表闭合成环
	iter->next = head;
	// 将iter指向新链表的尾结点
	while (add--) {
		iter = iter->next;
	}
	// 记录新链表的头结点
	struct ListNode* ret = iter->next;
	// 断开环
	iter->next = NULL;
	return ret;
}