class Solution {
	public boolean isValidSudoku(char[][] board) {
		// 每行、每列、每宫建立数组
		// row[0][2] 表示第一行数字2出现的次数
		// subboxes[1][2][3] 表示第二行第三列的九宫格中数字3出现的次数
		int[][] rows = new int [9][9];
		int[][] columns = new int[9][9];
		int[][][] subboxes = new int[3][3][9];
		
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				char c = board[i][j];
				if (c != '.') {
					int index = c - '0' - 1;
					rows[i][index]++;
					columns[j][index]++;
					subboxes[i / 3][j / 3][index]++;
					// 无论哪个部分存在数字大于1
					// 都不合法，返回false
					if (rows[i][index] > 1 || columns[j][index] > 1 
					|| subboxes[i / 3][j / 3][index] > 1) {
						return false;
					}
				}
			}
		}
		return true;
	}
}