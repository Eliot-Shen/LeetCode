def lengthOfLongestSubstring(s: str) -> int:
    left = 0
    right = 0
    record = 0
    window = dict()
    while right < len(s):
        if s[right] not in window:
            window[s[right]] = 1
        else:
            window[s[right]] += 1
        while window[s[right]] > 1:
            window[s[left]] -= 1
            left += 1
        record = max(record,right-left+1)
        right += 1
    return record
# 用hashmap记录字符，0为无，1为一个，>1为重复
print(lengthOfLongestSubstring("pwwkew"))