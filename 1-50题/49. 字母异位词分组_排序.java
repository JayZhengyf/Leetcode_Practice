class Solution {
	public List<List<String>> groupAnagrams(String[] strs) {
		Map<String, List<String>> map = new HashMap<String, List<String>>();
		for (String str : strs) {
			char[] array = str.toCharArray();
			// 字母异位词字母相同
			// 排序后结果一致
			Arrays.sort(array);
			String key = new String(array);
			// 查找键对应的值
			// 如果没有则返回默认值
			List<String> list = map.getOrDefault(key, new ArrayList<String>());
			list.add(str);
			// 将键值对放入哈希表
			map.put(key, list);
		}
		return new ArrayList<List<String>>(map.values());
	}
}