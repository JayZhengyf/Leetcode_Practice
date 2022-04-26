int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
	int* temp = malloc(sizeof(int) * (k + 1));
	int tempSize = 0;
	
	int** ans = malloc(sizeof(int*) * (1 << n));
	int ansSize = 0;
	
	// 初始化
	// 将temp中的[0, k - 1]每个位置i设置为i+1
	// 即[0, k - 1]存[1, k]
	// 末尾加一位n+1作为哨兵
	for (int i = 1; i <= k; ++i) {
		temp[i - 1] = i;
	}
	temp[k] = n + 1;
	
	int j = 0;
	while (j < k) {
		int* tmp = malloc(sizeof(int) * k);
		for (int i = 0; i < k; ++i) {
			tmp[i] = temp[i];
		}
		ans[ansSize++] = tmp;
		j = 0;
		// 寻找第一个temp[j] + 1 != temp[j + 1]的位置的t
		// 把[0, t - 1]区间中的每个位置重置成[1, t]
		while (j < k && temp[j] + 1 == temp[j + 1]) {
			temp[j] = j + 1;
			++j;
		}
		// j是第一个temp[j] + 1 != temp[j + 1]的位置
		++temp[j];
	}
	*returnSize = ansSize;
	*returnColumnSizes = malloc(sizeof(int) * ansSize);
	for (int i = 0; i < ansSize; ++i) {
		(*returnColumnSizes)[i] = k;
	}
	return ans;
}