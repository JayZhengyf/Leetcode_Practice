/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int post_idx;

typedef struct {
	int key;
	int val;
	UT_hash_handle hh;
} hashTable;

hashTable* idx_map;

// 创建节点的hash表
// 节点值为key, 节点下标为val
void insertHashTable(int x, int y) {
	hashTable* rec = malloc(sizeof(hashTable));
	rec->key = x;
	rec->val = y;
	HASH_ADD_INT(idx_map, key, rec);
}

// 查询节点值为x的节点下标
int queryHashTable(int x) {
	hashTable* rec;
	HASH_FIND_INT(idx_map, &x, rec);
	return rec->val;
}

// 构造二叉树
// in_left与in_right为左右边界
struct TreeNode* helper(int in_left, int in_right, int* inorder, int* postorder) {
	// 没有节点了
	if (in_left > in_right) {
		return NULL;
	}
	
	// 选择post_idx位置的元素作为当前子树的根节点
	int root_val = postorder[post_idx];
	struct TreeNode* root = malloc(sizeof(struct TreeNode));
	root->val = root_val;
	
	// 根据root所在位置分左右两棵子树
	int index = queryHashTable(root_val);
	// 指向下一个根节点
	post_idx--;
	
	// 必须先构造右子树, 再构造左子树 
	// 因为后序遍历的数组中整个数组是先存储左子树的节点，再存储右子树的节点，最后存储根节点
	// 如果按每次选择「后序遍历的最后一个节点」为根节点，则先被构造出来的应该为右子树。

	// 构造右子树
	root->right = helper(index + 1, in_right, inorder, postorder);
	// 构造左子树
	root->left = helper(in_left, index - 1, inorder, postorder);
	
	return root;
}

// inorder: 中序遍历的数组 postorder: 后序遍历的数组
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
	post_idx = postorderSize - 1;
	
	idx_map = NULL;
	int idx = 0;
	for (int i = 0; i < inorderSize; ++i) {
		insertHashTable(inorder[i], idx++);
	}
	
	return helper(0, inorderSize - 1, inorder, postorder);
}