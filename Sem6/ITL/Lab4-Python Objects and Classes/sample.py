class MyNewClass: 
 '''This is a docstring. I have created a new class''' 
pass

class Person: 
    "This is a person class" 
    age = 10
    def greet(self): 
        print('Hello') 
# Output: 10
print(Person.age) 
# Output: <function Person.greet>
print(Person.greet)
print(Person.__doc__)
harry = Person()
print(harry.greet) 
# Calling object's greet() method
# Output: Hello
harry.greet()

class Human:
    species = "H.Sapiens"

    def __init__(self,name):
      self.name = name
      self._age = 0
    def say(self, msg): 
        print("{name}: {message}".format(name=self.name, message=msg)) 
 # Another instance method
    def sing(self): 
        return 'yo... yo... microphone check... one two... one two...'
    @classmethod
    def get_species(cls): 
        return cls.species
    @staticmethod
    def grunt():
       return "*grunt*"
    @property
    def age(self):
       return self._age
    @age.setter
    def age(self,age):
       self._age = age
    @age.deleter 
    def age(self):
       del self._age
if __name__ == '__main__': 
 # Instantiate a class
    i = Human(name = "Ian") 
    i.say("hi") # "Ian: hi"
    j = Human("Joel") 
    j.say("hello") # "Joel: hello"
 # i and j are instances of type Human, or in other words: they are Human objects
 # Call our class method
    i.say(i.get_species()) # "Ian: H. sapiens"
 # Change the shared attribute
    Human.species = "H. neanderthalensis"
    i.say(i.get_species()) # => "Ian: H. neanderthalensis"
    j.say(j.get_species()) # => "Joel: H. neanderthalensis"
 # Call the static method 
    print(Human.grunt()) # => "*grunt*"
 # Cannot call static method with instance of object
 
 # because i.grunt() will automatically put "self" (the object i) as an argument
    print(i.grunt()) # => TypeError: grunt() takes 0 positional arguments but 1 was given
 # Update the property for this instance
    i.age = 42 # Get the property
    i.say(i.age) # => "Ian: 42"
    j.say(j.age) # => "Joel: 0" 
# Delete the property 
    del i.age

