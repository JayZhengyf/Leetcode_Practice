/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// 寻找中间的节点
// 使用快慢指针法：初始时，快指针 fast 和慢指针 slow 均指向链表的左端点 left。
// 我们将快指针 fast 向右移动两次的同时，将慢指针 slow 向右移动一次，
// 直到快指针到达边界（即快指针到达右端点或快指针的下一个节点是右端点）。
// 此时，慢指针对应的元素就是中位节点。
struct ListNode* getMedian(struct ListNode* left, struct ListNode* right) {
	struct ListNode* fast = left;
	struct ListNode* slow = left;
	while (fast != right && fast->next != right) {
		fast = fast->next;
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

struct TreeNode* buildTree(struct ListNode* left, struct ListNode* right){
	if (left == right) {
		return NULL;
	}
	struct ListNode* mid = getMedian(left, right);
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = mid->val;
	root->left = root->right = NULL;
	root->left = buildTree(left, mid);
	root->right = buildTree(mid->next, right);
	
	return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
	return buildTree(head, NULL);
}