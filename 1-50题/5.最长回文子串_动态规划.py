class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        if n < 2:
            return s
        
        max_len = 1
        begin = 0
        # dp[i][j]表示是s[i...j]是否是回文串
        dp = [[False] * n for _ in range(n)]
        for i in range(n):
            dp[i][i] = True
            
        # 递推开始
        # 先枚举子串长度
        for L in range(2, n+1):
        
            # 枚举左边界
            for i in range(n):
                # 由L和i可以在确定右边界，即j-i+1=L
                j = L + i - 1
                # 如果右边界越界，就可以退出当前循环
                if j >= n:
                    break
                    
                if s[i] != s[j]:
                    dp[i][j] = False
                else:
                    if j-i < 3:
                        dp[i][j] = True
                    else:
                        dp[i][j] = dp[i + 1][j - 1]
                        
                # 只要dp[i][j]==True成立，就表示子串s[i..j]是回文
                # 此时开始记录回文长度和起始位置
                if dp[i][j] and j - i + 1 > max_len:
                    max_len = j - i + 1
                    begin = i
        return s[begin:begin + max_len]