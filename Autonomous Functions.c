

void auton_red_left_E(){
}

void auton_red_right_main(){
	clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
	wait1Msec(500);
	setDriveForwardDistance(1000,1);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(250);
	setLiftPosition(281);
	gyroTurn("l",120,1,15);
	setDriveForwardDistance(-500,-1,2000,false);
	setLiftPosition(746);
	setDriveForwardDistance(-1000,-1,2000);
  setDrive(-50);
  wait1Msec(3800);
  setDrive(0);
  wait1Msec(1000);
  clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
  setLiftPosition(liftPositionBottom);
  wait1Msec(1100);
  setDriveForwardDistance(1250,1,1500);
  clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(400);
	setLiftPosition(746);
	setDriveForwardDistance(-1250,-1,2000);


}


void auton_red_right_alt(){
	clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
	setLiftPosition(358);
	setDriveForwardDistance(1250,1,2500);

}

void auton_red_right_E(){
	setDriveForwardDistance(-100,-1);
	clawLeftSetPosition(clawLeftPositionE);
	clawRightSetPosition(clawRightPositionE);
	setLiftPosition(liftPositionStart);
	wait1Msec(1);
	setLiftPosition(liftPositionBottom);
	wait1Msec(300);
	SensorValue(liftQuad)=0;
	setDriveForwardDistance(550,1,5000);
	clawRightSetPosition(clawRightPositionOpen);
	setDriveForwardDistance(700,1,2000);
	//setDriveForwardDistance(-150,-1);
	//wait1Msec(1000);
	//setDriveForwardDistance(150,1,1000);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(500);
	//setDriveForwardDistance(-100,-1);
	setDriveForwardDistance(-100,-1);
	setLiftPosition(400);
	wait1Msec(300);
	gyroTurn("l",90,1,20);
	setDriveForwardDistance(-1000,-1,2000);
	setDrive(-50);
	setLiftPosition(liftPositionTop);
	wait1Msec(300);
	setLiftPosition(liftPositionBottom);
	setDrive(0);
	setDriveForwardDistance(300,1);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(300);
	setDriveForwardDistance(-300,-1,500);
	setLiftPosition(liftPositionTop);






}

void auton_blue_left_main(){



}

void auton_blue_left_alt(){
	runThrow = false;
	clawLeftSetPosition(clawLeftPositionFlat);
	clawRightSetPosition(clawRightPositionFlat);
	wait1Msec(100);
	setLiftPosition(480);
	setDriveForwardDistance(700,1,1500);
	wait1Msec(300);
	setDriveForwardDistance(-400,-1);
	wait1Msec(100);
	setLiftPosition(0);
	wait1Msec(300);
	gyroTurn("l",170,1,15);
	SensorValue(liftQuad)= 0;
	setDriveForwardDistance(200,1);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(500);
	runThrow=true;
	setLiftPosition(200);
	setDriveForwardDistance(-500,-1);
	setDrive(-50);
	setLiftPosition(liftPositionTop);
	setDrive(0);
}

void auton_blue_left_E(){
}

void auton_blue_right_main(){
	auton_red_right_main();
}

void auton_blue_right_alt(){
	auton_red_right_alt();



}

void auton_blue_right_E(){
}

void auton_programmingskills(){
	setDriveForwardDistance(-200,-1);
	clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
	wait1Msec(800);
	setDriveForwardDistance(100,1);
	wait1Msec(666);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(500);
	setDriveForwardDistance(-550,-1,2000);
	setDrive(-50);
	setLiftPosition(liftPositionTop);
	wait1Msec(100);
	setLiftPosition(liftPositionBottom);
	setDrive(0);
	wait1Msec(500);
	SensorValue(liftQuad) = 0;
	setDriveForwardDistance(500,1);
	wait1Msec(666);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(300);
	setLiftPosition(150);
	setDriveForwardDistance(-500,-1,2000);
	setDrive(-50);
	setLiftPosition(liftPositionTop);
	wait1Msec(100);
	setLiftPosition(liftPositionBottom);
	setDrive(0);

	setDriveForwardDistance(500,1);
	wait1Msec(1000);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(300);
	setLiftPosition(150);
	setDriveForwardDistance(-500,-1,2000);
	setDrive(-50);
	setLiftPosition(liftPositionTop);
	wait1Msec(100);
	setLiftPosition(liftPositionBottom);
	setDrive(0);

	clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
	setDriveForwardDistance(310,1);
	gyroTurn("l",90,1,25);
	setDriveForwardDistance(-500,-1,1000);
	setDrive(-50);
	wait1Msec(500);
	setDrive(0);
	setDriveForwardDistance(700,1);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(300);
	setDriveForwardDistance(-490,-1);
	setLiftPosition(liftPositionMid);
	wait1Msec(300);
	gyroTurn("r",90,1,20);
	setDriveForwardDistance(-300,-1,2000);
	setDrive(-50);
	setLiftPosition(liftPositionTop);
	wait1Msec(100);
	setLiftPosition(liftPositionBottom);
	setDrive(0);

	clawLeftSetPosition(clawLeftPositionHalf);
	clawRightSetPosition(clawRightPositionHalf);
	setDriveForwardDistance(83,1);
	gyroTurn("l",90,1,20);
	setDriveForwardDistance(790,1);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(300);
	setDriveForwardDistance(-150,-1);
	setLiftPosition(liftPositionMid);
	gyroTurn("r",90,1,20);
	setDriveForwardDistance(-200,-1,700);
	setDrive(-50);
	setLiftPosition(liftPositionTop);
	wait1Msec(100);
	setLiftPosition(liftPositionBottom);
	setDrive(0);

	setDriveForwardDistance(500,1,1000);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(400);
	setDriveForwardDistance(-500,-1,1000);
	setDrive(-50);
	setLiftPosition(liftPositionTop);
	wait1Msec(100);
	setLiftPosition(liftPositionBottom);
	setDrive(0);

	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	setDriveForwardDistance(110,1);
	gyroTurn("l",89,1,15);
	setDriveForwardDistance(400,1);
	gyroTurn("r",90,1,15);
	clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
	wait1Msec(500);
	setDriveForwardDistance(470,1,1500);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(700);
	setDriveForwardDistance(-500,-1,2000);
	setDrive(-50);
	setLiftPosition(liftPositionTop);
	wait1Msec(100);
	setLiftPosition(liftPositionBottom);
	clawLeftSetPosition(clawLeftPositionHalf);
	clawRightSetPosition(clawRightPositionHalf);
	setDrive(0);
	setDriveForwardDistance(300,1);
	gyroTurn("l",46,1,15);
	setDriveForwardDistance(200,1);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(200);
	gyroTurn("r",180,1,15);
	clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
	setDriveForwardDistance(-200,-1,1000);
	//setLiftPositionSlow(liftPositionTop);
}
void auton_red_left_main(){ //grabs 2 stars + cube, throw, grab 3 stars, throw
	auton_blue_left_main();
}



void auton_test(){
	setDriveForwardDistance(1000,1,4000);
}

void auton_red_left_alt(){
	auton_blue_left_alt();

}
