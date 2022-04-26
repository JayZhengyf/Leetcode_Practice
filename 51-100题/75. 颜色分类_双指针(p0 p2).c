void swap(int* a, int* b) {
	int t = *a;
	*a = *b, *b = t;
}

void sortColors(int* nums, int numsSize) {
	int p0 = 0, p2 = numsSize - 1;
	for (int i = 0; i < numsSize; ++i) {
		while(i <= p2 && nums[i] == 2) {
			swap(&nums[i], &nums[p2]);
			--p2;
		}
		if (nums[i] == 0) {
			swap(&nums[i], &nums[p0]);
			++p0;
		}
	}
}