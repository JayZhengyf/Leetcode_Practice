// f(x) = x^2 - C
// 用C来表示待求出平方根的整数
// 则C的平方根就是该函数的零点
// x_i+1 = (1/2)(x_i + (C / x_i))

class Solution {
	public int mySqrt(int x) {
		if (x == 0) {
			return 0;
		}
		
		double C = x, x0 = x;
		while (true) {
			double xi = 0.5 * (x0 + C / x0);
			if (Math.abs(x0 - xi) < 1e-7) {
				break;
			}
			x0 = xi;
		}
		return (int)x0;
	}
}