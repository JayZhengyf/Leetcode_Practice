int height(struct TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	if (leftHeight == -1 || rightHeight == -1 || fabs(leftHeight - rightHeight) > 1) {
		// 不是平衡二叉树
		return -1;
	} else {
		return fmax(leftHeight, rightHeight) + 1;
	}
}

bool isBalanced(struct TreeNode* root) {
	return height(root) >= 0;
}