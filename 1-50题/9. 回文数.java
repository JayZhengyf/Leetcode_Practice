// 回文数，只反转一半
// 全部反转，可能溢出
class Solution {
	public boolean isPalindrome(int x) {
		// 特殊情况：
		// 当x<0，或者x最后一位数字为0时，x不是回文数
		// 0是回文数
		if (x < 0 || (x % 10 == 0 && x != 0)){
			return false;
		}
			
		int revertedNumber = 0;
		// 提取一半长度的数字
		while (x > revertedNumber) {
			revertedNumber = revertedNumber * 10 + x % 10;
			x /= 10;
		}
		
		// 当数字长度为奇数时，revertedNumber去掉最后一位
		// 如：输入12321
		return x == revertedNumber || x == revertedNumber / 10;
	}
}