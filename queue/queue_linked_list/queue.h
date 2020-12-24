#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

//Node definition
template <typename TN>
class Node {
public:
    TN data;
    Node<TN> * next;

    Node();
    ~Node();
};

template <typename TN>
Node<TN>::Node() {
    next = NULL;
}

template <typename TN>
Node<TN>::~Node() {}

//Queue definition
template <typename TQ>
class Queue {
public:
    Node<TQ> * front, * back;

    Queue();
    ~Queue();

    void enqueue(TQ);
    TQ dequeue();
    bool is_empty();

    void print_queue();
};

template <typename TQ>
Queue<TQ>::Queue() {
    front = NULL;
    back = NULL;
}

template <typename TQ>
Queue<TQ>::~Queue() {
    Node<TQ> * traverse;
    while (front) {
        traverse = front;
        front = front->next;
        delete traverse;
    }
}

template <typename TQ>
void Queue<TQ>::enqueue(TQ new_data) {
    Node<TQ> * temp = new Node<TQ>;
    temp->data = new_data;
    temp->next = NULL;

    if (front == NULL) {
        front = temp;
        back = temp;
    }
    else {
        back->next = temp;
        back = temp;
    }
} 

template <typename TQ>
TQ Queue<TQ>::dequeue() {
    if (front == NULL) {
        std::cerr << "No element in queue";
        std::exit(1);
    }
    TQ temp;
    Node<TQ> * temp_node;
    temp = front->data;
    temp_node = front;
    front = front->next;
    delete temp_node;
    return temp;
}

template <typename TQ>
bool Queue<TQ>::is_empty() {
    return front == NULL;
}

template <typename TQ>
void Queue<TQ>::print_queue() {
    Node<TQ> * traverse;
    traverse = front;
    std::cout << "Queue: ";
    while (traverse) {
        std::cout << traverse->data << " ";
        traverse = traverse->next;
    }
    std::cout << std::endl;
}

#endif