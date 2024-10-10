using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern smartdrive Drivetrain;
extern motor intake;
extern digital_out elevation;
extern digital_out elevated_intake;
extern digital_out PTO;
extern rotation tracking1;
extern rotation tracking2;
extern inertial Inertial;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );