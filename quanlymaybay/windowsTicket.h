
int checkSelectmouseBOOKTK(int x, int y){
	if(x>420 && x< 760 && y> 280 && y< 340 ){
		return 1;  //cmnd
	}else if(x>420 && x< 760 && y> 390 && y< 450 ){
		return 2;  //ho
	}else if(x>420 && x< 760 && y> 500 && y< 560 ){
		return 3; //ten
	}else if(x>525-17 && x< 525+17 && y> 640-17 && y< 640+17 ){
		return 4; //checkbox nam
	}else if(x>705-17 && x< 705+15 && y> 640-17 && y< 640+17 ){
		return 5; //checkbox nu
	}else if(x>1450 && x< 1650 && y> 720 && y< 770 ){ 
		return 6;  //vi tri ngoi 
	}else if(x>1240 && x< 1390 && y> 905 && y< 960 ){
		return 7;  //dat ve
	}else if(x>1530 && x< 1670 && y> 905 && y< 960 ){
		return 8;  // thoat
	}else if(x>1670 && x < 1695 && y> 730 && y < 760){
		return 9; //dsve truoc
	}else if(x>1815-60 && x < 1835-60 && y> 730 && y < 760){
		return 10;  // dsve sau
	}
	else{
		return -1;
	}
}
int checkSelectmouseFindFlight(int x, int y){
	if(x>1605-80 && x< 1650-80 && y> 185 && y< 250 ){
		return 1; 
	}else if(x>1665-80 && x< 1710-80 && y> 185 && y< 250 ){
		return 2; 
	}else if(x>1725-80 && x< 1805-80 && y> 185 && y< 250 ){
		return 3; 
	}else if(x>1465 && x< 1805 && y> 315 && y< 375 ){ 
		return 4;
	}else if(x>1570-80 && x< 1690-80 && y> 410 && y< 440 ){
		return 5; 
	}else if(x>1570+100 && x< 1690+100 && y> 410 && y< 440  ){
		return 6; 
	}else if(x>1170 && x< 1200 && y> 880 && y< 910){
		return 7;  // page truoc		
	}else if(x>1367+20 && x< 1390+20 && y> 880 && y< 910){
		return 8;   //page sau
	}else{
		return -1;
	}
}
void windowsBackgroundTicket(){
	// outtext
	outText("DANH SACH CHUYEN BAY",520,127+10,9,GREEN,11,2); 
	outText("(TK_SBD)",965+10,137,9,GREEN,11,1);	
	outText("STT",500,180+20,9,GREEN,11,1);
	outText("MA CB",574,180+20,9,GREEN,11,1);
	outText("SB DEN",740,180+20,9,GREEN,11,1);
	outText("SHMB",916,180+20,9,GREEN,11,1);
	outText("THOI GIAN",1060,180+20,9,GREEN,11,1);
	outText("TRANG THAI",1250,180+20,9,GREEN,11,1);				
	// draw 
	rectBox(1170-50,130,1424+5,171,1,WHITE); // search
	setcolor(GREEN);
	rectangle(1170-1-50,130-1,1424-1+5,171-1); //searchborder
	
	rectBox(1440,135,1555,165,1,GREEN); // search
	outText("Tim kiem",1443,135+5,9,WHITE,GREEN,1);	
	
	setcolor(GREEN);
	rectangle(496,166+20,1428,820+20); // table
	rectangle(496-1,166-1+20,1428-1,820-1+20); // table
	setlinestyle(0,1,2);
	
	// button 			rectBox(83,217,350,278,1,3);
		//	outText("May bay",135,225,6,MAGENTA,3,4);
	setcolor(MAGENTA);
	rectangle(1532-1,255-1,1737+1,309+1);	
	rectBox(1532+1,255+1,1737-1,309-1,1,15);	
	outText("DAT VE",1578,274,9,MAGENTA,15,1);	
	
	rectangle(1532-1,367-1,1737+1,422+1);	
	rectBox(1532+1,367+1,1737-1,422-1,1,15);	
	outText("HUY VE",1578,387,9,MAGENTA,15,1);	
	
	rectangle(1532-1,475-1,1737+1,527+1+3);	
	rectBox(1532+1,475+1,1737-1,527-1+3,1,15);	
	outText("TIM CB",1578,490,9,MAGENTA,15,1);	

    // 
    setcolor(GREEN);
	line(496,212+10+20,1427,212+10+20);  // line horizontal for head tabble
	// draw lines horizontal for table
	setlinestyle(1,1,1);
	
	int y =282+20;
	for(int i = 1; i < 10; i++){
		line(496,y,1427,y); 
		y+=60;
	}
	// line vertical for data table
	setlinestyle(0,1,2);
	line(554,166+20,554,820+20);
	line(703,166+20,703,820+20);
	line(878,166+20,878,820+20);
	line(1029,166+20,1029,820+20);
	line(1244,166+20,1244,820+20);
		// phan trang
	setcolor(GREEN);
	line(1170,897,1200,880);
	line(1200,880,1200,909);
	line(1200,909,1170,897);	
			
	line(1394+20,897,1368+20,880);
	line(1368+20,880,1368+20,909);
	line(1394+20,897,1368+20,909);	
	setfillstyle(1,GREEN);
	floodfill(1170+3,897,GREEN);	
	floodfill(1394-3,897,GREEN);
	
}

