void swap(int* a, int* b) {
	int t = *a;
	*a = *b, *b = t;
}

void sortColors(int* nums, int numsSize) {
	int ptr = 0; 
	for (int i = 0; i < numsSize; ++i) {
		if (nums[i] == 0) {
			swap(&nums[i], & nums[ptr]);
			++ptr;
		}
	}
	for (int i = ptr; i < numsSize; ++i) {
		if (nums[i] == 1) {
			swap(&nums[i], &nums[ptr]);
			++ptr;
		}
	}
}