import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

df = pd.read_csv('files/xyz.csv', header=None)
df.head()
df.tail()
df.columns=['preg','glu','bp','sft','ins','bmi','dpf','age','class']

plt.scatter(df['bmi'],df['glu'])
plt.xlabel('bmi')
plt.ylabel('Glucose')
plt.show()

df['age'].hist()
plt.show()

W = pd.read_csv('files/wine.xls',header=None)
print(W.head())
D= np.loadtxt('files/xyz.txt',delimiter=",")
print(D[:5,:])

G= pd.read_excel('files/germanCredit.xls', sheet_name="Sheet1")
print(G.head())

B= pd.read_html('files/Test runs-1.html')
print(B)
H = pd.read_table('files/HR_for_Week2.txt')
H.head()
f=H['Department'].value_counts()
f.plot(kind='bar')
plt.show()
f.plot(kind='pie')
plt.show()
fa=pd.crosstab(H['Gender'],H['Attrition'])
fa.plot(kind='bar')
plt.show()