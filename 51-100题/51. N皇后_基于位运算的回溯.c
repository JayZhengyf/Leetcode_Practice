int solutionsSize;

// 产生棋盘
char** generateBoard(int* queens, int n) {
	char** board = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++) {
		board[i] = (char*)malloc(sizeof(char) * (n + 1));
		for (int j = 0; j < n; j++) {
			board[i][j] = '.';
		}
		board[i][queens[i]] = 'Q', board[i][n] = 0;
	}
	return board;
}

// diagnoals1为主对角线，diagonals2为副对角线
// columns, diagnoals1, diagnoals2表示的二进制数
// 最低位对应最左列，最高位对应最右列
// 规定0代表可以放置皇后，1代表不可以放置皇后

void solve(char*** solutions, int* queens, int n, int row, int columns, int diagnoals1, int diagnoals2) {
	if (row == n) {
		char** board = generateBoard(queens, n);
		solutions[solutionsSize++] = board;
	} else {
		// columns | diagnoals1 | diagnoals2 表示所有不可以放置皇后的位置
		
		// (2ⁿ - 1) & (~(columns | diagnoals1 | diagnoals2))
		// 该结果值为1的位置表示可以放置皇后的位置
		// 这个'1'表示的可以和二进制中的'1'表示的禁止不冲突
		
		// x & (-x)可以获得x的二进制表示中的最低位的1的位置
		// x & (x - 1)可以将x的二进制表示中的最低位的1置成0
		// '|' 表示或运算，'~' 表示非运算，'&' 表示与运算
		
		int avaliablePositions = ((1 << n) - 1) & (~(columns | diagnoals1 | diagnoals2));
		
		while (avaliablePositions != 0) {
			// 获取avaliablePositions最低位的1的位置
			int position = avaliablePositions & (-avaliablePositions);
			// 将avaliablePositions最低位的1置成0
			avaliablePositions = avaliablePositions & (avaliablePositions - 1);
			// __builtin_ctz(x)：x末尾0的个数。x=0时结果未定义。
			int column = __builtin_ctz(position);
			queens[row] = column;
			// 对棋盘的操作与位移操作方向相反
			// columns | position 表示下一行不可以放置的列
			// (diagnoals1 | position) << 1 表示主对角线系在下一行禁止的位置
			// (diagnoals2 | position) >> 1 表示副对角线系在下一行禁止的位置
			solve(solutions, queens, n, row + 1, columns | position, (diagnoals1 | position) << 1, (diagnoals2 | position) >> 1);
			queens[row] = -1;
		}
	}
}

char** solveNQueens(int n, int* returnSize, int** returnColumnSize) {
	char*** solutions = malloc(sizeof(char**) * 501);
	solutionsSize = 0;
	int queens[n];
	memset(queens, -1, sizeof(queens));
	solve(solutions, queens, n, 0, 0, 0, 0);
	*returnSize = solutionsSize;
	*returnColumnSize = malloc(sizeof(int*) * solutionsSize);
	for (int i = 0; i < solutionsSize; i++) {
		(*returnColumnSize)[i] = n;
	}
	return solutions;
}