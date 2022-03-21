int* grayCode(int n, int* returnSize) {
	int ret_size = 1 << n;
	int* ret = (int*) malloc(ret_size * sizeof(int));
	// 设b位n位二进制数，g为对应的格雷码
	// 则g(i) = b(i + 1) xor b(i),  0 <= i < n
	// g(i)和b(i)表示g和b的第i位 
	// 最高位不用变化
	// 例如 5的二进制为101 按照上述方法得到的格雷码为111 -> 正确
	for (int i = 0; i < ret_size; i++) {
		ret[i] = (i >> 1) ^ i;
	}
	*returnSize = ret_size;
	return ret;
}