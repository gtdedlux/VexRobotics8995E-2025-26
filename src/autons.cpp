#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
//#include "globals.cpp"



void rightSideAuto(){
        //RIGHTBLUE/RIGHT
    chassis.moveToPoint(0, 11, 500);
    chassis.turnToHeading(32,300);
    intake1Speed = 115;
    chassis.moveToPoint(12, 35, 5000,{ .maxSpeed = 50});
    pros::delay(1000);
    chassis.turnToHeading(160,1500);
    chassis.moveToPoint(36, 3, 5000,{ .maxSpeed = 60} );
    pros::delay(200);
    chassis.turnToHeading(180,300);


     //distance sensor reset  
    pros::lcd::print(7, "X: %f", 72-((distanceL.get_distance())/25.4));
   pros::delay(700); //NEED THIS DELAY TO LET POS UPDATE BEFORE TURNING
    int x = 72-(distanceL.get_distance())/25.4;
    chassis.setPose((72-(distanceL.get_distance())/25.4),3, 180); 

    pros::delay(500);
    chassis.moveToPoint(56, 25, 3000,{ .forwards = false, .maxSpeed = 70});
    pros::delay(500);
    intake2Speed = 115;
    wing.extend();
     pros::delay(500);
    toungue.extend();
    
     chassis.moveToPoint(55, -12, 1000, {.maxSpeed = 60});  
    intake2Speed = 0;
    pros::delay(500);
    wing.retract();

    chassis.moveToPose(55, -6, 180, 1000, { .maxSpeed = 40});  
    chassis.moveToPoint(x+1.5, -15, 650, {.maxSpeed = 40});  
    pros::delay(100);

    chassis.moveToPoint(x+1.5, 20, 5000, {.forwards = false, .maxSpeed = 60});  

    chassis.moveToPose(56, 27,180, 10000,{ .forwards = false, .maxSpeed = 60,});
    //chassis.waitUntilDone();
    pros::delay(800);
    intake2Speed = 115;
    wing.extend();
    pros::delay(1500);
    // _________________

}



void leftSideAuto(){
        chassis.moveToPoint(0, 11, 500);
    chassis.turnToHeading(-32,300);
    intake1Speed = 115;
    chassis.moveToPoint(-12, 35, 5000,{ .maxSpeed = 50});
    pros::delay(1000);
    chassis.turnToHeading(-160,1500);
    chassis.moveToPoint(-34, 3, 5000,{ .maxSpeed = 60} );
    chassis.turnToHeading(0,300);


     //distance sensor reset  
    pros::lcd::print(7, "X: %f", 72-((distanceL.get_distance())/25.4));
   pros::delay(1000); //NEED THIS DELAY TO LET POS UPDATE BEFORE TURNING
    chassis.setPose(-(72-(distanceL.get_distance())/25.4),3, 0); 

    pros::delay(500);
    chassis.turnToHeading(180,500);
    chassis.moveToPoint(-54, 25, 5000,{ .forwards = false, .maxSpeed = 80,});
    pros::delay(300);
    intake2Speed = 115;
    pros::delay(1000);
        toungue.extend();
    
     chassis.moveToPoint(-54, -11, 1000, {.maxSpeed = 80});  
    pros::delay(200);

    intake2Speed = 0;
    chassis.moveToPoint(-54, -6, 1000, {.forwards = false, .maxSpeed = 60});  
    chassis.moveToPoint(-54, -11, 1000, {.maxSpeed = 60});  
    pros::delay(500);
    chassis.moveToPoint(-54, 25, 5000,{ .forwards = false, .maxSpeed = 60,});
    intake2Speed = 115;
    pros::delay(1500);
    // _________________





}



