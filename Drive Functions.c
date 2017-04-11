int driveTurn90 = 412;
int driveTurn180 = 823;
void setDriveLeft(int speed) // sets left side of drive to speed
{
	motor[port4] = speed;
}

void setDriveRight(int speed) // sets right side of drive to speed
{
	motor[port2] = speed;
}
void setDrive(int speed){
	setDriveLeft(speed);
	setDriveRight(speed);
}
void resetDrive()// sets drive speed to 0
{
	setDriveLeft(0);
	setDriveRight(0);
}

void setDriveForwardDistance(int distance, int direction){
	SensorValue(driveLeftQuad) = 0;
	SensorValue(driveRightQuad) = 0;
	if(direction >0){
		while((SensorValue(driveLeftQuad) + SensorValue(driveRightQuad))/2 < distance){
			setDrive(127);
		}
		setDrive(-127);
		wait1Msec(100);
		setDrive(0);
		wait1Msec(10);
	}
	else{
		while((SensorValue(driveLeftQuad) + SensorValue[driveRightQuad])/2 > distance){
			setDrive(-127);
		}
		setDrive(127);
		wait1Msec(100);
		setDrive(0);
		wait1Msec(10);
	}
}
void setDriveForwardDistance(int distance, int direction, int maxTime){
	SensorValue(driveLeftQuad) = 0;
	SensorValue(driveRightQuad) = 0;
	int time=0;
	if(direction >0){
		while(((SensorValue(driveLeftQuad) + SensorValue(driveRightQuad))/2 < distance) && time<maxTime){
			setDrive(127);
			time++;
			wait1Msec(1);
		}
		setDrive(-127);
		wait1Msec(100);
		setDrive(0);
		wait1Msec(10);
	}
	else{
		while(((SensorValue(driveLeftQuad) + SensorValue[driveRightQuad])/2 > distance) && time<maxTime){
			setDrive(-127);
			time++;
			wait1Msec(1);
		}
		setDrive(127);
		wait1Msec(100);
		setDrive(0);
		wait1Msec(10);
	}
}

void setDriveTurn(int distance, int direction){
	SensorValue(driveLeftQuad) = 0;
	SensorValue(driveRightQuad) = 0;
	while(((abs(SensorValue(driveLeftQuad))+ abs(SensorValue(driveRightQuad)))/2)<distance) {
		if(direction>0){
			setDriveLeft(120);
			setDriveRight(-120);
		}
		else{
			setDriveLeft(-120);
			setDriveRight(120);
		}
	}
	if(direction>0){
		setDriveLeft(-120);
		setDriveRight(120);
		wait1Msec(100);

	}
	else{
		setDriveLeft(120);
		setDriveRight(-120);
		wait1Msec(100);

	}
	resetDrive();
}

void gyroTurn(char* direction, float deg, int load, int kick){
	SensorValue[in8]=0;
	float integralMax = 30;//gyroKi;
	int counter = 0;
	int totalTime = 0;
	int time = kick;
	int degrees = deg*10;
	int gyroError =0;
	int gyroIntegral = 0;
	int gyroDerivative = 0;
	int gyroLastError = gyroError;
	int pGyro = 0;
	float gyroKp = 0.12;//.12
	float gyroKi = 0;
	float gyroKd = 0.17;//.17

	while(counter < 15 && totalTime < time){
		gyroIntegral += gyroError;

		if(direction == "r"){
			gyroError = degrees+SensorValue[in8];
		}
		else if(direction == "l"){
			gyroError = degrees-SensorValue[in8];
		}

		if(abs(gyroIntegral)>integralMax) gyroIntegral = integralMax;

		if(abs(gyroError) < 60) counter++;
		else counter = 0;

		gyroDerivative = gyroError-gyroLastError;

		pGyro = gyroKp*gyroError + gyroKi*gyroIntegral + gyroKd*gyroDerivative;

		if(pGyro > 127) pGyro = 127;
		//else if((pGyro > 0) && (pGyro < 11)) pGyro = 11;
		else if(pGyro < -127) pGyro = -127;
		//else if((pGyro < 0) && (pGyro > -11)) pGyro = -11;

		if(direction == "r"){
			setDriveLeft(pGyro);
			setDriveRight(-pGyro);
		}
		else if(direction == "l"){
			setDriveLeft(-pGyro);
			setDriveRight(pGyro);
		}

		gyroLastError = gyroError;

		totalTime++;
		wait1Msec(100);
	}

	setDrive(0);
}
