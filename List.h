#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstdlib>

template<typename T>
class List {
private:
    static const int MAX_ARR = 100; // Adjust as necessary
    T* elements;
    int numElements;

public:
    List() : numElements(0) {
        elements = new T[MAX_ARR];
    }

    ~List() {
        delete[] elements;
    }

    List& operator+=(const T& item) {
        if (numElements >= MAX_ARR) {
            std::cerr << "List is full, cannot add more items." << std::endl;
        } else {
            elements[numElements++] = item;
        }
        return *this;
    }

    List& operator-=(const T& item) {
        int index = -1;
        for (int i = 0; i < numElements; ++i) {
            if (elements[i] == item) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            for (int j = index; j < numElements - 1; ++j) {
                elements[j] = elements[j + 1];
            }
            --numElements;
        } else {
            std::cerr << "Item not found." << std::endl;
        }
        return *this;
    }

    T& operator[](int index) {
        if (index < 0 || index >= numElements) {
            std::cerr << "Index out of bounds" << std::endl;
            exit(1);
        }
        return elements[index];
    }
	void clear() {
        numElements = 0;
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= numElements) {
            std::cerr << "Index out of bounds" << std::endl;
            exit(1);
        }
        return elements[index];
    }

    int getSize() const {
        return numElements;
    }

    bool isFull() const {
        return numElements >= MAX_ARR;
    }
};

#endif // LIST_H
