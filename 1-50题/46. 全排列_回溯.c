/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int ansSize;
int* ansColumnSizes;
int outputsize;  // 当前排列的数字个数

// size为有多少个数
// first为当前填写到的位置
// output为当前的排列
// nums为给出的数组
// ans为存放全排列的列表
// uesd为标记数组，false为没有使用过，true为使用过

// 回溯
void backtrack(int numsSize, int first, int* output, int* nums, int** ans, bool* used) {
	// 回溯返回
	if (first == numsSize) {
		int* tmp = malloc(sizeof(int) * numsSize);
		memcpy(tmp, output, sizeof(int) * numsSize);
		ans[ansSize] = tmp;
		ansColumnSizes[ansSize++] = numsSize;
		return;
	}
	// 遍历、回溯
	for (int i = 0; i < numsSize; i++) {
		if (!used[i]) {
			output[outputsize++] = nums[i];
			used[i] = true;
			backtrack(numsSize, first + 1, output, nums, ans, used);
			outputsize--;
			used[i] = false;
		}
		
	}
}

// 全排列
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	bool used[6];
	for (int i = 0; i < 6; i++) {
		used[i] = false;
	}
	int* output = malloc(sizeof(int) * numsSize);
	int** ans = malloc(sizeof(int*) * 720);
	ansColumnSizes = malloc(sizeof(int) * numsSize);
	backtrack(numsSize, 0, output, nums, ans, used);
	*returnSize = ansSize;
	*returnColumnSizes = ansColumnSizes;

	return ans;
}
