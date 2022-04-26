/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define SEG_COUNT 4
int segments[SEG_COUNT];
char** ans;
int ans_len;

void dfs(char* s, int segId, int segStart) {
	int len_s = strlen(s);
	// 找到了4段IP地址并且遍历完了字符串
	if (segId == SEG_COUNT) {
		if (segStart == len_s) {
			char* ipAddr = (char*)malloc(sizeof(char) * (len_s + 4));
			int add = 0;
			for (int i = 0; i < SEG_COUNT; ++i) {
				// 取出第i部分的地址
				int number = segments[i];
				// 将整数转化成字符串
				if (number >= 100) {
					ipAddr[add++] = number / 100 + '0';
				}
				if (number >= 10) {
					ipAddr[add++] = number % 100 / 10 + '0';
				}
				ipAddr[add++] = number % 10 + '0';
				if (i != SEG_COUNT - 1) {
					ipAddr[add++] = '.';
				}
			}
			ipAddr[add] = 0;
			ans = realloc(ans, sizeof(char*) * (ans_len + 1));
			ans[ans_len++] = ipAddr;
		}
		// 如果找到4段了，但是没有遍历完字符串，直接返回
		return;
	}
	// 字符串遍历完了，但是没有找到4段
	if (segStart == len_s) {
		return;
	}
	// 因为不能有前导0，所以如果当前数字为0，那么这一段IP地址只能为0
	if (s[segStart] == '0')  {
		segments[segId] = 0;
		dfs(s, segId + 1, segStart + 1);
	}
	// 一般情况，枚举每种情况并递归
	int addr = 0;
	for (int segEnd = segStart; segEnd < len_s; ++segEnd) {
		addr = addr * 10 + (s[segEnd] - '0');
		// 0xFF 即 255
		if (addr > 0 && addr <= 0xFF) {
			segments[segId] = addr;
			dfs(s, segId + 1, segEnd + 1);
		} else {
			break;
		}
	}
}
 
 
char** restoreIpAddresses(char* s, int* returnSize){
	ans = (char**) malloc(0);
	ans_len = 0;
	dfs(s, 0, 0);
	(*returnSize) = ans_len;
	return ans;
}