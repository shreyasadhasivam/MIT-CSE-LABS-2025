import pandas as pd
import numpy as np
print("Part a:\n")
df =pd.DataFrame({'Name':['Annie','Diya','Charles','James','Emily'], 'Quiz_1/10':[8.0,9.0,7.5,8.5,6.5],'In_sem1/15':[11.0,14.0,14.5,13.0,12.5],'Quiz_2/10':[9.5,6.5,8.5,9.0,9.0],'In_sem2/15':[12.5,13.5,14.5,15.0,13.0]})
print(df)

total=df.iloc[:,1:].sum(axis=1)
print(total)
df["Total"] = total
print(df)
mean = df.iloc[:,1:].mean(axis='columns')
df= df.append(mean)
print(mean)
print(df)

