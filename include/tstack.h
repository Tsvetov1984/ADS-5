// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

#include <string>

template<typename T, int size>
class TStack {

private:
    T *data;
    int top;

    void resize(int nsize) {
        T *temp = new T[nsize];
        for (int i = 0; i < size; ++i) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        nsize = size;
    }

public:
    TStack() {
        data = new T[size];
        top = 0;
    }

    ~TStack() {
        delete[] data;
    }

    void push(T item) {
        if (top == size) {
            resize(2 * size);
        }
        data[top++] = item;
    }

    T pop() {
        if (top > 0) {
            return data[--top];
        } else {
            throw std::string("Empty");
        }
    }

    bool isEmpty() {
        return top == 0;
    }

    T get() {
        if (!isEmpty()) {
            return data[top - 1];
        }
    }
};

#endif  // INCLUDE_TSTACK_H_