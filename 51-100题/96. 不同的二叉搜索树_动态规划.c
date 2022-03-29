/* 
G(n)：长度为 n 的序列能构成的不同二叉搜索树的个数
F(i, n)：以 i 为根、序列长度为 n 的不同二叉搜索树的个数(1<=i<=n)
注：G(n)和序列的内容无关，只和序列的长度有关

G(n) = ∑ F(i, n)  i = 1, 2, 3, ..., n  <1>
F(i, n) = G(i - 1) * G(n - i)  <2>
联立<1>、<2>式，得
G(n) = ∑ G(i - 1) * G(n - i)  i = 1, 2, 3, ..., n <3>

 */

int numTrees(int n){
	int G[n + 1];
	memset(G, 0, sizeof(G));
	G[0] = G[1] = 1;
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			G[i] += G[j - 1] * G[i - j];
		}
	}
	return G[n];
}