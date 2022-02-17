// 因为要在target不存于nums中时返回应该插入的位置
// 因此二分查找的判断条件需要调整
// nums[pos - 1] < target <= nums[pos]
// pos为我们返回的位置

// ans初始化为numsSize
// 因为target可能大于nums中的所有数

int searchInsert(int* nums, int numsSize, int target) {
	int left = 0, right = numsSize - 1, ans = numsSize;
	while (left <= right) {
		int mid = ((right - left) / 2) + left;
		if (target <= nums[mid]) {
			ans = mid;
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	
	return ans;
}