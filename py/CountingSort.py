def CountingSort(num):
    count = [0]*(max(num) - min(num) + 1)
    for i in range(len(num)):
        count[num[i]-min(num)] += 1

    for i in range(1,len(count)):
        # sum += count[i]
        # count[i] = sum
        count[i] += count[i-1]
    
    res = [0 for _ in range(len(num))]
    #因为count计数的值为改数最后出现的索引,所以要逆序以减法填充num
    for k in range(len(num)-1, -1, -1):
        res[count[num[k] - min(num)] - 1] = num[k]
        count[num[k] - min(num)] -= 1
    print(res)
CountingSort([3,0,4,2,5,1,3,1,4,5])
        
