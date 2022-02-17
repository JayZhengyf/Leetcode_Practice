// 交换两个值
void swap(int* a, int* b) {
	int t = *a;
	*a = *b, *b = t;
}
// 反转降序的数组
void reverse(int* nums, int left, int right) {
	while (left < right) {
		swap(nums + left, nums + right);
		left++, right--;
	}
}

void nextPermutation(int* nums, int numsSize) {
	int i = numsSize - 2;
	// 寻找顺序对(i, i + 1)
	// 满足a[i] < a[i + 1]
	while (i >= 0 && nums[i] >= nums[i + 1]) {
		i--;
	}
	if (i >= 0) {
		int j = numsSize - 1;
		// 在区间[i + 1, n)寻找第一个元素j
		// 满足a[i] < a[j]
		while (j >= i + 1 && nums[i] >= nums[j]) {
			j--;
		}
		swap(nums + i, nums + j);
	}
	reverse(nums, i + 1, numsSize - 1);
}