// 搜索target所在的行
int binarySearchFirstColumn(int** matrix, int matrixSize, int target) {
	// row初始化为-1，方便没找到target时返回
	int low = -1, high = matrixSize - 1;
	while (low < high) {
		int mid = (high - low + 1) / 2 + low;
		if (matrix[mid][0] <= target) {
			low = mid;
		} else {
			high = mid - 1;
		}
	}
	return low;
}

// 在target所在的行中搜索所在的列
bool binarySearchRow(int* row, int rowSize, int target) {
	int low = 0, high = rowSize - 1;
	while (low <= high) {
		int mid = (high - low) / 2 + low;
		if (row[mid] == target) {
			return true;
		} else if (row[mid] > target) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return false;
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
	int rowIndex = binarySearchFirstColumn(matrix, matrixSize,target);
	if (rowIndex < 0) {
		return false;
	} 
	return binarySearchRow(matrix[rowIndex], matrixColSize[rowIndex], target);
}