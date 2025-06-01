class Solution:
    def numSubarrayProductLessThanK(self, nums: list[int], k: int) -> int:
        if k <= 1:
            return 0

        size = len(nums)
        left = 0
        right = 0
        window_product = 1

        count = 0

        while right < size:
            window_product *= nums[right]

            while window_product >= k:
                window_product /= nums[left]
                left += 1

            count += (right - left + 1)
            # 固定右端点后连续子数列个数为 j - i + 1，可以拿纸笔算一下
            # 也可以解决right到底后的子列该如何计数的问题
            right += 1

        return count


print(numSubarrayProductLessThanK([1,2,3], 0))