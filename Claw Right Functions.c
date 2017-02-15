int clawRightPositionBack = 0;
int clawRightPositionOpen = 1250;
int clawRightPositionHalf = 870;
int clawRightPositionClosed=380;

float kP_CR=0.35;
float kI_CR = 0.0;
float kD_CR = 0.35;
float error_CR=0;
float integral_CR= 0;
float derivative_CR = 0;

int currentPosition_CR = SensorValue(clawRightPot);
int setPosition_CR = clawRightPositionClosed;
int lastCurrentPosition_CR = currentPosition_CR;
int integralCap_CR = 200;
int speed_CR = 0;

bool runPID_CR= true;

void setClawRight(int speed){
	motor[clawRight]= speed;
}



void clawRightSetPosition(int position){
	setPosition_CR = position;
}
