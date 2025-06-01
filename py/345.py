def reverseString(s: list[str]) -> None:
    """
    Do not return anything, modify s in-place instead.
    """
    left = 0
    right = len(s) - 1
    s1 = list(s)
    while(left<right):
        if s1[left].lower() in ['a','e','i','o','u'] and s1[right].lower() in ['a','e','i','o','u']:
            s1[left], s1[right] = s1[right], s1[left]
            left += 1
            right -= 1
            continue
        if s1[left].lower() in ['a', 'e', 'i', 'o', 'u']:
            right -= 1
            continue
        if s1[right].lower() in ['a', 'e', 'i', 'o', 'u']:
            left += 1
            continue
        left += 1
        right -= 1
    s = ''.join(s1)
    return s
print(reverseString("hello"))
