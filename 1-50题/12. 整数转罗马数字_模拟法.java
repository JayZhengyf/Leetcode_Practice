class Solution {
	int[] values = {1000, 900, 500, 400, 100, 90,
	50, 40, 10, 9, 5, 4, 1};
	String[] symbols = {"M", "CM", "D", "CD", "C",
	"XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	
	public String inToRoman(int num) {
		StringBuffer roman = new StringBuffer();
		// 寻找不超过num 的最大符号值，
		// 将num减去该符号值，然后继续寻找不超过num的最大符号值，
		// 将该符号拼接在上一个找到的符号之后，循环直至num为0
		for (int i = 0; i < values.length; i++) {
			int value = values[i];
			String symbol = symbols[i];
			while (num >= value) {
				num -= value;
				roman.append(symbol);
			}
			if (num == 0) {
				break;
			}
		}
		return roman.toString();
	}
}