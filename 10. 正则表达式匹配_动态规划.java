class Solution {
	public boolean isMatch(String s, String p) {
		int m = s.length();
		int n = p.length();
		
		// f[i][j] 表示s的前i个字符与p的前j个字符是否能够匹配
		boolean[][] f = new boolean[m + 1][n + 1];
		f[0][0] = true;
		
		// i和j分别表示当前s和p的长度
		// 因此使用i和j表示坐标时，需要减一
		for (int i = 0; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (p.charAt(j - 1) == '*') { // 即p的第j个字符 == '*'
					// 先把f[i][j - 2]的boolean值赋给f[i][j]
					// 即使if(...)语句不成立
					// f[i][j]也有一个boolean值
					
					// 假设'*'匹配零次or'*'的前一个字符不匹配
					f[i][j] = f[i][j - 2];
					// 当s的第i个字符和p的第j - 1个字符匹配
					if (matches(s, p, i, j - 1)) {
						// '*'匹配零次时
						// f[i][j] = f[i][j - 2]
						// '*'匹配多次时
						// f[i][j] = f[i - 1][j]
						f[i][j] = f[i][j] || f[i - 1][j];
					}
				} else { // 即p的第j个字符 != '*'
					// 如果s的第i个字符和p的第j个字符匹配
					// 那么f[i][j] = f[i - 1][j - 1]
					if (matches(s, p, i, j)) {
						f[i][j] = f[i - 1][j - 1];
					}
				}
			}
		}
		return f[m][n];
	}
	
	// 判断s的第i个字符和p的第j个字符是否匹配
	public boolean matches(String s, String p, int i, int j) {
		if (i == 0) {
			return false;
		}
		if (p.charAt(j - 1) == '.') {
			return true;
		}
		
		return s.charAt(i - 1) == p.charAt(j - 1);
	}
}