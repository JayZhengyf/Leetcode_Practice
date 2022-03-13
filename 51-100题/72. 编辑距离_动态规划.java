class Solution {
	public int minDistance(String word1, String word2) {
		int n = word1.length();
		int m = word2.length();
		
		// 有一个字符串为空
		if (n * m == 0) {
			return n + m;
		}
		
		// DP数组
		// D[i][j]表示word1的前i个字符和word2的前j个字符之间的编辑距离
		int[][] D = new int[n + 1][m + 1];
		
		// 边界状态初始化
		for (int i = 0; i < n + 1; ++i) {
			D[i][0] = i;
		}
		for (int j = 0; j < m + 1; ++j) {
			D[0][j] = j;
		}
		
		// 计算所有DP值
		for (int i = 1; i < n + 1; ++i) {
			for (int j = 1; j < m + 1; ++j) {
				// 在word1中插入一个字符(等价于在word2中删除一个字符)
				int left = D[i - 1][j] + 1;
				// 在word2中插入一个字符(等价于在word1中删除一个字符)
				int down = D[i][j - 1] + 1;
				// 在word1中修改一个字符(等价于在word2中修改一个字符)
				int left_down = D[i - 1][j - 1];
				if (word1.charAt(i - 1) != word2.charAt(j - 1)) {
					left_down += 1;
				}
				D[i][j] = Math.min(left, Math.min(down, left_down));
			}
		}
		return D[n][m];
	}
}