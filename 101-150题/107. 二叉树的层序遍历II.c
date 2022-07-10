/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
	int** levelOrder = malloc(sizeof(int*) * 2001);
	*returnColumnSizes = malloc(sizeof(int) * 2001);
	*returnSize = 0;
	if (!root) {
		return levelOrder;
	}
	// 构造一个队列
	struct TreeNode** q = malloc(sizeof(struct TreeNode*) * 2001);
	int left = 0, right = 0;
	q[right++] = root;
	// BFS（广度优先遍历）
	while (left < right) {
		// 目前队列中的节点数
		int len = right - left;
		// 存放节点的值
		int* level = malloc(sizeof(int) * len);
		// 记录这一层的节点数
		(*returnColumnSizes)[*returnSize] = len;
		
		for (int i = 0; i < len; ++i) {
			struct TreeNode* node = q[left++];
			level[i] = node->val;
			if (node->left != NULL) {
				q[right++] = node->left;
			}
			if (node->right != NULL) {
				q[right++] = node->right;
			}
		}
		// 将这一层遍历的结果加入结果集
		levelOrder[(*returnSize)++] = level;
	}
	for (int i = 0; 2 * i < *returnSize; ++i) {
		// 现在的levelOrder是从第一层到最后一层的遍历
		// 需要将结果进行翻转
		int* tmp1 = levelOrder[i];
		levelOrder[i] = levelOrder[(*returnSize) - i - 1];
		levelOrder[(*returnSize) - i - 1] = tmp1;
		// 相应地记录每层元素个数的数组也需要调整
		int tmp2 = (*returnColumnSizes)[i];
		(*returnColumnSizes)[i] = (*returnColumnSizes)[(*returnSize) - i - 1];
		(*returnColumnSizes)[(*returnSize) - i - 1] = tmp2;
	}
	return levelOrder;
}