int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
	int maxNum = n * n;
	int curNum = 1;
	int** matrix = malloc(sizeof(int*) * n);
	*returnSize = n;
	*returnColumnSizes = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		matrix[i] = malloc(sizeof(int) * n);
		memset(matrix[i], 0, sizeof(int) * n);
		(*returnColumnSizes)[i] = n;
	}
	
	int row = 0, column = 0;
	// 决定方向变换
	int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	int directionIndex = 0;
	while (curNum <= maxNum) {
		matrix[row][column] = curNum;
		curNum++;
		int nextRow = row + directions[directionIndex][0];
		int nextCol = column + directions[directionIndex][1];
		if (nextRow < 0 || nextRow >= n || nextCol < 0 
		|| nextCol >= n  || matrix[nextRow][nextCol] != 0) {
			directionIndex = (directionIndex + 1) % 4;
		}
		row = row + directions[directionIndex][0];
		column = column + directions[directionIndex][1];
	}
	return matrix;
}