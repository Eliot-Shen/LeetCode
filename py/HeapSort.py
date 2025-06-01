class MaxHeap:
    def __init__(self):
        self.max_heap = []
    def peek(self):
        if not self.max_heap:
            return None
        return self.max_heap[0]
    def push(self,val):
        self.max_heap.append(val)
        size = len(self.max_heap)
        self.__shift_up(size - 1)
    def __shift_up(self,i):
        while(i-1) // 2 >= 0 and self.max_heap[i] > self.max_heap[(i-1)//2]:
            self.max_heap[i],self.max_heap[(i-1)//2] = self.max_heap[(i-1)//2],self.max_heap[i]
            i = (i-1) // 2
    def pop(self):
        if not self.max_heap:
            raise IndexError("堆为空")
        size = len(self.max_heap)
        self.max_heap[0], self.max_heap[size - 1] = self.max_heap[size - 1], self.max_heap[0]
        val = self.max_heap.pop()
        size -= 1
        self.__shift_down(0,size)
        return val

    def __shift_down(self, i, n):
        while 2*i + 1 < n:
            left, right = 2 * i + 1, 2 * i + 2
            if 2 * i + 2 >= n:
                    # 右子节点编号超出范围（只有左子节点
                    larger = left
            else:
                # 左子节点、右子节点都存在
                if self.max_heap[left] >= self.max_heap[right]:
                    larger = left
                else:
                    larger = right
            # 将当前节点值与其较大的子节点进行比较
            if self.max_heap[i] < self.max_heap[larger]:
                # 如果当前节点值小于其较大的子节点，则将它们交换
                self.max_heap[i], self.max_heap[larger] = self.max_heap[larger], self.max_heap[i]
                i = larger
            else:
                # 如果当前节点值大于等于于其较大的子节点，此时结束
                break

    def __bulidMaxHeap(self,nums):
        size = len(nums)
        for i in range(size):
            self.max_heap.append[nums[i]]
        
        for i in range((size-2) // 2, -1, -1):
            # size-2使从最后一个父节点开始
            self.__shift_down(i,size)
    
    def maxHeapSort(self,nums):
        self.__bulidMaxHeap(nums)

        size = len(self.max_heap)
        for i in range(size-1, -1, -1):
            self.max_heap[0], self.max_heap[i] = self.max_heap[i], self.max_heap[0]
            self.__shift_down(0, i)
        return self.max_heap
    
solution = MaxHeap()
print(solution.maxHeapSort([10, 25, 6, 8, 7, 1, 20, 23, 16, 19, 17, 3, 18, 14]))
    
