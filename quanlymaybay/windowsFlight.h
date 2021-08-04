
int checkSelectmouseNEWCB(int x, int y){
	if(x>760 && x< 1100 && y> 250 && y< 310 ){
		return 1;  //mcb
	}else if(x>760 && x< 1100 && y> 360 && y< 420 ){
		return 2;  //sbd
	}else if(x>760 && x< 1100 && y> 470 && y< 530 ){
		return 3; //shmb
	}else if(x>760 && x< 800 && y> 580 && y< 640 ){
		return 4; //gio
	}else if(x>820 && x< 860 && y> 580 && y< 640 ){
		return 5; //phut
	}else if(x>900 && x< 940 && y> 580 && y< 640 ){
		return 6;  //ngay
	}else if(x>960 && x< 1000 && y> 580 && y< 640 ){
		return 7;  //thang
	}else if(x>1020 && x< 1100 && y> 580 && y< 640 ){
		return 8;  // nam
	}else if(x>1200 && x< 1345 && y> 250 && y< 300  ){
		return 9;  //luu
	}else if(x>1220 && x< 1345 && y> 365 && y< 418 ){
		return 10;  // xoa	
	}else if(x>1220 && x< 1345 && y> 480 && y< 525 ){  
		return 11;  // thoat
	}else{
		return -1;
	}
}

void hightlighNODECB(NODECB p, int vitri, int STTpage, int color, int background){
	
	int y_1 = 260; // toa do y node dau tien tren table
	int stt = (STTpage-1)*10 + vitri;  // stt node tren table
	
	y_1 = y_1 + (vitri-1)*60;   // toa do y cua node chon
	char chuoiSTT[4]; // 
	char thoigian[18],gio[3],phut[3],ngay[3],thang[3],nam[5]; 
	
		itoa(p->info.thoiGian.gio, gio,10);
		itoa(p->info.thoiGian.phut, phut,10);
		itoa(p->info.thoiGian.ngay, ngay,10);
		itoa(p->info.thoiGian.thang, thang,10);
		itoa(p->info.thoiGian.nam, nam,10);		
		formatDate(thoigian,gio,phut,ngay,thang,nam);
		
		
		itoa(stt,chuoiSTT,10);
		outText(chuoiSTT,505,y_1,9,color,background,1);
		outText(p->info.maCB,574,y_1,9,color,background,1);
		outText(p->info.sanBayDen,715,y_1,9,color,background,1);
		outText(p->info.soHieuMB,890,y_1,9,color,background,1);
		outText(thoigian,1040,y_1,9,color,background,1);
		switch(p->info.trangThai){
			case HUYCHUYEN:{
				outText("Huy chuyen",1265,y_1,9,color,background,1);
				break;
			}
			case CONVE:{
				outText("Con ve",1290,y_1,9,color,background,1);
				break;
			}
			case HETVE:{
				outText("Het ve",1290,y_1,9,color,background,1);	
				break;
			}
			case HOANTAT:{
				outText("Hoan tat",1280,y_1,9,color,background,1);
				break;
			}
		}	
}

