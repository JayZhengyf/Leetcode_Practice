int cmp(int* a, int* b) {
	return *a - *b;
}

int* t;
int tSize;

void dfs(bool choosePre, int cur, int* nums, int numSize, int** ret, int* returnSize, int** returnColumnSizes) {
	if (cur == numSize) {
		int* tmp = malloc(sizeof(int) * tSize);
		memcpy(tmp, t, sizeof(int) * tSize);
		ret[*returnSize] = tmp;
		(*returnColumnSizes)[(*returnSize)++] = tSize;
		return;
	}
	// 不统计前一个
	dfs(false, cur + 1, nums, numSize, ret, returnSize, returnColumnSizes);
	// 如果不统计前一个，但是nums[cur - 1] == nums[cur]成立
	// 则说明含这个元素的子集已经存在，因此直接返回即可
	if (!choosePre && cur > 0 && nums[cur - 1] == nums[cur]) {
		return;
	}
	t[tSize++] = nums[cur];
	// 统计前一个
	dfs(true, cur + 1, nums, numSize, ret, returnSize, returnColumnSizes);
	tSize--;
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	qsort(nums, numsSize, sizeof(int), cmp);
	int n = numSize;
	*returnSize = 0;
	*returnColumnSizes = malloc(sizeof(int) * (1 << n));
	int** ret = malloc(sizeof(int*) * (1 << n));
	t = malloc(sizeof(int) * n);
	dfs(false, 0, nums, n, ret, returnSize, returnColumnSizes);
	return ret;
}