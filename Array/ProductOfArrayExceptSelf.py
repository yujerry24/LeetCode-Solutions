class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        start = 1
        leftProduct = []
        rightProduct = []
        for i in nums:
            start = start*i
            leftProduct.append(start)
        start = 1;
        for i in reversed(nums):
            start = start*i
            rightProduct.insert(0, start);
        returnType = []
        for x in range(len(nums)):
            if x == 0:
                returnType.append(rightProduct[1])  
            elif x == len(nums)-1:
                returnType.append(leftProduct[len(nums)-2])
            else :
                returnType.append(leftProduct[x-1]*rightProduct[x+1])
        return returnType;
        