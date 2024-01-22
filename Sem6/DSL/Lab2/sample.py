import pandas as pd
import numpy as np

s = pd.Series([3,9,-2,10,5])
print(s.sum())
print(s.min())
print(s.max())

data =[['Dinesh',10],['Nithya',12],['Raj',13]]
df = pd.DataFrame(data,columns=['Name','Age'])
print(df)
data = {'Name':['Kavitha', 'Sudha', 'Raju','Vignesh'],'Age':[28,34,29,42]}
df = pd.DataFrame(data, index=['rank1','rank2','rank3','rank4'])
print(df)
df1=pd.DataFrame({'A':pd.Timestamp('20130102'),'B':np.array([3]*4,dtype='int32'),
'C':pd.Categorical(['Male','Female','Male','Female'])})
print(df1.shape)
print(df1.head())
print(df1.tail())
print(df.describe())
print(df.T)
dates=pd.date_range('20130101', periods=100)
df2 = pd.DataFrame(np.random.randn(100,4), index=dates, columns=list('ABCD'))
print(df2.head())
print(df2.tail())
print(df2.index)
print(df2.columns)
print(df2.T)
df2.sort_index(axis=1, ascending=False)
print(df2)
df2.sort_values(by='B')
print(df2)
print(df2[0:3])

print(df2['20130105':'20130110'])
print(df2.iloc[0])
print(df2.iloc[0,:2])
print(df2.iloc[0,0])
print(df2['A'])
print(df2[['A','B']])
print(df2[['A','B']][:5])
print(df2.loc['20130101':'20130105',['A','B']][:5])
print(df2[df2.A>0])
df['Gender']=['Male','Female','Female','Male']
print(df)

print(df.drop ('Gender', axis =1, inplace=True))
print(df.drop ('rank1', axis =0, inplace=True))

