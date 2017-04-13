int liftPositionBottom = 0;
int liftPositionStart = 180;
int liftPositionMid = 230;
int liftPositionTop = 780;
int liftPositionFence = 450;
int liftPositionThrow = 630;


int liftPositionMax = 650;



float kP_lift = 0.7;
float error_lift = 0;

int currentPositon_lift = SensorValue(liftQuad);
int setPosition_lift = 0;



bool runPID_lift = true;



void resetLiftEncoder(){
	SensorValue(liftQuad) = 0;
}

void lift(int speed){
	motor[liftLeftMiddle]= speed;
	motor[liftLeftBottomOutside] = speed;
	motor[liftLeftTopOutside] = speed;
	motor[liftRightMiddle]= speed;
	motor[liftRightBottomOutside] = speed;
	motor[liftRightTopOutside] = speed;
}

void liftPID(int ticks){
	error_lift = ticks - SensorValue[liftQuad];
	lift(kP_lift * error_lift);
}

void setLiftPosition(int ticks){
	setPosition_lift = ticks;
}

task holdLift(){
	while(1){
		liftPID(setPosition_lift);
		if(SensorValue[liftQuad] > 500){
			setClawLeft(clawLeftPositionOpen);
			setClawRight(clawRightPositionOpen);
		}
		wait1Msec(10);
	}
}
