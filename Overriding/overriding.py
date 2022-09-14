# In python, it is similar to Java, where it is understood and no extra verbiage is necessary.

class Animal():

    def __init__(self):
        self.type = "Animal"

    # Our function to be overridden
    def getType(self):
        return self.type

class Dog(Animal):

    def __init__(self):
        self.type = "Dog"

    # Our overriding function
    def getType(self):
        return self.type

class Cat(Animal):

    def __init__(self):
        self.type = "Cat"

    # Our overriding function
    def getType(self):
        return self.type

# Driver code
animal = Animal()
dog = Dog()
cat = Cat()

# List of our animals
animals = [animal, dog, cat]

# Prints "Animal Dog Cat"
for a in animals:
    print(a.getType(), end=" ")