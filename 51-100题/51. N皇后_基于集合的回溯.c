/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// 记录有多少中排列方式
int solutionsSize;

// 根据给出的queens和n
// 生成一种棋盘
char** generateBoard(int* queens, int n) {
	char** board = (char**) malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++) {
		board[i] = (char*)malloc(sizeof(char) * (n + 1));
		for (int j = 0; j < n; j++) {
			board[i][j] = '.';
		}
		board[i][queens[i]] = 'Q', board[i][n] = 0;
	}
	return board;
}

// solutions表示所有棋盘的集合
// 设queens[i]的值为j，则有如此含义：在位于第i行时，第j列可以放置一个皇后
// columns用来记录一列是否已经有了皇后
// diagnoals1[i]用来记录从左上方到右下方的第i条对角线上是否已经有了皇后
// diagonals2[i]用来记录从右上方到左下方的第i条对角线上是否已经有了皇后
// 一个方向上的对角线有2n-1条

void backtrack(char*** solutions, int* queens, int n, int row, int* columns, int* diagnoals1, int* diagnoals2) {
	// 回溯退出条件
	// 产生棋盘并将其放入列表
	if (row == n) {
		char** board = generateBoard(queens, n);
		solutions[solutionsSize++] = board;
	} else {
		for (int i = 0; i < n; i++) {
			if (columns[i]) {
				continue;
			}
			// 从左上方到右下方一条对角线上的元素
			// 横坐标与纵坐标之差相同
			// 因为row - i会有负数产生
			// 因此加上n - 1使其能够放入数组
			// 整体来看，就是从右向左标识对角线
			int diagnoal1 = row - i + n - 1;
			if (diagnoals1[diagnoal1]) {
				continue;
			}
			// 从右上方到左下方一条对角线上的元素
			// 横坐标与纵坐标之和相同
			// 因此使用row + i来标识对角线
			// 整体来看，就是从左向右标识对角线
			int diagnoal2 = row + i;
			if (diagnoals2[diagnoal2]) {
				continue;
			}
			// 经过前面的筛选
			// 可知，该行该列以及主副对角线上都没有皇后
			// 因此，在当前位置放入皇后，并进行回溯
			queens[row] = i;
			columns[i] = true;
			diagnoals1[diagnoal1] = true;
			diagnoals2[diagnoal2] = true;
			backtrack(solutions, queens, n, row + 1, columns, diagnoals1, diagnoals2);
			// 回溯结束，将当前位置的标记重置
			queens[row]  = -1;
			columns[i] = false;
			diagnoals1[diagnoal1] = false;
			diagnoals2[diagnoal2]= false;
		}
	}
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
	char*** solutions = malloc(sizeof(char**) * 501);
	solutionsSize = 0;
	int queens[n];
	int columns[n];
	int diagnoals1[n + n];
	int diagnoals2[n + n];
	memset(queens, -1, sizeof(queens));
	memset(columns, 0, sizeof(columns));
	memset(diagnoals1, 0, sizeof(diagnoals1));
	memset(diagnoals2, 0, sizeof(diagnoals2));
	backtrack(solutions, queens, n, 0, columns, diagnoals1, diagnoals2);
	*returnSize = solutionsSize;
	*returnColumnSizes = malloc(sizeof(int*) * solutionsSize);
	for (int i = 0; i < solutionsSize; i++) {
		(*returnColumnSizes)[i] = n;
	}
	return solutions;
}