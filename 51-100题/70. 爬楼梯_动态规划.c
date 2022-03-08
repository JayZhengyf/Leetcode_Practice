int climbStairs(int n) {
	// f(x)的值表示到第x阶需要多少步
	// f(x) = f(x - 1) + f(x - 2)
	// 使用滚动数组
	int x = 0, y = 0, z = 1;
	// 进行动态规划
	for (int i = 1; i <= n; i++) {
		x = y;
		y = z;
		z = x + y;
	}
	return z;
}
