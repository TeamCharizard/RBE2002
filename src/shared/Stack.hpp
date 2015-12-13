#pragma once
#include "Arduino.h"

template<typename T, int SIZE>
class Stack {
public:
    Stack() : size(0) {}
    bool empty() {
        return size > 0;
    }

    void push(T t) {
        if(size < SIZE) { size++; }
        else { Serial.println("STACK FULL!!!"); }
        values[size] = t;
    }

    T pop() {
        if(!empty()) { size--; }
        else { Serial.println("STACK EMPTY!!!"); }
        return values[size];
    }
private:
    size_t size;
    T values[SIZE];
};
