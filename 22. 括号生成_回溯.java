class Solution {
	public List<String> generateParenthesis(int n) {
		List<String> ans = new ArrayList<String>();
		backtrack(ans, new StringBuilder(), 0, 0, n);
		
		return ans;
	}
	
	public void backtrack(List<String> ans, StringBuilder cur, int open, int close, int max) {
		if (cur.length() == max * 2) {
			ans.add(cur.toString());
			return;
		}
		// 左括号的数目要小于max即n
		if (open < max) {
			cur.append('(');
			backtrack(ans, cur, open + 1, close, max);
			cur.deleteCharAt(cur.length() - 1);
		}
		// 右括号的数目要小于左括号的数目
		// 否则会产生右括号在左括号左边的情况
		if (close < open) {
			cur.append(')');
			backtrack(ans, cur, open, close + 1, max);
			cur.deleteCharAt(cur.length() - 1);
		}
	}
}