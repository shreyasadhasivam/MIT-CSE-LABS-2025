import sys
cnt = 0
for line in sys.stdin:
    if cnt < 10:line = line.strip()
    words = line.split()
    for word in words:
        print("%s\t\t%s" %(word, 1))
        cnt+=1
    else :
        break
    #this is to limit to 10 lines as huge dataset