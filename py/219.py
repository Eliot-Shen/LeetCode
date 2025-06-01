#初解,超时
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        record = dict()
        for i, num in enumerate(nums):
            if num in record.values():
                if abs(max(k for k,v in record.items() if v == num) - i) <= k:
                    return True
                else:
                    record[i] = num
            else:
                record[i] = num
        return False
    
#变换一下num和i在字典中的角色即可,hashtable中访问键更容易
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        record = {}
        for i, num in enumerate(nums):
            if num in record and i - record[num] <= k:
                return True
            record[num] = i
        return False