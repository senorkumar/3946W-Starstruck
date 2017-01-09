int clawLeftPositionBack = 0;
int clawLeftPositionOpen = 0;
int clawLeftPositionClosed= 0;
int clawRightPositionBack =0;
int clawRightPositionOpen = 0;
int clawRightPositionClosed= 0;

//clawleftpid
float kP=0.7;
float kI = 0.0;
float kD = 0.0;
float error=0;
float integral= 0;
float derivative = 0;
int currentPosition = SensorValue(clawLeftPot);
int setPosition = currentPosition;
int lastCurrentPosition = currentPosition;
int integralCap = 200;

void setClawLeft(int speed){
	motor[clawLeft]= speed;
}

void setClawRight(int speed){
	motor[clawRight]= speed;
}
void resetClaw(){
	setClawLeft(0);
	setClawRight(0);
}

void setClawLeftPosition(int position){
	int clawLeftPosition= position;

	if(SensorValue[clawLeftPot]<clawLeftPosition){
		while(SensorValue[clawLeftPot]<clawLeftPosition){
			setClawLeft(127);
		}
		setClawLeft(-127);
		wait1Msec(100);
		setClawLeft(0);
	}
	else{
		while(SensorValue[clawLeftPot]>clawLeftPosition){
			setClawLeft(-127);
		}
		setClawLeft(127);
		wait1Msec(100);
		setClawLeft(0);
	}
}

void setClawRightPosition(int position){
	int clawRightPosition = position;
	if(clawRightPosition<SensorValue[clawRightPot]){
		while(clawRightPosition<SensorValue[clawRightPot]){
			setClawRight(127);
		}
		setClawRight(-127);
		wait1Msec(100);
		setClawRight(0);
	}
	else{
		while(clawRightPosition>SensorValue[clawRightPot]){
			setClawRight(-127);
		}
		setClawRight(127);
		wait1Msec(100);
		setClawRight(0);
	}
}


void clawLeftSetPosition(int position){
	setPosition = position;
}
