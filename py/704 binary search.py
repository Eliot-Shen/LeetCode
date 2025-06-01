def search(nums: list[int], target: int) -> int:
    left = 0
    right = len(nums) - 1
    while (left <= right):
        mid = left + (right - left) // 2  # 防止整型溢出
        if (target == nums[mid]):
            return mid
        elif (target < nums[mid]):
            right = mid - 1
            continue
        else:
            left = mid + 1
            continue
    return -1


print(search([-1, 0, 3, 5, 9, 12], 9))

# 排除法
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1

        # 在区间 [left, right] 内查找 target
        while left < right:
            # 取区间中间节点
            mid = left + (right - left) // 2
            # nums[mid] 小于目标值，排除掉不可能区间 [left, mid]，在 [mid + 1, right] 中继续搜索
            if nums[mid] < target:
                left = mid + 1
                # nums[mid] 大于等于目标值，目标元素可能在 [left, mid] 中，在 [left, mid] 中继续搜索
            else:
                right = mid
        # 判断区间剩余元素是否为目标元素，不是则返回 -1
        return left if nums[left] == target else -1
