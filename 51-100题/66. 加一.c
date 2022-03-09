int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int n = digitsSize - 1;
	// 反向遍历数组，让n指向第一个不是9的位置
	while (n >= 0 && digits[n] == 9) {
		n--;
	}
	// 不全是9或者没有9的情况
	if (n >= 0) {
		digits[n] += 1;
		for (int i = n + 1; i < digitsSize; i++) {
			digits[i] = 0;
		}
	}
	else {  // digits全是9
	 // 加1之后进位，需要新的数组
		int* digits_1 = malloc(sizeof(int) * (digitsSize + 1));
		memset(digits_1, 0, (digitsSize+1) * sizeof(int));
		digits_1[0] = 1;
		*returnSize = digitsSize + 1;
		return digits_1;
	}
	*returnSize = digitsSize;	
	return digits;
}