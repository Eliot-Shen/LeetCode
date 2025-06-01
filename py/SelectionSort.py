def SelectionSort(num):
    for i in range(len(num)):
        min_i = num[i]
        for j in range(i,len(num)):
            if num[j] < num[i]:
                num[i], num[j]= num[j], num[i]
    return num  
print(SelectionSort([5, 2, 3, 6, 1, 4]))