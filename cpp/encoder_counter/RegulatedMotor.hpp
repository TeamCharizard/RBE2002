#pragma once

#include "Encoder.hpp"

class RegulatedMotor : public DriveMotor{
  Encoder encoder;
};
