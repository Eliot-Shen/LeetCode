#1 枚举
class Solution:
    def countPrimes(self, n: int) -> int:
        count = 0
        if n in [0,1,2]:
            return 0
        if n == 3:
            return 1
        for i in range(2,n):
            cnt = 0     #别忘了清零!!!
            if i == 2:
                count += 1
                continue
            if i % 2 == 0:
                continue
            # a = (i+1)//2
            a = floor(i ** 0.5) + 1
            for j in range(2, a):
                if i % j == 0:
                    cnt = 1
                    break
            if cnt == 1:
                continue
            count += 1
        return count
#2 埃及筛
