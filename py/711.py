def numJewelsInStones(jewels: str, stones: str) -> int:
        count = 0
        for i in jewels:
            for j in stones:
                if i == j:
                    count += 1
        return count
print(numJewelsInStones(jewels = "aA",stones = "aAAbbbb"))

# 2.hashtable O(n+m)
def numJewelsInStones(jewels: str, stones: str) -> int:
    jew = set(jewels)
    return sum(s in jew for s in stones)