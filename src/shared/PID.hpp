#pragma once

/**
 * \brief A simple PID controller
 */
class PID{
  public:
    /**
     * \brief Construct the PID object with the given constants
     * \param kP proportional gain constant
     * \param kI integral gain constant
     * \param kD derivative gain constant
     * \param feedForward true if the PID controller should be feed-forward
     */
    PID(float kP, float  kI, float kD, bool feedForward);

    /**
     * \brief Set the setpoint of the controller
     * \param value Value to set the setpoint to
     * \param doWrap This should probably go somewhere else, but if true, then the controller will do normalize error to the range (-180, 180], used for controlling angle
     */
    void set(float setPoint);

    /** this returns an int because motor speeds can't be more precise than an int after scaling */
    int run(float value, bool doWrap = false);

    /** 
     * \brief determine whether or not the controlled value is 'stopped'
     * This is checked by determining if the current error and the setpoint are both small
     * \return true if the controlled value is 'stopped', false otherwise
     */
    bool stopped();

    float kP, kI, kD;
    float  lastError,
           iTerm;
    long lastUpdateTime;

    float setPoint;
    int output;

    bool feedForward = false;
};
