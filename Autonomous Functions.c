void auton_midlane_left(){ //grabs 2 stars + cube, throw, grab 3 stars, throw
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
void auton_programmingskills(){
	clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
	wait1Msec(100);
	setLiftPosition(liftPositionFence);
	wait1Msec(1000);
	setDriveForwardDistance(2500,1);
	wait1Msec(500);
	setDriveForwardDistance(-1550,-1);
	wait1Msec(500);//was 100
	setLiftPosition(liftPositionBottom);
	wait1Msec(500);//was 300
	setDriveTurn(driveTurn180,1);
	wait1Msec(500);//was 300
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(500);
	setLiftPosition(liftPositionMid);
	wait1Msec(1000);
	setDriveForwardDistance(-1800,-1,1300);
	wait1Msec(500);
	setLiftPosition(liftPositionThrow);
	wait1Msec(500);
	setLiftPosition(liftPositionBottom);
	setDriveForwardDistance(1700,1);
	wait1Msec(500);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(500);
	setLiftPosition(liftPositionMid,500);
	wait1Msec(1000);
	setDriveForwardDistance(-1700,-1,1300);
	wait1Msec(200);
	setLiftPosition(liftPositionThrow);
	wait1Msec(500);
	setLiftPosition(liftPositionBottom);
	clawLeftSetPosition(clawLeftPositionHalf);
	clawRightSetPosition(clawRightPositionHalf);
	wait1Msec(100);
	setDriveForwardDistance(-20,-1);
	wait1Msec(1000);
	setDriveForwardDistance(140,1);
	wait1Msec(500);
	setDriveTurn(driveTurn90,-1);
	wait1Msec(100);
	setDriveForwardDistance(3400,1);
	clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
	wait1Msec(1);
	setDriveForwardDistance(600,1);
	wait1Msec(1);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(600);
	setLiftPosition(liftPositionMid,1000);
	wait1Msec(1000);
	setDriveForwardDistance(-150,-1);
	wait1Msec(100);
	setDriveTurn(360,1);
	wait1Msec(500);
	setDriveForwardDistance(-400,-1,500);
	wait1Msec(500);
	setLiftPosition(liftPositionThrow);
	wait1Msec(300);
	setLiftPosition(liftPositionBottom);
	wait1Msec(100);
	setDriveForwardDistance(-400,-1,500);
	wait1Msec(500);
	setDriveForwardDistance(1475,1);
	wait1Msec(100);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(600);
	setLiftPosition(liftPositionMid,1000);
	wait1Msec(10);
	setDriveForwardDistance(-2300,-1,2000);
	wait1Msec(1);
	setLiftPosition(liftPositionThrow);
	wait1Msec(300);
	setLiftPosition(liftPositionBottom);
	clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
	wait1Msec(1000);
	setDriveForwardDistance(985,1);
	wait1Msec(300);
	setDriveTurn(driveTurn90,1);
	wait1Msec(300);
	setDriveForwardDistance(-1300,-1,1500);
	wait1Msec(300);
	setDriveForwardDistance(2300,1);
	wait1Msec(300);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(500);
	setLiftPosition(liftPositionMid);
	wait1Msec(300);
	setDriveTurn(430,-1);
	wait1Msec(300);
	setDriveForwardDistance(-900,-1,1000);
	wait1Msec(100);
	setLiftPosition(liftPositionThrow);
	wait1Msec(300);
	setLiftPosition(liftPositionBottom);
	wait1Msec(300);
	setDriveForwardDistance(-300,-1,1000);
	wait1Msec(300);
	setDriveForwardDistance(1500,1);
	wait1Msec(100);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(500);
	setLiftPosition(liftPositionMid);
	wait1Msec(100);
	setDriveForwardDistance(-1500,-1);
	wait1Msec(300);
	setLiftPosition(liftPositionThrow);


}
//void auton_fence_doublestarLeft(){
//	setDriveForwardDistance(300,1);
//	clawLeftSetPosition(clawLeftPositionOpen);
//	clawRightSetPosition(clawRightPositionOpen);
//	setLiftPosition(liftPositionStart);
//	wait1Msec(1000);
//	setDriveForwardDistance(2600,1); // end here for bryan
//	wait1Msec(100);
//	setDriveForwardDistance(-1650,-1);
//	wait1Msec(1000);//was 100
//	setLiftPosition(liftPositionMid);
//	wait1Msec(1000);//was 300
//	setDriveTurn(900,-1);
//	wait1Msec(500);
//	setLiftPosition(liftPositionBottom);
//	setDriveForwardDistance(900,1);
//	wait1Msec(1000);
//	resetLiftEncoder();
//	clawLeftSetPosition(clawLeftPositionClosed);
//	clawRightSetPosition(clawRightPositionClosed);
//	wait1Msec(800);
//	setLiftPosition(liftPositionMid);
//	wait1Msec(100);
//	setDriveForwardDistance(-2200,-1);
//	wait1Msec(300);
//	setLiftPosition(1100);
//	wait1Msec(1);
//}
void auton_fence_doublestarRight(){
	setDriveTurn(45,1);
	wait1Msec(100);
	clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
	wait1Msec(100);
	setLiftPosition(liftPositionFence);
	wait1Msec(1500);
	setDriveForwardDistance(2300,1);
	wait1Msec(800);
	setDriveForwardDistance(-1350,-1);
	wait1Msec(500);//was 100
	setLiftPosition(liftPositionBottom);
	wait1Msec(800);//was 300
	setDriveForwardDistance(-1000,-1);
	//setDriveTurn(740,1);
	//wait1Msec(300);//was 300
	//setDriveForwardDistance(600,1);
	//wait1Msec(300);
	//clawLeftSetPosition(clawLeftPositionClosed);
	//clawRightSetPosition(clawRightPositionClosed);
	//wait1Msec(900);
	//setLiftPosition(liftPositionMid);
	//wait1Msec(100);
	//setDriveForwardDistance(-1800,-1,1500);
	//wait1Msec(100);
	//setLiftPosition(liftPositionThrow);
	//wait1Msec(300);
	//setLiftPosition(liftPositionBottom);
	//wait1Msec(200);
	//setDriveForwardDistance(1000,1);
	//wait1Msec(300);
	//setDriveTurn(driveTurn90,1);
}
void auton_test(){
	clawLeftSetPosition(clawLeftPositionHalf);
	clawRightSetPosition(clawRightPositionHalf);

}
