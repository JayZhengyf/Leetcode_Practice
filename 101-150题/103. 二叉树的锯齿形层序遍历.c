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


// 第0层为特殊情况
// 奇数层，从右到左
// 偶数层，从左到右
 
// 这道题的使用了双端队列（可以在任意一端插入元素）
// 遍历依然按照广度优先遍历
// 但是使用isOrderLeft变量来记录这一层的元素怎样插入队列

// isOrderLeft为true，则将这一层遍历到的元素依次插入队列的尾部
// isOrderLeft为false，则将这一层遍历到的元素依次插入队列的头部

#define N 2000  // 节点最大为2000

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
	*returnSize = 0;
	if (root == NULL){
		return NULL;
	}
	int** ans = malloc(sizeof(int*) * N);
	*returnColumnSizes = malloc(sizeof(int) * N);
	struct TreeNode* nodeQueue[N];
	int left = 0, right = 0;
	bool isOrderLeft = true;
	nodeQueue[right++] = root;
	
	while (right > left) {
		int levelList[N * 2];  // 双端队列
		int front = N, rear = N;
		int size = right - left;
		for (int i = 0; i < size; ++i) {
			struct TreeNode*node = nodeQueue[left++];
			if (isOrderLeft) {
				levelList[rear++] = node->val;
			} else {
				levelList[--front] = node->val;
			}
			if (node->left) {
				nodeQueue[right++] = node->left;
			}
			if (node->right) {
				nodeQueue[right++] = node->right;
			}
		}
		int* tmp = malloc(sizeof(int) * (rear - front));
		for (int i = 0; i < rear - front; ++i) {
			tmp[i] = levelList[i + front];
		}
		ans[*returnSize] = tmp;
		(*returnColumnSizes)[(*returnSize)++] = rear - front;
		isOrderLeft = !isOrderLeft;	
	}
	return ans;
}