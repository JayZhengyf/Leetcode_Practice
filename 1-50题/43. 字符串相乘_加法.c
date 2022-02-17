// 字符串相加
char* addStrings(char* num1, char* num2) {
	// add时进位数
	int i = strlen(num1) - 1, j = strlen(num2) - 1, add = 0;
	char* ans = malloc(sizeof(char) * (i + j + 5));
	int ansLen = 0;
	while (i >= 0 || j >= 0 || add != 0) {
		int x = i >= 0 ? num1[i] - '0' : 0;
		int y = j >= 0 ? num2[j] - '0' : 0;
		int result = x + y + add;
		ans[ansLen++] = result % 10;
		add = result / 10;
		i--;
		j--;		
	}
	// 上一步字符串相加出的数组是反向的
	// 需要反转过来
	// e.g.:"123" + "12" 在数组中为"531"
	for (int i = 0; i < ansLen / 2; i++) {
		char t = ans[i];
		ans[i] = ans[ansLen - 1 - i];
		ans[ansLen - 1 - i] = t;
	}
	// 将所有数字变成字符
	for (int i = 0; i < ansLen; i++) {
		ans[i] += '0';
	}
	ans[ansLen++] = 0;
	return ans;
}

// 字符串相乘
char* multiply(char* num1, char* num2) {
	int m = strlen(num1), n = strlen(num2);
	char* ans = malloc(sizeof(char) * 2);
	ans[0] = '0', ans[1] = 0;
	if ((m == 1 && num1[0] == '0') || (n == 1 && num2[0] == '0')) {
		return ans;
	}
	for (int i = n - 1; i >= 0; i--) {
		char* curr = malloc(sizeof(char) * (n + m + 5));
		int currLen = 0;
		int add = 0;
		// 进行补0操作
		for (int j = n - 1; j > i; j--) {
			curr[currLen++] = 0;
		}
		// 字符转化为数字
		int y = num2[i] - '0';
		// 进行乘法运算
		for (int j = m - 1; j >= 0; j--) {
			int x = num1[j] - '0';
			int product = x * y + add;
			curr[currLen++] = product % 10;
			add = product / 10;
		}
		// 进位
		while (add != 0) {
			curr[currLen++] = add % 10;
			add /= 10;
		}
		// 将数组进行反转
		for (int i = 0; i < currLen / 2; i++) {
			char t = curr[i];
			curr[i] = curr[currLen - 1 - i];
			curr[currLen - 1 - i] = t;
		}
		// 将数字转化为字符
		for (int i = 0; i < currLen; i++) {
			curr[i] += '0';
		}
		// 数组转化为字符串
		curr[currLen++] = 0;
		// 字符串相加
		char* tmp = addStrings(ans, curr);
		free(ans), free(curr);
		ans = tmp;
	}
	return ans;
}