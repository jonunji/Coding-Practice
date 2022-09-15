#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// We will use a linked list to represent our stack
typedef struct Node {
    int data;
    struct Node* prev;
} Node;

Node* top = NULL;


// Creates a node with the given data
Node* createNode(int data)
{
    Node* temp = malloc(sizeof(Node));
    if (temp == NULL)
        return NULL;

    // Set our default values
    temp->data = data;
    temp->prev = NULL;

    return temp;
}

// Returns 1 if the stack is empty, 0 otherwise
int empty()
{
    return top == NULL;
}

// Returns the value at the top of the stack
int peek()
{
    return top ? top->data : INT_MIN;
}

// Pushes an element onto the stack
void push(int data)
{
    // If our stack is empty
    if (empty())
    {
        top = createNode(data);
        return;
    }

    // Create our new node
    Node* temp = createNode(data);
    if (temp == NULL) return;

    // Link new and old top
    temp->prev = top;
    top = temp;
}

// Gets rid of and returns the topmost element
int pop()
{
    int data;

    if (top == NULL) return INT_MIN;

    // Set the new top node
    Node* temp = top;
    top = top->prev;

    data = temp->data;

    // Get rid of the old top
    free(temp);

    return data;
}

// Prints and pops the whole stack
void print()
{
    printf("Printing: ");
    while (!empty())
        printf("%d ", pop());

    printf("\n");
}

int main()
{
    for (int i = 0; i <= 5; i++)
        push(i);
    
    printf("Top: %d\n", peek());

    print();
}