class Solution {
public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		// 哨兵结点prehead，初始val为-1
		ListNode prehead = new ListNode(-1);
		
		ListNode prev = prehead;
		while (l1 != null && l2 != null) {
			// 哪一个链表的当前结点的val值小
			// 就将这个结点接在prev后面
			if (l1.val < l2. val) {
				prev.next = l1;
				l1 = l1.next;
			} else {
				prev.next = l2;
				l2 = l2.next;
			}
			prev = prev.next;
		}
		prev.next = l1 == null ? l2 : l1;
		
		return prehead.next;
	}	
}