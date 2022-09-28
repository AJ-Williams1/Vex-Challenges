#include "main.h"

// This is the file with all the work we've done for you. If you want to look behind the curtain and see how the sausage
// is made, feel free to check it out.
#include "helpers.h"

// This gives you access to all the vex-ish functions through the PROS library
using namespace pros;

void autonomous()
{
    /********************************************
     *
     * ALL THE CODE YOU NEED
     *
     ********************************************/

    // Drive forward at a given speed. Speed should be between -127 and 127
    // (negative drives backwards). To stop, simply call this function with 0 as
    // the speed.
    drive(SPEED);

    // Turn left or right 90 degrees. Program will not continue until turn is completed
    turn_left();
    turn_right();

    // Find out if the bumper is pressed down; will return true if so, otherwise false
    bumper.get_value();

    // Get distance from distance sensor in mm. Keep in mind you might get garbage values if the object is too
    // close.
    distance_sensor.get();

    // This prints the values read from the sensors, so it might be useful for debugging
    printf("Bumper status: %s\nDistance sensor reading: %i", bumper.get_value() ? "pressed" : "not pressed",
           distance_sensor.get());
}
