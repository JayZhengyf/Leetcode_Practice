int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
	// n为行数，m为列数
	int n = obstacleGridSize, m = obstacleGridColSize[0];
	// 计算f(i, j)只需要f(i - 1, j)和f(i, j - 1)两个数据
	// 因此使用滚动数组，来达到节省空间的目的
	int f[m];
	memset(f, 0, sizeof(f));
	// 需要考虑(0, 0)就是障碍物的情况
	f[0] = (obstacleGrid[0][0] == 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 遇到障碍物，则认为无路可达
			if (obstacleGrid[i][j] == 1) {
				f[j] = 0;
				continue;
			}
			if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
				f[j] += f[j - 1];
			}
		}
	}
	return f[m - 1];
}