NODECB searchTableNODECB(DANHSACHCB &DSCB, int STTpage, int vitri){
	NODECB p = NULL;	
	int vitriNODECB = (STTpage-1)*10 + vitri;    //vitri la vi tri nodecb tren table
	if(vitriNODECB > DSCB.sl) return p;
	int i = 1;
	for(p = DSCB.ds ; i < vitriNODECB &&  p!= NULL; p=p->next,i++);
	return p;
}
void drawTableCB(){
	setcolor(GREEN);
	outText("STT",500,180+20,9,GREEN,11,1);
	outText("MA CB",574,180+20,9,GREEN,11,1);
	outText("SB DEN",740,180+20,9,GREEN,11,1);
	outText("SHMB",916,180+20,9,GREEN,11,1);
	outText("THOI GIAN",1060,180+20,9,GREEN,11,1);
	outText("TRANG THAI",1250,180+20,9,GREEN,11,1);	
	rectangle(496,166+20,1428,820+20); // table
	rectangle(496-1,166-1+20,1428-1,820-1+20); // table	   
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
}
void windowsBackgroundFlight(){
	// outtext
	outText("DANH SACH CHUYEN BAY",520,127+10,9,GREEN,11,2); 
	outText("(TK_MCB)",965+10,137,9,GREEN,11,1);	
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
	// button 	
	setcolor(MAGENTA);
	rectangle(1532-1,255-1,1737+1,309+1);	
	rectBox(1532+1,255+1,1737-1,309-1,1,15);	
	outText("THEM CB",1562,274,9,MAGENTA,15,1);	
	
	rectangle(1532-1,367-1,1737+1,422+1);	
	rectBox(1532+1,367+1,1737-1,422-1,1,15);	
	outText("HUY CB",1578,387,9,MAGENTA,15,1);	

	rectangle(1532-1,475-1,1737+1,527+1+3);	
	rectBox(1532+1,475+1,1737-1,527-1+3,1,15);	
	outText("CHINH SUA CB",1540,490,9,MAGENTA,15,1);
	
	rectangle(1532-1,475-1+100,1737+1,527+1+3+100);	
	rectBox(1532+1,475+1+100,1737-1,527-1+3+100,1,15);	
	outText("THONG TIN HK",1535,490+100,9,MAGENTA,15,1);
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
//			rectBox(83,217,350,278,1,3);
//			outText("May bay",135,225,6,MAGENTA,3,4);
void windowsBackgroundEditCB(char * title){
	windowsBackground();
	setlinestyle(1,0,2);
	setcolor(GREEN);
	outText(title,710,130,9,GREEN,11,2);
//	setcolor(MAGENTA);	
	rectangle(405,170,1505,820);
	rectangle(760-2,240+10-2,1100+2,300+10+2);
	rectangle(760-2,350+10-2,1100+2,410+10+2);	
	rectangle(760-2,460+10-2,1100+2,520+10+2);	

	rectangle(760-2,570+10-2,800+2,630+10+2);
	rectangle(820-2,570+10-2,860+2,630+10+2);
	rectangle(900-2,570+10-2,940+2,630+10+2);
	rectangle(960-2,570+10-2,1000+2,630+10+2);
	rectangle(1020-2,570+10-2,1100+2,630+10+2);	


	rectBox(760,240+10,1100,300+10,1,WHITE);	
	rectBox(760,350+10,1100,410+10,1,WHITE);
	rectBox(760,460+10,1100,520+10,1,WHITE);
	
	rectBox(760,570+10,800,630+10,1,WHITE);
	rectBox(820,570+10,860,630+10,1,WHITE);
	rectBox(900,570+10,940,630+10,1,WHITE);
	rectBox(960,570+10,1000,630+10,1,WHITE);
	rectBox(1020,570+10,1100,630+10,1,WHITE);
	
	rectBox(1220,250,1345,300,1,GREEN);
	outText("LUU",1245,265,9,WHITE,GREEN,1);
	
	rectBox(1220,365,1345,418,1,RED);	
	outText("XOA",1245,378,9,WHITE,RED,1);
	
	rectBox(1220,480,1345,525,1,BLACK);	
	outText("THOAT",1235,490,9,WHITE,BLACK,1);
	
	outText("Ma chuyen bay",580,270,9,GREEN,11,1);
	outText("San bay den",580,365,9,GREEN,11,1);
	outText("So hieu MB",580,480,9,GREEN,11,1);
	outText("Thoi gian",580,600,9,GREEN,11,1);
	outText(":",805,600,9,GREEN,11,2);
	outText("/",945,600,9,GREEN,11,2);
	outText("/",1005,600,9,GREEN,11,2);

	

}
void windowsBackgroundShowListCustomer(){
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
	outText("SO VE",442,180+20,9,GREEN,11,1);
	
	outText("SO CMND",610,180+20,9,GREEN,11,1);
	outText("HO",900,180+20,9,GREEN,11,1);
	outText("TEN",1155,180+20,9,GREEN,11,1);	
	outText("PHAI",1335,180+20,9,GREEN,11,1);	

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
	line(530,166+20,530,820+20);	
	line(555+265-20,166+20,554+265-20,820+20);
	line(555+265+300-50,166+20,554+265+300-50,820+20);
	line(555+265+300-70+270,166+20,554+265+300-70+270,820+20);
	
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
void windowsShowListCustomer(NODECB cb){
	windowsBackgroundShowListCustomer();
	outText("DANH SACH HANH KHACH THUOC CHUYEN BAY ",500,90,9,GREEN,11,2);
	outText(cb->info.maCB,1210,90,9,MAGENTA,11,2);
	outText("Ngay gio khoi hanh:",420+100,130,9,GREEN,11,1);

	char thoigian[18],gio[3],phut[3],ngay[3],thang[3],nam[5];
	itoa(cb->info.thoiGian.gio, gio,10);
	itoa(cb->info.thoiGian.phut, phut,10);
	itoa(cb->info.thoiGian.ngay, ngay,10);
	itoa(cb->info.thoiGian.thang, thang,10);
	itoa(cb->info.thoiGian.nam, nam,10);		
	formatDate(thoigian,gio,phut,ngay,thang,nam);
	outText(thoigian,660+100,130,9,MAGENTA,11,1);
	outText("Noi den:",1000,130,9,GREEN,11,1);	
	outText(cb->info.sanBayDen,1110,130,9,MAGENTA,11,1);
	
	setcolor(MAGENTA);
	rectangle(1532-1,255-1,1737+1,309+1);	
	rectBox(1532+1,255+1,1737-1,309-1,1,15);	
	outText("BACK",1600,274,9,MAGENTA,15,1);	
	
	int x,y,selected,page = 1, slHK = 0;
	int pageMAX = pageMax(cb->info.DSVE.sl);

	string* DS_CMNDHK = new string[cb->info.DSVE.sl+1];
	int* DS_CHONGOI = new int[cb->info.DSVE.sl+1];
	//addDSCMND_HK	
	for(int i = 1; i<= cb->info.DSVE.max;i++ ){
		if(cb->info.DSVE.ds[i] != ""){
			slHK++;
			DS_CMNDHK[slHK] = cb->info.DSVE.ds[i];
			DS_CHONGOI[slHK] = i;
		}
	}

	xuatDSHKCuaCB(DS_CMNDHK,DS_CHONGOI, slHK,page,pageMAX);

	while(1){
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE,x,y);
			selected = checkSelectMenuItems(x,y);
			switch(selected){
				case 8:{
					setcolor(MAGENTA);
					rectangle(1532-1,255-1,1737+1,309+1);	
					rectBox(1532+1,255+1,1737-1,309-1,1,3);	
					outText("BACK",1600,274,9,MAGENTA,3,1);
					break;
				}
				default:{
					setcolor(MAGENTA);
					rectangle(1532-1,255-1,1737+1,309+1);	
					rectBox(1532+1,255+1,1737-1,309-1,1,15);	
					outText("BACK",1600,274,9,MAGENTA,15,1);
					break;
				}
			}			
		}
		else if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			selected = checkSelectMenuItems(x,y);
			switch(selected){
				case 8:{   // thoat
					delete[] DS_CHONGOI;
					delete[] DS_CMNDHK;
					clearviewport();
					return;
				}
				case 11:{  // page truoc	
					if(page > 1 ) {
						clearTableDSHKCB();	
						xuatDSHKCuaCB(DS_CMNDHK,DS_CHONGOI, slHK,--page,pageMAX);									
					}
					break;		
				}
				case 12:{  // page sau
					if(page < pageMAX  ) {
						clearTableDSHKCB();		
						xuatDSHKCuaCB(DS_CMNDHK,DS_CHONGOI, slHK,++page,pageMAX);									
					}					
					break;
				}
			}
		}
		delay(10);
	}		
	
}
void windowsTHEMCB(){
	windowsBackgroundEditCB(" ~  THEM CHUYEN BAY MOI  ~  ");
	newCB(DS_CHUYENBAY);
}

