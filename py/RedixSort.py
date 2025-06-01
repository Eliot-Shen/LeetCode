def RedixSort(nums):
    size = len(str(max(nums)))  # 获取数组最大位数
    for i in range(size):
        buckets = [[] for _ in range(10)]
        for num in nums:
            buckets[num//(10**i)%10].append(num)
        nums.clear()
        for bucket in buckets:
            for num in bucket:
                nums.append(num)
    return nums
print(RedixSort([5,3,2,6,1]))