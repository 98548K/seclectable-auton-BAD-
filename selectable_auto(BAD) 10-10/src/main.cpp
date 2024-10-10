/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    1, 2, 3, 4, 5   
// intake               motor         6               
// elevation            digital_out   A               
// elevated_intake      digital_out   B               
// PTO                  digital_out   C               
// tracking1            rotation      7               
// tracking2            rotation      8               
// Inertial             inertial      9               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
int auton = 0;
void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(0, 0, 200,117);
  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(0, 117, 200,117);
  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(300, 0, 200,117);
  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(300, 117, 200,117);
  Brain.Screen.setFillColor(ClrPurple);
  Brain.Screen.drawRectangle(175, 0, 125,117);
  Brain.Screen.setFillColor(ClrPink);
  Brain.Screen.drawRectangle(175, 117, 125,117);
  Brain.Screen.setCursor(3,3);
  Brain.Screen.setFillColor(blue);
  Brain.Screen.setPenColor(white);
  Brain.Screen.print("Left Blue");
  Brain.Screen.setCursor(9,3);
  Brain.Screen.setFillColor(red);
  Brain.Screen.setPenColor(white);
  Brain.Screen.print("Left Red");
  Brain.Screen.setCursor(3,36);
  Brain.Screen.setFillColor(blue);
  Brain.Screen.setPenColor(white);
  Brain.Screen.print("Right Blue");
  Brain.Screen.setCursor(9,36);
  Brain.Screen.setFillColor(red);
  Brain.Screen.setPenColor(white);
  Brain.Screen.print("Right Red");
  Brain.Screen.setCursor(3,22);
  Brain.Screen.setFillColor(ClrPurple);
  Brain.Screen.setPenColor(white);
  Brain.Screen.print("Skills");
  Brain.Screen.setCursor(9,20);
  Brain.Screen.setFillColor(ClrPink);
  Brain.Screen.setPenColor(white);
  Brain.Screen.print("Calibrate");
  //touch screen
  while (true){
    if (Brain.Screen.pressing()){
     if (Brain.Screen.xPosition()< 180){
       if (Brain.Screen.yPosition()<120){
        auton = 1;
         Brain.Screen.setCursor(1,1);
         Brain.Screen.setFillColor(blue);
         Brain.Screen.print("Left Blue  ");
       }
     } 
     if (Brain.Screen.xPosition()> 180){
       if (Brain.Screen.yPosition()> 120){
         auton = 5;
         Brain.Screen.setCursor(1,1);
         Brain.Screen.setFillColor(blue);
         Brain.Screen.print("Calibrate  ");
       }
     } 
     if (Brain.Screen.xPosition()> 300){
       if (Brain.Screen.yPosition()>120){
         auton = 4;
         Brain.Screen.setCursor(1,1);
         Brain.Screen.setFillColor(blue);
         Brain.Screen.print("Right Red  ");
       }
     } 
     if (Brain.Screen.xPosition()< 180){
       if (Brain.Screen.yPosition()>120){
         auton = 2;
         Brain.Screen.setCursor(1,1);
         Brain.Screen.setFillColor(blue);
         Brain.Screen.print("Left Red  ");
       }
     }
     if (Brain.Screen.xPosition()> 180){
       if (Brain.Screen.yPosition()< 120){
         auton = 6;
         Brain.Screen.setCursor(1,1);
         Brain.Screen.setFillColor(blue);
         Brain.Screen.print("Skills      ");
       }
     }  
     if (Brain.Screen.xPosition()> 300){
       if (Brain.Screen.yPosition()< 120){
         auton = 3;
         Brain.Screen.setCursor(1,1);
         Brain.Screen.setFillColor(blue);
         Brain.Screen.print("Right Blue  ");
       }
     }  
    }
    wait(20, msec);
  }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
