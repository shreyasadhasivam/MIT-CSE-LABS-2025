list1 = ['hello','apple','hat','umbrella','cat']
def sortalfa(unsort_list):
    for i in range(len(unsort_list)-1):
        for j in range(i+1,len(unsort_list)):
            if unsort_list[i]>unsort_list[j]:
                temp = unsort_list[i]
                unsort_list[i] = unsort_list[j]
                unsort_list[j] = temp
    print("sorted list:{}".format(unsort_list))

sortalfa(list1)