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
