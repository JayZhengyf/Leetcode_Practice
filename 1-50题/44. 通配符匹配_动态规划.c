bool isMatch(char* s, char* p) {
	int m = strlen(s);
	int n = strlen(p);
	// dp[i][j] 表示s的前i个字符和p的前j个字符是否匹配
	int dp[m + 1][n + 1];
	// 初始全部置为false
	memset(dp, 0, sizeof(dp));
	
	// 边界状况的处理
	dp[0][0] = true;
	// dp[i][0] 一定为false，无需处理
	// dp[0][j]只有p的前j个字符全是'*'时，才为true
	for (int j = 1; j <= n; j++) {
		// 第j个字符为 '*'
		if (p[j - 1] == '*') {
			dp[0][j] = true;
		} else {
			break;
		}
	}
	
	// 开始处理一般状况
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			// p的第j个字符为 '*'
			if (p[j - 1] == '*') {
				// '*' 匹配零个字符 or 匹配任意个字符
				// '*' 匹配任意个字符时，s[i - 1] == p[j - 1]
				// 因此dp[i][j] 的状态决定于dp[i - 1][j];
				dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
			} else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
		}
	}
	
	return dp[m][n];
}