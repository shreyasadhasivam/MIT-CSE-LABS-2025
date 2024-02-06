for line in fileinput.input():
    data = line.strip().split("\t")
    current_key, current_value = data
    sum += int(current_value)

print("Number of odd numbers is:", sum)
