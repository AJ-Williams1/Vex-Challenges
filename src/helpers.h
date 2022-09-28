#include "main.h"

#define DRIVE_L_PORT 1
#define DRIVE_R_PORT 2
#define DISTANCE_PORT 3
#define BUMPER_PORT 1

using namespace pros;

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

void initialize()
{
    lcd::initialize();

    // Drive motors
    Motor drive_right(DRIVE_L_PORT, E_MOTOR_GEARSET_18, true, MOTOR_ENCODER_COUNTS);
    Motor drive_left(DRIVE_R_PORT, E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);

    // Sensors
    Distance distance_sensor(DISTANCE_PORT);
    ADIDigitalIn bumper(BUMPER_PORT);
}

// Make motors & sensors global
Motor drive_right(DRIVE_L_PORT);
Motor drive_left(DRIVE_R_PORT);
Distance distance_sensor(DISTANCE_PORT);
ADIDigitalIn bumper(BUMPER_PORT);

void drive(int speed)
{
    drive_right.move(speed);
    drive_left.move(speed);
}

int turn_counts = 100;
int turn_velocity = 100;

void turn_left()
{
    int target_pos_r = drive_right.get_position() + turn_counts;
    int target_pos_l = drive_left.get_position() - turn_counts;

    drive_right.move_absolute(target_pos_r, turn_velocity);
    drive_left.move_absolute(target_pos_l, turn_velocity);

    while (std::abs(drive_right.get_position() - target_pos_r) > 5 ||
           std::abs(drive_left.get_position() - target_pos_l) > 5)
        delay(2);
}

void turn_right()
{
    int target_pos_r = drive_right.get_position() - turn_counts;
    int target_pos_l = drive_left.get_position() + turn_counts;

    drive_right.move_absolute(target_pos_r, turn_velocity);
    drive_left.move_absolute(target_pos_l, turn_velocity);

    while (std::abs(drive_right.get_position() - target_pos_r) > 5 ||
           std::abs(drive_left.get_position() - target_pos_l) > 5)
        delay(2);
}
