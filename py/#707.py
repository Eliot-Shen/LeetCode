#设计链表
class ListNode:
    def __init__(self,val,next):
        self.val = val
        self.next = next
class MyLinkedList:
    def __init__(self):
        self.head = ListNode(None,None)

    def get(self, index: int) -> int:
        p = self.head
        for i in range(index):
            if p.next:
                p = p.next
            else:
                return -1
        return p.val

    def addAtHead(self, val: int) -> None:
        node = ListNode(val,self.head)
        self.head = node
        
    def addAtTail(self, val: int) -> None:
        p = self.head
        while p.next:
             p = p.next
        p.next = ListNode(val,None)
    def addAtIndex(self, index: int, val: int) -> None:
        p = self.head
        if index == 1:
            p.next = ListNode(val,p.next)
        else:
            for _ in range(index - 1):
                if p.next:
                    p = p.next
                else:
                    return -1
            p.next = ListNode(val,p.next)

    def deleteAtIndex(self, index: int) -> None:
        p = self.head
        if index == 1:
            t = p.next
            p.next = t.next
        else:
            for _ in range(index-1):
                if p.next:
                    p = p.next
                else:
                    return -1
            t = p.next
            p.next = t.next
# Your MyLinkedList object will be instantiated and called as such:

obj = MyLinkedList()

# param_1 = obj.get(index)
obj.addAtHead(1)

obj.addAtTail(3)
obj.addAtIndex(1,2)
obj.get(1)
obj.deleteAtIndex(1)
# for _ in range(1):
#     print(obj.head.val)
#     obj.head = obj.head.next
obj.get(1)

