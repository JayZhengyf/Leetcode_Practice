typedef struct {
    int val;
    struct TreeNode* node;
    struct queNode* next;
} queNode;

void init(queNode **p, int val, struct TreeNode* node) {
    (*p) = (queNode*)malloc(sizeof(queNode));
    (*p)->val = val;
    (*p)->node = node;
    (*p)->next = NULL;
}

int minDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    queNode *queLeft, *queRight;
    init(&queLeft, 1, root);
    queRight = queLeft;

    while (queLeft != NULL) {
        struct TreeNode* node = queLeft->node;
        int depth = queLeft->val;
        // 广度优先遍历首次遇见的叶子节点就是需要的节点
        if (node->left == NULL && node->right == NULL) {
            return depth;
        }
        // 入队
        if (node->left != NULL) {
            init(&queRight->next, depth + 1, node->left);
            queRight = queRight->next;
        }
        if (node->right != NULL) {
            init(&queRight->next, depth + 1, node->right);
            queRight = queRight->next;
        }
        queLeft = queLeft->next;
    }
    return 0;
}