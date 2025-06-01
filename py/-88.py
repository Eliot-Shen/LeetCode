class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        if m == 0:
            nums1 = nums2.copy
        if n==0:
            pass
        else:
            nums = []
            left_i, right_i = 0, 0
            while left_i < len(nums1) and right_i < len(nums2):
                if nums1[left_i] < nums2[right_i]:
                    nums.append(nums1[left_i])
                    left_i += 1
                else:
                    nums.append(nums2[right_i])
                    right_i += 1
            # 如果左子数组有剩余元素，则将其插入到结果数组中
            while left_i < len(nums1):
                nums.append(nums1[left_i])
                left_i += 1
            
            # 如果右子数组有剩余元素，则将其插入到结果数组中
            while right_i < len(nums2):
                nums.append(nums2[right_i])
                right_i += 1
            
            # 返回合并后的结果数组
            nums1 = nums