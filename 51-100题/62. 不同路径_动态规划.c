int uniquePaths(int m, int n) {
	// f[m][n] 表示到(m, n)点的路径数
	int f[m][n];
	// 第一列全部置1
	for (int i = 0; i < m ; i++) {
		f[i][0] = 1;
	}
	// 第一行全部置1
	for (int j = 0; j < n; j++) {
		f[0][j] = 1;
	}
	// 动态规划
	// 每次只能向下或向右走一步
	// 因此，到(i, j)必然要经过(i - 1, j) 或 (i, j - 1)
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			f[i][j] = f[i - 1][j] + f[i][j - 1];
		}
	}
	
	return f[m - 1][n - 1];
}