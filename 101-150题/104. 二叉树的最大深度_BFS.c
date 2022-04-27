// 队列节点
struct QueNode {
	struct TreeNode* p;
	struct QueNode* next;
};

// 将t入队
void init(struct QueNode** p, struct TreeNode* t) {
	(*p) = (struct QueNode*)malloc(sizeof(struct QueNode));
	(*p)->p = t;
	(*p)->next = NULL;
}

// 不同于一般的bfs（每次只从队列里拿出一个节点进行扩展）
// 在这里我们需要一次将这一层所有节点都拿出来进行扩展
// 放入节点时，我们也是每次将这一层所有节点放入
int maxDepth(struct TreeNode* root) {
	if (root == NULL) return 0;
	struct QueNode *left, *right;  // left指向队列的左边，right指向队列的右边
	init(&left, root);
	right = left;
	// ans记录有几层，sz记录当前层有几个节点
	int ans = 0, sz = 1, tmp = 0;
	while (left != NULL) {
		tmp = 0;
		while (sz > 0) {
			if (left->p->left != NULL) {
				init(&right->next, left->p->left);
				right = right->next;
				tmp++;
			}
			if (left->p->right != NULL) {
				init(&right->next, left->p->right);
				right = right->next;
				tmp++;
			}
			left = left->next;
			sz--;
		}
		sz += tmp;
		ans++;
	}
	return ans;
}