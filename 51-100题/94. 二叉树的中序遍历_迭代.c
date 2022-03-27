int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = 0;
	int* res = malloc(sizeof(int) * 501);
	struct TreeNode** stk = malloc(sizeof(struct TreeNode*) * 501);
	int top = 0;
	while (root != NULL || top > 0) {
		while (root != NULL) {
			stk[top++] = root;
			root = root->left;
		}
		root = stk[--top];
		res[(*returnSize)++] = root->val;
		root = root->right;
	}
	return res;
}