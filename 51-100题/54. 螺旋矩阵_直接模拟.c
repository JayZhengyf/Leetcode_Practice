// 决定接下来需要向什么方向走
int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// matrixSize为行数 matrixColSize为列数
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
	if (matrixSize == 0 || matrixColSize[0] == 0) {
		*returnSize = 0;
		return NULL;
	}
	
	int rows = matrixSize, columns = matrixColSize[0];
	// 记录相应位置上的元素是否被访问过
	int visited[rows][columns];
	memset(visited, 0, sizeof(visited));
	// total表示共有多少个元素
	int total = rows * columns;
	int* order = malloc(sizeof(int) * total);
	*returnSize = total;
	
	int row = 0, column = 0;
	int directionIndex = 0;
	for (int i = 0; i < total; i++) {
		order[i] = matrix[row][column];
		visited[row][column] = true;
		int nextRow = row + directions[directionIndex][0];
		int nextCol = column + directions[directionIndex][1];
		// 转换方向
		if (nextRow < 0 || nextRow >= rows ||
			nextCol < 0 || nextCol >= columns || 
			visited[nextRow][nextCol]) {
			directionIndex = (directionIndex + 1) % 4;
		}
		row += directions[directionIndex][0];
		column += directions[directionIndex][1];
	}
	return order;
}