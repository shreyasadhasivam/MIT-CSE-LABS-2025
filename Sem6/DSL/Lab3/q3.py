import numpy as np

B=np.array ([2.4,10.6,5.2])

print("a) Create array from list with type float:\n")
print(B)

tuple1 = ([8, 4, 6], [1, 2, 3])
array = np.asarray(tuple1)
print("\nb) Create array from tuple\n", tuple1,"\n",array)

print("\nc) Creating a 3X4 array with all zeros\n")
Z = np.zeros((3,4))
print(Z)

print("\nd) Create a sequence of integers from 0 to 20 with steps of 5\n")

array2 = np.arange(0,20,5)
print(array2)

print("\ne) Reshape 3X4 array to 2X2X3 array\n")
c = np.array([[1,2,3],
	 		  [3,4,5],
	 		  [5,6,7],
	 		  [6,7,8]])
c = np.reshape(c,(2,2,3))
print(c)

print("\nf) Find maximum and minimum element of array, Row wise max and min, column wise max and min and sum of elements. (Use functions max(), min(), sum())\n")

c = np.array([[1,2,3],
			 [2,3,4],
			 [5,6,7]])

print("Max:", np.max(c))
print("\nMin: ", np.min(c))

max_element_column = np.max(c, 0)
max_element_row = np.max(c, 1)
 
min_element_column = np.amin(c, 0)
min_element_row = np.amin(c, 1)
print('\nmaximum elements in the columns of the array is:',
      max_element_column)
 
print('\nmaximum elements in the rows of the array is:', 
      max_element_row)
 
print('\nminimum elements in the columns of the array is:',
      min_element_column)
 
print('\nminimum elements in the rows of the array is:',
      min_element_row)


print("\nSum is: ", c.sum())