void windowsCORRECTIONCB(NODECB &p){
	windowsBackgroundEditCB(" ~  HIEU CHINH CHUYEN BAY  ~  ");
	correctionCB(DS_CHUYENBAY, p);
}

void windowsFlight(){
	windowsBackgroundFlight();
	int x,y,selected,page = 1,  page_search = 1;
	int pageMAX = pageMax(DS_CHUYENBAY.sl),    page_searchMAX = 1;
	xuatDSCB(DS_CHUYENBAY,page);
	NODECB p = NULL;   // NODECB active
	int selectedNODECB = -1;    // vi tri nodecb tren table
	char MCB_SEARCH[MACB_MAX] = "";
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
					outText("THEM CB",1562,274,9,MAGENTA,3,1);	
	
					rectangle(1532-1,367-1,1737+1,422+1);	
					rectBox(1532+1,367+1,1737-1,422-1,1,15);	
					outText("HUY CB",1578,387,9,MAGENTA,15,1);	

					rectangle(1532-1,475-1,1737+1,527+1+3);	
					rectBox(1532+1,475+1,1737-1,527-1+3,1,15);	
					outText("CHINH SUA CB",1540,490,9,MAGENTA,15,1);
					
					rectangle(1532-1,475-1+100,1737+1,527+1+3+100);	
					rectBox(1532+1,475+1+100,1737-1,527-1+3+100,1,15);	
					outText("THONG TIN HK",1535,490+100,9,MAGENTA,15,1);
					break;
				}case 9:{
					setcolor(MAGENTA);
					rectangle(1532-1,255-1,1737+1,309+1);	
					rectBox(1532+1,255+1,1737-1,309-1,1,15);	
					outText("THEM CB",1562,274,9,MAGENTA,15,1);	
	
					rectangle(1532-1,367-1,1737+1,422+1);	
					rectBox(1532+1,367+1,1737-1,422-1,1,3);	
					outText("HUY CB",1578,387,9,MAGENTA,3,1);	

					rectangle(1532-1,475-1,1737+1,527+1+3);	
					rectBox(1532+1,475+1,1737-1,527-1+3,1,15);	
					outText("CHINH SUA CB",1540,490,9,MAGENTA,15,1);
					
					rectangle(1532-1,475-1+100,1737+1,527+1+3+100);	
					rectBox(1532+1,475+1+100,1737-1,527-1+3+100,1,15);	
					outText("THONG TIN HK",1535,490+100,9,MAGENTA,15,1);
					break;
				}case 10:{
					setcolor(MAGENTA);
					rectangle(1532-1,255-1,1737+1,309+1);	
					rectBox(1532+1,255+1,1737-1,309-1,1,15);	
					outText("THEM CB",1562,274,9,MAGENTA,15,1);	
	
					rectangle(1532-1,367-1,1737+1,422+1);	
					rectBox(1532+1,367+1,1737-1,422-1,1,15);	
					outText("HUY CB",1578,387,9,MAGENTA,15,1);	

					rectangle(1532-1,475-1,1737+1,527+1+3);	
					rectBox(1532+1,475+1,1737-1,527-1+3,1,3);	
					outText("CHINH SUA CB",1540,490,9,MAGENTA,3,1);

					rectangle(1532-1,475-1+100,1737+1,527+1+3+100);	
					rectBox(1532+1,475+1+100,1737-1,527-1+3+100,1,15);	
					outText("THONG TIN HK",1535,490+100,9,MAGENTA,15,1);
					break;
				}
				case 14:{
					setcolor(MAGENTA);
					rectangle(1532-1,255-1,1737+1,309+1);	
					rectBox(1532+1,255+1,1737-1,309-1,1,15);	
					outText("THEM CB",1562,274,9,MAGENTA,15,1);	
	
					rectangle(1532-1,367-1,1737+1,422+1);	
					rectBox(1532+1,367+1,1737-1,422-1,1,15);	
					outText("HUY CB",1578,387,9,MAGENTA,15,1);

					rectangle(1532-1,475-1,1737+1,527+1+3);	
					rectBox(1532+1,475+1,1737-1,527-1+3,1,15);	
					outText("CHINH SUA CB",1540,490,9,MAGENTA,15,1);
					
					rectangle(1532-1,475-1+100,1737+1,527+1+3+100);	
					rectBox(1532+1,475+1+100,1737-1,527-1+3+100,1,3);	
					outText("THONG TIN HK",1535,490+100,9,MAGENTA,3,1);
					break;
				}
				default:{
					setcolor(MAGENTA);
					rectangle(1532-1,255-1,1737+1,309+1);	
					rectBox(1532+1,255+1,1737-1,309-1,1,15);	
					outText("THEM CB",1562,274,9,MAGENTA,15,1);	
	
					rectangle(1532-1,367-1,1737+1,422+1);	
					rectBox(1532+1,367+1,1737-1,422-1,1,15);	
					outText("HUY CB",1578,387,9,MAGENTA,15,1);

					rectangle(1532-1,475-1,1737+1,527+1+3);	
					rectBox(1532+1,475+1,1737-1,527-1+3,1,15);	
					outText("CHINH SUA CB",1540,490,9,MAGENTA,15,1);
				
					rectangle(1532-1,475-1+100,1737+1,527+1+3+100);	
					rectBox(1532+1,475+1+100,1737-1,527-1+3+100,1,15);	
					outText("THONG TIN HK",1535,490+100,9,MAGENTA,15,1);
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
					nhapChuoi(MCB_SEARCH,1175-50,137,2,MACB_MAX-1,GREEN,1); 							
					setcolor(GREEN);
					rectangle(1170-1-50,130-1,1424-1+5,171-1); //searchborder

					if(strlen(MCB_SEARCH) == 0) {
						clearDSCB(DSCB_SEARCH);
						clearTableCB();		
						xuatDSCB(DS_CHUYENBAY,page);		
					}
					break;
				}
				case 7:{   // click button tim kiem
					if(strlen(MCB_SEARCH) == 0) {
						thongbao("Ban chua nhap vao ","san bay den");
						break;
					}
					clearDSCB(DSCB_SEARCH);
					SEARCH_DSCB_MCB(DSCB_SEARCH,MCB_SEARCH);
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
				case 8:{   // them cb
					clearviewport();
					windowsTHEMCB();		
					itemsActive(2);
					windowsBackgroundFlight();	
					pageMAX = pageMax(DS_CHUYENBAY.sl);				
					if(strlen(MCB_SEARCH) == 0){					
						xuatDSCB(DS_CHUYENBAY,page);						
					}else{
						clearDSCB(DSCB_SEARCH);
						SEARCH_DSCB_MCB(DSCB_SEARCH,MCB_SEARCH);
						page_searchMAX = pageMax(DSCB_SEARCH.sl);
						xuatDSCB(DSCB_SEARCH,page_search);
						outText(MCB_SEARCH,1175-50,137,9,GREEN,WHITE,1);
					}	
					if(strlen(MCB_SEARCH) == 0 && p!= NULL){// khi o tim kiem rong	
						hightlighNODECB(p,selectedNODECB,page,BLACK,WHITE);									
					}
					else if(strlen(MCB_SEARCH) != 0 && p!= NULL) {   // khi co tim kiem
						hightlighNODECB(p,selectedNODECB,page_search,BLACK,WHITE);
					}		
					break;
				}
				case 9:{  //huy cb
					if(p == NULL){
						thongbao("Chua chon chuyen bay", "muon thay doi!");
					}else{
						if(p->info.trangThai == HOANTAT){
							thongbao("Chuyen bay nay da","hoan tat!");
							break;
						}
						else if(p->info.trangThai == HUYCHUYEN){
							thongbao("Chuyen bay nay da","huy chuyen!");
							break;
						}
						bool check = confirm("Ban co chac muon", "huy chuyen bay nay?");
						if(check) {
							p->info.trangThai = HUYCHUYEN;  
							if(!isPlaneUsingForFlight_ignore(DS_CHUYENBAY,p->info.maCB,p->info.soHieuMB)){
								MAYBAY* mb = TimMayBayTheoSoHieu(DS_MAYBAY,p->info.soHieuMB);
								mb->active = true;
							}
							
						}
						clearFulltable();
						drawTableCB();  			
						if(strlen(MCB_SEARCH) == 0){					
							xuatDSCB(DS_CHUYENBAY,page);		
						}else{
							clearDSCB(DSCB_SEARCH);
							SEARCH_DSCB_MCB(DSCB_SEARCH,MCB_SEARCH);
							page_searchMAX = pageMax(DSCB_SEARCH.sl);
							xuatDSCB(DSCB_SEARCH,page_search);
						}
					}
					if(strlen(MCB_SEARCH) == 0 && p!= NULL){// khi o tim kiem rong	
						hightlighNODECB(p,selectedNODECB,page,BLACK,WHITE);									
					}
					else if(strlen(MCB_SEARCH) != 0 && p!= NULL) {   // khi co tim kiem
						hightlighNODECB(p,selectedNODECB,page_search,BLACK,WHITE);
					}	
					break;
				}
				case 10:{  // chinh sua cb
					if(p == NULL){
						thongbao("Chua chon chuyen bay", "muon thay doi!");
						break;
					}
					else{
						clearviewport();
						windowsCORRECTIONCB(p);	
				    	itemsActive(2);		
						windowsBackgroundFlight();				    	
						pageMAX = pageMax(DS_CHUYENBAY.sl); 
						if(strlen(MCB_SEARCH) == 0){					
							xuatDSCB(DS_CHUYENBAY,page);		
						}else{
							clearDSCB(DSCB_SEARCH);
							SEARCH_DSCB_MCB(DSCB_SEARCH,MCB_SEARCH);
							page_searchMAX = pageMax(DSCB_SEARCH.sl);
							xuatDSCB(DSCB_SEARCH,page_search);
							outText(MCB_SEARCH,1175-50,137,9,GREEN,WHITE,1);
						}                           
					}
					if(strlen(MCB_SEARCH) == 0 && p!= NULL){// khi o tim kiem rong	
						hightlighNODECB(p,selectedNODECB,page,BLACK,WHITE);									
					}
					else if(strlen(MCB_SEARCH) != 0 && p!= NULL) {   // khi co tim kiem
						hightlighNODECB(p,selectedNODECB,page_search,BLACK,WHITE);
					}	
					break;
				}
				case 11:{  // page truoc	
					if(strlen(MCB_SEARCH) == 0 && page > 1 ) {
						p = NULL;
						clearTableCB();
						xuatDSCB(DS_CHUYENBAY,--page);											
					}else if(strlen(MCB_SEARCH) != 0 && page_search > 1){	
						p = NULL;
						clearTableCB();
						xuatDSCB(DSCB_SEARCH,--page_search);
					}
					break;		
				}
				case 12:{  // page sau
					if(strlen(MCB_SEARCH) == 0 && page < pageMAX  ) {
						p = NULL;
						clearTableCB();
						xuatDSCB(DS_CHUYENBAY,++page);
											
					}else if(strlen(MCB_SEARCH) != 0 && page_search < page_searchMAX){
						p = NULL;
						clearTableCB();
						xuatDSCB(DSCB_SEARCH,++page_search);
					}					
					break;
				}
				case 13:{  // Khi click vao nodecb tren table => get p = nodecb duoc chon va highlight no sang len

					if(strlen(MCB_SEARCH) == 0){// khi o tim kiem rong	
						xuatDSCB(DS_CHUYENBAY,page);
						selectedNODECB = checkSelectTableNODE(x,y);    // vi tri nodecb tren table
						p = searchTableNODECB(DS_CHUYENBAY,page,selectedNODECB);
						if(p!= NULL){ // highlight  
							hightlighNODECB(p,selectedNODECB,page,BLACK,WHITE);
						}									
					}
					else{   // khi co tim kiem
						xuatDSCB(DSCB_SEARCH,page_search);
						selectedNODECB = checkSelectTableNODE(x,y);    // vi tri nodecb tren table
						NODECB q = searchTableNODECB(DSCB_SEARCH,page_search,selectedNODECB);
						if(q == NULL) break;
						
						p = searchCB(DS_CHUYENBAY.ds,q->info.maCB);
						if(p!= NULL){ // highlight
							hightlighNODECB(p,selectedNODECB,page_search,BLACK,WHITE);
						}			
					}									
					break;
				}
				case 14:{
					if(p == NULL){
						thongbao("Chua chon chuyen bay", "muon xem ds hanh khach!");
						break;
					}
					windowsShowListCustomer(p);
					itemsActive(2);
					windowsBackgroundFlight();				
					if(strlen(MCB_SEARCH) == 0){					
						xuatDSCB(DS_CHUYENBAY,page);						
					}else{
						xuatDSCB(DSCB_SEARCH,page_search);
						outText(MCB_SEARCH,1175-50,137,9,GREEN,WHITE,1);
					}
					if(strlen(MCB_SEARCH) == 0 && p!= NULL){// khi o tim kiem rong	
						hightlighNODECB(p,selectedNODECB,page,BLACK,WHITE);									
					}
					else if(strlen(MCB_SEARCH) != 0 && p!= NULL) {   // khi co tim kiem
						hightlighNODECB(p,selectedNODECB,page_search,BLACK,WHITE);
					}										
					break;
				}
				default:{

					if(selected > 0 && selected <6){
						clearDSCB(DSCB_SEARCH);						
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


