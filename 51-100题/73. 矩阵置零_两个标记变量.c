void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
	int m = matrixSize;
	int n = matrixColSize[0];
	int flag_col0 = false, flag_row0 = false;
	// 调整第一列的标记变量
	for (int i = 0; i < m; i++) {
		if (!matrix[i][0]) {
			flag_col0 = true;
		}
	}
	// 调整第一行的标记变量
	for (int j = 0; j < n; j++) {
		if (!matrix[0][j]) {
			flag_row0 = true;
		}
	}
	// 遍历矩阵，记录0出现的行与列
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (!matrix[i][j]) {
				matrix[i][0] = matrix[0][j] = 0;
			}
		}
	}
	// 开始置零
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (!matrix[i][0] || !matrix[0][j]) {
				matrix[i][j] = 0;
			}
		}
	}
	if (flag_col0) {
		for (int i = 0; i < m; i++) {
			matrix[i][0] = 0;
		}
	}
	if (flag_row0) {
		for (int j = 0; j < n; j++) {
			matrix[0][j] = 0;
		}
	}
}