class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        summ = 0
        s_nums = sum(nums)
        if 0 == (s_nums - nums[0]):
            return 0
        for i in range(1,len(nums)):
            summ += nums[i-1]
            if summ == (s_nums - summ - nums[i]):
                return i
        return -1