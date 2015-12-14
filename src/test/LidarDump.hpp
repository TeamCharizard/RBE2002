#include "../Robot.hpp"

class LidarDump {
public:
    void setup();
    void loop();
private:
    Robot* charizard;
    bool reading;
    int count;
};
