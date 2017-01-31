void auton_fence(){ // hit stars off fence

	//setDriveForwardDistance(300,1);
	//clawLeftSetPosition(clawLeftPositionOpen);
	//clawRightSetPosition(clawRightPositionOpen);
	//setLiftPosition(liftPositionStart);
	//wait1Msec(300);
	//setDriveForwardDistance(2600,1); // end here for bryan
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(1000);
	setDriveForwardDistance(-1000,-1);




}


void auton_cubepush(){
	setDriveForwardDistance(300,1);
	clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
//	setLiftPosition(liftPositionStart);
	setLiftPosition(liftPositionBottom);
	setDriveForwardDistance(2600,1);
	setDriveForwardDistance(-300,-1);
}

void auton_fencecube(){ // hit stars off fence, then picks up cube
	clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
	wait1Msec(300);
	setDriveForwardDistance(300,1);
	setLiftPosition(liftPositionFence);
	wait1Msec(3000);
	wait1Msec(500);
	setDriveForwardDistance(2200,1); // end here for bryan
	wait1Msec(200);
	setDriveForwardDistance(-1650,-1);
	wait1Msec(300);//was 300
	//setLiftPosition(liftPositionMid);
	//wait1Msec(300);//was 300
	//setDriveTurn(driveTurn90,1);
	//wait1Msec(300);//was 300
	//setLiftPosition(liftPositionBottom);
	//wait1Msec(300);//was 300
	//setDriveForwardDistance(1700,1);
	//wait1Msec(1);
	//clawLeftSetPosition(clawLeftPositionClosed);
	//clawRightSetPosition(clawRightPositionClosed);
	//wait1Msec(500);//was 1000
	//setLiftPosition(500);
	//wait1Msec(500);
	//setDriveTurn(470,1);
	//wait1Msec(250);//250
	//setDriveForwardDistance(-1400,-1,750);
	//wait1Msec(0);//was 500
	//setLiftPosition(liftPositionTop);
	//wait1Msec(300);//was 700
	//setLiftPosition(liftPositionBottom);
	//wait1Msec(200);
	//setDriveForwardDistance(1800,1);
	//wait1Msec(0);//was 1000
	//clawLeftSetPosition(3750);
	//clawRightSetPosition(150);
	//wait1Msec(750);//
	//setLiftPosition(500);
	//setDriveForwardDistance(-2000,-1,1000);
	//setLiftPosition(liftPositionTop);


}
void auton_programmingskills(){
	clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
	wait1Msec(100);
  setLiftPosition(liftPositionFence);
	wait1Msec(1000);
	setDriveForwardDistance(2300,1);
	wait1Msec(500);
	setDriveForwardDistance(-1550,-1);
	wait1Msec(500);//was 100
	setLiftPosition(liftPositionBottom);
	wait1Msec(1000);//was 300
	setDriveTurn(driveTurn180,1);
	wait1Msec(1000);//was 300
	clawLeftSetPosition(clawLeftPositionClosed);
  clawRightSetPosition(clawRightPositionClosed);
  wait1Msec(500);
  setLiftPosition(liftPositionMid);
	wait1Msec(1000);
  setDriveForwardDistance(-1700,-1);
  wait1Msec(200);
  setLiftPosition(liftPositionThrow);
  wait1Msec(500);
  setLiftPosition(liftPositionBottom);
  setDriveForwardDistance(1700,1);
  wait1Msec(1000);
  clawLeftSetPosition(clawLeftPositionClosed);
  clawRightSetPosition(clawRightPositionClosed);
  wait1Msec(300);
  setLiftPosition(liftPositionMid);
  setDriveForwardDistance(-1700,-1);
  wait1Msec(200);
  setLiftPosition(liftPositionThrow);
  wait1Msec(500);
  setLiftPosition(liftPositionBottom);
  wait1Msec(100);
   clawLeftSetPosition(clawLeftPositionHalf);
  clawRightSetPosition(clawRightPositionHalf);
  setDriveForwardDistance(15,1);
  setDriveTurn(driveTurn90,-1);
  setDriveForwardDistance(3400,1);




//	wait1Msec(1000);
//	setLiftPosition(liftPositionBottom);
//	setDriveForwardDistance(1900,1);
//	wait1Msec(1000);
//	clawLeftSetPosition(clawLeftPositionClosed);
//	clawRightSetPosition(clawRightPositionClosed);
//	wait1Msec(1000);
//	setLiftPosition(liftPositionMid);
//	wait1Msec(300);
//	setDriveForwardDistance(-1800,-1);
//	//setLiftPosition(liftPositionTop2Cubes);
//	wait1Msec(300);
//	setLiftPosition(liftPositionMid);
//	wait1Msec(1000);
//	setDriveForwardDistance(1500,1);
//	wait1Msec(1000);
////	setDriveTurn(driveTurn90,-1);
//	wait1Msec(1000);
//	setDriveForwardDistance(-1200,-1,2000);
//	wait1Msec(1000);
//	setDriveForwardDistance(1200,1);
//	wait1Msec(1000);
//	setLiftPosition(liftPositionBottom);
//	wait1Msec(1000);
//	setDriveForwardDistance(1000,1);
//	wait1Msec(500);
//	clawLeftSetPosition(clawLeftPositionClosed);
//	clawRightSetPosition(clawRightPositionClosed);
//	wait1Msec(500);//was 1000
//	setLiftPosition(500);
//	wait1Msec(500);
//	setDriveTurn(470,1);
//	wait1Msec(100);//250
//	setDriveForwardDistance(-1400,-1,750);
//	wait1Msec(1000);//was 500
//	setLiftPosition(liftPositionTop);
//	wait1Msec(300);//was 700
//	setLiftPosition(liftPositionBottom);
//	wait1Msec(200);
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
//void auton_fence_doublestarRight(){
//	setDriveForwardDistance(300,1);
//	clawLeftSetPosition(clawLeftPositionOpen);
//	clawRightSetPosition(clawRightPositionOpen);
//	setLiftPosition(liftPositionStart);
//	wait1Msec(700);
//	setDriveForwardDistance(2600,1); // end here for bryan
//	wait1Msec(100);
//	setDriveForwardDistance(-1650,-1);
//	wait1Msec(1000);//was 100
//	setLiftPosition(liftPositionMid);
//	wait1Msec(1000);//was 300
//	setDriveTurn(900,1);
//	wait1Msec(500);
//	setLiftPosition(liftPositionBottom);
//	setDriveForwardDistance(900,1);
//	wait1Msec(500);
//	resetLiftEncoder();
//	clawLeftSetPosition(clawLeftPositionClosed);
//	clawRightSetPosition(clawRightPositionClosed);
//	wait1Msec(800);
//	setLiftPosition(liftPositionMid);
//	wait1Msec(100);
//	setDriveForwardDistance(-2200,-1,1000);
//	wait1Msec(300);
//	setLiftPosition(1100);
//	wait1Msec(1);
//}
void auton_test(){
  setDriveTurn(driveTurn90,-1);


}
