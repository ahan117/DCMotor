#include "DCMotor.h"

DCMotor testMotor(5, 4);

void setup() {
  /*Hmmm*/
}

void loop() {

    int i;

    for(i = 0; i <= 100; i++){
        testMotor.run(i);
    }

    for(i = 100; i >= -100; i--){
        testMotor.run(i);
    }

    testMotor.fullStop();

    /*
    testMotor.runForward(50);
    testMotor.runReverse(50);
    */
}