/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
	public ListNode reverseKGroup(ListNode head, int k) {
		ListNode hair = new ListNode(0);
		hair.next = head;
		ListNode pre = hair;
		
		while (head != null) {
			ListNode tail = pre;
			
			for (int i = 0; i < k; i++) {
				tail = tail.next;
				if (tail == null) {
					return hair.next;
				}
			}
			
			ListNode nex = tail.next;
			// 翻转
			ListNode[] reverse = myReverse(head, tail);
			// 刷新头指针和尾指针
			head = reverse[0];
			tail = reverse[1];
			// 刷新指针指向
			pre.next = head;
			tail.next = nex;
			// 移动pre和head到下一组
			pre = tail;
			head = tail.next;
		}
		
		return hair.next;
	}
	
	// 翻转
	// 具体参考第206题
	public ListNode[] myReverse(ListNode head, ListNode tail) {
		ListNode prev = tail.next;
		ListNode p = head;
		
		while (prev != tail) {
			ListNode nex = p.next;
			p.next = prev;
			prev = p;
			p = nex;
		}
		
		return new ListNode[]{tail, head};
	}
	
}
