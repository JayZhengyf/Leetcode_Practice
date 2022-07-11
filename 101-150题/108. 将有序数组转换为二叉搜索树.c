/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// 本题要求是高度平衡的二叉搜索树
// 因此，选中间数字可以保证左右子树个数相同或差一
struct TreeNode* helper(int* nums, int left, int right) {
	if (left > right) {
		return NULL;
	}
	// 有三种选择根节点的方法：中间位置的左边，中间位置的右边，随机
	// 这里选择中间位置的左边
	int mid = (left + right) / 2;
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = nums[mid];
	root->left = helper(nums, left, mid - 1);
	root->right = helper(numd, mid + 1, right);
	return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
	return helper(nums, 0, numsSize - 1);
}