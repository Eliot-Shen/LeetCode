def getConcatenation(nums):
    n = len(nums)
    ans = [0]*2*n
    for i in range(n):
        ans[i] = nums[i]
        ans[i+n] = nums[i]
    return ans
print(getConcatenation([1,2,3]))
