// √x = x（½）= e ^ ((1/2)lnx)

class Solution {
	public int mySqrt(int x) {
		if (x == 0) {
			return 0;
		}
		// Math.exp()方法：返回自然数底数e的参数次方
		int ans = (int)Math.exp(0.5 * Math.log(x));
		return (long) (ans + 1) * (ans + 1) <= x ? ans + 1 : ans;
	}
}