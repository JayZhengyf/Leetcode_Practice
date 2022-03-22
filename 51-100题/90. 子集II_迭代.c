int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int** subsetsWithDup(int* nums,	 int numsSize, int* returnSize, int** returnColumnSizes) {
	qsort(nums, numsSize, sizeof(int), cmp);
	int n = numsSize;
	*returnSize = 0;
	*returnColumnSizes = malloc(sizeof(int) * (1 << n));
	int** ans = malloc(sizeof(int*) * (1 << n));
	for (int mask = 0; mask < (1 << n); ++mask) {
		int* t = malloc(sizeof(int) * n);
		int tSize = 0;
		bool flag = true;
		for (int i = 0; i < n; ++i) {
			// 判断i指向的mask的位置是否为1
			// 为1表示相对应的nums[i]存在于子集
			if (mask & (1 << i)) {
				// nums[0]之前没有数字了，因此i > 0
				// (mask >> (i - 1)) & 1 用来判断nums[i-1]是否出现在子集内
				// 为0表示没有，为1表示有
				// 如果前两个条件都满足，当nums[i]==nums[i-1]时
				// 设置flag为false，进而使得重复子集不计入ans
				if (i > 0 && (((mask >> (i - 1)) & 1) == 0) && nums[i] == nums[i - 1]) {
					flag = false;
					break;
				}
				t[tSize++] = nums[i];
			}
		}
		t = realloc(t, sizeof(int) * tSize);
		if (flag) {
			ans[*returnSize] = t;
			(*returnColumnSizes)[(*returnSize)++] = tSize;
		}
	}
	ans = realloc(ans, sizeof(int*) * (*returnSize));
	return ans;
}