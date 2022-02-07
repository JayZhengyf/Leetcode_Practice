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
	// 合并K个链表
	public ListNode mergeKLists(ListNode[] lists) {
		return merge(lists, 0, lists.length - 1);
	}
	
	// 合并(right - left)个链表
	public ListNode merge(ListNode[] lists, int left, int right) {
		if (left == right) {
			return lists[left];
		}
		if (left > right) {
			return null;
		}
		// 使用位运算执行效率高、节约内存
		int mid = (left + right) >> 1;
		return mergeTwoLists(merge(lists, 1, mid), merge(lists, mid + 1, right));
		
	}
	// 合并两个链表
	public ListNode mergeTwoLists(ListNode a, ListNode b) {
		if (a == null || b == null) {
			return a != null ? a : b; 
		}
		ListNode head = new ListNode(0);
		ListNode tail = head, aPtr = a, bPtr = b;
		
		while (aPtr != null && bPtr != null) {
			if (aPtr.val < bPtr.val) {
				tail.next = aPtr;
				aPtr = aPtr.next;
			} else {
				tail.next = bPtr;
				bPtr = bPtr.next;
			}
			tail = tail.next;
		}
		
		tail.next = (aPtr != null ? aPtr : bPtr);
		return head.next;
	}
}