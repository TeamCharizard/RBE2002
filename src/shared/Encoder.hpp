#pragma once
#include <Arduino.h>

/** \brief Template class for encoder counting.
 * It takes the two ports as template arguments
 * and uses simple quadrature counting */
template<int port1, int port2>
class Encoder {
public:
    static void setup() {
        pinMode(port1, INPUT_PULLUP);
        pinMode(port2, INPUT_PULLUP);
        attachInterrupt(digitalPinToInterrupt(port1), &Encoder<port1, port2>::isr_a, CHANGE);
        attachInterrupt(digitalPinToInterrupt(port2), &Encoder<port1, port2>::isr_b, CHANGE);
        count = 0;
        last_a = digitalRead(port1);
        last_b = digitalRead(port2);
    }

    static int read(bool reset = false) {
        int c = count;
        if(reset) { count = 0; }
        return c;
    }
private:
    static void isr_a() {
        int a = digitalRead(port1);
        if(last_b) {
            if(a) {
                count++;
            } else {
                count--;
            }
        } else {
            if(a) {
                count--;
            } else {
                count++;
            }
        }
        last_a = a;
    }

    static void isr_b() {
        int b = digitalRead(port2);
        if(last_a) {
            if(b) {
                count--;
            } else {
                count++;
            }
        } else {
            if(b) {
                count++;
            } else {
                count--;
            }
        }
        last_b = b;
    }

    static int last_a;
    static int last_b;
    static int count;
};

template<int a, int b>
int Encoder<a,b>::count = 0;
template<int a, int b>
int Encoder<a,b>::last_a = 0;
template<int a, int b>
int Encoder<a,b>::last_b = 0;
