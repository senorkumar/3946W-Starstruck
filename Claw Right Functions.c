int clawRightPositionOpen = 1554;//2121
int clawRightPositionHalf = 1104;
int clawRightPositionE = 1000;
int clawRightPositionClosed = 2747
int clawRightPositionFlat = 2882;
int clawRightPositionPreloadClosed = 780;

float kP_CR=0.075;
float kI_CR = 0.0;
float kD_CR = 0.0;
float error_CR=0;
float integral_CR= 0;
float derivative_CR = 0;

int currentPosition_CR = SensorValue(clawLeftPot);
int setPosition_CR = currentPosition_CR;
int lastCurrentPosition_CR = currentPosition_CR;
int integralCap_CR = 200;
int speed_CR = 0;

bool runPID_CR= true;

void setClawRight(int speed){
	motor[clawRight]= speed;
}

////void resetClaw(){
////	setClawRight(0);
//}

void clawRightSetPosition(int position){
	setPosition_CR = position;
}

void clawRightControlPID(int ticks){
		error_CR = ticks - (sensorvalue[clawRightPot]);
		derivative_CR = error_CR - lastCurrentPosition_CR;

		speed_CR = -(kP_CR * error_CR) + (kD_CR * derivative_CR);

		if((speed_CR > 127)) speed_CR = 127;
		else if ((speed_CR < -(127))) speed_CR = -(127);
		motor[clawRight] = speed_CR;

		lastCurrentPosition_CR = error_CR;

		wait1Msec(15);

}
