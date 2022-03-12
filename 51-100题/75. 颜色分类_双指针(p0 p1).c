// 双指针 p0来交换0，p1来交换1
void swap(int* a, int* b) {
	int t = *a;
	*a = *b, *b = t;
}

void sortColors(int* nums, int numsSize) {
	int p0 = 0, p1 = 0;
	for (int i = 0; i < numsSize; ++i) {
		if (nums[i] == 1) {
			swap(&nums[i], &nums[p1]);
			++p1;
		} else if (nums[i] == 0) {
			swap(&nums[i], &nums[p0]);
			// 如果p0小于p1
			// 那么需要将上一步交换出去的1，给交换回来
			if (p0 < p1) {
				swap(&nums[i], &nums[p1]);
			}
			++p0, ++p1;
		}
	}
}