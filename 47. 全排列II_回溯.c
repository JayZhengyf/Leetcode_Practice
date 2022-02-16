// 本题与46题的区别在于有重复的数字
// 但最终返回的列表中每种排列只能有一个

int* vis;  // 标记数字是否访问过

// idx为当前访问到的数组下标
void backtrack(int* nums, int numSize, int** ans, int* ansSize, int idx, int* perm) {
	if (idx == numSize) {
		int* tmp = malloc (sizeof(int) * numSize);
		memcpy(tmp, perm, sizeof(int) * numSize);
		ans[(*ansSize)++] = tmp;
	}
	for (int i = 0; i < numSize; i++) {
		// 访问过的数字跳过
		// 重复的数字只取一次
		if (vis[i] || (i > 0) && nums[i] == nums[i - 1] && !vis[i - 1]) {
			continue;
		}
		perm[idx] = nums[i];
		vis[i] = 1;
		backtrack(nums, numSize, ans, ansSize, idx + 1, perm);
		vis[i] = 0;
	}
}

int cmp(void* a, void* b) {
	return *(int*)a - *(int*)b;
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	// 存储所有排列的列表
	int** ans = malloc(sizeof(int*) * 2001);
	// 存储当前排列的数组
	int* perm = malloc(sizeof(int) * 2001);
	// 标记数组
	vis = malloc(sizeof(int) * numsSize);
	memset(vis, 0, sizeof(int) * numsSize);
	qsort(nums, numsSize, sizeof(int), cmp);
	*returnSize = 0;
	backtrack(nums, numsSize, ans, returnSize, 0, perm);
	*returnColumnSizes = malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < *returnSize; i++) {
		(*returnColumnSizes)[i] = numsSize;
	}
	return ans;
}