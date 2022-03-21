/* 	
n = 0 n = 1  n = 2   n = 3
  0	    0	  00	  000
		1  	  01	  001
			  11	  011
		      10	  010
					  110
					  111
					  101
					  100

 */

int* grayCode(int n, int* returnSize) {
	int *ret = (int*)malloc((1 << n) * sizeof(int));
	ret[0] = 0;
	int ret_size = 1;  // 表示有多少个格雷码
	for (int i = 1; i <= n; ++i) {
		// 对称
		for (int j = ret_size - 1; j >= 0; j--) {
			// 设ret[j] == 000对称之后应该为100(保证一位不同)
			// ret[j] | 1 << (i - 1)的含义：给000的最高位加上一个1变成100
			ret[2 * ret_size - 1 - j] = ret[j] | (1 << (i - 1));
		}
		ret_size <<= 1;
	}
	*returnSize = ret_size;
	return ret;
}