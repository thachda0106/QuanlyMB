
int checkSelectmouseThongKeMB(int x, int y){
	if(x>1170-400 && x< 1200-400 && y> 880 && y< 897 ){
		return 1;  //page trc
	}else if(x>1368+20-400 && x< 1394+20-400 && y> 880 && y< 897 ){
		return 2;  //page sau
	}else if(x>1532 && x< 1737 && y> 255 && y< 309 ){
		return 3; //back
	}else{
		return -1;
	}
}

void hightlighMB(MAYBAY* MAYBAY, int vitri, int STTpage, int color, int background){
	
	int y_1 = 260; // toa do y node dau tien tren table
	int stt = (STTpage-1)*10 + vitri;  // stt node tren table
	
	y_1 = y_1 + (vitri-1)*60;   // toa do y cua node chon
	char chuoiSTT[4], soCho[5]; // 
	
	itoa(stt,chuoiSTT,10); itoa(MAYBAY->soCho,soCho,10);
	outText(chuoiSTT,505,y_1,9,color,background,1);
	outText(MAYBAY->soHieuMB,574+10,y_1,9,color,background,1);
	outText(MAYBAY->loaiMB,890-30,y_1,9,color,background,1);
	outText(soCho,1040+200,y_1,9,color,background,1);	

}

