def moveZeroes(num): 
    #假定0大于任何数
    record = 0
    for i in range(len(num)):
        if num[i] == 0:
            record += 1
        else:
            num[i-record] = num[i]
    num[i-record+1:] = [0]*record
    return num
print(moveZeroes([0,1,3,0,12]))
# 一开始写了嵌套循环,搞的太复杂,简单题不简单.
# 思路是将不为零的数依次向前位移该数之前累积0的个数
# 然后再将最后record个数赋为0