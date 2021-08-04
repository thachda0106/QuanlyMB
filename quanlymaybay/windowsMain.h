
char menuMain[5][50] = {"May Bay", "Chuyen Bay", "Hanh Khach","Dat ve", "Thoat"};
void windowsBackground(){
	
	int xMax=getmaxx();
	int yMax=getmaxy();
	setcolor(GREEN);
	rectangle(1,1,xMax-1,yMax-1);
	rectangle(2,2,xMax-2,yMax-2);
	rectangle(3,3,xMax-3,yMax-3);
	rectBox(4,4,xMax-4,yMax-4,1,11);	
	outText("QUAN LY MAY BAY",600,10,6,YELLOW,3,6);
}

int checkSelectMainItems(int x, int y){
	if(x>760 && x< 1129 && y> 170 && y< 238 ){
		return 1;
	}else if(x>760 && x< 1129 && y> 314 && y< 385){
		return 2;
	}else if(x>760 && x< 1129 && y> 461 && y< 535){
		return 3;
	}else if(x>760 && x< 1129 && y> 604 && y< 676){
		return 4;
	}else if(x>760 && x< 1129 && y> 751 && y< 827){
		return 5;
	}else{
		return -1;
	}
	return -1;
}

int windowsMain(){
	cleardevice();
	int x,y,selected;
	windowsBackground();
	while(true){
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE,x,y);
		
			cout<<"toado:("<<x<<","<<y<<")"<<endl;
			selected = checkSelectMainItems(x,y);
			switch(selected){
				case 1:{
//					rectBox(760-1,170-1,1129-1,238-1,10,BLUE);
					rectBox(760,170,1129,238,10,BLUE);
					outText(menuMain[0],860,185,6,YELLOW,BLUE,4);
					rectBox(760,314,1129,385,10,WHITE);
					outText(menuMain[1],840,330,6,MAGENTA,WHITE,4);
					rectBox(760,461,1129,535,10,WHITE);
					outText(menuMain[2],840,480,6,MAGENTA,WHITE,4);
					rectBox(760,604,1129,676,10,WHITE);
					outText(menuMain[3],880,620,6,MAGENTA,WHITE,4);
					rectBox(760,751,1129,827,10,WHITE);
					outText(menuMain[4],890,770,6,MAGENTA,WHITE,4);	
					break;
				}
				case 2:{
					rectBox(760,170,1129,238,10,WHITE);
					outText(menuMain[0],860,185,6,MAGENTA,WHITE,4);
					rectBox(760,314,1129,385,10,BLUE);
					outText(menuMain[1],840,330,6,YELLOW,BLUE,4);
					rectBox(760,461,1129,535,10,WHITE);
					outText(menuMain[2],840,480,6,MAGENTA,WHITE,4);
					rectBox(760,604,1129,676,10,WHITE);
					outText(menuMain[3],880,620,6,MAGENTA,WHITE,4);
					rectBox(760,751,1129,827,10,WHITE);
					outText(menuMain[4],890,770,6,MAGENTA,WHITE,4);	
					break;
				}
				case 3:{
					rectBox(760,170,1129,238,10,WHITE);
					outText(menuMain[0],860,185,6,MAGENTA,WHITE,4);
					rectBox(760,314,1129,385,10,WHITE);
					outText(menuMain[1],840,330,6,MAGENTA,WHITE,4);
					rectBox(760,461,1129,535,10,BLUE);
					outText(menuMain[2],840,480,6,YELLOW,BLUE,4);
					rectBox(760,604,1129,676,10,WHITE);
					outText(menuMain[3],880,620,6,MAGENTA,WHITE,4);
					rectBox(760,751,1129,827,10,WHITE);
					outText(menuMain[4],890,770,6,MAGENTA,WHITE,4);	
					break;
				}case 4:{
					rectBox(760,170,1129,238,10,WHITE);
					outText(menuMain[0],860,185,6,MAGENTA,WHITE,4);
					rectBox(760,314,1129,385,10,WHITE);
					outText(menuMain[1],840,330,6,MAGENTA,WHITE,4);
					rectBox(760,461,1129,535,10,WHITE);
					outText(menuMain[2],840,480,6,MAGENTA,WHITE,4);
					rectBox(760,604,1129,676,10,BLUE);
					outText(menuMain[3],880,620,6,YELLOW,BLUE,4);
					rectBox(760,751,1129,827,10,WHITE);
					outText(menuMain[4],890,770,6,MAGENTA,WHITE,4);	
					break;
				}case 5:{
					rectBox(760,170,1129,238,10,WHITE);
					outText(menuMain[0],860,185,6,MAGENTA,WHITE,4);
					rectBox(760,314,1129,385,10,WHITE);
					outText(menuMain[1],840,330,6,MAGENTA,WHITE,4);
					rectBox(760,461,1129,535,10,WHITE);
					outText(menuMain[2],840,480,6,MAGENTA,WHITE,4);
					rectBox(760,604,1129,676,10,WHITE);
					outText(menuMain[3],880,620,6,MAGENTA,WHITE,4);
					rectBox(760,751,1129,827,10,BLUE);
					outText(menuMain[4],890,770,6,YELLOW,BLUE,4);	
					break;
				}
				default:{
					//clearviewport();
					setlinestyle(1,0,2);
					setcolor(MAGENTA);
					rectangle(760-2,170-2,1129+2,238+2);
					rectangle(760-2,314-2,1129+2,385+2);
					rectangle(760-2,461-2,1129+2,535+2);
					rectangle(760-2,604-2,1129+2,676+2);
					rectangle(760-2,751-2,1129+2,827+2);
					
					
					rectBox(760,170,1129,238,10,WHITE);
					outText(menuMain[0],860,185,6,MAGENTA,WHITE,4);
					rectBox(760,314,1129,385,10,WHITE);
					outText(menuMain[1],840,330,6,MAGENTA,WHITE,4);
					rectBox(760,461,1129,535,10,WHITE);
					outText(menuMain[2],840,480,6,MAGENTA,WHITE,4);
					rectBox(760,604,1129,676,10,WHITE);
					outText(menuMain[3],880,620,6,MAGENTA,WHITE,4);
					rectBox(760,751,1129,827,10,WHITE);
					outText(menuMain[4],890,770,6,MAGENTA,WHITE,4);	
					break;
				}
			}			
		}
		else if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN ,x,y);
			selected = checkSelectMainItems(x,y);
			cout<<"CLICK TAI: ("<<x<<","<<y<<")"<<endl;
			if(selected != -1){
				clearviewport();
				return selected;
			} 
		}		
		delay(100);
	}
		
}

