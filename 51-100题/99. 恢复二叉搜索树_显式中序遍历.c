/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int len, max_size;

// 中序遍历得到树的序列
// 二叉搜索树中序遍历得到的系列一定是升序
void inorder(struct TreeNode* root, int** nums) {
	if (root == NULL) {
		return;
	}
	inorder(root->left, nums);
	(*nums)[len++] = root->val;
	if (len == max_size) {
		max_size <<= 1;
		(*nums) = (int*)realloc((*nums), sizeof(int) * max_size);
	}
	inorder(root->right, nums);
}

// 找到nums中的不正确的节点
int* findTwoSwapped(int* nums) {
	int index1 = -1, index2 = -1;
	for (int i = 0; i < len - 1; ++i) {
		if (nums[i] > nums[i + 1]) {
			index2 = i + 1;
			// 找到了第一个不正确的节点
			if (index1 == -1) {
				index1 = i;
			} else {  // 找到了第二个不正确的节点
				break;
			}
		}
	}
	int x = nums[index1], y = nums[index2];
	int* ret = (int*)malloc(sizeof(int) * 2);
	ret[0] = x, ret[1] = y;
	return ret;
}

// 恢复二叉搜索树
// count用来记录有还有几个节点没有恢复
void recover(struct TreeNode* r, int count, int x, int y) {
	if (r != NULL) {
		if (r->val == x || r->val == y) {
			r->val = r->val == x ? y : x;
			if (--count == 0) {
				return;
			}
		}
		recover(r->left, count, x, y);
		recover(r->right, count, x, y);
	}
}


void recoverTree(struct TreeNode* root){
	len = 0, max_size = 1;
	int* nums = (int*)malloc(sizeof(int));
	inorder(root, &nums);
	int* swapped = findTwoSwapped(nums);
	recover(root, 2, swapped[0], swapped[1]);
}