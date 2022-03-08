/*
构建如下递推关系
[1 1][ f(n) ]  =  [f(n)+f(n-1)] = [f(n+1)]
[1 0][f(n-1)]     [    f(n)   ]   [ f(n) ]

因此
[f(n+1)]  =  [1 1]ⁿ[f(1)]
[ f(n) ]	 [1 0] [f(0)]

令 M = [1 1]
       [1 0]
	   
所以只需要计算M的n次幂，就可以得到f(n)的值
*/

/* 这种解法的时间复杂度是O(log n) */

struct Matrix {
	long long mat[2][2];
};

// 矩阵乘法
struct Matrix multiply(struct Matrix a, struct Matrix b) {
	struct Matrix c;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			c.mat[i][j] = a.mat[i][0] * b.mat[0][j] + a.mat[i][1] * b.mat[1][j];
		}
	}
	return c;
}

// 计算矩阵的幂次方
// 快速幂算法
struct Matrix matrixPow(struct Matrix a, int n) {
	struct Matrix ret;
	ret.mat[0][0] = ret.mat[1][1] = 1;
	ret.mat[0][1] = ret.mat[1][0] = 0;
	while (n > 0) {
		// 判断n是否为奇数
		// n为奇数时，二进制最低位一定是1
		// n为偶数时，n & 1返回1，否则返回0
		if ((n & 1) == 1) {  
			ret = multiply(ret, a);
		}
		n >>= 1;
		a = multiply(a, a);
	}
	return ret;
}

int climbStairs(int n) {
	struct Matrix ret;
	ret.mat[1][1] = 0;
	ret.mat[0][0] = ret.mat[0][1] = ret.mat[1][0] = 1;
	struct Matrix res = matrixPow(ret, n);
	return res.mat[0][0];
}