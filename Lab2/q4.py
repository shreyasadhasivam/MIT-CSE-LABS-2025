import pandas as pd
import numpy as np

student = {'Name':['Ishaan','Shreya','Aashish','Anika','Khushi'],'Height':[160,157,170,161,162],'Qualification':['BTech','BTech','BTech','BTech','BTech']}
print("\nPart a:")
df = pd.DataFrame(student)
print(df)

print("\nPart b:")
list1 = ['B15','B22','B8','B13','B13']

df.insert(3,'Address',pd.Series(list1))
print(df)