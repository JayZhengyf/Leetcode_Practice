/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL) {
		return true;
	} else if (p == NULL || q == NULL) {
		return false;
	}
	// 存放两棵树节点的队列
	struct TreeNode** que1 = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
	struct TreeNode** que2 = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
	int queleft1 = 0, queright1 = 0;
	int queleft2 = 0, queright2 = 0;
	que1[queright1++] = p;
	que2[queright2++] = q;
	
	while (queleft1 < queright1 && queleft2 < queright2) {
		// 节点出队列
		struct TreeNode* node1 = que1[queleft1++];
		struct TreeNode* node2 = que2[queleft2++];
		if (node1->val != node2->val) {
			return false;
		}
		struct TreeNode* left1 = node1->left;
		struct TreeNode* right1 = node1->right;
		struct TreeNode* left2 = node2->left;
		struct TreeNode* right2 = node2->right;
		// 判断对应节点位置是否相同
		if ((left1 == NULL) ^ (left2 == NULL)) {
			return false;
		}
		if ((right1 == NULL) ^ (right2 == NULL)) {
			return false;
		}
		// 如果节点不为空就放入队列
		if (left1 != NULL) {
			queright1++;
			que1 = realloc(que1, sizeof(struct TreeNode*) * queright1);
			que1[queright1 - 1] = left1;
		}
		if (right1 != NULL) {
			queright1++;
			que1 = realloc(que1, sizeof(struct TreeNode*) * queright1);
			que1[queright1 - 1] = right1;
		}
		if (left2 != NULL) {
			queright2++;
			que2 = realloc(que2, sizeof(struct TreeNode*) * queright2);
			que2[queright2 - 1] = left2;
		}
		if (right2 != NULL) {
			queright2++;
			que2 = realloc(que2, sizeof(struct TreeNode*) * queright2);
			que2[queright2 - 1] = right2;
		}
	}
	// 如果两棵树的节点队列最终都为空，则说明两棵树相同
	return queleft1 == queright1 && queleft2 == queright2;
}