void skillsAuto(){
    intakeM.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    intakeT.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    //MIDDLLE BALLS
    // chassis.setPose(0, 0, 0); 
    // intake1Speed = 120;
    // chassis.moveToPoint(0, 14, 1000); // slight move to reset odometry  
    // pros::delay(1000); // wait for a moment
    // chassis.moveToPoint(0, 10, 500, {.forwards = false, .maxSpeed = 90}); // slight move to reset odometry  
    // chassis.moveToPoint(0, 17, 700); // slight move to reset odometry  
    // pros::delay(1000); // wait for a moment
    // chassis.moveToPoint(0, 0, 2000, {.forwards = false}); // slight move to reset odometry  
    
    // chassis.setPose(0, 0, 180);

//MIDDLE LOADERS
    // chassis.setPose(8, 9, -145);
    // chassis.moveToPoint(17,38, 5000, {.forwards = false}); // move to shooting position
    // chassis.turnToHeading(-40,3000); // turn to face goal
    // chassis.moveToPoint(13,42, 5000); // move to shooting position
    // pros::delay(700); // wait for a moment to stabilize
    // intake1Speed = -120;
    // pros::delay(500); // wait for a moment to shoot
    // intake1Speed = 0;

//UNCOMMENT _________________________________________
    //move to loader
    chassis.setPose(0, 9, 90);
    chassis.moveToPoint(50, 9, 5000, {.maxSpeed = 90}); 

    pros::delay(500);
    toungue.extend();
    dec.extend();
    
  
    pros::delay(100); 
    chassis.turnToHeading ( -180, 5000);

    //distance sensor reset  
    pros::lcd::print(7, "X: %f", 72-((distanceL.get_distance())/25.4));
   pros::delay(1000); //NEED THIS DELAY TO LET POS UPDATE BEFORE TURNING
    chassis.setPose((72-(distanceL.get_distance())/25.4),9, 180); 

    

    //load balls
    intake1Speed = 120;
    loadBalls();

     int y = 95;
    //move to other side
    chassis.moveToPoint(53, 5, 5000, {.forwards = false}); 
    pros::delay(500);
    toungue.retract();
    intake1Speed = 0;
    chassis.moveToPoint(66, 32, 5000, {.forwards = false,  .minSpeed=62, .earlyExitRange=4}); 
    chassis.moveToPoint(65, 83, 5000, {.forwards = false, .minSpeed=62, .earlyExitRange=2}); //change back to 40
   // chassis.moveToPoint(50, 100, 5000, {.forwards = false, .maxSpeed = 70, }); 
    chassis.moveToPoint(53, y, 5000, {.forwards = false, .maxSpeed = 70, }); 

      //distance sensor reset  
      pros::delay(50);
   chassis.turnToHeading(0, 1000);
   chassis.waitUntilDone();
    pros::lcd::print(7, "X: %f", 72-((distanceR.get_distance())/25.4));
    chassis.setPose((72-(distanceR.get_distance())/25.4),y, 0); 
        pros::delay(200);


   //score loaded balls
   chassis.turnToHeading(0, 500); // turn to face goal
    pros::delay(50); // wait for a moment to stabilize
    //chassis.moveToPoint(53, 100, 1500, {.forwards = false, .maxSpeed = 70});
    chassis.moveToPose(54, 83, 0, 5000, {.forwards = false});
    pros::delay(1500); // wait for a moment to shoot
    wing.extend();
    intake1Speed = 120;
    intake2Speed = 120;  
    jam(120);

    pros::delay(2300); // wait for a moment to shoot

    
    //second loader
    intake1Speed = 0;
    intake2Speed = 0;
    toungue.extend();
    intake1Speed = 120;
    
    
     chassis.moveToPoint(53, 104.5, 5000);
     chassis.waitUntilDone();
     wing.retract();
     loadBalls();
     pros::delay(1500); //added delay to ensure balls are loaded
     
//     //final shoot

    chassis.moveToPoint(54, 83, 5000, {.forwards = false});
    chassis.turnToHeading(0, 50); // turn to face goal
    pros::delay(20); // wait for a moment to stabilize
    wing.extend();
    intake1Speed = 120;
    intake2Speed = 120;  
    pros::delay(50); // wait for a moment to shoot
    intake2Speed = -120;  
    intake1Speed = -120;
   pros::delay(100); //jam
    intake2Speed = 120;  
    intake1Speed = 120;

    
    pros::delay(2200); // wait for a moment to shoot

 
    
      chassis.moveToPoint(54, 92, 5000);

//     //imu reset
//     /*
//     pros::delay(800);
//     chassis.setPose(55,100, avgImuHeading(imu.get_heading(), imu2.get_heading()));   
//     */

     chassis.turnToHeading(90,1000);

    intake1Speed = 0;
    intake2Speed = 0; 
    toungue.retract();
     int x = 39;

     //travel
    chassis.moveToPose(x, 92,90, 5000, {.forwards = false});
//TAPED ____________________________
          //distance sensor reset  
     
    pros::lcd::print(7, "X: %f", 72-((distanceL.get_distance())/25.4));
   pros::delay(1000); //NEED THIS DELAY TO LET ROBOT GET TO POINT BEFORE SETTING POSE
    chassis.setPose(x,109-(distanceL.get_distance())/25.4, 90); 

        chassis.moveToPoint(-38, 88, 5000, {.forwards = false, .minSpeed=72, .earlyExitRange=6});
        chassis.moveToPoint(-45, 88, 5000, {.forwards = false, .maxSpeed = 55});

        wing.retract();


    //REFLECTION

   pros::delay(500);
    toungue.extend();
    
    pros::delay(100); 
    intake1Speed = 120;
    chassis.turnToHeading ( 0, 5000);




    //distance sensor reset  
    pros::lcd::print(7, "X: %f", 72-((distanceL.get_distance())/25.4));
   pros::delay(1000); //NEED THIS DELAY TO LET POS UPDATE BEFORE TURNING
    chassis.setPose(-(72-(distanceL.get_distance())/25.4),86.5, 0); //CHECK ALL VALUES 

    chassis.moveToPoint(-45, 91.5, 5000, {.maxSpeed = 80});
    chassis.waitUntilDone();
    loadBalls();


     y = 2;
    //move to other side
    chassis.moveToPoint(-53, 95, 5000, {.forwards = false}); 
    pros::delay(500);
    toungue.retract();
    intake1Speed = 0;
    chassis.moveToPoint(-66, 70, 5000, {.forwards = false,  .minSpeed=62, .earlyExitRange=4}); 
     chassis.moveToPoint(-65, 13, 5000, {.forwards = false, .minSpeed=62, .earlyExitRange=2}); //change back to 40
     chassis.moveToPoint(-53, y, 5000, {.forwards = false, .maxSpeed = 70, }); 

      //distance sensor reset  
      pros::delay(50);
   chassis.turnToHeading(180, 1000);
   chassis.waitUntilDone();
    pros::lcd::print(7, "X: %f", 72-((distanceR.get_distance())/25.4));
    chassis.setPose(-(72-(distanceR.get_distance())/25.4),y, 180); 
        pros::delay(200);


   //score loaded balls
   chassis.turnToHeading(180, 500); // turn to face goal
    pros::delay(50); // wait for a moment to stabilize
    //chassis.moveToPoint(53, 100, 1500, {.forwards = false, .maxSpeed = 70});
    chassis.moveToPose(-54, 15, 180, 5000, {.forwards = false});
    pros::delay(500); // wait for a moment to shoot
    wing.extend();
    intake1Speed = 120;
    intake2Speed = 120;  
    pros::delay(1500); // wait for a moment to shoot

    
    //second loader
    intake1Speed = 0;
    intake2Speed = 0;
    toungue.extend();
    intake1Speed = 120;
    
    
     chassis.moveToPoint(-52.5, -6, 5000);
     chassis.waitUntilDone();
     wing.retract();
     loadBalls();
     pros::delay(1500); //added delay to ensure balls are loaded
     
     //final shoot

    chassis.moveToPoint(-54, 15, 5000, {.forwards = false});
    wing.extend();
    chassis.turnToHeading(180, 50); // turn to face goal
    pros::delay(20); // wait for a moment to stabilize
    toungue.retract();
    intake1Speed = 120;
    intake2Speed = 120;  
    pros::delay(1000); // wait for a moment to shoot

    intake1Speed = 0;

    //PARK
    //chassis.setPose(-54, 15, 180); //REMOVE
     chassis.moveToPoint(-39, -21,  2000, {.maxSpeed = 80});
//     //chassis.swingToHeading( 90,lemlib::DriveSide::LEFT, 500, {.minSpeed = 127, .earlyExitRange = 10});
   chassis.turnToHeading (90, 1000);
     chassis.moveToPoint(-43, -22.5,  5000, {.forwards = false});
    chassis.moveToPoint(-10, -24, 5000, {.minSpeed = 100, .earlyExitRange = 5});
     pros::delay(500); 
    //toungue.extend();


    



     pros::delay(5000); // wait for a min type
     
}



void loadBalls(){
    float x = chassis.getPose().x;
    float y = chassis.getPose().y;
    float theta = chassis.getPose().theta;

    if (theta>170 && theta<190){
        chassis.moveToPoint(x, y-13, 3000, {.maxSpeed = 60});
        chassis.moveToPoint(x, y-20, 1500, {.maxSpeed = 10});

        // chassis.moveToPoint(x, y-5, 5000, {.forwards = false, .maxSpeed = 90 });
        // chassis.moveToPoint(x, y-12, 2000, {.maxSpeed = 10});

    }
    else{
        chassis.moveToPoint(x, y+13, 3000, {.maxSpeed = 60});
        chassis.moveToPoint(x, y+20, 1500, {.maxSpeed = 10});

        // chassis.moveToPoint(x, y+5, 5000, {.forwards = false, .maxSpeed = 90});
        // chassis.moveToPoint(x, y+12, 3000, {.maxSpeed = 10});

        
    }

}