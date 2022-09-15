#include <iostream>
#include <string>

using namespace std;

// A node has two things:
// - Some data
// - A next node within the list

// A node's default data is an integer
template <class T = int>
struct Node {
    T data;
    Node* next;

    // Constructor for data + next node
    Node(T data, Node* next)
    {
        this->data = data;
        this->next = next;
    }

    // Constructor for only data
    Node(T data)
    {
        this->data = data;
        next = nullptr;
    }

    // Default constructor
    Node()
    {
        // When using templates, {} inserts the default value
        data = {};
        next = nullptr;
    }
};

// Template linked list with default of ints
template <class T = int>
class LinkedList {
private:
    Node<T>* _head;
    Node<T>* _tail;
    int _size = 0;

    // Sets the head and tail node 
    // Used in edge cases when we have no head
    void setHeadAndTail(Node<T>* node)
    {
        _size++;

        _head = node;
        _tail = _head;

        cout << "Set head and tail node to \"" << node->data << "\"." << endl;
    }

public:

    LinkedList() 
    { 
        cout << "Created Linked List with default values!" << endl;
        _head = nullptr; 
        _tail = nullptr; 
    }
    
    // Given a head node, create a linked list
    LinkedList(Node<T>* head) 
    { 
        cout << "Created Linked List with given NODE: " << head->data << endl;

        this->_head = head; 
        _tail = head; 

        _size = 1;
    }

    // Given data, create a linked list
    LinkedList(T data) 
    { 
        cout << "Created Linked List with given DATA: " << data << endl;

        this->_head = new Node<T>(data); 
        _tail = _head;

        _size = 1; 
    }

    // Make sure to get rid of all the nodes in the list when deconstructed
    ~LinkedList()
    {
        clear();
    }

    // Functions to get head, tail, and size
    T getFront() { return this->_head->data; }
    T getBack() { return this->_tail->data; }
    int size() { return this->_size; }

    // Add a node to the end of the list 
    void add(Node<T>* node)
    {
        // if we have no nodes left, just set this as our head
        if (!_head)
        {
            setHeadAndTail(node);
            return;
        }
        
        // update the size
        _size++;

        // Use and update the tail pointer
        _tail->next = node;
        _tail = node;

        cout << "Added \"" << node->data <<"\" to end of list." << endl;
    }
    
    // Add a node with given data to the end of the list
    void add(T data)
    {
        add(new Node<T>(data));
    }

    // Add a node to the front of the list
    void addFront(Node<T>* node)
    {
        _size++;

        node->next = _head;
        _head = node;

        cout << "Added \"" << node->data <<"\" to front of list." << endl;
    }

    // Add a node with given data to the front of the list
    void addFront(T data)
    {
        addFront(new Node<T>(data));
    }

    // Add a node at a specified index
    void add(Node<T>* node, int i)
    {
        // Just saved to print later
        int index = i;

        // special case of adding to the front
        if (i == 0)
        {
            addFront(node);
            return;
        }       

        // if we have no nodes left, just set this as our head
        if (!_head || i < 0)
        {
            if (i < 0) throw invalid_argument("LinkedList(Insert): index out of bounds!");
            else setHeadAndTail(node);

            return;
        }

        // update the size
        _size++;

        Node<T>* curr = _head;
        // Find the index/next available spot
        while (curr->next && --i > 0) { curr = curr->next; }

        // connect the nodes!
        node->next = curr->next;
        curr->next = node;
        // If the index is at the tail, we have a new tail
        if (curr == _tail) _tail = node;

        cout << "Inserted \"" << node->data <<"\" at position: " << index << "." << endl;
    }

    // Add a node with given data at a specified index
    void add(T data, int i)
    {
        add(new Node<T>(data), i);
    }

    // Removes the last node (AKA tail) from the list
    void removeBack()
    {
        // in case we removed everything
        if (!_head)
        {
            cout << "Nothing to remove." << endl;
            return;
        }

        _size--;

        // Locate and *destroy* the tail
        Node<T>* curr = _head;
        while (curr->next != _tail)
            curr = curr->next;

        delete _tail;

        // Set our new tail!
        _tail = curr;
        _tail->next = nullptr;

        cout << "Removed the last element." << endl;
    }

    // Removes the first node (AKA head) from the list
    void removeFront()
    {
        // Nothing to remove
        if (!_head) return;

        Node<T>* newHead = _head->next;
        delete _head;

        // update the size
        _size--;

        _head = newHead;

        cout << "Removed the first element" << endl;
    }

    // Remove a node at the specified index
    void remove(int i)
    {
        if (i < 0) throw invalid_argument("LinkedList(Remove): index out of bounds!");
        if (i == 0)
        {
            removeFront();
            return;
        } 

        // Used for printing at the end of the function
        int index = i;
        int removedData;

        // Find the index or arrive at the tail
        Node<T>* curr = _head;
        while (curr->next && --i > 0) { curr = curr->next; }

        if (i != 0) throw invalid_argument("LinkedList(Remove): index out of bounds!");

        // update the size
        _size--;

        Node<T>* temp = curr->next;
        curr->next = temp->next;

        removedData = temp->data;

        delete temp;

        // In case we remove the tail.
        if (!curr->next) _tail = curr;

        cout << "Removed \"" << removedData <<"\" at position: " << index << "." << endl;
    }

    // Removes all occurences of a specific value
    void removeVal(T data)
    {
        // sizes how many we remove
        int c = 0;

        Node<T>* curr = _head;
        while(curr->next)
        {
            // If we find the data were looking for, delete it
            if (curr->next->data == data)
            {
                Node<T>* temp = curr->next;
                curr->next = temp->next;

                delete temp;

                c++;
                _size--;
            }
            else
                curr = curr->next;
        }

        // In case we remove the tail.
        if (!curr->next) _tail = curr;

        cout << "Removed " << c << " instances of \"" << data << "\"" << endl;
    }

    // Counts the amount of times "data" appears in the list
    int count(T data)
    {
        int c = 0;

        Node<T>* curr = _head;
        while(curr)
        {
            // If we find the data were looking for, add 1 to the counter
            if (curr->data == data) c++;

            curr = curr->next;
        }

        return c;
    }

    // Removes everything in the list
    void clear()
    {
        Node<T>* next = _head;
        while(next)
        {
            Node<T>* curr = next;
            next = curr->next;

            delete curr;
        }

        // delete does not set head to nullptr, so we do this in case of clear called twice!
        _head = nullptr;
        _size = 0;
        cout << "Cleared the list." << endl;
    }

    // Prints everything in the list, from head to tail
    void print()
    {
        cout << "Printing list:" << endl;
        Node<T>* curr = _head;
        while (curr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << endl;
    }
};