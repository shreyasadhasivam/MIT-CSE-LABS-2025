with open("myfile.txt") as f:
    data = f.readlines()
with open("myfile.txt") as fnew:
    datanew = fnew.read()  

f1= open("output.txt", "w+")
f2 = open("output2.txt","w+")

data_1 = data[::-1]
data_2 = datanew[::-1]
f1.writelines(data_1)#reverses order of lines
f2.write(data_2) #reverses every character
f1.close()
