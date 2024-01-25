num1 = int(input("Enter number 1: "))
num2 = int(input("Enter number 2: "))
print("Select operation: \n+\n-\n*\n/\n")

op = input()

if(op=='+'):
    result = num1+num2
elif(op=='-'):
    result = num1-num2
elif(op=='*'):
    result = num1*num2
elif(op=='/'):
    result = num1/num2

print("The answer is",result)