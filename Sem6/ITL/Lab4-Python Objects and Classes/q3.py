class Solution(object):
    def myPow(self, x, n):
        power = abs(n)
        res = 1.0
        while power:
            if power & 1:
                res*=x
            x*=x
            power>>=1
        if n<0:
            return 1/res
        return res
    
if __name__=='__main__':
        x = int(input("Enter number: "))
        n = int(input("Enter power: "))
        print(Solution().myPow(x,n))