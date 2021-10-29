class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        temp = s.split(' ')
        toReturn=''
        
        for word in temp:
            toReturn += word[::-1] + ' '
            
        return toReturn.strip()