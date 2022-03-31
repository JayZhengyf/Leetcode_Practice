// 中序遍历二叉搜索树得到的序列一定是一个升序序列
class Solution {
	public boolean isValidBST(TreeNode root) {
		Deque<TreeNode> stack = new LinkedList<TreeNode>();
		double inorder = -Double.MAX_VALUE;
		
		while (!stack.isEmpty() || root != null) {
			while (root != null) {
				stack.push(root);
				root = root.left;
			}
			root = stack.pop();
			// 如果中序遍历得到的节点值小于等于前一个inorder
			// 说明不是二叉搜索树
			if (root.val <= inorder) {
				return false;
			}
			inorder = root.val;
			root = root.right;
		}
		return true;
	}
}