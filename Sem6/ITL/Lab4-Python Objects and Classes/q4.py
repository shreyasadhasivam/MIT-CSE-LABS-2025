class IOString():
    def __init__(self):
        self.str1 = ""

    def get_String(self):
        self.str1 = input("Enter string: ")

    def print_String(self):
        print("String in UPPER:",self.str1.upper())

str1 = IOString()

str1.get_String()
str1.print_String()
