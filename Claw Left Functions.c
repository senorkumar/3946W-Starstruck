int clawLeftPositionOpen = 1550;
int clawLeftPositionHalf = 880;
int clawLeftPositionE = 830;
int clawLeftPositionClosed= 540;
int clawLeftPositionFlat = 1940;
int clawLeftPositionPreloadClosed = 780;

float kP_CL=0.25;//.35
float kI_CL = 0.0;
float kD_CL = 0.85;//.35
float error_CL=0;
float integral_CL= 0;
float derivative_CL = 0;

int currentPosition_CL = SensorValue(clawLeftPot);
int setPosition_CL = clawLeftPositionClosed;
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
