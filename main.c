#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in5,    clawRightPot,   sensorPotentiometer)
#pragma config(Sensor, in6,    clawLeftPot,    sensorPotentiometer)
#pragma config(Sensor, dgtl1,  driveRightQuad, sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  driveLeftQuad,  sensorQuadEncoder)
#pragma config(Sensor, I2C_1,  liftQuad,       sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           liftLeftMid,   tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           clawLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           driveLeft,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           liftRightMid,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           driveRight,    tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           liftRightTop,  tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           liftLeftTop,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           liftRightOut,  tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           liftLeftOut,   tmotorVex393_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port10,          clawRight,     tmotorVex393_HBridge, openLoop, reversed)
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
	nMotorEncoder[liftLeftOut] = 0;
	nMotorEncoder[driveLeft] = 0;
	nMotorEncoder[driveRight] = 0;
	resetDriveSensors();

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
task driveControl(){

	while(true){
		//setDriveRight(vexRT[Ch3] - vexRT[Ch1]);
		//setDriveLeft(vexRT[Ch3] + vexRT[Ch1]);
		motor[port3] = vexRT[Ch3]+ vexRT[Ch1];
		motor[port5] = vexRT[Ch3] -vexRT[Ch1];
		wait1Msec(5);

	}
}

task liftControl(){
	while(true){
		if(vexRT[Btn5U] == 1){
			setLift(127);
		}
		else if (vexRT[Btn5D]==1){
			setLift(-127);
		}
		else if(vexRT[Btn6U] == 1){
			setLiftPosition(liftPositionTop);
		}
		else if (vexRT[Btn6D]==1){
			setLiftPosition(liftPositionBottom);
		}
		else if(vexRT[Btn8U]==1){
			setLiftPosition(liftPositionMid);
		}
		else{
			setLift(10);
		}
		wait1Msec(5);

	}
}
task liftControlAuton(){
	while(true){
		if(liftConst){
			setLift(10);
		}
	}
}
task clawLeftControlPID(){
	while(true){
		currentPosition_CL = SensorValue(clawLeftPot);
		error_CL = setPosition_CL - currentPosition_CL;

		//integral += error;
		//if(lastCurrentPosition != currentPosition){
		//	integral = 0;
		//}
		derivative_CL = (currentPosition_CL-lastCurrentPosition_CL)/10;
		lastCurrentPosition_CL = currentPosition_CL;

		//if(integral_CL> integralCap_CL){
		//	integral_CL = integralCap_CL;
		//}

		int speed_CL = (kP_CL * error_CL) + (kI_CL * integral_CL) + (kD_CL * derivative_CL);

		if(speed_CL>120){
			speed_CL=120;
		}
		else if(speed_CL < -120){
			speed_CL = -120;
		}
		if(speed_CL<30 && speed_CL>-30){
			speed_CL=0;
		}

		setClawLeft(speed_CL);
		wait1Msec(10);

	}

}


