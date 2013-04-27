/*
DCMotor.h - Arduino Library for DC Motor
Created by MJC; Mikkel, Joakim & Casper
April 2013
*/

/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * MJC wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy us a beer in return.
 * /MJC; Mikkel, Joakim & Casper
 * ----------------------------------------------------------------------------
 */

#ifndef DCMotor_h
#define DCMotor_h

#include "Arduino.h"

class DCMotor
{
    public:
        DCMotor(int out1, int out2);
        void run(int Speed);
        void runReverse(int Speed);
        void runForward(int Speed);
        void fullStop();
    private:
        int _out1, _out2;
        int Speed;
};

#endif