/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int height(struct TreeNode* root) {
	if (root == NULL) {
		return 0;
	} else {
		return fmax(height(root->left), height(root->right)) + 1;
	}
}
// 平衡二叉树的各个子树也要求是平衡二叉树
bool isBalanced(struct TreeNode* root){
	if (root == NULL) {
		return true;
	} else {
		return fabs(height(root->left) - height(root->right)) <= 1 
			&& isBalanced(root->left) && isBalanced(root->right);
	}
}