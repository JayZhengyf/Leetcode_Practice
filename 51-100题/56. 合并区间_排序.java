class Solution {
	public int[][] merge(int[][] intervals) {
		if (intervals.length == 0) {
			return new int[0][2];
		}
		
		Arrays.sort(intervals, new Comparator<int[]>() {
			public int compare(int[] interval1, int[] interval2) {
				return interval1[0] - interval2[0];
			}
		}) ;
		
		List<int[]> merged = new ArrayList<int[]>();
		for (int i = 0; i < intervals.length; i++) {
			int L = intervals[i][0], R = intervals[i][1];
			// 两个区间不可以合并或列表为空时
			if (merged.size() == 0 || merged.get(merged.size() - 1)[1] < L) {
				merged.add(new int[]{L, R});
			} else { // 两个区间能合并时
				merged.get(merged.size() - 1)[1] = Math.max(merged.get(merged.size() - 1)[1], R);
			}
		}
		return merged.toArray(new int[merged.size()][]);
	}
}