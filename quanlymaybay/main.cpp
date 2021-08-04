#include "include.h"
int main(void)
{
	initwindow(dai,rong);
	readFILE();
	int selected = -1;	
	while(true){
		selected = windowsMain();
		if(windowsMenu(selected)){
			writeFILE();
			return 0;
		}
	}
}


