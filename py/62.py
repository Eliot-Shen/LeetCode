#1 math
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        def poly(n):
            anw = 1
            for i in range(1,n+1):
                anw *= i
            return anw
        return poly(m+n-2)//(poly(m-1)*poly(n-1))
#2 dynamic programming
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[[0] for _ in range(n)] for _ in range(m)] #创建m*n的二维数组
        dp[0][0] = 1
        for j in range(n):
            dp[0][j] = 1
        #第一行元素只有一条路径（即只能通过前一个元素向右走得到）
        for i in range(m):
            dp[i][0] = 1

        for i in range(1,m):
            for j in range(1,n):
                dp[i][j] = dp[i][j-1] + dp[i-1][j]
        #从上往下.从左往右计算路径数,通过相邻的左上子问题路径数相加获得
        return dp[m-1][n-1]
