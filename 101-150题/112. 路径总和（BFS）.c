/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct queNode {
    int val;
    struct TreeNode *node;
    struct queNode *next;
} queNode;

void init(struct queNode **p, int val, struct TreeNode *node) {
    (*p) = (struct queNode*)malloc(sizeof(queNode));
    (*p)->val = val;
    (*p)->node = node;
    (*p)->next = NULL;
}


bool hasPathSum(struct TreeNode* root, int targetSum){
    if (root == NULL) {
        return false;
    }
    struct queNode *queLeft, *queRight;
    init(&queLeft, root->val, root);
    queRight = queLeft;

    while (queLeft != NULL) {
        struct TreeNode *now = queLeft->node;
        int temp = queLeft->val;
        if (now->left == NULL && now->right == NULL) {
            if (temp == targetSum) return true;
        }
        if (now->left != NULL) {
            init(&queRight->next, now->left->val + temp, now->left);
            queRight = queRight->next;
        }
        if (now->right != NULL) {
            init(&queRight->next, now->right->val + temp, now->right);
            queRight = queRight->next;
        }
        queLeft = queLeft->next;
    }
    return false;
}