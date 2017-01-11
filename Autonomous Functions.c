void auton_fence(){ // hit stars off fence

	setDriveForwardDistance(300,1);
	clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
	setLiftPosition(liftPositionStart);
	wait1Msec(300);
	setDriveForwardDistance(2600,1); // end here for bryan
}

void auton_cubepush(){
	setDriveForwardDistance(300,1);
	clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
	setLiftPosition(liftPositionStart);
	setLiftPosition(liftPositionBottom);
	setDriveForwardDistance(2600,1);
	setDriveForwardDistance(-300,-1);
}

void auton_fencecube(){ // hit stars off fence, then picks up cube
	setDriveForwardDistance(300,1);
	clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
	setLiftPosition(liftPositionStart);
	wait1Msec(300);
	setDriveForwardDistance(2600,1); // end here for bryan
	wait1Msec(300);
	setDriveForwardDistance(-1650,-1);
	wait1Msec(300);
	setLiftPosition(liftPositionMid);
	wait1Msec(300);
	setDriveTurn(driveTurn90,1);
	wait1Msec(300);
	setLiftPosition(liftPositionBottom);
	wait1Msec(300);
	setDriveForwardDistance(1300,1);
	wait1Msec(1);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(1000);
	setLiftPosition(400);
	wait1Msec(500);
	setDriveTurn(470,1);
	setDriveForwardDistance(-1400,-1,2000);
	wait1Msec(500);
	setLiftPosition(liftPositionTop);
	wait1Msec(700);
	setLiftPosition(liftPositionBottom);
	wait1Msec(200);
	setDriveForwardDistance(2000,1);
	wait1Msec(1000);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);



}
void auton_test(){

}
