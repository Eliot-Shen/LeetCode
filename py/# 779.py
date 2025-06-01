# 正确 但超出内存限制 可看题解中更高效的算法
def kthGrammar(n: int, k: int) -> int:
    nums = [[] for _ in range(n)]
    kth(nums , n-1)
    print(nums[n-1][k-1])
    return 1
def kth(nums,n):
    if n == 0:
        nums[0] = [0]
        return 1
    if n == 1:
        nums[1] = [0,1]
    kth(nums, n - 1)

    for num in nums[n-1]:
        if num == 0:
            nums[n].extend([0,1])
            # nums[n].append(1)
        else:
            nums[n].extend([1,0])
            # nums[n].append(0)

kthGrammar(4,1)


class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        if k == 1:
            return 0
        if k > (1 << (n - 2)):  # 判断k是否为后一半
            return 1 ^ self.kthGrammar(n - 1, k - (1 << (n - 2)))
        return self.kthGrammar(n - 1, k)
