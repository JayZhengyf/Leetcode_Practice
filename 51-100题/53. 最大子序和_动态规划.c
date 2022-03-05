int maxSubArray(int* nums, int numsSize) {
	// f[i]表示以第i个元素结尾的连续子数组的最大和
	// 使用pre来维护f[i - 1]
	// f[i - 1] + nums[i]与nums[i]的比值大小
	// 决定了nums[i]是单独成段，还是并入f[i - 1]
	// 动态规划方程：f(i) = max{f(i - 1) + nums[i], nums[i]}
	int pre = 0, maxAns = nums[0];
	for (int i = 0; i < numsSize; i++) {
		pre = fmax(pre + nums[i], nums[i]);
		maxAns = fmax(maxAns, pre);
	}
	return maxAns;
}