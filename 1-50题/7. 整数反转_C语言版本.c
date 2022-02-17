// 此题为leetcode第七题，数学推导见网页
// (https://leetcode-cn.com/problems/reverse-integer/solution/zheng-shu-fan-zhuan-by-leetcode-solution-bccn/)
// C语言版本
int reverse(int x) {
	int rev = 0;
	while (x != 0) {
		if (rev < INT_MIN / 10 || rev > INT_MAX / 10) {
			return 0;
		}
		int digit = x % 10;
		x /= 10;
		rev = rev * 10 + digit;
	}
	return rev;
}

