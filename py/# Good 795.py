# def numSubarrayBoundedMax(nums: list[int], left: int, right: int) -> int:
#     l = 0
#     r = 0
#     ans = 0
#     window = []
#     tempmax = 0
#     while r < len(nums):
#         window.append(nums[r])
#         tempmax = max(tempmax, window[-1])
#         if tempmax not in range(left,right+1):
#             r -= 1
#             window.pop(-1)
#             while max(window) not in range(left,right+1)
#                 l += 1
#                 window.pop(0)
#         ans += 1
#         r += 1
#     if tempmax in range(left,right+1):
#         if r == l:
#             ans += 1
#         else:
#             ans += (r - l + 1) * (r - l) / 2
#     return int(ans)
def numSubarrayBoundedMax(nums: list[int], left: int, right: int) -> int:
    res = 0
    last2 = last1 = -1
    for i, x in enumerate(nums):
        if left <= x <= right:
            last1 = i
        elif x > right:
            last2 = i
            last1 = -1
        if last1 != -1:
            res += last1 - last2
    return res
print(numSubarrayBoundedMax([2,1,4,3],2,3))