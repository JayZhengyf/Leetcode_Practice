/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void inorder(struct TreeNode* root, int* res, int* resSize) {
	// 树为空
	if (!root) {
		return;
	}
	inorder(root->left, res, resSize);
	res[(*resSize)++] = root->val;
	inorder(root->right, res, resSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	int* res = malloc(sizeof(int) * 501);
	*returnSize = 0;
	inorder(root, res, returnSize);
	return res;
}