void auton_red_left_main(){ //grabs 2 stars + cube, throw, grab 3 stars, throw
	setDriveForwardDistance(310,1);
	wait1Msec(100);
	clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
	wait1Msec(700);
	setDriveForwardDistance(1000,1);
	wait1Msec(300);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(500);
	setLiftPosition(100);
	wait1Msec(100);
	//setDriveForwardDistance(1500,1);
	wait1Msec(200);
	setDriveTurn(550,1);
	wait1Msec(400);
	setDriveForwardDistance(-1200,-1,1000);
	wait1Msec(400);
	setLiftPosition(liftPositionThrow);
	wait1Msec(300);
	setLiftPosition(liftPositionBottom);
	wait1Msec(200);
	setDriveForwardDistance(1580,1);
	wait1Msec(100);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(400);
	setLiftPosition(liftPositionMid);
	wait1Msec(100);
	setDriveForwardDistance(-1600,-1);
	wait1Msec(300);
	setLiftPosition(liftPositionThrow);
	wait1Msec(500);
	setLiftPosition(liftPositionBottom);
}

void auton_red_left_alt(){
}

void auton_red_right_main(){
}

void auton_red_right_alt(){

}

void auton_red_right_E(){
}

void auton_blue_left_main(){
	clawLeftSetPosition(clawLeftPositionHalf);
	clawRightSetPosition(clawRightPositionHalf);
	setLiftPosition(liftPositionStart);
	wait1Msec(1);
	setLiftPosition(liftPositionBottom);
	wait1Msec(510);
	SensorValue(liftQuad)=0;
	clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
	setDriveForwardDistance(350,1);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(300);
	setLiftPosition(350);
	wait1Msec(500);
	gyroTurn("r",120,1,15);
	wait1Msec(500);
	setDriveForwardDistance(-500,-1,1000);
	wait1Msec(1);
	setDrive(-50);
	wait1Msec(300);
	setLiftPosition(liftPositionTop);
	wait1Msec(300);
	setLiftPosition(liftPositionBottom);
	wait1Msec(1);
	setDrive(0);
	wait1Msec(10);
	setDriveForwardDistance(500,1);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(300);
	setLiftPosition(liftPositionMid);
	wait1Msec(1);
	setDriveForwardDistance(-500,-1);
	wait1Msec(1);
	setDrive(-127);
	setLiftPosition(liftPositionTop);
	wait1Msec(300);
	setLiftPosition(liftPositionBottom);
	setDrive(0);


}

void auton_blue_left_alt(){
	runThrow = false;
	clawLeftSetPosition(clawLeftPositionFlat);
	clawRightSetPosition(clawRightPositionFlat);
	setLiftPosition(480);
	setDriveForwardDistance(600,1);
	wait1Msec(300);
	setDriveForwardDistance(-300,-1);
	wait1Msec(100);
	setLiftPosition(0);
	wait1Msec(300);
	gyroTurn("l",180,1,15);
	setDriveForwardDistance(250,1);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(500);
	runThrow=true;
	setLiftPosition(200);
	setDriveForwardDistance(-500,-1);
	setLiftPosition(liftPositionTop);




}

void auton_blue_right_main(){
}

void auton_blue_right_alt(){
	runThrow = false;
	clawLeftSetPosition(clawLeftPositionFlat);
	clawRightSetPosition(clawRightPositionFlat);
	setLiftPosition(480);
	setDriveForwardDistance(600,1);
	wait1Msec(300);
	setDriveForwardDistance(-300,-1);
	wait1Msec(100);
	setLiftPosition(0);
	wait1Msec(300);
	gyroTurn("r",180,1,15);
	setDriveForwardDistance(250,1);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(500);
	runThrow=true;
	setLiftPosition(200);
	setDriveForwardDistance(-500,-1);
	setLiftPosition(liftPositionTop);


}

void auton_blue_right_E(){
}

void auton_programmingskills(){
	setDriveForwardDistance(-200,-1);
	clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
	wait1Msec(800);
	setDriveForwardDistance(100,1);
	wait1Msec(1000);
	clawLeftSetPosition(clawLeftPositionPreloadClosed);
	clawRightSetPosition(clawRightPositionPreloadClosed);
	wait1Msec(300);
	setLiftPosition(200);
	setDriveForwardDistance(-550,-1);
	setDrive(-50);
	setLiftPosition(liftPositionTop);
	wait1Msec(100);
	setLiftPosition(liftPositionBottom);
	setDrive(0);
	wait1Msec(500);
	SensorValue(liftQuad) = 0;
	setDriveForwardDistance(550,1);
	wait1Msec(1000);
	clawLeftSetPosition(clawLeftPositionPreloadClosed);
	clawRightSetPosition(clawRightPositionPreloadClosed);
	wait1Msec(300);
	setLiftPosition(200);
	setDriveForwardDistance(-550,-1);
	setDrive(-50);
	setLiftPosition(liftPositionTop);


}


void auton_test(){
	clawLeftSetPosition(clawLeftPositionFlat);
	clawRightSetPosition(clawRightPositionFlat);

}