void windowsBackgoundBookTicket(char* title, int flag){
	clearviewport();
	windowsBackground();
	setlinestyle(1,0,2);
	setcolor(GREEN);
	
	outText(title,865,100,9,GREEN,11,2);
	outText("THONG TIN KHACH HANG",285,158,9,GREEN,11,2);
	outText("DANH SACH GHE NGOI",1260,158,9,GREEN,11,2);
	outText("SO CMND",230,305,9,GREEN,11,2);
	outText("HO",230,410,9,GREEN,11,2);
	outText("TEN",230,515,9,GREEN,11,2);
	outText("GIOI TINH",230,630,9,GREEN,11,2);
	outText("Nam",420+10,630,9,0,11,2);
	outText("Nu",620+10,630,9,0,11,2);
	outText("( Cac vi tri mau xanh la vi tri ghe trong. )",1200,195,9,GREEN,11,1);
	setcolor(GREEN);
	//khung ngoai 
	rectangle(30,130,1880,1000);
	rectangle(55,235-50,1080,920-50);
	rectangle(1130,235-50,1800,920-50);


	// thong tin khach hang
	
	rectangle(420-2,280-2,760+2,340+2);
	rectangle(420-2,390-2,760+2,450+2);
	rectangle(420-2,500-2,760+2,560+2);
	
	rectBox(420,280,760,340,1,WHITE);	
	rectBox(420,390,760,450,1,WHITE);	
	rectBox(420,500,760,560,1,WHITE);	
	
	// check box
	setcolor(GREEN);
	circle(505+20,640,17);
	circle(505+20,640,18);
	circle(685+20,640,17);
	circle(685+20,640,18);
	
	// danh sach ghe ngoi
	
	rectangle(1180-10,235-10,1755+10,695+10);	
	rectangle(1450-2,720-2,1650+2,770+2);	
	outText("Vi tri cho ngoi",1230,735,9,GREEN,11,2);	
	rectBox(1450,720,1650,770,1,WHITE);	
	
	//button
	if(flag == 1){
		outText("DAT VE",1260,920,9,WHITE,GREEN,2);
	}
	else{
		outText("HUY VE",1260,920,9,WHITE,GREEN,2);
	}
	outText("THOAT",1550,920,9,WHITE,BLACK,2);
	rectBox(1240,905,1390,960,1,GREEN);
	rectBox(1530,905,1670,960,1,BLACK);
	
	// phan trang ghe ngoi
	
	setcolor(GREEN);
	line(1670,745,1695,730);
	line(1695,730,1695,760);
	line(1695,760,1670,745);	
			
	line(1835-60,745,1815-60,730);
	line(1815-60,730,1815-60,760);
	line(1815-60,760,1835-60,745);	
	setfillstyle(1,GREEN);
	floodfill(1670+3,745,GREEN);	
	floodfill(1835-60-3,745,GREEN);
	
}
void windowsBackgroundFindFlight(){
	clearviewport();
	int xMax=getmaxx();
	int yMax=getmaxy();
	setcolor(GREEN);
	rectangle(1,1,xMax-1,yMax-1);
	rectangle(2,2,xMax-2,yMax-2);
	rectangle(3,3,xMax-3,yMax-3);
	rectBox(4,4,xMax-4,yMax-4,1,11);
		
	setcolor(GREEN);
	outText("STT",365,180+20,9,GREEN,11,1);
	outText("Ma CB",465,180+20,9,GREEN,11,1);
//	
	outText("Ve Trong",620,180+20,9,GREEN,11,1);
	outText("Gio Khoi Hanh",760,180+20,9,GREEN,11,1);
	outText("San Bay Den",1035,180+20,9,GREEN,11,1);	
	outText("Trang Thai",1280,180+20,9,GREEN,11,1);	
	outText("DANH SACH CAC CHUYEN BAY KHOI HANH TRONG NGAY",500,90,9,GREEN,11,2);
	outText("Ngay gio khoi hanh:",420+100,130,9,GREEN,11,1);
	outText("Noi den:",1000,130,9,GREEN,11,1);	
	outText("TRANG 0/0  " ,1210,885,9,GREEN,11,1);  // outtext xd vitri

	rectangle(355,166+20,1428,820+20); // table
	rectangle(355-1,166-1+20,1428-1,820-1+20); // table	   
	line(355,212+10+20,1427,212+10+20);  // line horizontal for head tabble
	// draw lines horizontal for table
	setlinestyle(1,1,1);
	int y =282+20;
	for(int i = 1; i < 10; i++){
		line(355,y,1427,y); 
		y+=60;
	}
	// line vertical for data table
	setlinestyle(0,1,2);
	line(430,166+20,430,820+20);	
	line(610,166+20,610,820+20);	
	line(735,166+20,735,820+20);
	line(990,166+20,990,820+20);
	line(1245,166+20,1245,820+20);
	
	// phan trang
	setcolor(GREEN);
	line(1170,897,1200,880);
	line(1200,880,1200,909);
	line(1200,909,1170,897);	
			
	line(1394+20,897,1368+20,880);
	line(1368+20,880,1368+20,909);
	line(1394+20,897,1368+20,909);	
	setfillstyle(1,GREEN);
	floodfill(1170+3,897,GREEN);	
	floodfill(1394-3,897,GREEN);
	

	outText("/",1573,210,9,GREEN,11,2);
	outText("/",1633,210,9,GREEN,11,2);
	outText("          dd / mm / yyyy",1470,155,9,GREEN,11,2);
	outText("San bay den",1560,280,9,GREEN,11,2);
	setlinestyle(1,0,2);

	rectangle(1605 -80 -2,185-2,1650+2 -80,250+2);  
	rectangle(1665 -80-2,185-2,1710+2 -80,250+2);
	rectangle(1725 -80-2,185-2,1805+2 -80,250+2);	
	rectangle(1465 -2,315-2,1805+2,375+2);

	rectBox(1605 -80,185,1650 -80,250,1,WHITE);
	rectBox(1665 -80,185,1710 -80,250,1,WHITE);
	rectBox(1725 -80,185,1805 -80,250,1,WHITE);
	rectBox(1465,315,1805,375,1,WHITE);
	rectBox(1570-80,410,1690-80,440,1,GREEN); // search
	outText("Tim kiem",1575-80,415,9,WHITE,GREEN,1);
	rectBox(1570+100,410,1690+100,440,1,BLACK); // search
	outText("Thoat",1590+100,415,9,WHITE,BLACK,1);
	
}


