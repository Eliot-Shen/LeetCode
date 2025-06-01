#还有很多方法
#1 首个自己的思路 work
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        record = [0]*len(nums)
        for i in range(len(nums)):
            if (i + k) >= len(nums):
                record[(i+k)%len(nums)] = nums[i]
            else:
                record[i+k] = nums[i]
        for i in range(len(nums)):
            nums[i] = record[i]
#2 翻转数组 空间复杂度O(1)
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        nums.reverse()
        nums[0:(k%n)] = list(reversed(nums[0:(k%n)]))
        nums[(k%n):n] = list(reversed(nums[(k%n):n]))
#等价方法,速度更快
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if k != 0 and k!= n:
            nums.reverse()
            nums[0:(k%n)] = nums[(k%n)-1::-1]
            nums[(k%n):n] = nums[n:(k%n)-1:-1]