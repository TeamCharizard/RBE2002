#include <mraa.hpp>

class Encoder {
public:
    Encoder(int port1, int port2);
    int read(bool reset = false);
private:
    mraa::Gpio enc_a;
    mraa::Gpio enc_b;
    static void isr_a(void* args);
    static void isr_b(void* args);
    int last_a;
    int last_b;
    int count;
};
