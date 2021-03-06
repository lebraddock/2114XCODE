#include "main.h"
#include "api.h"
#include "initialize.cpp"

using namespace pros::literals;

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol()
{
	pros::Motor arm (1, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
	pros::Controller master (pros::E_CONTROLLER_MASTER);
	while (true)
	{
		arm.move(master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
		pros::delay(4);
	}
}
