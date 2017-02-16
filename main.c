#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, in1,    clawRightPot,   sensorPotentiometer)
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
		//if(SensorValue(liftQuad)>liftPositionMax && vexRT[Btn5D]!=1){
		//	setLiftPosition(liftPositionMax);
		//}
		if(vexRT[Btn5U] == 1){
			setLift(127);
			setPosition_lift = SensorValue(liftQuad);
		}
		else if (vexRT[Btn5D]==1&& SensorValue(liftQuad)>-1){
			setLift(-70);
			setPosition_lift = SensorValue(liftQuad);
		}
		else if(vexRT[Btn6U] == 1){
			setLift(50);
			setPosition_lift = SensorValue(liftQuad);
		}
		else if (vexRT[Btn6D]==1){
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
			runPID_CL = true;
			clawLeftSetPosition(clawLeftPositionOpen);
		}
		else if(vexRT[Btn5UXmtr2]==1 && setPosition_CL>clawLeftPositionClosed){
			runPID_CL=false;
			setPosition_CL = SensorValue(clawLeftPot);
			setClawLeft(127);
		}
		else if(vexRT[Btn5DXmtr2]==1&& setPosition_CL<clawLeftPositionOpen){
			runPID_CL = false;
			setPosition_CL = SensorValue(clawLeftPot);
			setClawLeft(-127);
		}
		else{
			runPID_CL=true;
		}

		//right claw
		if(vexRT[Btn7LXmtr2]==1){
			runPID_CR = true;
			clawRightSetPosition(clawRightPositionOpen);
		}
		else if(vexRT[Btn5UXmtr2]==1 && setPosition_CR>clawRightPositionClosed){
			runPID_CR=false;
			setPosition_CR = SensorValue(clawRightPot);
			setClawRight(127);

		}
		else if(vexRT[Btn5DXmtr2]==1&& setPosition_CR<clawRightPositionOpen){
			runPID_CR = false;
			setPosition_CR = SensorValue(clawRightPot);
			setClawRight(-127);
		}
		else{
			runPID_CR = true;
		}

		//if(vexRT[Btn7LXmtr2]==1){
		//	runPID_CR = true;
		//	clawRightSetPosition(clawRightPositionOpen);
		//}
		//else if(vexRT[Btn8RXmtr2]==1){
		//	runPID_CR = true;
		//	clawRightSetPosition(clawRightPositionClosed);
		//}
		//else if(vexRT[Btn6UXmtr2]==1){
		//	runPID_CR=false;
		//	setPosition_CR = SensorValue(clawRightPot);
		//	setClawRight(127);
		//}
		//else if(vexRT[Btn6DXmtr2]==1){
		//	runPID_CR = false;
		//	setPosition_CR = SensorValue(clawRightPot);
		//	setClawRight(-127);
		//}
		//else{
		//	runPID_CR=true;
		//}


		wait1Msec(1);
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

			datalogDataGroupStart();
			datalogAddValue(1,setPosition_CR);
			datalogAddValue(2,SensorValue(clawRightPot));
			datalogAddValue(3,-speed_CR);
			datalogDataGroupEnd();

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


task grapher(){
	clearDebugStream();
	while(true){
		int proportional_effect = kP_CL * error_CL;
		int derivative_effect = kD_CL * derivative_CL;



		writeDebugStream("%f", currentPosition_CL);
		writeDebugStream(",");
		writeDebugStream("%f", setPosition_CL);
		writeDebugStream(",");
		writeDebugStream("%f", speed_CL);
		writeDebugStream(",");
		writeDebugStream("%f", proportional_effect);
		writeDebugStream(",");
		writeDebugStreamLine("%f", derivative_effect);



		wait1Msec(10);
	}

}

task autonomous()
{
	startTask(liftControlAuton);
	startTask(clawLeftControl);
	startTask(clawRightControl);
	startTask(liftThrowAuton);
	wait1Msec(1);


	//auton_test();
	//auton_programmingskills();
	auton_fence_doublestarRight();
	//auton_midlane_left();
}

task usercontrol()
{
	datalogClear();
wait1Msec(1);
	startTask(clawLeftControl);
	startTask(clawRightControl);
	startTask(combinedControl);
	startTask(liftThrow);
	//startTask(grapher);

}
