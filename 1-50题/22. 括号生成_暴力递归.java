class Solution {
	public List<String> generateParenthesis(int n) {
		List<String> combinations = new ArrayList<String>();
		generateAll(new char[2 * n], 0, combinations);
		return combinations;
	}
	
	// 递归生成所有的括号组合
	// 并将合法的括号组合存入列表
	public void generateAll(char[] current, int pos, List<String> result) {
		if (pos == current.length) {
			if (valid(current)) {
				result.add(new String(current));
			}
		} else {
			current[pos] = '(';
			generateAll(current, pos + 1, result);
			current[pos] = ')';
			generateAll(current, pos + 1, result);
		}
	}
	
	// 判断括号字符串是否合法
	public boolean valid(char[] current) {
		int balance = 0;
		for (char c: current) {
			if (c == '(') {
				balance++;
			} else {
				balance--;
			}
			if (balance < 0) {
				return false;
			}
		}
		return balance == 0;
	}
}