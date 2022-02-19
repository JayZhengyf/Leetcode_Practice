class Solution {
	public int jump(int[] nums) {
		int length = nums.length;
		// 上一次的边界值（下一次的最右起跳点）
		// 在这一点一定会跳
		int end = 0;  
		int maxPosition = 0;  // 目前的边界值
		int steps = 0;
		// 不访问最后一个元素
		for (int i = 0; i < length - 1; i++) {
			maxPosition = Math.max(maxPosition, i + nums[i]);
			if (i == end) {
				end = maxPosition;
				steps++;
			}
		}
		return steps;
	}
}