void windowsShowFindFlight(){

	windowsBackgroundFindFlight();
	char thoigian[18] ="",ngay[3]="",thang[3]="",nam[5]="", sanBayDen[SBD_MAX]=  "";
	int x,y,selected,page = 1, pageMAX = 1;
	DANHSACHCB DSCB;
	while(1){
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE,x,y);
			selected = checkSelectmouseFindFlight(x,y);
			switch(selected){
				case 5:{
					rectBox(1570-80,410,1690-80,440,1,BLUE); // search
					outText("Tim kiem",1575-80,415,9,WHITE,BLUE,1);					
					break;
				}
				case 6:{
					rectBox(1570+100,410,1690+100,440,1,BLACK); // search
					outText("Thoat",1590+100,415,9,RED,BLACK,1);
					break;
				}
				default:{
					rectBox(1570-80,410,1690-80,440,1,GREEN); // search
					outText("Tim kiem",1575-80,415,9,WHITE,GREEN,1);
					rectBox(1570+100,410,1690+100,440,1,BLACK); // search
					outText("Thoat",1590+100,415,9,WHITE,BLACK,1);
					break;
				}
			}			
		}
		else if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			selected = checkSelectmouseFindFlight(x,y);
			switch(selected){
				case 1:{
					setcolor(BLUE);	
					rectangle(1605 -80 -2,185-2,1650+2 -80,250+2);  														
					setcolor(GREEN);
					rectangle(1665 -80-2,185-2,1710+2 -80,250+2);
					rectangle(1725 -80-2,185-2,1805+2 -80,250+2);		
					rectangle(1465-2,315-2,1805+2,375+2);		
					nhapChuoi(ngay,1610- 80,205,3,2,BLACK,1);						
					break;
				}
				case 2:{
					setcolor(BLUE);	
					rectangle(1665 -80-2,185-2,1710+2 -80,250+2);														
					setcolor(GREEN);
					rectangle(1605 -80 -2,185-2,1650+2 -80,250+2);  
					rectangle(1725 -80-2,185-2,1805+2 -80,250+2);		
					rectangle(1465-2,315-2,1805+2,375+2);	
					nhapChuoi(thang,1670- 80,205,3,2,BLACK,1);							
					break;
				}
				case 3:{
					setcolor(BLUE);	
					rectangle(1725 -80-2,185-2,1805+2 -80,250+2);										
					setcolor(GREEN);
					rectangle(1605 -80 -2,185-2,1650+2 -80,250+2);  
					rectangle(1665 -80-2,185-2,1710+2 -80,250+2);		
					rectangle(1465-2,315-2,1805+2,375+2);		
					nhapChuoi(nam,1730- 80,205,3,4,BLACK,1);					
					break;
				}
				case 4:{
					setcolor(BLUE);	
					rectangle(1465-2,315-2,1805+2,375+2);															
					setcolor(GREEN);
					rectangle(1605 -80 -2,185-2,1650+2 -80,250+2);  
					rectangle(1665 -80-2,185-2,1710+2 -80,250+2);
					rectangle(1725 -80-2,185-2,1805+2 -80,250+2);				
					nhapChuoi(sanBayDen,1470,335,1,SBD_MAX-1,BLACK,1);				
					break;
				}
				case 5:{
					THOIGIAN tg;
					tg.gio = 0;
					tg.phut = 0;
					tg.ngay = atoi(ngay);
					tg.thang = atoi(thang);
					tg.nam = atoi(nam);
					if(strlen(sanBayDen)==0){
						thongbao_s2("Chua nhap san bay den!","");
						break;
					}else if(!checkDateTimeValue(tg)){
						thongbao_s2("Thoi gian khong hop le!","");
						break;						
					}
					formatTime(thoigian,ngay,thang,nam);					
					outText("dd/mm/yyyy",660+100,130,9,11,11,1);
					outText("dddddddddddddd",1110,130,9,11,11,1);
					outText(thoigian,660+100,130,9,MAGENTA,11,1);
					outText(sanBayDen,1110,130,9,MAGENTA,11,1);
					clearDSCB(DSCB);			// clear ds cu de get ds moi
					findDSCB(DS_CHUYENBAY,DSCB,tg,sanBayDen);
					page =1; pageMAX = pageMax(DSCB.sl);  // get max page 
					clearFindDSCB();
					xuatFindDSCB(DSCB,page); // xuat trang 1/max	
					break;				
				}
				case 6:{
					clearDSCB(DSCB);
					clearviewport();
					return;
				}			
				case 7:{
					if(page > 1 ) {
						clearFindDSCB();
						xuatFindDSCB(DSCB,--page); 										
					}					
					break;
				}	
				case 8:{
					if( page < pageMAX  ) {
						clearFindDSCB();
						xuatFindDSCB(DSCB,++page); 											
					}					
					break;
				}
				default:{																
					setcolor(GREEN);				
					rectangle(1605 -80 -2,185-2,1650+2 -80,250+2);  
					rectangle(1665 -80-2,185-2,1710+2 -80,250+2);
					rectangle(1725 -80-2,185-2,1805+2 -80,250+2);		
					rectangle(1465-2,315-2,1805+2,375+2);										
					break;
				}
			}
		}
		delay(10);
	}		
	
}
void windowsCancelTK(DANHSACHCB& DS_CHUYENBAY, DANHSACHHK& DS_HANHKHACH, NODECB& cb ){
	windowsBackgoundBookTicket("~  HUY VE  ~",2);
	cancelVE(DS_CHUYENBAY,DS_HANHKHACH,cb);
}
void windowsBookTK(DANHSACHCB& DS_CHUYENBAY, DANHSACHHK& DS_HANHKHACH, NODECB& cb ){
	windowsBackgoundBookTicket("~  DAT VE  ~",1);
	bookVE(DS_CHUYENBAY,DS_HANHKHACH,cb);
}

