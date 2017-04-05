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

void setLiftLeft(int speed){
	motor[liftLeftMiddle]= speed;
	motor[liftLeftBottomOutside] = speed;
	motor[liftLeftTopOutside] = speed;

}

void setLiftRight(int speed){
	motor[liftRightMiddle]= speed;
	motor[liftRightBottomOutside] = speed;
	motor[liftRightTopOutside] = speed;
}

void setLift(int speed){
	setLiftLeft(speed);
	setLiftRight(speed);
}

void resetLift(){
	setLift(0);
}

void setLiftPosition(int position){
	runPID_lift = false;
	if(position>SensorValue(liftQuad)){
		while(position>SensorValue(liftQuad)){
			setLift(127);
			wait1Msec(10);
		}
		setLift(-10);
		wait1Msec(100);
		resetLift();
		setPosition_lift = SensorValue(liftQuad);
		wait1Msec(1);
		runPID_lift=true;
	}
	else{
		runPID_lift =false;
		while(position<SensorValue(liftQuad)){
			setLift(-80);
			wait1Msec(10);
		}
		setLift(10);
		wait1Msec(100);
		resetLift();
		setPosition_lift = SensorValue(liftQuad);
		wait1Msec(1);
		runPID_lift=true;

	}

}

void setLiftPositionSlow(int position){
	runPID_lift = false;
	if(position>SensorValue(liftQuad)){
		while(position>SensorValue(liftQuad)){
			setLift(60);
			wait1Msec(10);
		}
		setLift(-10);
		wait1Msec(100);
		resetLift();
		setPosition_lift = SensorValue(liftQuad);
		wait1Msec(1);
		runPID_lift=true;
	}
	else{
		runPID_lift =false;
		while(position<SensorValue(liftQuad)){
			setLift(-80);
			wait1Msec(10);
		}
		setLift(10);
		wait1Msec(100);
		resetLift();
		setPosition_lift = SensorValue(liftQuad);
		wait1Msec(1);
		runPID_lift=true;

	}

}


void setLiftPosition(int position, int maxTime){
	int time = 0;
	runPID_lift = false;
	if(position>SensorValue(liftQuad)){
		while(position>SensorValue(liftQuad)&& time<maxTime){
			setLift(127);
			wait1Msec(1);
			time++;
		}
		setLift(-10);
		wait1Msec(100);
		resetLift();
		setPosition_lift = SensorValue(liftQuad);
		wait1Msec(1);
		runPID_lift=true;
	}
	else{
		runPID_lift =false;
		while(position<SensorValue(liftQuad)&& time<maxTime){
			setLift(-80);
			wait1Msec(1);
			time++;
		}
		setLift(10);
		wait1Msec(100);
		resetLift();
		setPosition_lift = SensorValue(liftQuad);
		wait1Msec(1);
		runPID_lift=true;

	}

}
