const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;

static int count = 0; // declare count variable to keep track of our choice

//Wait for Press
void waitForPress()
{
	while(nLCDButtons == 0){}
	wait1Msec(5);
}

//Wait for Release
void waitForRelease()
{
	while(nLCDButtons != 0){}
	wait1Msec(5);
}

void WaitForPressAndRelease (int value = -1) {
	waitForPress();
	if(nLCDButtons == leftButton) {
		waitForRelease();
		if (value > 0) {
			count = value;
		}
		else {
			count--;
		}
	}
	else if(nLCDButtons == rightButton) {
		waitForRelease();
		if (value == 0) {
			count = 0;
		}
		else {
			count++;
		}
	}
}
