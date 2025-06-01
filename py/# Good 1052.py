def maxSatisfied(customers: list[int], grumpy: list[int], minutes: int) -> int:
    if minutes >= len(customers):
        return sum(customers)
    total = 0
    increase = 0
    maxincrease = 0
    left = 0
    right = 0
    window = []
    window_sum = 0
    for j in range(len(customers)):
        total += abs(grumpy[j] - 1) * customers[j]
    while right < len(customers):
        window.append(customers[right])
        window_sum += customers[right]
        while right - left + 1 >= minutes:
            temp = 0
            for i in range(left, left + minutes):
                temp += abs(grumpy[i] - 1) * customers[i]
            increase = window_sum - temp
            maxincrease = max(maxincrease, increase)
            window_sum -= window[0]
            window.pop(0)
            left += 1
        right += 1
    return total + maxincrease
    # ans = 0
    # left = 0
    # right = 0
    # window = []
    # window_sum = 0
    # while right < len(customers):
    #     window.append(customers[right])
    #     window_sum += customers[right]
    #     while right - left + 1 >= minutes:
    #         temp = 0
    #         if right < len(customers) - 1:
    #             for i in range(right + 1, len(customers)):
    #                 temp += abs(grumpy[i] - 1) * customers[i]
    #         if left >= 1:
    #             for j in range(left):
    #                 temp += abs(grumpy[j] - 1) * customers[j]
    #         ans = max(ans, window_sum + temp)
    #         window_sum -= window[0]
    #         window.pop(0)
    #         left += 1
    #     right += 1
    # return ans
print(maxSatisfied([1,0,1,2,1,1,7,5],[0,1,0,1,0,1,0,1],3))

class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        n = len(customers)
        total = sum(c for c, g in zip(customers, grumpy) if g == 0)
        # total只算总体内grumpy = 0的总和
        maxIncrease = increase = sum(c * g for c, g in zip(customers[:minutes], grumpy[:minutes]))
        # increase只算该窗口里grumpy = 1的总和，没算上等于0的
        for i in range(minutes, n):
            increase += customers[i] * grumpy[i] - customers[i - minutes] * grumpy[i - minutes]
            #滑动窗口
            maxIncrease = max(maxIncrease, increase)
        return total + maxIncrease

# 作者：力扣官方题解
# 链接：https://leetcode.cn/problems/grumpy-bookstore-owner/
# 来源：力扣（LeetCode）
# 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。