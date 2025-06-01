def maxArea(height: list[int]) -> int:
    left = 0
    right = len(height) - 1
    volume = 0
    area = right - left
    while(left < right):
        volume = max(volume,(right-left)*min(height[left], height[right]))
        if(height[left]<=height[right]):
            left += 1
        else:
            right -= 1
    return volume
print(maxArea([1,8,6,2,5,4,8,3,7]))
