class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        record = 0
        temp = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                temp = 0
                continue
            temp += 1
            if temp > record:
                record = temp
        return record
#第一次写了一个O(n^2)的嵌套循环,超时