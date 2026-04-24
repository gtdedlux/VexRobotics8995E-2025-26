#include "main.h"
#include <cmath>



void setIntake1(int speed) {
    intake1.move(speed);
    intakeM.move(speed);
    pros::delay(10);
}

void setIntake2(int speed) {
    intakeT.move(speed);
    pros::delay(10);
}

void setIntakeM(int speed) {
    intakeM.move(speed);
    intakeT.move(-(speed)/2);
    pros::delay(10);
}

void jam(int speed) {
    intake2Speed=-120;
    intake1Speed=-120;
    pros::delay(70);

    intake2Speed=120;
    intake1Speed=120;
    pros::delay(10);
}

double avgImuHeading(double h1, double h2) {
    // convert degrees → unit circle
    
    double x = cos(h1 * M_PI / 180.0) + cos(h2 * M_PI / 180.0);
    double y = sin(h1 * M_PI / 180.0) + sin(h2 * M_PI / 180.0);

    double ang = atan2(y, x) * 180.0 / M_PI;
    return fmod((ang + 360.0), 360.0);
}



// void moveIntake(int intakePower, bool reverse, int degrees){
//     intake11W.move_relative(degrees, intakePower);

// }
// void setArm(int armSpeed){
//     ladyB.move(armSpeed);
//     ladyB.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    
// }


    // void setIntake(int speed) {
    //     if (sortingEnabled && optical.get_proximity() >= 200) {
    //         return; // Prevent manual control when sorting is active
    //     }
    //     intake11W.move(speed);
    //     pros::delay(10);
    // }