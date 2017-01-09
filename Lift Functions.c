int liftPositionBottom = 0;
int liftPositionMid = 300;
int liftPositionTop = 1000;
int liftPositionFence = 700;
void setLiftLeft(int speed){
	motor[liftLeftMid]= speed;
	motor[liftLeftOut] = speed;
	motor[liftLeftTop] = speed;

}

void setLiftRight(int speed){
	motor[liftRightMid]= speed;
	motor[liftRightOut] = speed;
	motor[liftRightTop] = speed;
}

void setLift(int speed){
	setLiftLeft(speed);
	setLiftRight(speed);
}

void resetLift(){
	setLift(0);
}

void setLiftPosition(int position){
	if(position>nMotorEncoder[liftLeftOut]){
		while(position>nMotorEncoder[liftLeftOut]){
			setLift(127);
			wait1Msec(10);
		}
		setLift(-10);
		wait1Msec(100);
		resetLift();
		wait1Msec(1);
	}
	else{
		while(position<nMotorEncoder[liftLeftOut]){
			setLift(-127);
			wait1Msec(10);
		}
		setLift(10);
		wait1Msec(100);
		resetLift();
		wait1Msec(1);
	}

}
