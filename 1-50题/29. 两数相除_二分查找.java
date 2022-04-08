// 假设环境只能存储32位有符号整数，数值范围为[-2^31, 2^31 - 1]

// x, y为负数，z一定是正数或0
// x / y >= z（结果取整）可以转化为 z*y >= x > (z+1)*y
class Solution {
	public int divide(int dividend, int divisor) {
		// 考虑被除数为最小值的情况
		if (dividend == Integer.MIN_VALUE) {
			if (divisor == 1) {
				return Integer.MIN_VALUE;
			}
			if (divisor == -1) {
				return Integer.MAX_VALUE;
			}
		}
		// 考虑除数为最小值的情况
		if (divisor == Integer.MIN_VALUE) {
			return dividend == Integer.MIN_VALUE ? 1 : 0;
		}
		// 考虑被除数为 0 的情况
		if (dividend == 0) {
			return 0;
		}
		
		// 一般情况，使用二分查找
		// 将所有正数取反，只考虑一种情况（如果负数取正，可能产生溢出）
		boolean rev = false;  // 记录取反
		if (dividend > 0) {
			dividend = -dividend;
			rev = !rev;
		}
		if (divisor > 0) {
			divisor = -divisor;
			rev = !rev;
		}
		
		int left = 1, right = Integer.MAX_VALUE, ans = 0;
		while (left <= right) {
			// 注意溢出，不能使用除法
			// z*y >= x > (z+1)*y	x:dividend, y:divisor, z:mid
			int mid = left + ((right - left) >> 1);
			boolean check = quickAdd(divisor, mid, dividend);
			if (check) {
				ans = mid;
				// 注意溢出，不能使用除法
				if (mid == Integer.MAX_VALUE) {
					break;
				}
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		return rev ? -ans : ans;		
	}
	
	// 快速乘和快速幂类似
	// 前者通过加法实现乘法，后者通过乘法实现幂运算
	
	public boolean quickAdd(int y, int z, int x) {
		// x 和 y为负数，z是正数
		// 需要判断z * y >= x是否成立
		// z * y <=> z个y相加
		int result = 0, add = y;
		while (z != 0) {
			if ((z & 1) != 0) {
				// 需要保证result + add >= x
				// 加法可能溢出所以转化为减法
				if (result < x - add) {
					return false;
				}
				result += add;
			}
			if (z != 1) {
				// 没看明白？？？！！！
				// 需要保证add + add >= x
				if (add < x - add) {
					return false;
				}
				add += add;
			}
			// 不能使用除法
			z >>= 1;
		}
		return true;
	}
}