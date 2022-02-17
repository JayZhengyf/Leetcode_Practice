class Solution {
	public int search(int[] nums, int target) {
		int n = nums.length;
		if (n == 0) {
			return -1;
		}
		if (n == 1) {
			return nums[0] == target ? 0 : -1;
		}
		int left = 0, right = n - 1;
		while (left <= right) {
			int mid = (left + right) >> 1;
			if (nums[mid] == target) {
				return mid;
			}
			// [0, mid)为升序
			if (mid[0] <= nums[mid]) {
				// target在[0, mid)中
				if (nums[0] <= target && target < nums[mid]) {
					right = mid - 1;
				} else {
					left = mid + 1;
				}
			// (mid, n - 1]为升序
			} else {
				// target在(mid, n - 1]中
				if (nums[mid] < target && target <= nums[n - 1]) {
					left = mid + 1;
				} else {
					right = mid - 1;
				}
			}
		}
		return -1;
	}
}