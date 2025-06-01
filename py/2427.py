class Solution:
    def commonFactors(self, a: int, b: int) -> int:
        c = min(a,b)
        record = 0
        for i in range(1,c+1):
            if a%i == 0 and b%i == 0:
                record += 1
        return record
# 求最大公约数,详见leetcode