//array implementation of stack
#ifndef STACK_H
#define STACK_H

#include <iostream>

//Stack definition
template <typename TS>
class Stack {
public:
    //top keeps index of the element at the top of the stack
    int top, capacity;
    TS *arr;

    Stack();
    ~Stack();

    void push(TS);
    TS pop();
    TS peek();
    bool is_empty();
    void increase_size();
    void print_stack();
};

template <typename TS>
Stack<TS>::Stack() {
    top = -1;
    capacity = 10;
    arr = new TS[capacity];
}

template <typename TS>
Stack<TS>::~Stack() {
    delete[] arr;
}

template <typename TS>
void Stack<TS>::push(TS new_data) {
    if (top >= capacity-1) {
        this->increase_size();
    }
    top++;
    arr[top] = new_data;
}

template <typename TS>
TS Stack<TS>::pop() {
    TS temp = arr[top];
    top--;
    return temp;
}

template <typename TS>
TS Stack<TS>::peek() {
    return arr[top];
}

template <typename TS>
bool Stack<TS>::is_empty() {
    return top < 0;
}

template <typename TS>
void Stack<TS>::increase_size() {
    capacity *= 2;
    TS *temp = new TS[capacity];
    for (int i=0; i<=top; i++) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}

template <typename TS>
void Stack<TS>::print_stack() {
    std::cout << "Stack:" << std::endl;
    for (int i=top; i>=0; i--) {
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;
}

#endif