void windowsTicket(){
	windowsBackgroundTicket();
	int x,y,selected,page = 1,  page_search = 1;
	DANHSACHCB DSCB_CONVE; 	AddDSCB_CONVE(DS_CHUYENBAY,DSCB_CONVE);	
	int pageMAX = pageMax(DSCB_CONVE.sl),    page_searchMAX = 1;
	xuatDSCB(DSCB_CONVE,page);
	NODECB p = NULL;   // NODECB active
	int selectedNODECB = -1;    // vi tri nodecb tren table
	char SBD_SEARCH[SBD_MAX] = "";
	DANHSACHCB DSCB_SEARCH; 
	while(1){

		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE,x,y);
			selected = checkSelectMenuItems(x,y);
			switch(selected){
				case 7:{
					rectBox(1440,135,1555,165,1,BLUE); // search
					outText("Tim kiem",1443,135+5,9,WHITE,BLUE,1);
					break;
				}
				case 8:{
					setcolor(MAGENTA);
					rectangle(1532-1,255-1,1737+1,309+1);	
					rectBox(1532+1,255+1,1737-1,309-1,1,3);	
					outText("DAT VE",1578,274,9,MAGENTA,3,1);	
	
					rectangle(1532-1,367-1,1737+1,422+1);	
					rectBox(1532+1,367+1,1737-1,422-1,1,15);	
					outText("HUY VE",1578,387,9,MAGENTA,15,1);		
					
					rectangle(1532-1,475-1,1737+1,527+1+3);	
					rectBox(1532+1,475+1,1737-1,527-1+3,1,15);	
					outText("TIM CB",1578,490,9,MAGENTA,15,1);				
					
					break;
				}case 9:{
					setcolor(MAGENTA);
					rectangle(1532-1,255-1,1737+1,309+1);	
					rectBox(1532+1,255+1,1737-1,309-1,1,15);	
					outText("DAT VE",1578,274,9,MAGENTA,15,1);	
	
					rectangle(1532-1,367-1,1737+1,422+1);	
					rectBox(1532+1,367+1,1737-1,422-1,1,3);	
					outText("HUY VE",1578,387,9,MAGENTA,3,1);

					rectangle(1532-1,475-1,1737+1,527+1+3);	
					rectBox(1532+1,475+1,1737-1,527-1+3,1,15);	
					outText("TIM CB",1578,490,9,MAGENTA,15,1);	
					break;
				}case 10:{
					setcolor(MAGENTA);
					rectangle(1532-1,255-1,1737+1,309+1);	
					rectBox(1532+1,255+1,1737-1,309-1,1,15);	
					outText("DAT VE",1578,274,9,MAGENTA,15,1);	
	
					rectangle(1532-1,367-1,1737+1,422+1);	
					rectBox(1532+1,367+1,1737-1,422-1,1,15);	
					outText("HUY VE",1578,387,9,MAGENTA,15,1);	

					rectangle(1532-1,475-1,1737+1,527+1+3);	
					rectBox(1532+1,475+1,1737-1,527-1+3,1,3);	
					outText("TIM CB",1578,490,9,MAGENTA,3,1);
					break;
				}
				default:{
					setcolor(MAGENTA);
					rectangle(1532-1,255-1,1737+1,309+1);	
					rectBox(1532+1,255+1,1737-1,309-1,1,15);	
					outText("DAT VE",1578,274,9,MAGENTA,15,1);	
	
					rectangle(1532-1,367-1,1737+1,422+1);	
					rectBox(1532+1,367+1,1737-1,422-1,1,15);	
					outText("HUY VE",1578,387,9,MAGENTA,15,1);	

					rectangle(1532-1,475-1,1737+1,527+1+3);	
					rectBox(1532+1,475+1,1737-1,527-1+3,1,15);	
					outText("TIM CB",1578,490,9,MAGENTA,15,1);						
					rectBox(1440,135,1555,165,1,GREEN); // search
					outText("Tim kiem",1443,135+5,9,WHITE,GREEN,1);
					break;
				}
			}			
		}
		else if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			selected = checkSelectMenuItems(x,y);
			switch(selected){
				case 6:{ //search
					setcolor(BLUE);
					rectangle(1170-1-50,130-1,1424-1+5,171-1); //searchborder
					nhapChuoi(SBD_SEARCH,1175-50,137,1,SBD_MAX-1,GREEN,1); 							
					setcolor(GREEN);
					rectangle(1170-1-50,130-1,1424-1+5,171-1); //searchborder

					if(strlen(SBD_SEARCH) == 0) {
						clearDSCB(DSCB_SEARCH);
						clearTableCB();		
						xuatDSCB(DSCB_CONVE,page);		
					}
					break;
				}
				case 7:{   // click button tim kiem
					if(strlen(SBD_SEARCH) == 0) {
						thongbao("Ban chua nhap vao ","san bay den");
						break;
					}
					clearDSCB(DSCB_SEARCH);
					SEARCH_DSCB_SBD(DSCB_SEARCH,SBD_SEARCH);
					if(DSCB_SEARCH.sl == 0){
						thongbao("Khong co chuyen bay nao! ","");
						break;
					}else{
						thongbao("Loading...","");
					}
					clearTableCB();					
					page_search = 1;
					page_searchMAX =  pageMax(DSCB_SEARCH.sl);
					xuatDSCB(DSCB_SEARCH,page_search); 	
					break;
				}
				case 8:{   // DAT VE
					if(p==NULL){
						thongbao("Ban chua chon chuyen bay","de dat ve!");
						break;
					}				
					else if(p->info.trangThai == HETVE){
						thongbao("Chuyen bay nay","da het ve!");
						break;
					}
					windowsBookTK(DS_CHUYENBAY,DS_HANHKHACH,p);
		
					itemsActive(4);
					windowsBackgroundTicket();					
					if(strlen(SBD_SEARCH) == 0){					
						xuatDSCB(DSCB_CONVE,page);						
					}else{
						xuatDSCB(DSCB_SEARCH,page_search);
						outText(SBD_SEARCH,1175-50,137,9,GREEN,WHITE,1);
					}		
					if(strlen(SBD_SEARCH) == 0 && p!= NULL){// khi o tim kiem rong	
						hightlighNODECB(p,selectedNODECB,page,BLACK,WHITE);									
					}
					else if(strlen(SBD_SEARCH) != 0 && p!= NULL) {   // khi co tim kiem
						hightlighNODECB(p,selectedNODECB,page_search,BLACK,WHITE);
					}
					break;
				}
				case 9:{  //HUY VE
					if(p==NULL){
						thongbao("Ban chua chon chuyen bay","de huy ve!");
						break;
					}
					windowsCancelTK(DS_CHUYENBAY,DS_HANHKHACH,p);
					itemsActive(4);
					windowsBackgroundTicket();					
					if(strlen(SBD_SEARCH) == 0){					
						xuatDSCB(DSCB_CONVE,page);						
					}else{
						xuatDSCB(DSCB_SEARCH,page_search);
						outText(SBD_SEARCH,1175-50,137,9,GREEN,WHITE,1);
					}
					if(strlen(SBD_SEARCH) == 0 && p!= NULL){// khi o tim kiem rong	
						hightlighNODECB(p,selectedNODECB,page,BLACK,WHITE);									
					}
					else if(strlen(SBD_SEARCH) != 0 && p!= NULL) {   // khi co tim kiem
						hightlighNODECB(p,selectedNODECB,page_search,BLACK,WHITE);
					}
					break;
				}
				case 10:{  // tim kiem cb theo time va sbd
					windowsShowFindFlight();
					itemsActive(4);
					windowsBackgroundTicket();					
					if(strlen(SBD_SEARCH) == 0){					
						xuatDSCB(DSCB_CONVE,page);						
					}else{
						xuatDSCB(DSCB_SEARCH,page_search);
						outText(SBD_SEARCH,1175-50,137,9,GREEN,WHITE,1);
					}							
					if(strlen(SBD_SEARCH) == 0 && p!= NULL){// khi o tim kiem rong	
						hightlighNODECB(p,selectedNODECB,page,BLACK,WHITE);									
					}
					else if(strlen(SBD_SEARCH) != 0 && p!= NULL) {   // khi co tim kiem
						hightlighNODECB(p,selectedNODECB,page_search,BLACK,WHITE);
					}			
					break;					
				}
				case 11:{  // page truoc	
					if(strlen(SBD_SEARCH) == 0 && page > 1 ) {
						p = NULL;
						clearTableCB();
						xuatDSCB(DSCB_CONVE,--page);											
					}else if(strlen(SBD_SEARCH) != 0 && page_search > 1){
						p = NULL;
						clearTableCB();
						xuatDSCB(DSCB_SEARCH,--page_search);
					}
					break;		
				}
				case 12:{  // page sau
					if(strlen(SBD_SEARCH) == 0 && page < pageMAX  ) {
						p = NULL;
						clearTableCB();
						xuatDSCB(DSCB_CONVE,++page);
											
					}else if(strlen(SBD_SEARCH) != 0 && page_search < page_searchMAX){
						p = NULL;
						clearTableCB();
						xuatDSCB(DSCB_SEARCH,++page_search);
					}					
					break;
				}
				case 13:{  // Khi click vao nodecb tren table => get p = nodecb duoc chon va highlight no sang len

					if(strlen(SBD_SEARCH) == 0){// khi o tim kiem rong	
						xuatDSCB(DSCB_CONVE,page);
						selectedNODECB = checkSelectTableNODE(x,y);    // vi tri nodecb tren table
						NODECB q = searchTableNODECB(DSCB_CONVE,page,selectedNODECB);
						if(q!= NULL){ // highlight
							hightlighNODECB(q,selectedNODECB,page,BLACK,WHITE);
							p = searchCB(DS_CHUYENBAY.ds, q->info.maCB);
						}									
					}
					else{   // khi co tim kiem
						xuatDSCB(DSCB_SEARCH,page_search);
						selectedNODECB = checkSelectTableNODE(x,y);    // vi tri nodecb tren table
						NODECB q = searchTableNODECB(DSCB_SEARCH,page_search,selectedNODECB);
						if(q!= NULL){ // highlight
							hightlighNODECB(q,selectedNODECB,page_search,BLACK,WHITE);
							p = searchCB(DS_CHUYENBAY.ds, q->info.maCB);
						}		
					}									
					break;
				}
				default:{

					if(selected > 0 && selected <6){
						clearDSCB(DSCB_SEARCH);
						clearDSCB(DSCB_CONVE);						
						windowsMenu(selected);
						return;
					}
					break;
				}
			}
		}
		delay(10);
	}	

}

