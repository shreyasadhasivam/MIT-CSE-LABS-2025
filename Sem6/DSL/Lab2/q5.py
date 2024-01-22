import pandas as pd
import numpy as np
print("Part a:\n")
df1 =pd.DataFrame({'Name':['Ram','Diya','Chandan','James','Alice']})
df2=pd.DataFrame({'Maths':[80.0,90.0,77.5,87.5,86.5],'Physics':[81.0,94.0,74.5,83.0,82.5],'Chemistry':[91.5,86.5,85.5,90.0,91.0],'Biology':[82.5,83.5,84.5,85.0,93.0]})
print(df1)
print(df2)

print("\nPart b:")
df_new = pd.concat([df1, df2],axis = 1)
print(df_new)
total=df_new.iloc[:,1:].sum(axis=1)
print(total)
df_new["Total"] = total
print(df_new)
