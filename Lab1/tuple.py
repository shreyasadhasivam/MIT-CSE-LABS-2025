tuple = ( 'abcd', 786 , 2.23, 'john', 70.2 )
list = [ 'abcd', 786 , 2.23, 'john', 70.2 ]
#tuple[2] = 1000 # Invalid syntax with tuple
list[2] = 1000 # Valid syntax with list
num=float(input('Enter a number:'))
if num>0:
	print('pos number')
elif num==0:
	print('zero')
else:
	print('Neg number')
x=float(input('Enter a number:'))
if x<10:
	print('smaller')
if x>20:
	print('bigger')
print('Finished')
x=5
print('Before 5')
if x==5:
	print ('this is 5')
	print('still 5')
print('After 5')
print('Before 6')
if x==6:
	print('this is 6')
print ('After 6')
x=float(input('Enter a number:'))
if x<20:
	print('Below 20')
elif x<10:
	print('Below 10')
else:
	print('something else')

x=42
if x>1:
	print('above one')
	if x<100:
		print('less than 100')
print('All done')
age=15
b=('kid' if age<18 else 'adult')
print(b)
#this will print ‘kid’
for val in [5,4,3,2,1]:
	print(val)
print ('Done')
stud=['Ram','Vijay','Nithya','Anu','Ramesh','suja']
for k in stud:
	print('Hello:', k)
	print('done')
for i in range(5):
	print(i)
	if i>2:
		print('Bigger than 2')
	print('Done with i',i)
	
x=int(input('Enter a number:'))
for i in range(1,x+1):
	if x%i ==0:
		print(i)
		
		
from math import *
x= [9, 41, 12, 3, 74, 15]
Largest= -inf
for i in x:
	if i>Largest:
		Largest=i
print(Largest)


x= [9, 41, 12, 3, 74, 15]
smallest=inf
for i in x:
	if i<smallest:
		smallest=i
print(smallest)

count=sum=avg=0
for i in x:
	count=count+1
	sum=sum+1
avg=sum/count
print(count)
print(sum)
print(avg)

for i in x:
	if i>20:
		print (i)


res=[]
for i in x:
	if i>20:
		res.append(i)

import numpy as np
y=np.zeros(len(x))
for i in range(len(x)):
	if x[i]>20:
		y[i]=x[i]
print(y)

price = 100
if price > 100:
	print("price is greater than 100")
elif price == 100:
	print("price is 100")
elif price < 100:
	print("price is less than 100")
i=1
n=5
# while loop from i = 1 to 5
while i <= n:
	print(i)
	i=i+1

total = 0
number = int(input('Enter a number: '))
# add numbers until number is zero
while number != 0:
	total += number # total = total + number
# take integer input again
	number = int(input('Enter a number: '))
	print('total =', total)






