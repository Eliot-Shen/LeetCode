class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        n = len(digits)
        while n > 0:
            if digits[n - 1] == 9:
                digits[n - 1] = 0
                n -= 1
            else:
                digits[n - 1] +=  1
                return digits
        if n == 0:
            return [1] + digits

        
        

