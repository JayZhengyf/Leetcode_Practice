class Solution {
	public boolean isSymmetric(TreeNode root) {
		return check(root, root);
	}
	
	public boolean check(TreeNode u, TreeNode v) {
		// 创建存放两棵树节点的队列
		Queue<TreeNode> q = new LinkedList<TreeNode>();
		// 将两棵树的根节点放入队列
		q.offer(u);
		q.offer(v);
		while (!q.isEmpty()) {
			u = q.poll();
			v = q.poll();
			if (u == null && v == null) {
				continue;
			}
			if ((u == null || v == null) || (u.val != v.val)) {
				return false;
			}
			// 镜像对称的放入元素
			q.offer(u.left);
			q.offer(v.right);
			
			q.offer(u.right);
			q.offer(v.left);
		}
		return true;
	}
}