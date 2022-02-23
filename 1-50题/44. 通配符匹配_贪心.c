// 判断是否str全为 '*'
bool allStars(char* str, int left, int right) {
	for (int i = left; i < right; i++) {
		if (str[i] != '*') {
			return false;
		}
	}
	return true;
}

// 判断两个字符是否匹配
bool charMatch(char u, char v) {
	return u == v || v == '?';
}

// 假设模式p的理想形式为：* u_1 * u_2 * ... * u_n *
bool isMatch(char* s, char* p) {
	int len_s = strlen(s), len_p = strlen(p);
	// 如果p的结尾字符不是 '*'
	while (len_s && len_p && p[len_p - 1] != '*') {
		if (charMatch(s[len_s - 1], p[len_p - 1])) {
			len_s--;
			len_p--;
		} else {
			return false;
		}
	}
	// dp[i][j]，表示s的前i个字符与p的前j个字符是否匹配
	// dp[0][0]，返回true
	// dp[i][0]，返回false
	if (len_p == 0) {
		return len_s == 0;
	}
	// sIndex和pIndex表示当前遍历到s和p的位置
	// 此时我们正在 s 中寻找某个 u_i
	// sRecord和pRecord表示u_i在s和p中的起始位置
	int sIndex = 0, pIndex = 0;
	// 初始化为-1，将模式p的首字符不为'*'的情况考虑在内
	int sRecord = -1, pRecord = -1;
	while (sIndex < len_s && pIndex < len_p) {
		// 如果遇到'*'，说明找到了u_i，开始寻找u_i+1
		if (p[pIndex] == '*') {
			pIndex++;
			sRecord = sIndex;
			pRecord = pIndex;
		} 
		// 如果两个字符可以匹配，继续寻找u_i的下一个字符
		else if (charMatch(s[sIndex], p[pIndex])) {
			sIndex++;
			pIndex++;
		} 
		// 如果两个字符不匹配，就需要重新寻找u_i
		// 枚举下一个s中的起始位置
		// 如果sRecord == -1，说明没有重新进行匹配的机会 
		else if (sRecord != -1 && sRecord + 1 < len_s) {
			sRecord++;
			sIndex = sRecord;
			pIndex = pRecord;
		} 
		// 如果不匹配并且下一个起始位置不存在
		// 那么匹配失败
		else {
			return false;
		}
	}
	return allStars(p, pIndex, len_p);
}
