x = [11,-21,0,45,66,-93]
pos_count = 0
neg_count = 0
for i in x:
	if(i<0):
		neg_count+= 1
	elif(i>=0):
		pos_count+=1
	

print("Positive numbers: ", pos_count)
print("Negative numbers: ", neg_count)