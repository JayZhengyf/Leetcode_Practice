char phoneMap[11][5] = {
	"\0", "\0", "abc\0","def\0", "ghi\0", "jkl\0", "mno\0", "pqrs\0", "tuv\0", "wxyz\0"
};

// 数字的一维数组
char *digits_tmp;
// 数组中元素个数
int digits_size;

// 二维数组
// combinations中嵌套combination
char **combinations;
int combinations_size;

// 一维数组
char *combination;
int combination_size;

// 回溯法
void backtrack(int index) {
	// 控制退出
	if (index == digits_size) {
		char* tmp = malloc(sizeof(char) * (combination_size + 1));
		// 从存储区combination复制sizeof...个字符到tmp
		memcpy(tmp, combination, sizeof(char) * (combination_size + 1));
		combinations[combinations_size++] = tmp;
	} else {
		char digit = digits_tmp[index];
		// 从phoneMap中取出数字对应的字符串
		// 取出的是一个一维数组
		// 因此combination初始化时，需要写成如下形式
		// combination = malloc(sizeof(char*) * digits_size)
		char *letters = phoneMap[digit - '0'];
		int len = strlen(letters);
		
		for (int i = 0; i < len; i++) {
			combination[combination_size++] = letters[i];
			combination[combination_size] = 0;
			backtrack(index + 1);
			combination[combination_size--] = 0;
		}
	}
}

char** letterCombinations(char* digits, int* returnSize) {
	combination_size = combinations_size = 0;
	digits_tmp = digits;
	digits_size = strlen(digits);
	if (digits_size == 0) {
		*returnSize = 0;
		return combinations;
	}
	int num = 1;
	// 计算所有可能的情况
	// 一位数字最多有四种情况
	// 4 * digits_size即，最大可能情况
	for (int i = 0; i < digits_size; i++) num *= 4;
	// 初始化二维数组的空间
	combinations = malloc(sizeof(char*) * num);
	// 初始化一维数组的空间
	combination = malloc(sizeof(char*) * digits_size);
	// 开始回溯
	backtrack(0);
	*returnSize = combinations_size;
	return combinations;
}