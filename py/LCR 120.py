#1 hashmap
class Solution:
    def findRepeatDocument(self, documents: List[int]) -> int:
        record = {}
        for i in range(len(documents)):
            if documents[i] in record:
                return documents[i]
            record[documents[i]] = i
        return None
    
# 2 原地交换 空间O(1)  不能用for,因为不是每次语句结束后都要i+=1,仔细看题解 
class Solution:
    def findRepeatDocument(self, documents: List[int]) -> int:
        i = 0
        while i < len(documents):
            if documents[i] == i:
                i += 1
                continue
            if documents[documents[i]] == documents[i]:
                return documents[i]
            documents[documents[i]], documents[i] = documents[i], documents[documents[i]]
        return -1