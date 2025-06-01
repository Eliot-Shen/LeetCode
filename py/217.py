# solution1 set 
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(set(nums)) != len(nums)

# solution2 hash table
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        record = dict()
        for num in nums:
            if num in record:
                return True
            else:
                record[num] = num
        return False

# solution3 sort
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        nums.sort()
        for i in range(len(nums)):
            if nums[i] == nums[i+1]:
                return True
        return False