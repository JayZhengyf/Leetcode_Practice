int minPathSum(int** grid, int gridSize, int* gridColSize) {
	int rows = gridSize, columns = gridColSize[0];
	if (rows == 0 || columns == 0) {
		return 0;
	}
	// 使用滚动数组进行优化
	int dp[columns];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (i == 0) {  // 第一行特殊处理
				dp[j] = grid[i][j] + (j - 1 >= 0 ? dp[j - 1] : 0);
			} else { 
				dp[j] = grid[i][j] + (j - 1 >= 0 ? fmin(dp[j], dp[j - 1]) : dp[j]);
			}
		}
	}
	return dp[columns - 1];
}