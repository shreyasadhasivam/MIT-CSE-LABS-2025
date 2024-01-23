import numpy as np

print("Enter the Number: ")
num = input()

num = int(num)
print("\nFactors of", num)

i = 1
for i in range(1,num+1):
    if num%i==0:
        print(i)
    i = i+1