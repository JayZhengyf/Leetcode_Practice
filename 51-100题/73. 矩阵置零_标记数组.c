void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
	int m = matrixSize;  // 行数
	int n = matrixColSize[0];  // 列数
	int row[m], col[n];  // 标记第i行第i列是否含0
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			// matrix[i][j] == 0
			if (!matrix[i][j]) {
				row[i] = col[j] = true;
			}
		}
	}
	// 出现0的行列置零
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (row[i] || col[j]) {
				matrix[i][j] = 0;
			}
		}
	}
}