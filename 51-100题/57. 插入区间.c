int** insert(int** intervals, int intervalsSize, int* intervalColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
	*returnSize = 0;
	int left = newInterval[0];
	int right = newInterval[1];
	bool placed = false;
	int** ans = malloc(sizeof(int*) * (intervalsSize + 1));
	*returnColumnSizes = malloc(sizeof(int*) * (intervalsSize + 1));
	
	for (int i = 0; i < intervalsSize; i++) {
		int* interval = intervals[i];
		if (interval[0] > right) {
			// newinterval在当前区间的左侧且无交集
			// 判断newinterval是否已经放入过ans
			// 如果放入过了就将当前区间放入ans
			// 如果没有就先将newinterval放入ans然后放入当前区间
			if (!placed) {
				int* tmp = malloc(sizeof(int) * 2);
				tmp[0] = left, tmp[1] = right;
				(*returnColumnSizes)[*returnSize] = 2;
				ans[(*returnSize)++] = tmp;
				placed = true;
			}
			int* tmp = malloc(sizeof(int) * 2);
			memcpy(tmp, interval, sizeof(int) * 2);
			(*returnColumnSizes)[*returnSize] = 2;
			ans[(*returnSize)++] = tmp;
		} else if (interval[1] < left) {
			// newinterval在当前区间的右侧且无交集
			// 将当前指向的区间放入ans
			int* tmp = malloc(sizeof(int) * 2);
			memcpy(tmp, interval, sizeof(int) * 2);
			(*returnColumnSizes)[*returnSize] = 2;
			ans[(*returnSize)++] = tmp;
		} else {
			// 与当前指向区间有交集，计算并集
			left = fmin(left, interval[0]);
			right = fmax(right, interval[1]);
		}
	} 
	// 如果遍历完所有区间后
	// newinterval仍然没有被放入ans
	// 这时就将newinterval直接放入ans即可
	if (!placed) {
		int* tmp = malloc(sizeof(int) * 2);
		tmp[0] = left, tmp[1] = right;
		(*returnColumnSizes)[*returnSize] = 2;
		ans[(*returnSize)++] = tmp;
	}
	return ans;
}