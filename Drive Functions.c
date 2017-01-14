int driveTurn90 = 510;
int driveTurn180 = 1030;
void setDriveLeft(int speed) // sets left side of drive to speed
{
	motor[port3] = speed;
}

void setDriveRight(int speed) // sets right side of drive to speed
{
	motor[port5] = speed;
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
			setDriveLeft(127);
			setDriveRight(-127);
		}
		else{
			setDriveLeft(-127);
			setDriveRight(127);
		}
	}
	if(direction>0){
		setDriveLeft(-127);
		setDriveRight(127);
		wait1Msec(100);

	}
	else{
		setDriveLeft(127);
		setDriveRight(-127);
		wait1Msec(100);

	}
	resetDrive();
}
