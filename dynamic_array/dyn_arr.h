#ifndef DYN_ARR_H
#define DYN_ARR_H

#include <iostream>

template <typename T>
class dyn_arr {
public:
    int size;
    int capacity;
    T *arr;

    dyn_arr();
    ~dyn_arr();

    void append(T);
    void update(int, T);
    void insert(int, T);
    void remove(int);
    void del(T);
    void reverse();

    void increase_size();
    bool contains(T);
    int count(T);
    void print();
};

template <typename T>
dyn_arr<T>::dyn_arr() {
    size = 0;
    capacity = 2;
    arr = new T[capacity];
}

template <typename T>
dyn_arr<T>::~dyn_arr() {
    delete[] arr;
}

template <typename T>
void dyn_arr<T>::append(T new_data) {
    if (size == capacity) {
        this->increase_size();
    }
    arr[size] = new_data;
    size++;
}

template <typename T>
void dyn_arr<T>::update(int index, T new_data) {
    if (index < 0 || index >= size) {
        std::cerr << "Index out of range" << std::endl;
    }
    arr[index] = new_data;
}

template <typename T>
void dyn_arr<T>::insert(int index, T new_data) {
    if (index < 0 || index > size) {
        std::cerr << "Index out of range" << std::endl;
    }
    if (size == capacity) {
        this->increase_size();
    }
    //shift values on right to the right
    for (int i=size; i>index; i--) {
        arr[i] = arr[i-1];
    }
    arr[index] = new_data;
    size++;
}

template <typename T>
void dyn_arr<T>::remove(int index) {
    if (index < 0 || index >= size) {
        std::cerr << "Index out of range" << std::endl;
    }
    for (int i=index; i<size-1; i++) {
        arr[i] = arr[i+1];
    }
    size--;
}

template <typename T>
void dyn_arr<T>::del(T del_data) {
    int i;
    for (i=0; i<size; i++) {
        if (arr[i] == del_data) {
            this->remove(i);
            return;
        }
    }
}

template <typename T>
void dyn_arr<T>::reverse() {
    int left = 0, right = size-1;
    T temp;
    while (left < right) {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

template <typename T>
void dyn_arr<T>::increase_size() {
    capacity *= 2;
    T * temp = new T[capacity];
    for (int i=0; i<size; i++) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}

template <typename T>
bool dyn_arr<T>::contains(T data) {
    for (int i=0; i<size; i++) {
        if (arr[i] == data) {
            return true;
        }
    }
    return false;
}

template <typename T>
int dyn_arr<T>::count(T data) {
    int cnt = 0;
    for (int i=0; i<size; i++) {
        if (arr[i] == data) {
            cnt++;
        }
    }
    return cnt;
}

template <typename T>
void dyn_arr<T>::print() {
    for (int i=0; i<size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

#endif