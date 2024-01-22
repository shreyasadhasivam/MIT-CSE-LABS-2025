x = int(input('Enter num 1: '))
y = int(input('Enter num 2: '))
z = int(input('Enter num 3: '))
Largest = 0
if(x>y):
	Largest = x
	if(x>z):
		Largest = x
	else:
		Largest = z
elif(y>z):
	Largest = y
else:
	Largest = z
print(Largest)