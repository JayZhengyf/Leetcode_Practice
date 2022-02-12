// 目前的解法没有剪枝

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// 最终的结构：列表ans:[[combine1], [combine2], ...]

int candidatesSize_tmp; 
int ansSize; // 返回的列表ans中的数组个数
int combineSize; // 组合combine中元素的个数
int* ansColumnSize; // 列表ans中每个combine的size构成的数组

void dfs(int* candidates, int target, int** ans, int* combine, int idx) {
	if (idx == candidatesSize_tmp) {
		return;
	}
	if (target == 0) {
		int* tmp = malloc(sizeof(int) * combineSize);
		for (int i = 0; i < combineSize; i++) {
			tmp[i] = combine[i];
		}
		ans[ansSize] = tmp;
		ansColumnSize[ansSize++] = combineSize;
		return;
	}
	// 直接跳过
	dfs(candidates, target, ans, combine, idx + 1);
	// 选择当前数
	if (target - candidates[idx] >= 0) {
		combine[combineSize++] = candidates[idx];
		dfs(candidates, target - candidates[idx], ans, combine, idx);
		// combineSize需要与当前的combine的状况保持一致
		combineSize--;
	}
}

// candidates：整数数组  candidatesSize：整数数组长度  target：目标数字
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
	candidatesSize_tmp = candidatesSize;
	ansSize = combineSize = 0;
	int** ans = malloc(sizeof(int*) * 1001);
	ansColumnSize = malloc(sizeof(int) * 1001);
	int combine[2001];
	dfs(candidates, target, ans, combine, 0);
	*returnSize = ansSize;
	*returnColumnSizes = ansColumnSize;
	return ans;
}