#pragma config(Sensor, in1,    clawRightPot,   sensorNone)
#pragma config(Sensor, in2,    clawLeftPot,    sensorPotentiometer)
#pragma config(Sensor, dgtl1,  driveRightQuad, sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  driveLeftQuad,  sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  liftQuad,       sensorQuadEncoder)
#pragma config(Motor,  port1,           liftLeftMid,   tmotorVex393HighSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           clawLeft,      tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           driveLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           liftRightMid,  tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           driveRight,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           liftRightTop,  tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port7,           liftLeftTop,   tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           liftRightOut,  tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           clawRight,     tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          liftLeftOut,   tmotorVex393HighSpeed_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"
#include "Drive Functions.c"
#include "Lift Functions.c"
#include "Sensor Functions.c"
#include "Claw Left Functions.c"
#include "Claw Right Functions.c"
#include "Autonomous Functions.c"
#include "Throw Functions.c"
#include "LCD Functions.c"



/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	bLCDBacklight = true; // Turn on LCD Backlight

	// check if the robot is disabled or enabled
	if (nVexRCReceiveState & vrDisabled) {
		// Disabled
	}
	else {
		// Enabled
		return; // skip LCD selection
	}

	// Display the battery level

	// Code Chooser
	while(nLCDButtons != centerButton) {
		switch(count){

		case 0:
			displayLCDCenteredString(0, "<No Autonomous>");
			WaitForPressAndRelease(12); // go forward to 4 if left is pressed
			break;

		case 1:
			displayLCDCenteredString(0, "<Red Left Main>");
			WaitForPressAndRelease();
			break;

		case 2:
			displayLCDCenteredString(0, "<Red Left Alt>");
			WaitForPressAndRelease();
			break;

		case 3:
			displayLCDCenteredString(0, "<Red Right Main>");
			WaitForPressAndRelease();
			break;

		case 4:
			displayLCDCenteredString(0, "<Red Right Alt>");
			WaitForPressAndRelease();
			break;

		case 5:
			displayLCDCenteredString(0, "<Red Right E>");
			WaitForPressAndRelease();
			break;

		case 6:
			displayLCDCenteredString(0, "<Blue Left Main>");
			WaitForPressAndRelease();
			break;

		case 7:
			displayLCDCenteredString(0, "<Blue Left Alt>");
			WaitForPressAndRelease();
			break;

		case 8:
			displayLCDCenteredString(0, "<Blue Right Main>");
			WaitForPressAndRelease();
			break;

		case 9:
			displayLCDCenteredString(0, "<Blue Right Alt>");
			WaitForPressAndRelease();
			break;

		case 10:
			displayLCDCenteredString(0, "<Blue Right E>");
			WaitForPressAndRelease();
			break;

		case 11:
			displayLCDCenteredString(0, "<Prog Skills>");
			WaitForPressAndRelease(); // go back to zero if right is pressed
			break;

		case 12:
			displayLCDCenteredString(0, "<Test>");
			WaitForPressAndRelease(0); // go back to zero if right is pressed
			break;
		}

	}

	SensorValue(liftQuad) = 0;
	SensorValue(driveLeftQuad) = 0;
	SensorValue(driveRightQuad) = 0;


	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
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



