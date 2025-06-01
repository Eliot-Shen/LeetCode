def BubbleSort(num):
    for i in range(len(num)-1):
        flag = False
        for j in range(len(num)-i-1):
            if num[j+1] > num[j]:
                num[j+1], num[j] = num[j],num[j+1]
                flag = True
        if flag == False:
            return num
    return num
print(BubbleSort([10,3,8,9,4]))

