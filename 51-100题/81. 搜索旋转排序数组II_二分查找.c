// 本题与33题的区别在于：有重复元素
bool search(int* nums, int numsSize, int target) {
	if (numsSize == 0) {
		return false;
	}
	if (numsSize == 1) {
		return nums[0] == target;
	}
	int left = 0, right = numsSize - 1;
	while (left <= right) {
		int mid = (left + right) >> 1;
		if (nums[mid] == target) {
			return true;
		}
		// 因为数组中有重复元素，二分查找可能会有a[left]=a[mid]=a[right]的情况
		// 此时无法判断哪个区间是有序的
		// 这种情况下，左边界加一，有边界减一，在新的区间上继续二分查找
		if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
			++left;
			--right;
		} else if (nums[left] <= nums[mid]) {  // [left, mid]区间有序
			if (nums[left] <= target && target < nums[mid]) {
				// target 在[left, mid]区间中
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		} else {  // [mid, numsSize-1]区间有序
			if (nums[mid] < target && target <= nums[numsSize - 1]) {
				// target在[mid, numsSize-1]区间中
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
	}
	return false;
}