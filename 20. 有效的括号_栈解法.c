char pairs(char a) {
	if (a == '}') return '{';
	if (a == ']') return '[';
	if (a == ')') return '(';
	
	return 0;
}

bool isValid(char* s) {
	int n = strlen(s);
	// 字符串一定是偶数
	// 如果是奇数，则返回false，退出
	if (n % 2 == 1) {
		return false;
	}
	// 初始化一个栈
	int stk[n + 1], top = 0;
	
	for (int i = 0; i < n; i++) {
		char ch = pairs(s[i]);
		// 如果是'}', ']', ')'之一，则检查有无对应的'{', '[', '('
		if (ch) {
			if (top == 0 || stk[top - 1] != ch) {
				return false;
			}
			top--;
		// 不是'}', ']', ')'之一，则入栈
		} else {
			stk[top++] = s[i];
		}
	}
	// 如果匹配完所有的右括号，栈中还存在左括号
	// 证明该字符串不合法
	// 因此，最终需要用top == 0来进行一次判断
	return top == 0;
}