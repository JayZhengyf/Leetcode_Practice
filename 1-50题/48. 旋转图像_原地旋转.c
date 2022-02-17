/*
一次循环
matrix[row][col]
matrix[col][n - row - 1]
matrix[n - row - 1][n - col - 1]
matrix[n - col - 1][row]
*/

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
	// 将图像分为四个部分
	for (int i = 0; i < matrixSize / 2; i++) {
		for (int j = 0; j < (matrixSize + 1) / 2; j++) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[matrixSize - j - 1][i];
			matrix[matrixSize - j - 1][i] = matrix[matrixSize - i - 1][matrixSize - j - 1];
			matrix[matrixSize - i - 1][matrixSize - j - 1] = matrix[j][matrixSize - i - 1];
			matrix[j][matrixSize - i - 1] = temp;
		}
	}
}