//int checkSelectMenuItems(int x, int y){
//	if(x>83 && x< 350 && y> 217 && y< 278 ){
//		return 1;
//	}else if(x>83 && x< 350 && y> 331 && y< 392){
//		return 2;
//	}else if(x>83 && x< 350 && y> 444 && y< 504){
//		return 3;
//	}else if(x>83 && x< 350 && y> 552 && y< 608){
//		return 4;
//	}else if(x>83 && x< 350 && y> 648 && y< 704){
//		return 5;
//	}else{
//		return -1;
//	}
//	return -1;
//}

//bool checkMouseMoveInMenu(int x, int y){
//	if((x>20 && x< 415 ) && ( y>165 &&  y<768)){
//		return true;
//	}
//	return false;
//}

int itemsActive(int selected){
	clearWindows();
	windowsBackground();

	outText("MENU",150,120,6,YELLOW,12,4);
	setcolor(GREEN);	
	rectangle(20,165+20,415,768);
	rectangle(20-1,165-1+20,415-1,768-1);

	//
	rectangle(440,165-55,1899-30,1040);
	rectangle(440-1,165-55-1,1899-30-1,1040-1);	
	
	setlinestyle(1,0,2);
	rectBox(83,217,350,278,1,WHITE);
	outText("May bay",135,225,6,MAGENTA,15,4);
	rectangle(83-1,217-1,350+1,278+1);
	
	rectBox(83,331,350,392,1,WHITE);
	outText("Chuyen bay",110,340,6,MAGENTA,15,4);
	rectangle(83-1,331-1,350+1,392+1);

	rectBox(83,444,350,504,1,WHITE);
	outText("Hanh khach",110,450,6,MAGENTA,15,4);
	rectangle(83-1,444-1,350+1,504+1);
	
	rectBox(83,552,350,608,1,WHITE);
	outText("Dat ve",150,560,6,MAGENTA,15,4);	
	rectangle(83-1,552-1,350+1,608+1);
	
	rectBox(83,648,350,704,1,WHITE);
	outText("Thoat",150,655,6,MAGENTA,15,4);
	rectangle(83-1,648-1,350+1,704+1);	
	switch(selected){
		case 1:{
			rectBox(83,217,350,278,1,3);
			outText("May bay",135,225,6,MAGENTA,3,4);
			break;
		}
		case 2:{
			rectBox(83,331,350,392,1,3);
			outText("Chuyen bay",110,340,6,MAGENTA,3,4);
			break;
		}
		case 3:{
			rectBox(83,444,350,504,1,3);
			outText("Hanh khach",110,450,6,MAGENTA,3,4);
			break;
		}
		case 4:{
			rectBox(83,552,350,608,1,3);
			outText("Dat ve",150,560,6,MAGENTA,3,4);
			break;
		} 
		case 5:{
			return 5;
			break;
		}
	}
	return -1;
}

bool windowsMenu(int selected){
	if(selected == 5){
		return true;
	}
	itemsActive(selected);
	switch(selected){
		case 1:{ // May Bay
			windowsPlane();				
			break;
		}
		case 2:{ // Chuyen Bay
			windowsFlight();
			break;
		}
		case 3:{ // Hanh Khach
			windowsCustormer();
			break; 
		}
		case 4:{ // Dat Ve
			windowsTicket();
			break;
		}
		case 5:{
			return true;
			break;
		}
	}
	return false;
}


