char ** split(const char * s, char delim, int* returnSize) {
	int n = strlen(s);
	char** ans = (char**)malloc(sizeof(char*) * n);
	int pos = 0;
	int curr = 0;
	int len = 0;
	
	while (pos < n) {
		// 找到分隔符
		while (pos < n && s[pos] == delim) {
			pos++;
		}
		// 记录分隔符
		curr = pos;
		// 记录找到的字符串的位置
		while (pos < n && s[pos] != delim) {
			pos++;
		}
		if (curr < n) {
			ans[len] = (char*)malloc(sizeof(char) * (pos - curr + 1));
			strncpy(ans[len], s + curr, pos - curr);
			ans[len][pos - curr] = 0;  // 字符串截至符
			len++;
		}
	}
	*returnSize = len;
	return ans;
	
}

char* simplifyPath(char* path) {
	// 记录分割出了多少个字符串
	int namesSize = 0;
	int n = strlen(path);
	// 按照'/'分割路径
	char** names = split(path, '/', &namesSize);
	char** stack = (char**)malloc(sizeof(char*) * namesSize);
	int stackSize = 0;
	
	for (int i = 0; i < namesSize; i++) {
		if (!strcmp(names[i], "..")) {
			// names[i]等于".."，返回上层目录
			if (stackSize > 0) {
				stackSize--;
			}
		} else if (strcmp(names[i], ".")) {
			// names[i]不等于"."，记录下层目录
			// "."表示当前目录，不做处理
			stack[stackSize] = names[i];
			stackSize++;
		}
	}
	
	char* ans = (char*)malloc(sizeof(char) * (n + 1));
	int curr = 0;
	if (stackSize == 0) {
		ans[curr] = '/';
		curr++;
	} else {
		for (int i = 0; i < stackSize; i++) {
			ans[curr] = '/';
			curr++;
			strcpy(ans + curr, stack[i]);
			curr += strlen(stack[i]);
		}
	}
	ans[curr] = 0;
	for (int i = 0; i < namesSize; i++) {
		free(names[i]);
	}
	free(names);
	free(stack);
	return ans;
}
