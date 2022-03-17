int* temp;
int tempSize;

int** ans;
int ansSize;

void dfs(int cur, int n, int k) {
	// 剪枝：temp长度加上区间[cur, n]的长度小于k
	// 则不可能制造出长度为k的temp
	if (tempSize + (n - cur + 1) < k) {
		return;
	}
	// 记录合法的答案
	if (tempSize == k) {
		int* tmp = malloc(sizeof(int) * k);
		for (int i = 0; i < k; ++i) {
			tmp[i] = temp[i];
		}
		ans[ansSize++] = tmp;
		return;
	}
	// 选择当前位置
	temp[tempSize++] = cur;
	dfs(cur + 1, n, k);
	// 不选择当前位置
	tempSize--;
	dfs(cur + 1, n, k);
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
	temp = malloc(sizeof(int) * k);
	ans = malloc(sizeof(int*) * (1 << n));
	tempSize = ansSize = 0;
	dfs(1, n, k);
	*returnSize = ansSize;
	*returnColumnSizes = malloc(sizeof(int) * ansSize);
	for (int i = 0; i < ansSize; ++i) {
		(*returnColumnSizes)[i] = k;
	}
	return ans;
}