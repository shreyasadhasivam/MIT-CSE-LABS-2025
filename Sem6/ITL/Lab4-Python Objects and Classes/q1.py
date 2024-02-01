class get_subset:
   def sort_list(self, my_list):
      return self. subset_find([], sorted(my_list))
   def subset_find(self, curr, my_list):
      if my_list:
         return self. subset_find(curr, my_list[1:]) + self. subset_find(curr + [my_list[0]], my_list[1:])
      return [curr]
my_list = []
num_elem = int(input("Enter the number of elements in the list.. "))
for i in range(0,num_elem):
   elem=int(input("Enter the element.."))
   my_list.append(elem)
print("Subsets of the list are : ")
print(get_subset().sort_list(my_list))