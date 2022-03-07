void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
	int m = matrixSize;
	int n = matrixColSize[0];
	int flag_col0 = false;
	for (int i = 0; i < m; i++) {
		if (!matrix[i][0]) {
			flag_col0 = true;
		}
		for (int j = 1; j < n; j++) {
			if (!matrix[i][j]) {
				matrix[i][0] = matrix[0][j] = 0;
			}
		}
	}
	// 为了防止每一列的第一个元素提前更新
	// 需要从最后一行开始处理矩阵
	// 例如下面这种情况，如果从第一行开始处理
	// 就会影响第二、三列
	/*
	[0,1,2,0],			[0,0,0,0],
	[3,4,5,6],	---->	[3,4,5,6],
	[1,2,3,4]			[1,2,3,4]
	*/
	for (int i = m - 1; i >= 0; i--) {
		for (int j = 1; j < n; j++) {
			if (!matrix[i][0] || !matrix[0][j]) {
				matrix[i][j] = 0;
			}
		}
		if (flag_col0) {
			matrix[i][0] = 0;
		}
	}
}