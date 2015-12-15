#pragma once
#include "Arduino.h"

/**
 * \brief A simple fixed size stack
 */
template<typename T, int SIZE>
class Stack {
public:
    Stack() : size(0) {}

    /**
     * \brief Check if the stack is empty
     * \return true if the stack is empty, false otherwise
     */
    bool empty() {
        return size <= 0;
    }

    /**
     * \brief Push a value onto the stack
     * If you push when the stack is full, this implementation
     * will overwrite the last value in the stack
     * \param t the value to push
     */
    void push(T t) {
        values[size] = t;
        if(size < SIZE) { size++; }
        else { Serial.println("STACK FULL!!!"); }
    }

    /**
     * \brief Pop a value from the stack
     * If you pop when the stack is empty, this implementation
     * will return garbage
     * \return The poppped value
     */
    T pop() {
        if(!empty()) { size--; }
        else { Serial.println("STACK EMPTY!!!"); }
        return values[size];
    }
private:
    size_t size;
    T values[SIZE];
};
