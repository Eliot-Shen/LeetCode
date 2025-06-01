class Solution:
    def countTriples(self, n: int) -> int:
        record = 0
        for i in range(1, floor(n/(2**0.5))+1):
            for j in range(i, floor(sqrt(n**2-i**2)) + 1):
                if sqrt(i**2 + j**2) % 1 == 0:
                    record += 1
        return record*2