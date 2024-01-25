list1= [1,2,3,4,5,6,7,8,9]

num = int(input("Enter number to search: "))
i = 0

def BinSearch(list1):
    i = 0
    if(list1[i]==num):
        print("Number is there in list")
    else:
        i+=1
        if(i!=len(list1)):
            BinSearch(list1[i:])
        else:
            print("Number is not found")

if __name__ =='__main__':
    BinSearch(list1)