/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
task combinedControl(){ //drive, lift, clawinput
	while(true){
		//driveControl
		motor[port3] = vexRT[Ch3]+ vexRT[Ch1];
		motor[port5] = vexRT[Ch3] -vexRT[Ch1];

		//liftControl


		if(vexRT[Btn5U] == 1 && (SensorValue(liftQuad)<780|| vexRT[Btn8UXmtr2])){
			setLift(127);
			setPosition_lift = SensorValue(liftQuad);
		}
		else if (vexRT[Btn5D]==1&& SensorValue(liftQuad)>-1){
			setLift(-127);
			setPosition_lift = SensorValue(liftQuad);
		}
		else if(vexRT[Btn6U] == 1){
			setLift(50);
			setPosition_lift = SensorValue(liftQuad);
		}
		else if(vexRT[Btn6D]==1){
			setLift(-127);
			setPosition_lift = SensorValue(liftQuad);
		}
		else{
			currentPositon_lift = SensorValue(liftQuad);

			error_lift = setPosition_lift - currentPositon_lift;
			int speed = kP_lift * error_lift;
			setLift(speed);

		}


		//clawInput
		//left claw

		if(vexRT[Btn7LXmtr2]==1){
			clawLeftSetPosition(clawLeftPositionOpen);
		}
		else if(vexRT[Btn5UXmtr2]==1 && SensorValue(clawLeftPot)>clawLeftPositionClosed){
			setPosition_CL = SensorValue(clawLeftPot);
			setClawLeft(120);
		}
		else if((vexRT[Btn6DXmtr2]==1) || (vexRT[Btn5DXmtr2]==1&& SensorValue(clawLeftPot)<clawLeftPositionOpen)){
			setPosition_CL = SensorValue(clawLeftPot);
			setClawLeft(-127);
		}
		else{
			if(setPosition_CL<clawLeftPositionClosed){
				setPosition_CL = clawLeftPositionClosed;
			}
			else if(setPosition_CL>clawLeftPositionOpen){
				setPosition_CL = clawLeftPositionOpen;
			}
			currentPosition_CL = SensorValue(clawLeftPot);
			error_CL=setPosition_CL-currentPosition_CL;

			derivative_CL = (lastCurrentPosition_CL-currentPosition_CL);
			lastCurrentPosition_CL = currentPosition_CL;


			speed_CL = (kP_CL * error_CL + kD_CL*derivative_CL);

			if(speed_CL<15 && speed_CL>-15){
				speed_CL = 0;
			}

			setClawLeft(-speed_CL);


		}

		//right claw
		if(vexRT[Btn7LXmtr2]==1){
			clawRightSetPosition(clawRightPositionOpen);
		}
		else if(vexRT[Btn5UXmtr2]==1 && SensorValue(clawRightPot)>clawRightPositionClosed){
			setPosition_CR = SensorValue(clawRightPot);
			setClawRight(120);
		}
		else if(vexRT[Btn6DXmtr2]==1 || (vexRT[Btn5DXmtr2]==1&& SensorValue(clawRightPot)<clawRightPositionOpen)){
			setPosition_CR = SensorValue(clawRightPot);
			setClawRight(-127);
		}
		else{
			if(setPosition_CR<clawRightPositionClosed){
				setPosition_CR = clawRightPositionClosed;
			}
			else if(setPosition_CR>clawRightPositionOpen){
				setPosition_CR = clawRightPositionOpen;
			}
			currentPosition_CR = SensorValue(clawRightPot);
			error_CR=setPosition_CR-currentPosition_CR;

			derivative_CR = (lastCurrentPosition_CR-currentPosition_CR);
			lastCurrentPosition_CR = currentPosition_CR;


			speed_CR = (kP_CR * error_CR + kD_CR*derivative_CR);

			if(speed_CR<15 && speed_CR>-15){
				speed_CR = 0;
			}

			setClawRight(-speed_CR);


		}


		wait1Msec(10);
	}

}


task liftControlAuton(){
	while(true){
		while(runPID_lift){
			currentPositon_lift = SensorValue(liftQuad);

			error_lift = setPosition_lift - currentPositon_lift;
			int speed = kP_lift * error_lift;
			setLift(speed);

		}
		wait1Msec(5);
	}
}

task liftThrow(){
	while(true){

		liftPosition = SensorValue(liftQuad);

		//if((vexRT[Btn8DXmtr2]==1) && (liftPosition>lastLiftPosition) && liftPosition>throwThresholdClose){
		//	clawLeftSetPosition(clawLeftPositionOpen);
		//	clawRightSetPosition(clawRightPositionOpen);
		//}
		if((liftPosition>lastLiftPosition) && liftPosition>throwThresholdFar){
			clawLeftSetPosition(clawLeftPositionOpen);
			clawRightSetPosition(clawRightPositionOpen);
		}


		lastLiftPosition = SensorValue(liftQuad);
		wait1Msec(10);
	}
}

