// 本题要求：不使用额外的数组空间
// 方法一与26题一致，使用双指针
// 此处为方法二，双指针优化版本
// 方法二避免了需要保留的元素的重复赋值操作

// e.g. 序列[1,2,3,4,5]，删除 1
// 使用方法一则后面四个元素都需要前移
// 使用方法二则避免了这种情况
int removeElement(int* nums, int numsSize, int val) {
	int left = 0, right = numsSize;
	while (left <= right) {
		if (nums[left] == val) {
			nums[left] = nums[--right];
		} else {
			left++;
		}
	}
	
	return left;
}