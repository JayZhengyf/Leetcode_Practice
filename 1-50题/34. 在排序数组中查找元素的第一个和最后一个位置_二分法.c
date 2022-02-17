int binarySearch(int* nums, int numsSize, int target, bool lower) {
	int left = 0, right = numsSize - 1, ans = numsSize;
	while (left <= right) {
		int mid = (left + right) >> 1;
		// lower为true，查找第一个大于等于target的下标
		// lower为false，查找第一个大于target的下标
		// 第一个大于target的下标减一，即最后一个target的位置
		if (nums[mid] > target || (lower && nums[mid] >= target)) {
			right = mid - 1;
			ans = mid;
		} else {
			left = mid + 1;
		}
	}
	return ans;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
	int leftIdx = binarySearch(nums, numsSize, target, true);
	int rightIdx = binarySearch(nums, numsSize, target, false) - 1;
	int* ret = malloc(sizeof(int) * 2);
	*returnSize = 2;
	// 检查leftIdx和rightIdx是否合规
	if (leftIdx <= rightIdx && rightIdx < numsSize 
	&& nums[leftIdx] == target && nums[rightIdx] == target) {
		ret[0] = leftIdx, ret[1] = rightIdx;
		return ret;
	}
	ret[0] = -1, ret[1] = -1;
	return ret;
}