#for example.txt
import fileinput
max_value = 0
old_key = None
for line in fileinput.input():
 data = line.strip().split("\t")
 if len(data) != 2:
    continue
 current_key, current_value = data
 if old_key and old_key != current_key:
    print(old_key,"\t", max_value)
    max_value = 0
 if float(current_value) > float(max_value):
    max_value = float(current_value)
    old_key = current_key
if old_key != None:
 print (old_key, "\t", max_value)

#for heart_disease_data.csv
# import fileinput
# max_value = 0
# old_key = None
# for line in fileinput.input():
#  data = line.strip().split("\t")
#  if len(data) != 2:
#     continue
#  current_key, current_value = data
#  if current_value == 'chol':
#     pass
#  else:
#    if old_key and old_key != current_key:
#       print(old_key,"\t", max_value)
#       max_value = 0
#    if float(current_value) > float(max_value):
#       max_value = float(current_value)
#       old_key = current_key
# if old_key != None:
#    print (old_key, "\t", max_value)

#for covid_19_data.csv
# import fileinput
# max_value = 0
# old_key = None
# for line in fileinput.input():
#  data = line.strip().split("\t")
#  if len(data) != 2:
#     continue
#  current_key, current_value = data
#  if current_value == 'Confirmed':
#     pass
#  else:
#    if old_key and old_key != current_key and max_value!=0:
#       print(old_key,"\t", max_value)
#       max_value = 0
#    if float(current_value) > float(max_value):
#       max_value = float(current_value)
#       old_key = current_key
# if old_key != None and max_value != 0:
#    print (old_key, "\t", max_value)

#for german-credit.csv
# import fileinput
# max_value = 0
# old_key = None
# for line in fileinput.input():
#  data = line.strip().split("\t")
#  if len(data) != 2:
#     continue
#  current_key, current_value = data
#  if current_value == 'DurationOfCreditInMonths':
#     pass
#  else:
#    if old_key and old_key != current_key and max_value!=0:
#       print(old_key,"\t", max_value)
#       max_value = 0
#    if float(current_value) > float(max_value):
#       max_value = float(current_value)
#       old_key = current_key
# if old_key != None and max_value != 0:
#    print (old_key, "\t", max_value)