task clawRightControlPID(){
	while(true){
		currentPosition_CR = SensorValue(clawRightPot);
		error_CR = setPosition_CR - currentPosition_CR;

		//integral += error;
		//if(lastCurrentPosition != currentPosition){
		//	integral = 0;
		//}
		derivative_CR = (currentPosition_CR-lastCurrentPosition_CR)/10;
		lastCurrentPosition_CR = currentPosition_CR;

		//if(integral_CL> integralCap_CL){
		//	integral_CL = integralCap_CL;
		//}

		int speed_CR = (kP_CR * error_CR) + (kI_CR * integral_CR) + (kD_CR * derivative_CR);

		if(speed_CR>120){
			speed_CR=120;
		}
		else if(speed_CR < -120){
			speed_CR = -120;
		}
		if(speed_CR<30 && speed_CR>-30){
			speed_CR=0;
		}

		setClawRight(-speed_CR);
		wait1Msec(10);

	}


}
task clawLeftControlPIDDriver(){
	while(true){
<<<<<<< HEAD
<<<<<<< HEAD
		if(vexRT[Btn5UXmtr2]==1){//open
			setClawLeft(-127);
		}
		else if(vexRT[Btn5DXmtr2] ==1){//close
			setClawLeft(127);
=======
=======
>>>>>>> parent of 63779b1... auton, new drive functions, throw task
		if(vexRT[Btn6UXmtr2]==1){//open
			clawLeftSetPosition(clawLeftPositionOpen);
			clawRightSetPosition(clawRightPositionOpen);
>>>>>>> parent of 63779b1... auton, new drive functions, throw task
		}
		else{
			if(vexRT[Btn8RXmtr2]==1){
				clawLeftSetPosition(clawLeftPositionOpen);
			}
			else if(vexRT[Btn7LXmtr2]==1){
				clawLeftSetPosition(clawLeftPositionClosed);
			}
			else{
				clawLeftSetPosition(SensorValue(clawLeftPot));
			}
			while(vexRT[Btn5UXmtr2]!=1 && vexRT[Btn5DXmtr2]!=1 && vexRT[Btn8RXmtr2]!=1 && vexRT[Btn7LXmtr2]!=1){
				currentPosition_CL = SensorValue(clawLeftPot);
				error_CL = setPosition_CL - currentPosition_CL;

				//integral += error;
				//if(lastCurrentPosition != currentPosition){
				//	integral = 0;
				//}
				derivative_CL = (currentPosition_CL-lastCurrentPosition_CL)/10;
				lastCurrentPosition_CL = currentPosition_CL;

				//if(integral_CL> integralCap_CL){
				//	integral_CL = integralCap_CL;
				//}

				int speed_CL = (kP_CL * error_CL) + (kI_CL * integral_CL) + (kD_CL * derivative_CL);

				if(speed_CL>120){
					speed_CL=120;
				}
				else if(speed_CL < -120){
					speed_CL = -120;
				}
				if(speed_CL<30 && speed_CL>-30){
					speed_CL=0;
				}

				setClawLeft(speed_CL);
				wait1Msec(10);
			}
		}

	}

}


<<<<<<< HEAD
task clawRightControlPIDDriver(){
	while(true){
		if(vexRT[Btn6UXmtr2]==1){//open
			setClawRight(-127);
		}
		else if(vexRT[Btn6DXmtr2] ==1){//close
			setClawRight(127);
		}
		else{
			if(vexRT[Btn8RXmtr2]==1){
				clawRightSetPosition(clawRightPositionOpen);
			}
			else if(vexRT[Btn7LXmtr2]==1){
				clawRightSetPosition(clawRightPositionClosed);
			}
			else{
				clawRightSetPosition(SensorValue(clawRightPot));
			}

			currentPosition_CR = SensorValue(clawRightPot);
			error_CR = setPosition_CR - currentPosition_CR;

			//integral += error;
			//if(lastCurrentPosition != currentPosition){
			//	integral = 0;
			//}
			derivative_CR = (currentPosition_CR-lastCurrentPosition_CR)/10;
			lastCurrentPosition_CR = currentPosition_CR;

			//if(integral_CL> integralCap_CL){
			//	integral_CL = integralCap_CL;
			//}

			int speed_CR = (kP_CR * error_CR) + (kI_CR * integral_CR) + (kD_CR * derivative_CR);

			if(speed_CR>120){
				speed_CR=120;
			}
			else if(speed_CR < -120){
				speed_CR = -120;
			}
			if(speed_CR<30 && speed_CR>-30){
				speed_CR=0;
			}

			setClawRight(-speed_CR);
			wait1Msec(10);

		}
=======
task autonomous()
{
	startTask(liftControlAuton);
	startTask(clawLeftControlPID);
	startTask(clawRightControlPID);
	wait1Msec(1);
	auton_fence();
<<<<<<< HEAD
>>>>>>> parent of 63779b1... auton, new drive functions, throw task

=======
>>>>>>> parent of 63779b1... auton, new drive functions, throw task

	}
}
	task clawControl(){
		while(true){
			if(vexRT[Btn6UXmtr2]==1){//open
				setClawLeft(-127);
				setClawRight(-127);
			}
			else if(vexRT[Btn5UXmtr2]==1){//close
				setClawLeft(127);
				setClawRight(127);

			}
			else if(nMotorEncoder[liftLeftOut]>liftPositionThrow){
				setClawLeft(clawLeftPositionOpen);
				setClawRight(clawRightPositionOpen);
			}
			else{
				clawLeftSetPosition(SensorValue(clawLeftPot));
				clawRightSetPosition(SensorValue(clawRightPot));
			}

		}

		wait1Msec(5);
	}


	task autonomous()
	{
		startTask(liftControlAuton);
		startTask(clawLeftControlPID);
		startTask(clawRightControlPID);
		startTask(clawControl);
		wait1Msec(1);
		auton_fencecube();

	}

	task usercontrol()
	{
		startTask(driveControl);
		startTask(liftControl);
		//startTask(clawControl);
		startTask(clawLeftControlPIDDriver);
		startTask(clawRightControlPIDDriver);




		while(true){

		}
		// User control code here, inside the loop
	}
