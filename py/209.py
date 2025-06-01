def minSubArrayLen(target: int, nums: list[int]) -> int:
    left = 0
    right = 0
    window_sum = 0
    record = len(nums) + 1

    while right < len(nums):
        window_sum += nums[right]
        while window_sum >= target:
            record = min(record, right - left + 1)
            window_sum -= nums[left]
            left += 1
        right += 1
    return record if record != len(nums) + 1 else 0
print(minSubArrayLen(11, [1,1,1,1,1,1,1,1]))