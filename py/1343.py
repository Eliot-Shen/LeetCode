def numOfSubarrays(arr: list[int], k: int, threshold: int) -> int:
    left = 0
    right = 0
    size = len(arr)
    window_sum = 0
    record = 0
    while right < size:
        window_sum += arr[right]

        if right - left + 1 >= k:
            if window_sum>= k*threshold:
                record += 1
            window_sum -= arr[left]
            left += 1
        right += 1
    return record
print(numOfSubarrays([2,2,2,2,5,5,5,8],3,4))