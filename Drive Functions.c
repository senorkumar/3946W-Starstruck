void setDriveLeft(int speed) // sets left side of drive to speed
{
	motor[driveLeft] = speed;
}

void setDriveRight(int speed) // sets right side of drive to speed
{
	motor[driveRight] = speed;
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
	nMotorEncoder[driveLeft] = 0;
	nMotorEncoder[driveRight] = 0;
	if(direction >0){
		while((nMotorEncoder[driveLeft] + nMotorEncoder[driveRight])/2 < distance){
			setDrive(127);
		}
		setDrive(-127);
		wait1Msec(100);
		setDrive(0);
		wait1Msec(1);
	}
	else{
		while((nMotorEncoder[driveLeft] + nMotorEncoder[driveRight])/2 > distance){
			setDrive(-127);
		}
		setDrive(127);
		wait1Msec(100);
		setDrive(0);
		wait1Msec(1);
	}


}
