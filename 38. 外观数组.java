class Solution {
	public String countAndSay(int n) {
		String str = "1";
		for(int i = 1; i < n; i++) {
			// 存放描述字符串
			StringBuilder string = new StringBuilder();
			// 相同数字开始位置和结束位置
			int start = 0, pos = 0;
			while (pos < str.length()) {
				while (pos < str.length() && str.charAt(pos) == str.charAt(start)) {
					pos++;
				}
				string.append(Integer.toString(pos - start)).append(string.charAt(start));
				start = pos;
			}
			str = string.toString();
		}
		return str;
	}
}