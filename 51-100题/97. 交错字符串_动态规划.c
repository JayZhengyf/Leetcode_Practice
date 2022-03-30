/* 
	本题用不了双指针法
	e.g. s1 = aabcc, s2 = dbbca, s3 = aadbbcbcac
	用双指针得出false，实际上应该是true	
 */

bool isInterleave(char * s1, char * s2, char * s3){
	int n = strlen(s1), m = strlen(s2), t  = strlen(s3);
	
	// f(i, j)表示s1的前i个元素和s2的前j个元素能否交错组成s3的前i+j个元素
	int f[n + 1][m + 1];
	memset(f, 0, sizeof(f));
	
	if (n + m != t) {
		return false;
	}
	
	f[0][0] = true;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			int p = i + j - 1;
			// 用或操作的原因：
			// 假设s1的判断为true，s2的判断为false
			// 如果不加或操作，那么，经过s1的判断之后f为true，但是经过s2会让f变为false
			// 最终导致f的值错误
			if (i > 0) {
				// f[i - 1][j]为true
				// 并且，s1的第i个元素和s3的第i+j个元素相等
				// 那么f[i][j]为true
				f[i][j] |= (f[i - 1][j] && s1[i - 1] == s3[p]);
			}
			if (j > 0) {
				// f[i][j - 1]为true
				// 并且，s2的第j个元素和s3的第i+j个元素相等
				// 那么f[i][j]为true
				f[i][j] |= (f[i][j - 1] && s2[j - 1] == s3[p]);
			}
		}
	}
	return f[n][m];
}