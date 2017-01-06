void setClawLeft(int speed){
	motor[clawLeft]= speed;
}

void setClawRight(int speed){
	motor[clawRight]= speed;
}
void resetClaw(){
	setClawLeft(0);
	setClawRight(0);
}

void setClawLeftPosition(int position){
	int clawLeftPosition= position;

	if(SensorValue[clawLeftPot]<clawLeftPosition){
		while(SensorValue[clawLeftPot]<clawLeftPosition){
			setClawLeft(127);
		}
		setClawLeft(0);
	}
	else{
		while(SensorValue[clawLeftPot]>clawLeftPosition){
			setClawLeft(-127);
		}
		setClawLeft(0);
	}
}

void setClawRightPosition(int position){
	int clawRightPosition = position;
	if(clawRightPosition<SensorValue[clawRightPot]){
		while(clawRightPosition<SensorValue[clawRightPot]){
			setClawRight(127);
		}
		setClawRight(0);
	}
	else{
		while(clawRightPosition>SensorValue[clawRightPot]){
			setClawRight(-127);
		}
		setClawRight(0);
	}
}
