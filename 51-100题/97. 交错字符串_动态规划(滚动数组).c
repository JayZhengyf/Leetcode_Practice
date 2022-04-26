bool isInterleave(char* s1, char* s2, char* s3) {
	int n = strlen(s1), m = strlen(s2), t = strlen(s3);
	
	int f[m + 1];
	memset(f, 0, sizeof(f));
	
	if (n + m != t) {
		return false;
	}
	
	f[0] = true;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			int p = i + j - 1;
			if (i > 0) {
				f[j] &= (s1[i - 1] == s3[p]);
			}
			if (j > 0) {
				f[j] |= (f[j - 1] && s2[j - 1] == s3[p]);
			}
		}
	}
	return f[m];	
}