int clawLeftPositionBack = 0;
int clawLeftPositionOpen = 1825;
int clawLeftPositionClosed= 3750;

float kP_CL=0.09;
float kI_CL = 0.0;
float kD_CL = 0.02;
float error_CL=0;
float integral_CL= 0;
float derivative_CL = 0;

int currentPosition_CL = SensorValue(clawLeftPot);
int setPosition_CL = currentPosition_CL;
int lastCurrentPosition_CL = currentPosition_CL;
int integralCap_CL = 200;

void setClawLeft(int speed){
	motor[clawLeft]= speed;
}


void resetClaw(){
	setClawLeft(0);
}

void clawLeftSetPosition(int position){
	setPosition_CL = position;
}
