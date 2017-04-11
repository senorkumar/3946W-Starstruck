int clawLeftPositionOpen = 1663;
int clawLeftPositionHalf = 880;
int clawLeftPositionE = 830;
int clawLeftPositionClosed= 2781;
int clawLeftPositionFlat = 1940;
int clawLeftPositionPreloadClosed = 780;

float kP_CL=0.2;//.35
float kI_CL = 0.0;
float kD_CL = 0.05;//.35
float error_CL=0;
float integral_CL= 0;
float derivative_CL = 0;

int currentPosition_CL = SensorValue(clawLeftPot);
int setPosition_CL = currentPosition_CL;
int lastCurrentPosition_CL = currentPosition_CL;
int integralCap_CL = 200;
int speed_CL = 0;

bool runPID_CL = true;

void setClawLeft(int speed){
	motor[clawLeft]= speed;
}

void resetClaw(){
	setClawLeft(0);
}

void clawLeftSetPosition(int position){
	setPosition_CL = position;
}


void clawLeftControlPID(int ticks){
		error_CL = ticks - (sensorvalue[clawLeftPot]);
		derivative_CL = error_CL - lastCurrentPosition_CL;

		speed_CL = -(kP_CL * error_CL) + (kD_CL * derivative_CL);

		if((speed_CL > 127)) speed_CL = 127;
		else if ((speed_CL < -(127))) speed_CL = -(127);
		motor[clawLeft] = speed_CL;

		lastCurrentPosition_CL = error_CL;

		wait1Msec(15);

}
