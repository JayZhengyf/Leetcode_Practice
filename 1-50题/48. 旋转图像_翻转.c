void swap(int* a, int* b) {
	int t = *a;
	*a = *b, *b = t;
}

// 先水平翻转后主对角线翻转
// 效果等价于九十度旋转

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
	// 水平翻转
	for (int i = 0; i < matrixSize / 2; i++) {
		for (int j = 0; j < matrixSize; j++) {
			swap(&matrix[i][j], &matrix[matrixSize - i - 1][j]);
		}
	}
	// 主对角线翻转
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < i; j++) {
			swap(&matrix[i][j], &matrix[j][i]);
		}
	}
}