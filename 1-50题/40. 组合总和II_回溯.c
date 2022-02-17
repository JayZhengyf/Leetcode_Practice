/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// 本题与39题的区别在于：candidates中的元素在每个组合中只能出现一次
// ans:[[sequence1], [sequence2], ...]
int** ans;  // 最终返回的列表
int* ansColumnSizes;  // 每个组合的长度构成的数组
int ansSize;  // ans的长度

int* sequence; // 一种组合
int sequenceSize; // 一种组合的长度

// freq[pos][0]表示第pos个数的值
// freq[pos][1]表示第pos个数在candidates中的出现次数
int** freq;  
int freqSize;  // candidates中不重复数的个数

void dfs(int pos, int rest) {
	if (rest == 0) {
		int* tmp = malloc(sizeof(int) * sequenceSize);
		memcpy(tmp, sequence, sizeof(int) * sequenceSize);
		ans[ansSize] = tmp;
		ansColumnSizes[ansSize++] = sequenceSize;
		return;
	}
	if (pos == freqSize || rest < freq[pos][0]) {
		return;
	}
	// 直接跳过
	dfs(pos + 1, rest);
	
	// 选择当前数
	// 当前第pos个数在sequence中最多出现most次
	int most = fmin(rest / freq[pos][0], freq[pos][1]);
	for (int i = 1; i <= most; i++) {
		sequence[sequenceSize++] = freq[pos][0];
		dfs(pos + 1, rest - i * freq[pos][0]);
	}
	// sequenceSize需要与sequence的实际情况保持一致
	sequenceSize -= most;
}

int comp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
	ans = malloc(sizeof(int*) * 2001);
	ansColumnSizes = malloc(sizeof(int) * 2001);
	sequence = malloc(sizeof(int) * 2001);
	freq = malloc(sizeof(int*) * 2001);
	ansSize = sequenceSize = freqSize = 0;
	
	// 剪枝
	// 递归时会先选择小的数，再选大的数
	// 当我们递归到dfs(pos,rest)时
	// 如果freq[pos][0]已经大于rest
	// 那么后面还没有递归到的数也都大于rest
	// 这就说明不可能再选择若干个和为rest的数放入列表了
	// 此时就可以直接回溯了
	qsort(candidates, candidatesSize, sizeof(int), comp);
	for (int i = 0; i < candidatesSize; i++) {
		if (freqSize == 0 || candidates[i] != freq[freqSize - 1][0]) {
			freq[freqSize] = malloc(sizeof(int) * 2);
			freq[freqSize][0] = candidates[i];
			freq[freqSize++][1] = 1;
		} else {
			++freq[freqSize - 1][1];
		}
	}
	
	dfs(0, target);
	*returnSize = ansSize;
	*returnColumnSizes = ansColumnSizes;
	return ans;
}