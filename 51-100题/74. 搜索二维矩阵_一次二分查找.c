bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
	int m = matrixSize, n = matrixColSize[0];
	int low = 0, high = m * n - 1;
	while (low <= high) {
		int mid = (high - low) / 2 + low;
		// 将二维数组映射到一维数组上
		int x = matrix[mid / n][mid % n];
		if (x < target) {
			low = mid + 1;
		} else if (x > target) {
			high = mid - 1;
		} else {
			return true;
		}
	}
	return false;
	
}