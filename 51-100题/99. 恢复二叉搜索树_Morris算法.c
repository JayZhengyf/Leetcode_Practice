void recoverTree(struct TreeNode* root) {
	struct TreeNode* x = NULL;
	struct TreeNode* y = NULL;
	struct TreeNode* pred = NULL;  // 使用pred节点来记录前一个节点
	struct TreeNode* predecessor = NULL;
	
	while (root != NULL) {
		if (root->left != NULL) {
			// 找到predecessor节点
			predecessor = root->left;
			while (predecessor->right != NULL && predecessor->right != root) {
				predecessor = predecessor->right;
			}
				
			// 让predecessor的右指针指向root，然后继续遍历左子树
			if (predecessor->right == NULL) {
				predecessor->right = root;
				root = root->left;
			} else {  // 说明左子树已经遍历完了，需要断开连接
				if (pred != NULL && root->val < pred->val) {
					y = root;
					if (x == NULL) {
						x = pred;
					}
				}
				pred = root;
				
				predecessor->right = NULL;
				root = root->right;
			}
		} else {  // 没有左孩子，直接访问右孩子
			if (pred != NULL && root->val < pred->val) {
				y = root;
				if (x == NULL) {
					x = pred;
				}
			}
			pred = root;
			root = root->right;
		}
	}
	int t = x->val;
	x->val = y->val, y->val = t;
}