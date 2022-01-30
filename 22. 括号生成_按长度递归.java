class Solution {
	ArrayList[] cache = new ArrayList[100];
	
	
	// generate返回的是n个括号的有效组合的列表
	public List<String> generate(int n) {
		if (cache[n] != null) {
			return cache[n];
		}
		ArrayList<String> ans = new ArrayList<String>();
		if (n == 0) {
			ans.add("");
		} else {
			for (int c = 0; c < n; c++) {
				for (String left: generate(c)) {
					// n为括号数
					// 减1是因为 "(" + left + ")" + right 当中含有一组括号
					// 减c是因为需要减去left的值
					// 最终，n - 1 - c 是right的值
					for (String right: generate(n - 1 - c)) {
						ans.add("(" + left + ")" + right);
					}
				}
			}
		}
		cache[n] = ans;
		return ans;
	}
	
	public List<String> generateParenthesis(int n) {
		return generate(n);	
	}
}