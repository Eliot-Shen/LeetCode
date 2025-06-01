class MergeSort:
    def merge(self, left_nums, right_nums):
        nums = []
        left_i, right_i = 0, 0
        while left_i < len(left_nums) and right_i < len(right_nums):
            if left_nums[left_i] < right_nums[right_i]:
                nums.append(left_nums[left_i])
                left_i += 1
            else:
                nums.append(right_nums[right_i])
                right_i += 1
        # 如果左子数组有剩余元素，则将其插入到结果数组中
        while left_i < len(left_nums):
            nums.append(left_nums[left_i])
            left_i += 1
        
        # 如果右子数组有剩余元素，则将其插入到结果数组中
        while right_i < len(right_nums):
            nums.append(right_nums[right_i])
            right_i += 1
        
        # 返回合并后的结果数组
        return nums
    def mergeSort(self, nums):
        if len(nums) <= 1:
            return nums
        mid_i = len(nums) // 2
        left_num = self.mergeSort(nums[0:mid_i])
        right_num = self.mergeSort(nums[mid_i:])
        return self.merge(left_num, right_num)
    def sortArray(self,nums):
        return self.mergeSort(nums)

print(MergeSort().sortArray([0, 5, 7, 3, 1, 6, 8, 4]))