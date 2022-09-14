// Practicing the keyword "virtual" in C++
// Compile using g++ -o virtual.exe virtual.cpp
// and run using ./virtual.exe

// Virtual allows a child class to use the intended function instead of a parent function.
// This is how we achieve "Overriding" in C++

#include <iostream>

using namespace std;

class Animal {
private:
    string type;

public:

    // Returns the type of animal
    virtual string getType() { return type; }

    string getType2() { return type; }

    // constructor for our animal
    Animal() : type("Animal") {}
};


class Dog : public Animal {
private:
    string type;

public:
    // Returns the type of animal
    // We can choose to use or not to use the keyword "override"
    string getType() override { return type; }

    // A test to see that this will indeed not override parent function 
    string getType2() { return type; }

    Dog() : type("Dog") {}
};


class Cat : public Animal {
private:
    string type;

public:
    // Returns the type of animal
    // We can choose to use or not to use the keyword "override"
    string getType() { return type; }

    // A test to see that this will indeed not override parent function 
    string getType2() { return type; }

    Cat() : type("Cat") {}
};

int main(void) 
{
    Animal* animal = new Animal();
    Animal* dog = new Dog();
    Animal* cat = new Cat();

    Animal* animalArr[3] = {animal, dog, cat};

    // prints "Animal Dog Cat"
    for (Animal* animal : animalArr)
        cout << animal->getType() << " ";
    cout << endl;

    // prints "Animal Animal Animal"
    for (Animal* animal : animalArr)
    {
        cout << animal->getType2() << " ";
        
        // Get rid of that space!
        delete animal;
    }
    cout << endl;

    return 0;
}