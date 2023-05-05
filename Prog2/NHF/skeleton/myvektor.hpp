//
// Created by Jajecnik Marcell on 2023. 05. 04..
//

#ifndef SKELETON_MYVEKTOR_HPP
#define SKELETON_MYVEKTOR_HPP

#include <iostream>
#include <cstring>
#include <stdexcept>

template<typename T>
class MyVector {
private:
    T* m_buffer; // pointer to the start of the data buffer

    size_t m_capacity; // the current capacity of the buffer

    size_t m_size; // the current number of elements in the buffer

    // Reserve additional memory for the vector
    void reserve(size_t new_capacity) {
        if (new_capacity <= m_capacity) {
            return;
        }
        T* new_buffer = new T[new_capacity];
        memcpy(new_buffer, m_buffer, m_size * sizeof(T));
        delete[] m_buffer;
        m_buffer = new_buffer;
        m_capacity = new_capacity;
    }

public:
    // Constructor
    MyVector(): m_capacity(10), m_size(0) {
        m_buffer = new T[m_capacity];
    }

    // Push back element to vector
    void push_back(T value) {
        if (m_size == m_capacity) {
            reserve(m_capacity * 2);
        }
        m_buffer[m_size] = value;
        m_size++;
    }

    // Return number of elements in the vector
    size_t size() const {
        return m_size;
    }

    // Return the current capacity of the vector
    size_t capacity() const {
        return m_capacity;
    }

    // Remove an element at a given position
    void erase(size_t pos) {
        if (pos >= m_size) {
            return;
        }
        for (size_t i = pos; i < m_size - 1; i++) {
            m_buffer[i] = m_buffer[i + 1];
        }
        m_size--;
    }

    // Remove the last element
    void pop_back() {
        if (m_size > 0) {
            m_size--;
        }
    }

    T& operator[](size_t i) {
        if ((i<0 || i>=m_size)) throw std::range_error("Index error");
        return m_buffer[i];
    }
    const T& operator[](size_t i) const {
        if ((i<0 || i>=m_size)) throw std::range_error("Index error");
        return m_buffer[i];
    };
    // Destructor
    ~MyVector() {
        delete[] m_buffer;
    }
};


#endif //SKELETON_MYVEKTOR_HPP
