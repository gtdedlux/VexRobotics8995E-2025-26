#include "main.h"

//motors

 pros::Motor intake1(14,pros::v5::MotorGears::blue); 
pros::Motor intakeM(-12,pros::v5::MotorGears::green); 
pros::Motor intakeT(19,pros::v5::MotorGears::green); 




//pneumatics
pros::adi::Pneumatics toungue('H', false);
pros::adi::Pneumatics wing('E', false);

pros::adi::Pneumatics dec('A', false);




//sensors
pros::Imu imu(15); //main imu sensor  MAKE SURE TO CHECK PORTS OF BOTH IMUS


pros::Imu imu2(20); //secondary imu sensor




 pros::Distance distanceL(17);
  pros::Distance distanceR(18);

// pros::Rotation armSensor(13);



//pros::Motor conveyor11W(-8,pros::v5::MotorGears::blue);
//pros::MotorGroup fintake({-8,20},pros::v5::MotorGears::blue); 

// pros::ADIAnalogIn aSelector ('F');


// mogoMech.extend();
// mogoMech.retract();
// mogoMech.toggle();
// mogoMech.isExtended();