#for example.txt
import fileinput
for line in fileinput.input():
 data = line.strip().split("\t")
 if len(data)==6:
    date, time, location, item, cost, payment = data
    print("{0}\t{1}".format(location, cost))

#for heart_disease_data.csv
import fileinput
for line in fileinput.input():
 data = line.strip().split(",")
if len(data) == 14:
   age, sex, cp, trestbps, chol, fbs, restecg, thalach,exang, oldpeak, slope, ca, thal, target = data
   print ("{0}\t{1}".format(age, chol))

#for covid_19_data.csv
# import fileinput
# for line in fileinput.input():
#  data = line.strip().split(",")
# if len(data) == 8:
#     SNo, ObservationDate, Province_State, Country_Region,Last_Update, Confirmed, Deaths, Recovered = data
#     print ("{0}\t{1}".format(Province_State, Confirmed))

#for german-credit.csv
# import fileinput
# for line in fileinput.input():
#  data = line.strip().split(",")
#  if len(data) == 3:
#    Creditability, CreditAmount, DurationOfCreditInMonths = data
#    DurationOfCreditInMonths =str(DurationOfCreditInMonths).replace("'",'')
#    DurationOfCreditInMonths =str(DurationOfCreditInMonths).replace('"','')
#    if DurationOfCreditInMonths == 'DurationOfCreditInMonths':
#      pass
#    else:
#        print ("{0}\t{1}".format(Creditability, DurationOfCreditInMonths))


