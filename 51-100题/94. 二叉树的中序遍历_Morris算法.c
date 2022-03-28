/*
 Mirros算法的实质：
假设遍历到了节点x，将x的左子树的最右边的节点的右孩子指向x
如此，遍历完左子树之后，就可以通过这个指向，直接走到x 
*/

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	int* res = malloc(sizeof(int) * 501);
	*returnSize = 0;
	struct TreeNode* predecessor = NULL;
	
	while (root != NULL) {
		if (root->left != NULL) {
			// predecessor节点就是当前root节点向左走一步，然后一直向右走到尽头
			// 如果predecessor的右孩子指向了根节点，则说明左子树已经遍历遍历完了
			predecessor = root->left;
			while (predecessor->right != NULL && predecessor->right != root) {
				predecessor = predecessor->right;
			}
			// 让predecessor的右指针指向root，继续遍历左子树
			if (predecessor->right == NULL) {
				predecessor->right = root;
				root = root->left;
			} else {	// 左子树访问完了， 需要断开连接
				res[(*returnSize)++] = root->val;
				root = root->right;
			}
		} else {	// 没有左孩子，直接访问右孩子
			res[(*returnSize)++] = root->val;
			root = root->right;
		}
	}
	return res;
 }