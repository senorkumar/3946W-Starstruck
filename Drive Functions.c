void setDriveLeft(int speed) // sets left side of drive to speed
{
	motor[driveLeft] = speed;
}

void setDriveRight(int speed) // sets right side of drive to speed
{
	motor[driveRight] = speed;
}
//void resetDrive()// sets drive speed to 0
//{
//	setDriveLeft(0);
//	setDriveRight(0);
//}

//void setDrive(string direction, int speed) // sets drive direction and to specific speed
//{

//	if(direction == "left"){
//		setDriveLeft(speed);
//	}
//	else if(direction == "right"){
//		setDriveRight(speed);
//	}
//	else if(direction == "forward"){
//		setDriveLeft(speed);
//		setDriveRight(speed);
//	}
//	else if(direction == "turn"){
//		if(speed>0){
//			setDriveRight(-speed);
//			setDriveLeft(speed);
//		}
//		else{
//			setDriveRight(speed);
//			setDriveLeft(-speed);
//		}
//	}
//}

//void setDriveDistance(string direction, int distance, int speed){ // uses sensors to drive robot a encoder value
//	//resetDrive();
//	//resetDriveSensors();


//	//if(direction == "left"){
//	//	while(SensorValue(driveLeftQuad)<distance){
//	//			setDriveLeft(speed);
//	//			wait1Msec(1);
//	//	}
//	//	wait1Msec(1);
//	//	setDriveLeft(0);
//	//}
//	//else if(direction == "right"){
//	//		while(SensorValue(driveRightQuad)<distance){
//	//			setDriveRight(speed);
//	//			wait1Msec(1);
//	//	}
//	//	wait1Msec(1);
//	//	setDriveRight(0);
//	//}
//	//else if(direction == "forward"){
//	//	setDriveLeft(speed);
//	//	setDriveRight(speed);
//	//}
//	//else if(direction == "turn"){
//	//	if(speed>0){
//	//		setDriveRight(-speed);
//	//		setDriveLeft(speed);
//	//	}
//	//	else{
//	//		setDriveRight(speed);
//	//		setDriveLeft(-speed);
//	//	}
//}
//int limit(int input){
//	if(input<15 && input>-15){
//		return 0;
//	}
//	else{
//		return input;
//	}

//}
