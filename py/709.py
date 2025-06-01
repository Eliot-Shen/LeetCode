class Solution:
    def toLowerCase(self, s: str) -> str:
        stem = []
        for j in s:
            if ord('A') <= ord(j) <= ord('Z'):
                stem.append(chr(ord(j) + 32))
            else:
                stem.append(j)
        return ''.join(stem)
# str是不可变对象 str[i] = XXX 是错误的
# join方法,转换为字符串