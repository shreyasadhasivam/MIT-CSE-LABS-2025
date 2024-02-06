#for example.txt
import fileinput
transactions_count = 0
sales_total = 0
for line in fileinput.input():
 data = line.strip().split("\t")
 if len(data) != 2:
 # Something has gone wrong. Skip this line.
    continue
 current_key, current_value = data
 transactions_count += 1
 sales_total += float(current_value)
print (transactions_count, "\t", sales_total)

#for heart_disease_data.csv
# import fileinput
# sex_count = 0
# chol_total = 0
# for line in fileinput.input():
#  data = line.strip().split("\t")
#  if len(data) != 2:
#  # Something has gone wrong. Skip this line.
#     continue
#  current_key, current_value = data
#  if current_value == 'chol':
#     pass
#  else:
#    sex_count += 1
#    chol_total += float(current_value)
# chol_avg = chol_total/sex_count
# print (sex_count, "\t", chol_avg)

#for covid_19_data.csv
# import fileinput
# province_count = 0
# confirm_total = 0
# for line in fileinput.input():
#  data = line.strip().split("\t")
#  if len(data) != 2:
#  # Something has gone wrong. Skip this line.
#     continue
#  current_key, current_value = data
#  if current_value == 'Confirmed':
#     pass
#  else:
#    province_count += 1
#    confirm_total += float(current_value)
# print (province_count, "\t", confirm_total)

#for german-credit.csv
# import fileinput
# creditability_count = 0
# amount_total = 0
# for line in fileinput.input():
#  data = line.strip().split("\t")
#  if len(data) != 2:
#  # Something has gone wrong. Skip this line.
#     continue
#  current_key, current_value = data
#  if current_value == 'CreditAmount':
#     pass
#  else:
#    creditability_count += 1
#    amount_total += float(current_value)
# print (creditability_count, "\t", amount_total)


