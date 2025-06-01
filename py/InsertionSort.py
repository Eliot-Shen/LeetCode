def InsertionSort(num):
    for i in range(1,len(num)):
        temp = num[i]
        j = i
        while j > 0 and num[j-1] > temp:
        # 将有序区间中插入位置右侧的所有元素依次右移一位
            num[j] = num[j-1]
            j -= 1
        num[j] = temp
    return num
print(InsertionSort([5, 2, 3, 6, 1, 4]))