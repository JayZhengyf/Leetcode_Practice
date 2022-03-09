int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int n = digitsSize;
	for (int i = n - 1; i >= 0; i--) {
		if (digits[i] != 9) {
			digits[i]++;
			for (int j = i + 1; j < n; j++) {
				digits[j] = 0;
			}
			*returnSize = digitsSize;
			return digits;
		}
	}
	// digits中所有元素都为9
	int* ans = malloc(sizeof(int) * (digitsSize + 1));
	memset(ans, 0, (digitsSize + 1) * sizeof(int));
	ans[0] = 1;
	*returnSize = digitsSize + 1;
	return ans;
	
}