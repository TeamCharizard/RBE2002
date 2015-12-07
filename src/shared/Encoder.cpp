#include <stdio.h>
#include "Encoder.hpp"

Encoder::Encoder(int port1, int port2) :
    enc_a(port1), enc_b(port2),
    last_a(0), last_b(0),
    count(0)
{
    enc_a.dir(mraa::DIR_IN);
    enc_b.dir(mraa::DIR_IN);

    enc_a.isr(mraa::EDGE_BOTH, Encoder::isr_a, this);
    enc_b.isr(mraa::EDGE_BOTH, Encoder::isr_b, this);
}

void Encoder::isr_a(void* args) {
    Encoder* self = (Encoder*)args;
    int a = self->enc_a.read();
    if(self->last_b) {
        if(a) {
            self->count++;
        } else {
            self->count--;
        }
    } else {
        if(a) {
            self->count--;
        } else {
            self->count++;
        }
    }
    self->last_a = a;
}

void Encoder::isr_b(void* args) {
    Encoder* self = (Encoder*)args;
    int b = self->enc_b.read();
    if(self->last_a) {
        if(b) {
            self->count--;
        } else {
            self->count++;
        }
    } else {
        if(b) {
            self->count++;
        } else {
            self->count--;
        }
    }
    self->last_b = b;
}

int Encoder::read(bool reset) {
    int c = count;
    if(reset) { count = 0; }
    return c;
}

/*
int main(int argc, char** argv) {
    Encoder enc1(11, 8);

    while(true) {
        int c = enc1.read();
        printf("%d\n", c);
    }
}
*/
