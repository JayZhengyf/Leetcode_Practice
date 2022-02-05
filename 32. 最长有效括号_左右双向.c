// 对于“)))(((”这样的情况
// 无论是从左到右还是从右到左
// 都会使得 right > left 或 left > right 成立
// 进而使计数器置零
// 因此，这种情况可以判断

int longestValidParentheses(char* s) {
	int n = strlen(s);
	int left = 0, right = 0, maxlength = 0;
	// 从左到右
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			left++;
		} else {
			right++;
		}
		if (left == right) {
			maxlength = fmax(maxlength, 2 * right);
		} else if (right > left) {
			left = right = 0;
		}
	}
	left = right = 0;
	// 从右到左
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '(') {
			left++;
		} else {
			right++;
		}
		if (left == right) {
			maxlength = fmax(maxlength, 2 * left);
		} else if (left > right) {
			left = right = 0;
		}
	}
	return maxlength;
}