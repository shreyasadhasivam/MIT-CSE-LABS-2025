class py_solution:
  def twoSum(self, nums, target):
    lookup = {}
    for i, num in enumerate(nums):
        if target - num in lookup:
            return (lookup[target - num], i+1 )
        lookup[num] = i+1
if __name__=='__main__':
    num = int(input("Enter size of list:"))
    print("Enter the numbers in list")
    list = []
    for i in range(0,num):
        ele = int(input())
        list.append(ele)

    target = int(input("Enter target:"))
   
    print("Output: ",py_solution().twoSum(list,target))