void windowsBackgroundPlane(){
		// outtext
	outText("DANH SACH MAY BAY",520,127+10,9,GREEN,11,2); 
	outText("(TK_SHMB)",965,137,9,GREEN,11,1);	
	outText("STT",500,180+20,9,GREEN,11,1);
	outText("SO HIEU MB",574+20,180+20,9,GREEN,11,1);
	outText("LOAI MB",916,180+20,9,GREEN,11,1);
	outText("SO CHO NGOI",1180,180+20,9,GREEN,11,1);				
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
	outText("THEM MB",1562,274,9,MAGENTA,15,1);	
	
	rectangle(1532-1,367-1,1737+1,422+1);	
	rectBox(1532+1,367+1,1737-1,422-1,1,15);	
	outText("XOA MB",1578,387,9,MAGENTA,15,1);	

	rectangle(1532-1,475-1,1737+1,527+1+3);	
	rectBox(1532+1,475+1,1737-1,527-1+3,1,15);	
	outText("HIEU CHINH",1540+20,490,9,MAGENTA,15,1);
    // 
	rectangle(1532-1,475-1+100,1737+1,527+1+3+100);	
	rectBox(1532+1,475+1+100,1737-1,527-1+3+100,1,15);	
	outText("THONG KE",1560,490+100,9,MAGENTA,15,1);
	
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
	line(555,166+20,554,820+20);
	line(555+265,166+20,554+265,820+20);
	line(555+265+300,166+20,554+265+300,820+20);
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
void drawTableMB(){
	setcolor(GREEN);
	outText("(TK_SHMB)",965,137,9,GREEN,11,1);	
	outText("STT",500,180+20,9,GREEN,11,1);
	outText("SO HIEU MB",574+20,180+20,9,GREEN,11,1);
	outText("LOAI MB",916,180+20,9,GREEN,11,1);
	outText("SO CHO NGOI",1180,180+20,9,GREEN,11,1);
	
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
	line(555,166+20,554,820+20);
	line(555+265,166+20,554+265,820+20);
	line(555+265+300,166+20,554+265+300,820+20);
}
void windowsBackgroundEditMB(char * title){
	cleardevice();
	windowsBackground();
	setlinestyle(1,0,2);
	setcolor(GREEN);
	outText(title,710,130,9,GREEN,11,2);
//	setcolor(MAGENTA);	
	rectangle(405,170,1505,820);
	rectangle(760-2,240+10-2,1100+2,300+10+2);
	rectangle(760-2,350+10-2,1100+2,410+10+2);	
	rectangle(760-2,460+10-2,1100+2,520+10+2);	

	rectBox(760,240+10,1100,300+10,1,WHITE);	
	rectBox(760,350+10,1100,410+10,1,WHITE);
	rectBox(760,460+10,1100,520+10,1,WHITE);
	

	
	rectBox(1220,250,1345,300,1,GREEN);
	outText("LUU",1245,265,9,WHITE,GREEN,1);
	
	rectBox(1220,365,1345,418,1,RED);	
	outText("XOA",1245,378,9,WHITE,RED,1);
	
	rectBox(1220,480,1345,525,1,BLACK);	
	outText("THOAT",1235,490,9,WHITE,BLACK,1);
	
	outText("SO HIEU MB",580,270,9,GREEN,11,1);
	outText("LOAI MB",580,365,9,GREEN,11,1);
	outText("SO CHO ",580,480,9,GREEN,11,1);

}

void windowsBackgroundThongKeMB(){
	cleardevice();
	int xMax=getmaxx();
	int yMax=getmaxy();
	setcolor(GREEN);
	rectangle(1,1,xMax-1,yMax-1);
	rectangle(2,2,xMax-2,yMax-2);
	rectangle(3,3,xMax-3,yMax-3);
	rectBox(4,4,xMax-4,yMax-4,1,11);
		
	setcolor(GREEN);
	outText("~  THONG KE SO LUOT THUC HIEN CUA MOI BAY BAY  ~",500,120,9,GREEN,11,2);
	outText("STT",610,185+20,9,GREEN,11,1);
	outText("So Hieu MB",700,185+20,9,GREEN,11,1);
	outText("So Luot TH",970,185+20,9,GREEN,11,1);
//	
	

	rectangle(605,185,1130,835); // table
	rectangle(605-1,185-1,1130-1,835-1); // table	   
	line(605,212+10+20,1130,212+10+20);  // line horizontal for head tabble
	// draw lines horizontal for table
	setlinestyle(1,1,1);
	int y =282+20;
	for(int i = 1; i < 10; i++){
		line(605,y,1130,y); 
		y+=60;
	}
	// line vertical for data tableca
	setlinestyle(0,1,2);
	line(930,185,930,835);	
	line(665,185,665,835);	
	// phan trang
	setcolor(GREEN);
	line(1170-400,897,1200-400,880);
	line(1200-400,880,1200-400,909);
	line(1200-400,909,1170-400,897);	
			
	line(1394+20-400,897,1368+20-400,880);
	line(1368+20-400,880,1368+20-400,909);
	line(1394+20-400,897,1368+20-400,909);	
	setfillstyle(1,GREEN);
	floodfill(1170-400+3,897,GREEN);	
	floodfill(1394+20-400-3,897,GREEN);
	setcolor(MAGENTA);
	rectangle(1532-1,255-1,1737+1,309+1);	
	rectBox(1532+1,255+1,1737-1,309-1,1,15);	
	outText("BACK",1600,274,9,MAGENTA,15,1);	

}
void windowsShowThongKeMB(){
	windowsBackgroundThongKeMB();

	
	int x,y,selected,page = 1, slHK = 0;
	int pageMAX = pageMax(DS_MAYBAY.sl);
	
	DANHSACHMB DSMB_SLTH;
	GetDSMB(DS_MAYBAY, DSMB_SLTH );
	Quick_Sort(DSMB_SLTH);
	
	xuatDSMB_SLTH(DSMB_SLTH,page);

	while(1){
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE,x,y);
			selected = checkSelectmouseThongKeMB(x,y);
			switch(selected){
				case 1:{
					cout<<"truoc"<<endl;
					break;
				}
				case2:{
					cout<<"sau"<<endl;			
					break;
				}
				case 3:{
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
			selected = checkSelectmouseThongKeMB(x,y);
			switch(selected){
				case 1:{   // page truoc
					if(page > 1 ) {
						clearTableDSMB_SLTH();	
						xuatDSMB_SLTH(DSMB_SLTH,--page);									
					}
					break;	
				}
				case 2:{  // page sau
					if(page < pageMAX ) {
						clearTableDSMB_SLTH();	
						xuatDSMB_SLTH(DSMB_SLTH,++page);								
					}
					break;		
				}
				case 3:{  //thoat
					clearviewport();					
					return;
				}
			}
		}
		delay(10);
	}		
	
}
void windowsThemMB(){
	windowsBackgroundEditMB("         ~  THEM MAY BAY  ~");
	newMB(DS_MAYBAY);
}
void windowsCorrectionMB(DANHSACHMB &DSMB, MAYBAY*& mb){
	windowsBackgroundEditMB("     ~  HIEU CHINH MAY BAY  ~");
	correctionMB(DSMB,mb);
}
void windowsPlane(){
	windowsBackgroundPlane();
	int x,y,selected,page = 1 , page_SEARCH = 1;
	int pageMAX = pageMax(DS_MAYBAY.sl), pageMax_SEARCH = 1;
	xuatDSMB(DS_MAYBAY,page);
	MAYBAY* mb = NULL;   // MB selected
	DANHSACHMB DSMB_SEARCH;
	int selectedMB = -1;    // vi tri mb tren table
	char SHMB_SEARCH[SHMB_MAX] = "";
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
					outText("THEM MB",1562,274,9,MAGENTA,3,1);	

					rectangle(1532-1,367-1,1737+1,422+1);	
					rectBox(1532+1,367+1,1737-1,422-1,1,15);	
					outText("XOA MB",1578,387,9,MAGENTA,15,1);	

					rectangle(1532-1,475-1,1737+1,527+1+3);	
					rectBox(1532+1,475+1,1737-1,527-1+3,1,15);	
					outText("HIEU CHINH",1540+20,490,9,MAGENTA,15,1);
					
					rectangle(1532-1,475-1+100,1737+1,527+1+3+100);	
					rectBox(1532+1,475+1+100,1737-1,527-1+3+100,1,15);	
					outText("THONG KE",1560,490+100,9,MAGENTA,15,1);
					break;
				}case 9:{
					setcolor(MAGENTA);
					rectangle(1532-1,255-1,1737+1,309+1);	
					rectBox(1532+1,255+1,1737-1,309-1,1,15);	
					outText("THEM MB",1562,274,9,MAGENTA,15,1);	

					rectangle(1532-1,367-1,1737+1,422+1);	
					rectBox(1532+1,367+1,1737-1,422-1,1,3);	
					outText("XOA MB",1578,387,9,MAGENTA,3,1);	

					rectangle(1532-1,475-1,1737+1,527+1+3);	
					rectBox(1532+1,475+1,1737-1,527-1+3,1,15);	
					outText("HIEU CHINH",1540+20,490,9,MAGENTA,15,1);
					
					rectangle(1532-1,475-1+100,1737+1,527+1+3+100);	
					rectBox(1532+1,475+1+100,1737-1,527-1+3+100,1,15);	
					outText("THONG KE",1560,490+100,9,MAGENTA,15,1);
					break;
				}case 10:{
					setcolor(MAGENTA);
					rectangle(1532-1,255-1,1737+1,309+1);	
					rectBox(1532+1,255+1,1737-1,309-1,1,15);	
					outText("THEM MB",1562,274,9,MAGENTA,15,1);	

					rectangle(1532-1,367-1,1737+1,422+1);	
					rectBox(1532+1,367+1,1737-1,422-1,1,15);	
					outText("XOA MB",1578,387,9,MAGENTA,15,1);	

					rectangle(1532-1,475-1,1737+1,527+1+3);	
					rectBox(1532+1,475+1,1737-1,527-1+3,1,3);	
					outText("HIEU CHINH",1540+20,490,9,MAGENTA,3,1);
					
					rectangle(1532-1,475-1+100,1737+1,527+1+3+100);	
					rectBox(1532+1,475+1+100,1737-1,527-1+3+100,1,15);	
					outText("THONG KE",1560,490+100,9,MAGENTA,15,1);
					break;
				}case 14:{

					setcolor(MAGENTA);
					rectangle(1532-1,255-1,1737+1,309+1);	
					rectBox(1532+1,255+1,1737-1,309-1,1,15);	
					outText("THEM MB",1562,274,9,MAGENTA,15,1);	

					rectangle(1532-1,367-1,1737+1,422+1);	
					rectBox(1532+1,367+1,1737-1,422-1,1,15);	
					outText("XOA MB",1578,387,9,MAGENTA,15,1);	

					rectangle(1532-1,475-1,1737+1,527+1+3);	
					rectBox(1532+1,475+1,1737-1,527-1+3,1,15);	
					outText("HIEU CHINH",1540+20,490,9,MAGENTA,15,1);
					
					rectangle(1532-1,475-1+100,1737+1,527+1+3+100);	
					rectBox(1532+1,475+1+100,1737-1,527-1+3+100,1,3);	
					outText("THONG KE",1560,490+100,9,MAGENTA,3,1);
					break;
				}
				default:{
					setcolor(MAGENTA);
					rectangle(1532-1,255-1,1737+1,309+1);	
					rectBox(1532+1,255+1,1737-1,309-1,1,15);	
					outText("THEM MB",1562,274,9,MAGENTA,15,1);	

					rectangle(1532-1,367-1,1737+1,422+1);	
					rectBox(1532+1,367+1,1737-1,422-1,1,15);	
					outText("XOA MB",1578,387,9,MAGENTA,15,1);	

					rectangle(1532-1,475-1,1737+1,527+1+3);	
					rectBox(1532+1,475+1,1737-1,527-1+3,1,15);	
					outText("HIEU CHINH",1540+20,490,9,MAGENTA,15,1);
					
					rectangle(1532-1,475-1+100,1737+1,527+1+3+100);	
					rectBox(1532+1,475+1+100,1737-1,527-1+3+100,1,15);	
					outText("THONG KE",1560,490+100,9,MAGENTA,15,1);
					
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
					nhapChuoi(SHMB_SEARCH,1175-50,137,2,SHMB_MAX-1,GREEN,1);
					setcolor(GREEN);
					rectangle(1170-1-50,130-1,1424-1+5,171-1); //searchborder

					if(strlen(SHMB_SEARCH) == 0) {
						clearTableMB();		
						xuatDSMB(DS_MAYBAY,page);		
					}
					break;
				}
				case 7:{   // click button tim kiem
					if(strlen(SHMB_SEARCH) == 0) {
						thongbao("Ban chua nhap vao ","so hieu MB!");
						break;
					}
					DSMB_SEARCH.sl = 0;
					findDSMB_SEARCH(DS_MAYBAY,DSMB_SEARCH,SHMB_SEARCH);
				 
					if(DSMB_SEARCH.sl == 0){
						thongbao("So hieu may bay ","khong ton tai!");
						break;
					}else{
						thongbao("Loading...","");
					}
					clearTableMB();	
					page_SEARCH = 1; 	
					pageMax_SEARCH = pageMax(DSMB_SEARCH.sl);								
					xuatDSMB(DSMB_SEARCH,page_SEARCH);	
					
					
					break;
				}
				case 8:{  // them mb
					windowsThemMB();
					itemsActive(1);
					windowsBackgroundPlane();
					clearFulltable();
					drawTableMB(); 					
					if(strlen(SHMB_SEARCH) == 0){// khi o tim kiem rong	
						pageMAX = pageMax(DS_MAYBAY.sl);	
						xuatDSMB(DS_MAYBAY,page);
						if(mb!= NULL){ // highlight
							hightlighMB(mb,selectedMB,page,BLACK,WHITE);
						}									
					}
					else{   // khi co tim kiem				
						pageMax_SEARCH = pageMax(DSMB_SEARCH.sl);	
						xuatDSMB(DSMB_SEARCH,page_SEARCH);
						outText(SHMB_SEARCH,1175-50,137,6,GREEN,WHITE,1);
						if(mb != NULL ){
							hightlighMB(mb,selectedMB,1,BLACK,WHITE);						
						}	
					}				
					break;
				}
				case 9:{   // xoa mb
					if(mb == NULL){
						thongbao("Chua chon may bay", "muon thay doi!");
					}else{
						if(mb->active == false){
							thongbao("May bay nay dang duoc","su dung cho chuyen bay!");
							break;
						}
						bool check = confirm("Ban co chac muon", "xoa may bay nay?");
						if(check) {
							XoaMayBay(DS_MAYBAY, mb->soHieuMB);
							mb = NULL;
						}
						clearFulltable();
						drawTableMB();  	
						if(strlen(SHMB_SEARCH) == 0){// khi o tim kiem rong	
							pageMAX = pageMax(DS_MAYBAY.sl);	
							xuatDSMB(DS_MAYBAY,page);
							if(mb!= NULL){ // highlight
								hightlighMB(mb,selectedMB,page,BLACK,WHITE);
							}									
						}
						else{   // khi co tim kiem				
							pageMax_SEARCH = pageMax(DSMB_SEARCH.sl);	
							xuatDSMB(DSMB_SEARCH,page_SEARCH);
							outText(SHMB_SEARCH,1175-50,137,6,GREEN,WHITE,1);
							if(mb != NULL ){
								hightlighMB(mb,selectedMB,1,BLACK,WHITE);						
							}	
						}
					}					
					break;
				}
				case 10:{   // hieu chinh mb
					if(mb == NULL){
						thongbao("Chua chon may bay", "muon thay doi!");
						break;
					}
					else{
						windowsCorrectionMB(DS_MAYBAY, mb);	
				    	itemsActive(1);		
						windowsBackgroundPlane();
						clearFulltable();
						drawTableMB(); 														
					}
					if(strlen(SHMB_SEARCH) == 0){// khi o tim kiem rong	
						pageMAX = pageMax(DS_MAYBAY.sl);	
						xuatDSMB(DS_MAYBAY,page);
						if(mb!= NULL){ // highlight
							hightlighMB(mb,selectedMB,page,BLACK,WHITE);
						}									
					}
					else{   // khi co tim kiem				
						pageMax_SEARCH = pageMax(DSMB_SEARCH.sl);	
						xuatDSMB(DSMB_SEARCH,page_SEARCH);
						outText(SHMB_SEARCH,1175-50,137,6,GREEN,WHITE,1);
						if(mb != NULL ){
							hightlighMB(mb,selectedMB,1,BLACK,WHITE);						
						}	
					}
					break;
				}
				case 11:{  // page truoc	
					if(strlen(SHMB_SEARCH) == 0 && page > 1 ) {
						mb = NULL;
						clearTableMB();
						xuatDSMB(DS_MAYBAY,--page);									
					}
					else if( page_SEARCH > 1) {
						mb =NULL;
						clearTableMB();
						xuatDSMB(DSMB_SEARCH,--page_SEARCH);							
					}
					break;		
				}
				case 12:{  // page sau
					if(strlen(SHMB_SEARCH) == 0 && page < pageMAX  ) {
						mb = NULL;
						clearTableMB();
     				 	xuatDSMB(DS_MAYBAY,++page);
					}
					else if( page_SEARCH < pageMax_SEARCH) {
						mb =NULL;
						clearTableMB();
						xuatDSMB(DSMB_SEARCH,++page_SEARCH);							
					}									
					break;
				}
				case 13:{  
					if(strlen(SHMB_SEARCH) == 0){// khi o tim kiem rong	
						xuatDSMB(DS_MAYBAY,page);
						selectedMB = checkSelectTableNODE(x,y);    // vi tri MB tren table
						
						mb = searchTableMB(DS_MAYBAY,page,selectedMB);
						if(mb!= NULL){ // highlight
							hightlighMB(mb,selectedMB,page,BLACK,WHITE);
						}									
					}
					else{   // khi co tim kiem				
						if(DSMB_SEARCH.sl == 0) break;
						xuatDSMB(DSMB_SEARCH,page_SEARCH);
						selectedMB = checkSelectTableNODE(x,y);    // vi tri nodecb tren table
						mb = searchTableMB(DSMB_SEARCH,page_SEARCH,selectedMB);
						if(mb != NULL ){
							hightlighMB(mb,selectedMB,1,BLACK,WHITE);						
						}	
					}									
					break;
				}
				case 14:{
					windowsShowThongKeMB();
				    itemsActive(1);		
					windowsBackgroundPlane();													
					if(strlen(SHMB_SEARCH) == 0){// khi o tim kiem rong	
						pageMAX = pageMax(DS_MAYBAY.sl);	
						xuatDSMB(DS_MAYBAY,page);
						if(mb!= NULL){ // highlight
							hightlighMB(mb,selectedMB,page,BLACK,WHITE);
						}									
					}
					else{   // khi co tim kiem				
						pageMax_SEARCH = pageMax(DSMB_SEARCH.sl);	
						xuatDSMB(DSMB_SEARCH,page_SEARCH);
						outText(SHMB_SEARCH,1175-50,137,6,GREEN,WHITE,1);
						if(mb != NULL ){
							hightlighMB(mb,selectedMB,1,BLACK,WHITE);						
						}	
					}					
					break;
				}
				default:{
					if(selected > 0 && selected <6){
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



