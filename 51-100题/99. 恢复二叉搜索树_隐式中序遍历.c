void recoverTree(struct TreeNode* root) {
	// 建立一个堆栈
	struct TreeNode** stk = (struct TreeNodd**)malloc(0);
	int stk_top = 0;
	struct TreeNode* x = NULL;
	struct TreeNode* y = NULL;
	struct TreeNode* pred = NULL;  // 使用pred节点标记前一个节点
	
	while (stk_top > 0 || root != NULL) {
		while (root != NULL) {
			stk_top++;
			stk = (struct TreeNodd**)realloc(stk, sizeof(struct TreeNodd*) * stk_top);
			stk[stk_top - 1] = root;
			root = root->left;
		}
		root = stk[--stk_top];
		if (pred != NULL && root->val < pred->val) {
			y = root;
			// 找到了第一个不正确节点
			if (x == NULL) {
				x = pred;
			} else {  // 找到了第二个不正确节点
				break;
			}
		}
		pred = root;
		root = root->right;
	}
	int t = x->val;
	x->val = y->val, y->val = t;
}