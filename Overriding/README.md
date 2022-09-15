# Overriding

Overriding is a way for a parent class and child class to share a function name.
With each language, the way it is done is slightly different, but the function is the same.

If we declare a child, we want it's respective function to run.
If we have a parent, we may also want a general function which applies to the larger category.

This is the structure of our classes:

* Animal
    * Dog
    * Cat

We want the Dog and Cat to run their respective functions, but still, if we have an Animal, still to run their respective function. But we also want to use the same function name for simplicity for the function caller.

Additional Readings:
https://www.geeksforgeeks.org/function-overloading-vs-function-overriding-in-cpp/
https://www.geeksforgeeks.org/overriding-in-java/
https://www.geeksforgeeks.org/method-overriding-in-python/