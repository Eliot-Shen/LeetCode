#dynamic programming 
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        dp = [0]*(n+1)
        dp[0] = 1
        dp[1] = 1
        dp[2] = 2
        for i in range(2,n+1):
            dp[i] = dp[i-1] + dp[i-2] 
        return dp[n]
        # n = 4 1111 121 211 22 112
#滑动数组
class Solution:
    def climbStairs(self, n: int) -> int:
        p = 0
        q = 0
        r = 1
        for i in range(1,n+1):
            p = q
            q = r
            r = p + q
        return r