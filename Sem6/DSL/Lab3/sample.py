import numpy as np
import random
'''A = np.array ([2,5,10])
print(A.dtype)


B=np.array ([2.4,10.6,5.2])
print(B.dtype)

A=np.array([(3,4,5),(12,6,1)])
print(A)
Z=np.zeros((2,4))
print(Z)

Y  = np.ones((3,3))
print(Y)
S = np.arange(10,30,5)
print(S)
'''
T=np.arange(0,2,0.3)
print(T)

S1=np.linspace(0,2,9)


print(random.choice([1,2,3,4,5]))

print(random.choice('python'))

print(random.randrange(25,50))

print(random.randrange(25,50,2))

print(random.random())

print(random.uniform(5,10))

print(random.shuffle([1,2,3,4,5]))

print(random.seed(10))

a = np.arange(15).reshape(3, 5)
print(a)

print(a.shape)
print(a.size)

print(a.T)

c = np.arange(24).reshape(2,3,4)
print(c)

print(c.shape)

a = np.array( [20,30,40,50] )
b = np.arange(4)

print(b)
c = a-b
print(c)
print(b**2)

print(10*np.sin(a))

print(a<35)

A = np.array( [[1,1],[0,1]] )
B = np.array( [[2,0],[3,4]] )
print(A*B)

print(A.dot(B))
print(np.dot(A,B))

b = np.arange(12).reshape(3,4)
print(b)

print(b.sum(axis=0))
print(b.sum(axis=1))

a = np.arange(10)**3
print(a)

print(a[2:5])
print(a[0:6:2])

b = np.array([[ 0, 1, 2, 3],
[10, 11, 12, 13],
[20, 21, 22, 23],
[30, 31, 32, 33],
[40, 41, 42, 43]])
print(b[2,3])

print(b[0:5,1])
print(b[:5,1])
print(b[:,1])

print(b[-1,:]) # will fetch last row
print(b[:,-1]) # will fetch last col
for row in b:
	print (row) # will print every row
for element in b.flat:
	print (element) # will show all elements of b in 1−D array
print(b.ravel())

B1 = b.reshape(4,5)

A1=np.array([(3,4,5),(12,6,1)])
print(A1)
A2=np.array([(1,2,6),(-4,3,8)])
print(A2)
D1=np.vstack((A1,A2))
print(D1)
D2=np.hstack((A1,A2))
print(D2)

a = np.array([4.,2.])
b = np.array([3.,8.])
print(np.column_stack((a,b)))
print(np.hstack((a,b)))
print(np.hstack((a[:,np.newaxis],b[:,np.newaxis])))

a = np.arange(12)**2
i = np.array( [ 1,1,3,8,5 ] )
print(a[i])

j = np.array( [[3, 4], [9, 7] ] ) # a bidimensional array of indices
print(a[j])

a=np.array([(3,2,9),(1,6,7)])
s1=0
for row in a:
	for col in row:
		s1+=col
	print(s1)

a=np.array([(3,2,9),(1,6,7)])
s=0
for i in range(a.shape[0]):
	for j in range(a.shape[1]):
		s+=a[i,j]
print(s)