# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def removeElements(head, val) :
    if not head:
        return head
    while head.val == val:
        if head.next == None:
            head = None
            return head
        head = head.next
    cur = head
    while cur.next:
        if cur.next.val == val:
            if not cur.next.next:
                cur.next = None
                break
            cur.next = cur.next.next
            continue
        cur = cur.next
    return head

head = ListNode(0)
a = ListNode(1)
b = ListNode(2)
head.next = a
a.next = b
removeElements(head,2)
print(head.val,head.next.val)
# recursion
# if not head: return
#         head.next = self.removeElements(head.next, val)
#         return head.next if head.val==val else head