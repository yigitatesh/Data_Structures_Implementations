//queue on a circular array
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template <typename T>
class Queue {
public:
    //add to back, remove from front
    //front is index of first element
    //back is index of last element
    int front, back, capacity;
    T *arr;

    Queue();
    ~Queue();

    void enqueue(T);
    T dequeue();
    bool is_empty();
    bool is_full();
    void increase_size();

    void print_queue();
    void print_with_spaces();
    void fill_with(T);
};

template <typename T>
Queue<T>::Queue() {
    front = -1;
    back = -1;
    capacity = 4;
    arr = new T[capacity];
}

template <typename T>
Queue<T>::~Queue() {
    delete[] arr;
}

template <typename T>
void Queue<T>::enqueue(T new_data) {
    if (this->is_full()) {
        this->increase_size();
    }

    if (this->is_empty()) {
        front = 0;
        back = 0;
    }
    else {
        back = (back + 1) % capacity;
    }
    arr[back] = new_data;
}

template <typename T>
T Queue<T>::dequeue() {
    if (this->is_empty()) {
        std::cerr << "No element to dequeue" << std::endl;
        std::exit(1);
    }
    else if (front == back) { //one element
        T temp = arr[front];
        ////////
        //arr[front] = -1;
        front = -1;
        back = -1;
        return temp;
    }
    else {
        ////////
        //arr[front] = -1;
        T temp = arr[front];
        front = (front + 1) % capacity;
        return temp;
    }
}

template <typename T>
bool Queue<T>::is_empty() {
    return front == -1 & back == -1;
}

template <typename T>
bool Queue<T>::is_full() {
    return (back + 1) % capacity == front;
}

template <typename T>
void Queue<T>::increase_size() {
    T * temp = new T[capacity*2];
    //fill with -1 for visualization
    /*for (int i=0; i<capacity*2; i++) {
        temp[i] = -1;
    }*/
    if (front < back) {
        //copy as it is
        for (int i=front; i<=back; i++) {
            temp[i] = arr[i];
        }
    }
    else if (back < front) {
        //shift after front to end of array
        for (int i=0; i<=back; i++) {
            temp[i] = arr[i];
        }
        for (int i=front; i<capacity; i++) {
            temp[i+capacity] = arr[i];
        }
        front += capacity;
    }
    capacity *= 2;
    delete[] arr;
    arr = temp;
}

template <typename T>
void Queue<T>::print_queue() {
    std::cout << "Queue: ";
    for (int i=front; i != back; i = (i+1)%capacity) {
        std::cout << arr[i] << " ";
    }
    if (back != -1) {
        std::cout << arr[back];
    }
    std::cout << std::endl;
}

template <typename T>
void Queue<T>::print_with_spaces() {
    for (int i=0; i<capacity; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void Queue<T>::fill_with(T data) {
    for (int i=0; i<capacity; i++) {
        arr[i] = data;
    }
}

#endif