// In Java, overriding is much simpler and doesn't require the virtual keyword.
// Just provide the child class with the same named function as the parent.

// Compile using javac Virtual.java
// and run using java Virtual

class Animal {

    String type;

    // Our virtual function. We don't use keywords in Java
    public String getType() { return type; }

    public Animal() { type = "Animal"; } 
}

class Dog extends Animal {

    // Our virtual function. We don't use keywords in Java
    public String getType() { return type; }

    public Dog() { type = "Dog"; } 
}

class Cat extends Animal {

    // Our virtual function. We don't use keywords in Java
    public String getType() { return type; }

    public Cat() { type = "Cat"; } 
}

public class Virtual {
    public static void main(String [] args)
    {
        Animal animal = new Animal();
        Animal dog = new Dog();
        Animal cat = new Cat();

        Animal animals[] = { animal, dog, cat };

        // Prints "Animal Dog Cat"
        for (Animal a : animals)
            System.out.print(a.getType() + " ");
        System.out.println();
    }
}
