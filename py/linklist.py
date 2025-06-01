class Node():
    def __init__(self,val = 0,next = None):
        self.val = val
        self.next = next
class Linklist():
    def __init__(self):
        self.head = None
    def add(self,data):
        self.head = Node(0)
        i = self.head
        for temp in data:
            a = Node(temp)
            i.next = a
            i = a
    def insert(self,index,val):
        count = 0
        cur = self.head
        while cur and count < index - 1:
            count += 1
            cur = cur.next
        #cur.next = aim
        node = Node(val,next = cur.next)
        cur.next = node
