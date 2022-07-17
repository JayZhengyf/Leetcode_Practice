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

// 树中节点总数在范围 [0, 5000] 内
// -1000 <= Node.val <= 1000
// -1000 <= targetSum <= 1000

int** ret;
int retSize;
int* retColSize;

int* path;
int pathSize;

// hash表
typedef struct {
    struct TreeNode* key;
    struct TreeNode* val;
    UT_hash_handle hh;
} hashTable;

hashTable* parent;

// 插入键值对，y是x的父节点
void insertHashTable(struct TreeNode* x, struct TreeNode* y) {
    hashTable* rec = malloc(sizeof(hashTable));
    rec->key = x;
    rec->val = y;
    HASH_ADD_PTR(parent, key, rec);  // 第二个参数是键字段的名称。
}
// 查询x节点，得到其父节点
struct TreeNode* queryHashTable(struct TreeNode* x) {
    hashTable* rec;
    HASH_FIND_PTR(parent, &x, rec);
    return rec->val;
}
// 获取node节点的路径信息
void getPath(struct TreeNode* node) {
    int* tmp = malloc(sizeof(int) * 2001);
    int tmpSize = 0;
    while (node != NULL) {
        tmp[tmpSize++] = node->val;
        node = queryHashTable(node);
    }
    // 目前的路径信息是倒过来的，翻转一下
    for (int i = 0; i < tmpSize / 2; i++) {
        int t = tmp[i];
        tmp[i] = tmp[tmpSize - 1 - i];
        tmp[tmpSize - 1 - i] = t;
    }
    ret[retSize] = tmp;
    retColSize[retSize++] = tmpSize;
}

int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes){
    ret = malloc(sizeof(int*) * 2001);
    retColSize = malloc(sizeof(int) * 2001);
    path = malloc(sizeof(int) * 2001);
    retSize = pathSize = 0;
    parent = NULL;
    insertHashTable(root, NULL);

    if (root == NULL) {
        *returnColumnSizes = retColSize;
        *returnSize = retSize;
        return ret;
    }

    struct TreeNode* que_node[10001];
    int que_sum[10001];
    int left = 0, right = 0;
    que_node[right] = root;  // 队列
    que_sum[right++] = 0;  // 记录对应位置的sum值

    while (left < right) {
        struct TreeNode* node = que_node[left];
        int rec = que_sum[left++] + node->val;

        if(node->left == NULL && node->right == NULL) {
            if (rec == targetSum) {
                getPath(node);
            }
        }
        else {
            if (node->left != NULL) {
                insertHashTable(node->left, node);
                que_node[right] = node->left;
                que_sum[right++] = rec; 
            }
            if (node->right != NULL) {
                insertHashTable(node->right, node);
                que_node[right] = node->right;
                que_sum[right++] = rec;
            }
        }
    }
    *returnColumnSizes = retColSize;
    *returnSize = retSize;
    return ret;
}