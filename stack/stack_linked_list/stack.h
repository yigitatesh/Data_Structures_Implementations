#ifndef STACK_H
#define STACK_H

#include <iostream>

//Node definition
template <typename TN>
class Node {
public:
    TN data;
    Node<TN> * next;

    Node();  
};

template <typename TN>
Node<TN>::Node() {
    next = NULL;
}

//Stack definition
template <typename TS>
class Stack {
public:
    Node<TS> * head;

    Stack();
    ~Stack();

    void push(TS);
    TS pop();
    TS peek();
    bool is_empty();
    void print_stack();
};

template <typename TS>
Stack<TS>::Stack() {
    head = NULL;
}

template <typename TS>
Stack<TS>::~Stack() {
    Node<TS> *traverse;
    while (head != NULL) {
        traverse = head;
        head = head->next;
        delete traverse;
    }
}

template <typename TS>
void Stack<TS>::push(TS new_data) {
    Node<TS> * temp = new Node<TS>;
    temp->data = new_data;
    temp->next = head;
    head = temp;
}

template <typename TS>
TS Stack<TS>::pop() {
    Node<TS> * last;
    last = head;
    head = head->next;
    return last->data;
}

template <typename TS>
TS Stack<TS>::peek() {
    return head->data;
}

template <typename TS>
bool Stack<TS>::is_empty() {
    return head == NULL;
}

template <typename TS>
void Stack<TS>::print_stack() {
    Node<TS> * traverse;
    traverse = head;
    std::cout << "Stack:" << std::endl;
    while (traverse) {
        std::cout << traverse->data << std::endl;
        traverse = traverse->next;
    }
    std::cout << std::endl;
}

#endif