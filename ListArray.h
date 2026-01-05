#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <iostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {

private:
    T* arr;
    int max;
    int n;
    static const int MINSIZE = 2;

    void resize(int new_size) {
        T* newArr = new T[new_size];
        for (int i = 0; i < n; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        max = new_size;
    }

public:
    // Constructor
    ListArray() : max(MINSIZE), n(0) {
        arr = new T[max];
    }

    // Destructor
    ~ListArray() {
        delete[] arr;
    }

    // ===== Implementación de List<T> =====

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n)
            throw std::out_of_range("Posición inválida");

        if (n == max)
            resize(max * 2);

        for (int i = n; i > pos; --i)
            arr[i] = arr[i - 1];

        arr[pos] = e;
        ++n;
    }

    void append(T e) override {
        insert(n, e);
    }

    void prepend(T e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición inválida");

        T value = arr[pos];

        for (int i = pos; i < n - 1; ++i)
            arr[i] = arr[i + 1];

        --n;

        if (n > 0 && n <= max / 4 && max / 2 >= MINSIZE)
            resize(max / 2);

        return value;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición inválida");
        return arr[pos];
    }

    int search(T e) override {
        for (int i = 0; i < n; ++i) {
            if (arr[i] == e)
                return i;
        }
        return -1;
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }

    // ===== Operadores opcionales =====

    T operator[](int pos) const {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición inválida");
        return arr[pos];
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const ListArray<U>& list);
};

// Operador <<
template <typename U>
std::ostream& operator<<(std::ostream& os, const ListArray<U>& list) {
    os << "[";
    for (int i = 0; i < list.n; ++i) {
        os << list.arr[i];
        if (i < list.n - 1) os << ", ";
    }
    os << "]";
    return os;
}

#endif

