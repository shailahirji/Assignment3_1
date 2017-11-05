//============================================================================
// Name        :LinkedStack.h
// Author      :Shaila Hirji
// Version     :
// Copyright   : Your copyright notice
// Description : This header file contains the implementations of the standard LIFO- Stack functions
//               using LinkedList as the underlying structure.
//               The methods contained within the class are: Push(item), Pop(), Peek and isEmpty()
//============================================================================
#include <stddef.h>

/*
 * Struct defining a node
 */
template<class T>
struct node {
    T data;
    node<T> *next;
};


template<class T>
class LinkedStack {


    node<T> *top;//pointer to object at the top of the stack, LIFO

public:
    //provide function prototypes for a Stack here
    LinkedStack();

    void push(T &item);

    T pop();

    T peek();

    bool isEmpty();


    virtual ~LinkedStack();

};
//provide function implementations here


/*
 * Constructs a LinkedStack, sets top pointer to point to NULL
 */
template<class T>
LinkedStack<T>::LinkedStack() {
    top = NULL;
}


/*
 * Adds item to the top of the Stack
 * Item to be added is passed by reference
 */
template<class T>
void LinkedStack<T>::push(T &item) {

    node<T> *temp = new node<T>; //create temp pointer of type node
    temp->data = item;//store item into temp's data
    temp->next = top;//place item at the top of stack
    top = temp;//reassign top pointer to point to new item

}

/*
 * This method removes the item at the top of the stack
 * Returns the item at the top of the stack
 */
template<class T>
T LinkedStack<T>::pop() {

    node<T> *temp;
    while (top != NULL) {
        temp = top;//return value at top
        top = top->next;//re assign top to next value
        return temp->data;//delete this node?
    }

    return temp->data;//delete this node?
}

/*
 * This method retursn the item at the top of stack without remvoing it from Stack
 */
template<class T>
T LinkedStack<T>::peek() {
    return top->data;
}

/*
 * This method returns a boolean for whether or not the stack is empty
 */
template<class T>
bool LinkedStack<T>::isEmpty() {
    return (top == NULL);
}

/*
 * This method destroy's the stack by calling the pop() function
 */
template<class T>
LinkedStack<T>::~LinkedStack() {

    while (!isEmpty()) {
        pop();
    }

}