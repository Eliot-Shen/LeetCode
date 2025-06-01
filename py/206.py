# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        p,p_pre = head,None
        while p:
            p_next = p.next
            p.next = p_pre
            p_pre = p
            p = p_next
        return p_pre
#思考特殊的初始情况,p为head时,写出通用性的语句