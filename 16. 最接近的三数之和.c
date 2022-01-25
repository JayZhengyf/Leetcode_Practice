int comp(const void *a, const void *b) { 
	// 将a,b强制类型转换为整型指针
	return *(int *) a - *(int *)b;
}
int threeSumClosest(int *nums, int numsSize, int target) {
	int n = numsSize;
	qsort(nums, n, sizeof(int), comp);
	int best = 1e7;	//best初始值为最大值
	// 根据差值的绝对值来更新答案
	
	// 枚举a
	for (int i = 0; i < n; i++) {
		
		// 保证和上一次枚举的元素不相等
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		
		// 使用双指针枚举b和c
		int j = i + 1, k = n - 1;
		while(j < k) {
			int sum = nums[i] + nums[j] + nums[k];
			if (sum == target) {
				return target;
			}
			if (abs(sum - target) < abs(best - target)) {
				best = sum;
			}
			if (sum > target) {
				// 如果sum大于target，移动c对应的指针
				int k0 = k - 1;
				// 移动到下一个不相等的元素
				while (j < k0 && nums[k0] == nums[k]) {
					k0--;
				}
				k = k0;
			} else {
				// 如果sum小于target，移动b对应的指针
				int j0 = j + 1;
				// 移动到下一个不相等的元素
				while (j0 < k && nums[j0] == nums[j]) {
					j0++;
				}
				j = j0;
			}
		}
	}
	return best;
}