// The implementation of our .hpp file
// Testing the functions and some edge cases

#include "linkedlists.hpp"

int main(void) 
{
    // Create an empty list
    LinkedList<> list;
    list.print();
    cout << "Size is: " << list.size() << endl << endl; // 0


    // Add to empty list
    list.add(new Node<int>(0));
    list.print();
    cout << "Size is: " << list.size() << endl << endl; // 1

    // Adds nodes with data 1-10
    for (int i = 1; i <= 10; i++)
        list.add(new Node<int>(i));
    list.print();                                       // "0 1 2 3 4 5 6 7 8 9 10"
    cout << "Size is: " << list.size() << endl << endl; // 11


    cout << "Front: " << list.getFront() << endl;       // 0
    cout << "Back: " << list.getBack() << endl << endl; // 10


    // Removes node at index = 2
    list.remove(2);
    list.print();                                       // "0 1 3 4 5 6 7 8 9 10"
    cout << "Size is: " << list.size() << endl << endl; // 10

    // Adds 3 nodes to the end of the list with value "4"
    for (int i = 0; i < 3; i++)
        list.add(new Node<int>(4));
    list.print();                                       // "0 1 3 4 5 6 7 8 9 10 4 4 4"
    

    cout << endl << "There are " << list.count(4) << " instances of \"4\" in the list." << endl;

    // Removes all instances of the number 4
    list.removeVal(4);
    list.print();                                       // "0 1 3 5 6 7 8 9 10"
    cout << "Size is: " << list.size() << endl << endl; // 9


    // Removes position 8 from the list
    list.remove(8);
    list.print();                                       // "0 1 3 5 6 7 8 9"
    cout << "Size is: " << list.size() << endl << endl; // 8


    cout << "Front: " << list.getFront() << endl;       // 0
    cout << "Back: " << list.getBack() << endl << endl; // 9


    // Removes node from front of list
    list.removeFront();
    list.print();                                       // "1 3 5 6 7 8 9"
    cout << "Size is: " << list.size() << endl << endl; // 7


    cout << "Front: " << list.getFront() << endl;       // 1
    cout << "Back: " << list.getBack() << endl << endl; // 9


    // Removes node from back of list
    list.removeBack();
    list.print();                                       // "1 3 5 6 7 8"
    cout << "Size is: " << list.size() << endl << endl; // 6


    cout << "Front: " << list.getFront() << endl;       // 1
    cout << "Back: " << list.getBack() << endl << endl; // 8


    // Gets rid of everything
    list.clear();
    cout << "Size is: " << list.size() << endl << endl; // 0

    // Adding using data rather than nodes
    list.add(2);
    list.addFront(1);
    list.print();                                       // 1 2
    cout << "Size is: " << list.size() << endl << endl; // 2

    cout << "Front: " << list.getFront() << endl;       // 1
    cout << "Back: " << list.getBack() << endl << endl; // 2

    LinkedList<string> strList("big");
    strList.add("world!");
    strList.addFront("Hello,");
    strList.print();                                        // Hello, big world!

    cout << "Size is: " << strList.size() << endl << endl;  // 3

    cout << "Front: " << strList.getFront() << endl;        // Hello,
    cout << "Back: " << strList.getBack() << endl << endl;  // world!

    return 0;
}