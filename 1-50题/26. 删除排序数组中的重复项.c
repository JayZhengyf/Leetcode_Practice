// 本题关键是“原地”，即不使用额外的数组空间

int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 0) {
		return 0;
	}
	
	// 使用双指针法
	int fast = 1, slow = 1;
	while (fast < numsSize) {
		if (nums[fast] != nums[fast - 1]) {
			nums[slow++] = nums[fast];
		}
		fast++;
	}
	
	return slow;
}