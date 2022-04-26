/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	// 长度为n的集合，有2^n个子集
	int** ans = malloc(sizeof(int*) * (1 << numsSize));
	*returnColumnSizes = malloc(sizeof(int) * (1 << numsSize));
	*returnSize = 1 << numsSize;
	int t[numsSize];
	// 枚举mask ∈ [0, 2^n - 1]
	// mask的一个二进制表示一个0/1序列
	// 按照0/1序列从原集合中取值
	for (int mask = 0; mask < (1 << numsSize); ++mask) {
		int tSize = 0;
		for (int i = 0; i < numsSize; ++i) {
			// 如果有哪一位是1就表示取原集合对应位置的数字
			// 使用mask & (1 << i)来查看mask的哪一位为1
			if (mask & (1 << i)) {
				t[tSize++] = nums[i];
			}
		}
		int* tmp = malloc(sizeof(int) * tSize);
		memcpy(tmp, t, sizeof(int) * tSize);
		(*returnColumnSizes)[mask] = tSize;
		ans[mask] = tmp;
	}
	return ans;
}