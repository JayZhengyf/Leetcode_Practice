int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

// 检查以board[i][j]开始，是否能找到和s[k...]匹配的字符串
// s[k...]的含义：字符串从第k个字符开始到结尾的子串
// visited用来记录一个位置是否被访问过，防止下一步走到上一步的位置
bool check(char** board, int boardSize, int boardColSize, int** visited, int i, int j, char* s, int sSize, int k) {
	if (board[i][j] != s[k]) {
		return false;
	} else if (k == sSize - 1) {
		return true;
	}
	visited[i][j] = true;
	bool result = false;
	// 一个格子有四个方向可以走
	for (int sel = 0; sel < 4; ++sel) {
		// 决定下一步走的方向
		int newi = i + directions[sel][0];
		int newj = j + directions[sel][1];
		if (newi >= 0 && newi < boardSize && newj >= 0 && newj < boardColSize) {
			if (!visited[newi][newj]) {
				bool flag = check(board, boardSize, boardColSize, visited, newi, newj, s, sSize, k + 1);
				if (flag) {
					result = true;
					break;
				}
			}
		}
	}
	visited[i][j] = false;
	return result;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
	int** visited = malloc(sizeof(int*) * boardSize);
	for (int i = 0; i < boardSize; ++i) {
		visited[i] = malloc(sizeof(int) * boardColSize[0]);
		memset(visited[i], 0, sizeof(int) * boardColSize[0]);
	}
	int wordSize = strlen(word);
	// 遍历每一个格子
	for (int i = 0; i < boardSize; ++i) {
		for (int j = 0; j < boardSize; ++j) {
			bool flag = check(board, boardSize, boardColSize[0], visited, i, j, word, wordSize, 0);
			if (flag) {
				return true;
			}
		}
	}
	return false;
}