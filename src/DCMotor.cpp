/*
DCMotor.cpp - Library for motor control
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

#include "DCMotor.h"

DCMotor::DCMotor(int out1, int out2)
{
    pinMode(out1, OUTPUT);
    pinMode(out2, OUTPUT);
    _out1 = out1;
    _out2 = out2;
}
void DCMotor::runForward(int Speed)
{
    if (Speed < 0){Speed = 0;}
    if (Speed > 100){Speed = 100;}
    Speed = map(Speed, 0, 100, 0, 255);
    analogWrite(_out1, Speed);
    digitalWrite(_out2, LOW);
}
void DCMotor::runReverse(int Speed)
{
    if (Speed < 0){Speed = 0;}
    if (Speed > 100){Speed = 100;}
    Speed = map(Speed, 0, 100, 0, 255);
    digitalWrite(_out1, LOW);
    analogWrite(_out2, Speed);
}
void DCMotor::run(int Speed)
{
    if (Speed < -100){Speed = -100;}
    if (Speed > 100){Speed = 100;}
    
    if (Speed < 0){
        Speed = map(-1*Speed, 0, 100, 0, 255);
        runReverse(Speed);
    } else {
        Speed = map(Speed, 0, 100, 0, 255);
        run(Speed);
    }
}
void DCMotor::fullStop(){
    digitalWrite(_out1, HIGH);
    digitalWrite(_out2, HIGH);
}