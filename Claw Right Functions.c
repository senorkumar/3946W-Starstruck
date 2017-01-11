int clawRightPositionBack = 0;
int clawRightPositionOpen = 1917;
int clawRightPositionClosed= 250;

float kP_CR=0.1;
float kI_CR = 0.0;
float kD_CR = 0.02;
float error_CR=0;
float integral_CR= 0;
float derivative_CR = 0;

int currentPosition_CR = SensorValue(clawRightPot);
int setPosition_CR = currentPosition_CR;
int lastCurrentPosition_CR = currentPosition_CR;
int integralCap_CR = 200;

void setClawRight(int speed){
	motor[clawRight]= speed;
}



void clawRightSetPosition(int position){
	setPosition_CR = position;
}
