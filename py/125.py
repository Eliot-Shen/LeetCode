import re


def isPalindrome(s: str) -> bool:
    s = s.lower()
    s = re.sub('[\W_]+', "", s)
    # 正则表达式
    left = 0
    right = len(s) - 1
    while(left<=right):
        if s[left] == s[right]:
            left += 1
            right -= 1
        else:
            return False
    return True
print(isPalindrome("race a car"))

