int maxSubArray(int* nums, int numsSize) {
	int* f = (int*)malloc(sizeof(int) * numsSize);
	f[0] = nums[0];
	int maxAns = nums[0];
	for (int i = 1; i < numsSize; i++) {
		if (f[i - 1] + nums[i] > nums[i]) {
			f[i] = f[i - 1] + nums[i];
			if (f[i - 1] + nums[i] > maxAns) {
				maxAns = f[i - 1] + nums[i];
			}
		} else {
			f[i] = nums[i];
			if (nums[i] > maxAns) {
				maxAns = nums[i];
			};
		}
	}
	return maxAns;
}