task liftThrowAuton(){
	while(true){

		liftPosition = SensorValue(liftQuad);

		//if((vexRT[Btn8DXmtr2]==1) && (liftPosition>lastLiftPosition) && liftPosition>throwThresholdClose){
		//	clawLeftSetPosition(clawLeftPositionOpen);
		//	clawRightSetPosition(clawRightPositionOpen);
		//}
		if((liftPosition>lastLiftPosition) && liftPosition>throwThresholdFarAuton){
			clawLeftSetPosition(clawLeftPositionOpen);
			clawRightSetPosition(clawRightPositionOpen);
		}


		lastLiftPosition = SensorValue(liftQuad);
		wait1Msec(10);
	}
}
task clawLeftControl(){
	while(true){
		while(runPID_CL){

			currentPosition_CL = SensorValue(clawLeftPot);
			error_CL=setPosition_CL-currentPosition_CL;

			derivative_CL = (lastCurrentPosition_CL-currentPosition_CL);
			lastCurrentPosition_CL = currentPosition_CL;


			speed_CL = (kP_CL * error_CL + kD_CL*derivative_CL);

			if(speed_CL<15 && speed_CL>-15){
				speed_CL = 0;
			}

			setClawLeft(-speed_CL);

			int proportional_effect = kP_CL * error_CL;
			int derivative_effect = kD_CL * derivative_CL;



			//writeDebugStream("%f", currentPosition_CL);
			//writeDebugStream(",");
			//writeDebugStream("%f", setPosition_CL);
			//writeDebugStream(",");
			//writeDebugStream("%f", speed_CL);
			//writeDebugStream(",");
			//writeDebugStream("%f", proportional_effect);
			//writeDebugStream(",");
			//writeDebugStream("%f", derivative_effect);
			//writeDebugStreamLine("%f", time1[T1]);


			wait1Msec(10);
		}

	}

}

task clawRightControl(){

	while(true){
		while(runPID_CR){

			currentPosition_CR = SensorValue(clawRightPot);
			error_CR=setPosition_CR-currentPosition_CR;

			derivative_CR = (lastCurrentPosition_CR-currentPosition_CR);
			lastCurrentPosition_CR = currentPosition_CR;


			speed_CR = (kP_CR * error_CR + kD_CR*derivative_CR);

			if(speed_CR<15 && speed_CR>-15){
				speed_CR = 0;
			}

			setClawRight(-speed_CR);

			//datalogDataGroupStart();
			//datalogAddValue(2,setPosition_CR);
			//datalogAddValue(3,SensorValue(clawRightPot));
			//datalogAddValue(4,-speed_CR);
			//datalogDataGroupEnd();

			//int proportional_effect = kP_CL * error_CL;
			//int derivative_effect = kD_CL * derivative_CL;



			//writeDebugStream("%f", currentPosition_CL);
			//writeDebugStream(",");
			//writeDebugStream("%f", setPosition_CL);
			//writeDebugStream(",");
			//writeDebugStream("%f", speed_CL);
			//writeDebugStream(",");
			//writeDebugStream("%f", proportional_effect);
			//writeDebugStream(",");
			//writeDebugStream("%f", derivative_effect);
			//writeDebugStreamLine("%f", time1[T1]);


			wait1Msec(10);
		}

	}

}


task autonomous()
{

	startTask(liftControlAuton);
	startTask(clawLeftControl);
	startTask(clawRightControl);
	startTask(liftThrowAuton);
	wait1Msec(1);

	bLCDBacklight = true; // Turn on LCD Backlight
	displayLCDCenteredString(0, "Autonomous");
	switch(count){
	case 0:
		// No Autonomous
		displayLCDCenteredString(1, "No Autonomous");
		break;
	case 1:
		displayLCDCenteredString(1, "Red Left Main");
		auton_red_left_main();
		break;
	case 2:
		displayLCDCenteredString(1, "Red Left Alt");
		auton_red_left_alt();
		break;
	case 3:
		displayLCDCenteredString(1, "Red Right Main");
		auton_red_right_main();
		break;
	case 4:
		displayLCDCenteredString(1, "Red Right Alt");
		auton_red_right_alt();
		break;
	case 5:
		displayLCDCenteredString(1, "Red Right E");
		auton_red_right_E();
		break;
	case 6:
		displayLCDCenteredString(1, "Blue Left Main");
		auton_blue_left_main();
		break;
	case 7:
		// test
		displayLCDCenteredString(1, "Blue Left Alt");
		auton_blue_left_alt();
		break;
	case 8:
		// test
		displayLCDCenteredString(1, "Blue Right Main");
		auton_blue_right_main();
		break;
	case 9:
		// test
		displayLCDCenteredString(1, "Blue Right Alt");
		auton_blue_right_alt();
		break;
	case 10:
		// test
		displayLCDCenteredString(1, "Blue Right E");
		auton_blue_right_E();
		break;
	case 11:
		// test
		displayLCDCenteredString(1, "Prog Skills");
		auton_programmingskills();
		break;
	case 12:
		// test
		displayLCDCenteredString(1, "Test");
		auton_test();
		break;
	}
}

task usercontrol()
{
	datalogClear();
	wait1Msec(1);
	//startTask(clawLeftControl);
	//startTask(clawRightControl);
	startTask(combinedControl);
	startTask(liftThrow);
	//startTask(grapher);

}
