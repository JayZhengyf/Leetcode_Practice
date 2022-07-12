// 与108题类似

int getLength(struct ListNode* head) {
	int ret = 0;
	while (head != NULL) {
		++ret, head = head->next;
	}
	return ret;
}

struct TreeNode* buildTree(struct ListNode** head, int left, int right) {
	if (left > right) {
		return NULL;
	}
	// mid = (left + right) / 2 也可以
	int mid = (left + right + 1) / 2;
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->left = buildTree(head, left, mid - 1);
	// 先使用一个占位元素，等到中序遍历到该节点时，再填充它的值
	root->val = (*head)->val;
	(*head) = (*head)->next;
	root->right = buildTree(head, mid + 1, right);
	
	return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
	int length = getLength(head);
	return buildTree(&head, 0, length - 1);
}