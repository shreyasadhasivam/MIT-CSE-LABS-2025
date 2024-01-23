import numpy as np

a = np.array([[2,3,4],
	 [6,7,8],
	 [10,11,12]])
print("The array is:\n", a)
print("\nSum of rows: ",a.sum(axis=1))
print("\nSum of columns: ",a.sum(axis=0))