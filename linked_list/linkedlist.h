#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

//Node definition
template <typename TN>
class Node {
public:
    TN data;
    Node<TN> * next;
    Node<TN> * prev;

    Node();
    ~Node();
};

template <typename TN>
Node<TN>::Node() {
    next = NULL;
    prev = NULL;
}

template <typename TN>
Node<TN>::~Node() {
    delete &data;
}

//Linked List definition
template <typename TL>
class LinkedList {
public:
    int size;
    Node<TL> * head;
    Node<TL> * tail;

    LinkedList();
    ~LinkedList();

    void append(TL);
    void pushleft(TL);
    TL pop();
    TL popleft();
    void insert(int, TL);
    void remove(int);
    void del(TL);

    bool is_empty();
    void print();
    bool contains(TL);
    int count(TL);
    void reverse();
};

template <typename TL>
LinkedList<TL>::LinkedList() {
    head = NULL;
    tail = NULL;
    size = 0;
}

template <typename TL>
LinkedList<TL>::~LinkedList() {
    Node<TL> * traverse;
    while (head != NULL) {
        traverse = head;
        head = head->next;
        delete traverse;
    }
}

template <typename TL>
void LinkedList<TL>::append(TL new_data) {
    Node<TL> * temp = new Node<TL>;
    temp->data = new_data;

    if (head == NULL) {
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        tail = temp;
    }
    else {
        temp->next = NULL;
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    size++;
}

template <typename TL>
void LinkedList<TL>::pushleft(TL new_data) {
    Node<TL> * temp = new Node<TL>;
    temp->data = new_data;

    if (head == NULL) {
        temp->prev = NULL;
        temp->next = NULL;
        head = temp;
        tail = temp;
    }
    else {
        temp->next = head;
        temp->prev = NULL;
        head->prev = temp;
        head = temp;
    }
    size++;
}

template <typename TL>
TL LinkedList<TL>::pop() {
    if (head == NULL) {
        std::cerr << "No element" << std::endl;
    }

    TL temp;
    temp = tail->data;
    Node<TL> * temp_node;

    if (head == tail) {
        temp_node = head;
        head = NULL;
        tail = NULL;
        delete temp_node;
    }

    else {
        temp_node = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp_node;
    }
    size--;

    return temp;
}

template <typename TL>
TL LinkedList<TL>::popleft() {
    if (head == NULL) {
        std::cerr << "No element" << std::endl;
    }

    TL temp;
    temp = head->data;
    Node<TL> * temp_node;

    if (head == tail) {
        temp_node = head;
        head = NULL;
        tail = NULL;
        delete temp_node;
    }
    else {
        temp_node = head;
        head = head->next;
        head->prev = NULL;
        delete temp_node;
    }
    size--;

    return temp;
}

template <typename TL>
void LinkedList<TL>::insert(int index, TL new_data) {
    if (index < 0 || index > size) {
        std::cerr << "Index out of range" << std::endl;
    }

    if (index == 0) { //insert as head
        this->pushleft(new_data);
        return;
    }
    else if (index == size) { //append
        this->append(new_data);
        return;
    }
    
    Node<TL> * temp = new Node<TL>;
    temp->data = new_data;
    Node<TL> * traverse;
    int i;
    
    if (index <= size / 2) { //traverse from head
        i = 0;
        traverse = head;
        while (i < index) {
            traverse = traverse->next;
            i++;
        }

        temp->next = traverse;
        temp->prev = traverse->prev;
        (temp->prev)->next = temp;
        traverse->prev = temp;
    }
    else { //traverse from tail
        i = size-1;
        traverse = tail;
        while (i > index) {
            traverse = traverse->prev;
            i--;
        }

        temp->next = traverse;
        temp->prev = traverse->prev;
        (temp->prev)->next = temp;
        traverse->prev = temp;
    }
    size++;
}

template <typename TL>
void LinkedList<TL>::remove(int index) {
    if (index < 0 || index >= size) {
        std::cerr << "Index out of range" << std::endl;
    }

    if (index == 0) {
        this->popleft();
        return;
    }
    else if (index == size-1) {
        this->pop();
        return;
    }

    Node<TL> * traverse;
    int i;
    if (index <= size / 2) { //traverse from head
        i = 0;
        traverse = head;
        while (i < index) {
            traverse = traverse->next;
            i++;
        }

        traverse->prev->next = traverse->next;
        traverse->next->prev = traverse->prev;
        delete traverse;
    }
    else { //traverse from tail
        i = size-1;
        traverse = tail;
        while (i > index) {
            traverse = traverse->prev;
            i--;
        }

        traverse->prev->next = traverse->next;
        traverse->next->prev = traverse->prev;
        delete traverse;
    }
    size--;
}

template <typename TL>
void LinkedList<TL>::del(TL data) {
    if (this->is_empty()) {
        std::cerr << "No element" << std::endl;
    }

    Node<TL> * traverse;
    traverse = head;
    bool found = false;
    while (traverse != NULL) {
        if (traverse->data == data) {
            found = true;
            break;
        }
        traverse = traverse->next;
    }

    if (!found) {
        return;
    }
    if (head == tail) {
        head = NULL;
        tail = NULL;
        delete traverse;
    }
    else if (traverse == head) {
        head = traverse->next;
        head->prev = NULL;
        delete traverse;
    }
    else if (traverse == tail) {
        tail = traverse->prev;
        tail->next = NULL;
        delete traverse;
    }
    else {
        traverse->prev->next = traverse->next;
        traverse->next->prev = traverse->prev;
        delete traverse;
    }
    size--;
}

template <typename TL>
bool LinkedList<TL>::is_empty() {
    return head == NULL;
}

template <typename TL>
void LinkedList<TL>::print() {
    Node<TL> * traverse;
    traverse = head;
    while (traverse != NULL) {
        std::cout << traverse->data << " ";
        traverse = traverse->next;
    }
    std::cout << std::endl;
}

template <typename TL>
bool LinkedList<TL>::contains(TL data) {
    Node<TL> * traverse;
    traverse = head;
    while (traverse != NULL) {
        if (traverse->data == data) {
            return true;
        }
        traverse = traverse->next;
    }
    return false;
}

template <typename TL>
int LinkedList<TL>::count(TL data) {
    Node<TL> * traverse;
    traverse = head;
    int cnt = 0;
    while (traverse != NULL) {
        if (traverse->data == data) {
            cnt++;
        }
        traverse = traverse->next;
    }
    return cnt;
}

template <typename TL>
void LinkedList<TL>::reverse() {
    Node<TL> * left;
    Node<TL> * right;
    left = head;
    right = tail;
    int i=0, j=size-1;
    TL temp_data;

    while (i < j) {
        temp_data = left->data;
        left->data = right->data;
        right->data = temp_data;
        left = left->next;
        right = right->prev;
        i++;
        j--;
    }
}

#endif