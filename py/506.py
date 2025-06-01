class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        ans, d = [None] * len(score), dict()
        for i, num in enumerate(score):
            d[num] = i #保存排序前的各元素坐标
        score.sort(reverse=True)
        for i, num in enumerate(score, 1): #指定start开始坐标为1
            if i <= 3:
                ans[d[num]] = ["", "Gold Medal","Silver Medal","Bronze Medal"][i] #高级用法
            else:
                ans[d[num]] = str(i)
        return ans
#注意,数组在排序后就会改变,不是原数组了