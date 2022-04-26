/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 双指针，一快一慢找到新的头结点
struct ListNode* rotateRight(struct ListNode* head, int k) {
	if (head == NULL || head -> next == NULL || k == 0) {
		return head;
	}
	// 统计元素个数
	int num = 1;
	struct ListNode* pnum = head;
    struct ListNode* pfast = head;
    struct ListNode* pslow = head;
	while (pnum -> next) {
		pnum = pnum -> next;
		num++;
	}
	// 当k为n的倍数时，移动之后无变化，古直接返回
	if ((k % num) == 0) {
		return head;
	}
	// 让pfast指针比pslow指针先走k步
	for (int i = 0; i < (k % num); i++) {
		pfast = pfast -> next;
	}
	// 让pfast与pslow同时向后运动
	// 直到pfast -> next == NULL
	// 此时pslow的下一个就是新链表的头结点
	while (pfast -> next) {
		pfast = pfast -> next;
		pslow = pslow -> next;
	}
	// 将原链表闭合成环
	pnum -> next = head;
	// 新链表的头结点
	struct ListNode* newhead = pslow -> next;
	// 断开环
	pslow -> next = NULL;
	
	return newhead;	
}