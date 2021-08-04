
int checkSelectmouseNEWHK(int x, int y){
	if(x>420-2+370 && x< 760+2+370 && y> 280 && y< 340 ){
		return 1;  //cmnd
	}else if(x>420-2+370 && x< 760+2+370 && y> 390 && y< 450 ){
		return 2;  //ho
	}else if(x>420-2+370 && x< 760+2+370 && y> 500 && y< 560 ){
		return 3; //ten
	}else if(x>505+20+370 -18 && x< 505+20+370 + 18 && y> 640 -18 && y< 640 + 18 ){
		return 4; //nam
	}else if(x>685+20+370 -18 && x< 685+20+370 + 18 && y> 640 -18 && y< 640 + 18 ){
		return 5; //nu
	}else if(x>690 && x< 840 && y>905 && y< 960 ){
		return 6;  //them
	}else if(x>1530-550 && x< 1670-550 && y> 905 && y< 960 ){
		return 7;  //thoat
	}else{
		return -1;
	}
}
void hightlighHK(NODEHK hk, int vitri, int STTpage, int color, int background){
	
	int y = 260; // toa do y node dau tien tren table
	int stt = (STTpage-1)*10 + vitri;  // stt node tren table
	
	y = y + (vitri-1)*60;   // toa do y cua node chon
	char chuoiSTT[4];
	
	itoa(stt,chuoiSTT,10); 
	outText(chuoiSTT,505,y,9,color,background,1);
	outText(hk->info.ho,570,y,9,color,background,1);	
	outText(hk->info.ten,820,y,9,color,background,1);
	outText(hk->info.soCMND,1130,y,9,color,background,1);	
	if(hk->info.gioiTinh == NAM){
		outText("Nam",1335,y,9,color,background,1);	
	}else 	outText("Nu",1335,y,9,color,background,1);	
}
void windowsBackgoundEditHK(char* title, int flag){
	clearviewport();
	windowsBackground();
	setlinestyle(1,0,2);
	setcolor(GREEN);
	outText(title,285+480,145,9,GREEN,11,2);
	outText("SO CMND",230+370,305,9,GREEN,11,2);
	outText("HO",230+370,410,9,GREEN,11,2);
	outText("TEN",230+370,515,9,GREEN,11,2);
	outText("GIOI TINH",230+370,630,9,GREEN,11,2);
	outText("Nam",420+10+370,630,9,0,11,2);
	outText("Nu",620+10+370,630,9,0,11,2);
	setcolor(GREEN);
	//khung ngoai 
	rectangle(400,235-50,1555,920-50);
	// thong tin khach hang
	
	rectangle(420-2+370,280-2,760+2+370,340+2);
	rectangle(420-2+370,390-2,760+2+370,450+2);
	rectangle(420-2+370,500-2,760+2+370,560+2);
	
	rectBox(420+370,280,760+370,340,1,WHITE);	
	rectBox(420+370,390,760+370,450,1,WHITE);	
	rectBox(420+370,500,760+370,560,1,WHITE);	
	
	// check box
	setcolor(GREEN);
	circle(505+20+370,640,17);
	circle(505+20+370,640,18);
	circle(685+20+370,640,17);
	circle(685+20+370 ,640,18);
	
//	button
	if(flag == 1){
		outText("THEM",1260-550,920,9,WHITE,GREEN,2);
	}
	else{
		outText("LUU",1260-550,920,9,WHITE,GREEN,2);
	}
	outText("THOAT",1550-550,920,9,WHITE,BLACK,2);
	rectBox(1240-550,905,1390-550,960,1,GREEN);
	rectBox(1530-550,905,1670-550,960,1,BLACK);
	

//	fillBox(525,640,1,GREEN);   
	
	/* // de check box ve trang thai ban dau
	setcolor(GREEN);
	circle(505+20,640,17);
	circle(505+20,640,18);	
	fillBox(525,640,1,11);
	setcolor(GREEN);
	circle(505+20,640,17);
	circle(505+20,640,18);		
	
	*/

}



void windowsBackgroundCustomer(){
		// outtext
	outText("DANH SACH HANH KHACH",520,127+10,9,GREEN,11,2); 
	outText("(TK_CMND)",965,137,9,GREEN,11,1);	
	outText("STT",500,180+20,9,GREEN,11,1);
	outText("HO",650,180+20,9,GREEN,11,1);
	outText("TEN",910,180+20,9,GREEN,11,1);
	outText("SO CMND",1145,180+20,9,GREEN,11,1);	
	outText("GT",1355,180+20,9,GREEN,11,1);			
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
	outText("THEM HK",1562,274,9,MAGENTA,15,1);	
	
	rectangle(1532-1,367-1,1737+1,422+1);	
	rectBox(1532+1,367+1,1737-1,422-1,1,15);	
	outText("XOA HK",1570,387,9,MAGENTA,15,1);	

	rectangle(1532-1,475-1,1737+1,527+1+3);	
	rectBox(1532+1,475+1,1737-1,527-1+3,1,15);	
	outText("HIEU CHINH",1540+20,490,9,MAGENTA,15,1);
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
	line(555,166+20,554,820+20);
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
void drawTableHK(){
	setcolor(GREEN);
	outText("STT",500,180+20,9,GREEN,11,1);
	outText("HO",650,180+20,9,GREEN,11,1);
	outText("TEN",910,180+20,9,GREEN,11,1);
	outText("SO CMND",1145,180+20,9,GREEN,11,1);	
	outText("GT",1355,180+20,9,GREEN,11,1);	
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
	line(555+265-20,166+20,554+265-20,820+20);
	line(555+265+300-50,166+20,554+265+300-50,820+20);
	line(555+265+300-70+270,166+20,554+265+300-70+270,820+20);
}
void windowsTHEMHK(DANHSACHHK& DS_HANHKHACH ,HANHKHACH* DS_HKxuat){
	windowsBackgoundEditHK("~ THEM KHACH HANG  ~", 1);
	newHK(DS_HANHKHACH, DS_HKxuat);
}
void windowsCorrectionHK(NODEHK& hk){
	windowsBackgoundEditHK("~ THEM KHACH HANG  ~", 0);
	correctionHK(hk);	
}

void windowsCustormer(){
	windowsBackgroundCustomer();
	
	int x,y,selected,page = 1, slHK = 0;
	int pageMAX = pageMax(DS_HANHKHACH.sl);
	//
	HANHKHACH* DS_HK = new HANHKHACH [DS_HANHKHACH.sl+ 20];   //  DS_HK bat dau tu 1 chua DSHK va co the new them 20 hk
	addDSHK(DS_HANHKHACH.ds,DS_HK,slHK);
	int sizeMax = (slHK + 20 ) * sizeof(HANHKHACH);    // sizeMax mang DS_HK co the new
	//
	SortDSHK(DS_HK,slHK);
	xuatDSHK(DS_HK,slHK,page,pageMAX);
	NODEHK hk = NULL;   // NODECB active
	int selectedHK = -1;    // vi tri nodecb tren table
	char SEARCH_CMND[CMND_MAX] = "";
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
					outText("THEM HK",1562,274,9,MAGENTA,3,1);	
					
					rectangle(1532-1,367-1,1737+1,422+1);	
					rectBox(1532+1,367+1,1737-1,422-1,1,15);	
					outText("XOA HK",1560+10,387,9,MAGENTA,15,1);
					
					rectangle(1532-1,475-1,1737+1,527+1+3);	
					rectBox(1532+1,475+1,1737-1,527-1+3,1,15);	
					outText("HIEU CHINH",1540+20,490,9,MAGENTA,15,1);	
					break;
				}case 9:{
					setcolor(MAGENTA);
					rectangle(1532-1,255-1,1737+1,309+1);	
					rectBox(1532+1,255+1,1737-1,309-1,1,15);	
					outText("THEM HK",1562,274,9,MAGENTA,15,1);	
					
					rectangle(1532-1,367-1,1737+1,422+1);	
					rectBox(1532+1,367+1,1737-1,422-1,1,3);	
					outText("XOA HK",1560+10,387,9,MAGENTA,3,1);	
					
					rectangle(1532-1,475-1,1737+1,527+1+3);	
					rectBox(1532+1,475+1,1737-1,527-1+3,1,15);	
					outText("HIEU CHINH",1540+20,490,9,MAGENTA,15,1);	

					break;
				}case 10:{
					setcolor(MAGENTA);
					rectangle(1532-1,255-1,1737+1,309+1);	
					rectBox(1532+1,255+1,1737-1,309-1,1,15);	
					outText("THEM HK",1562,274,9,MAGENTA,15,1);	
					
					rectangle(1532-1,367-1,1737+1,422+1);	
					rectBox(1532+1,367+1,1737-1,422-1,1,15);	
					outText("XOA HK",1560+10,387,9,MAGENTA,15,1);	
										
					rectangle(1532-1,475-1,1737+1,527+1+3);	
					rectBox(1532+1,475+1,1737-1,527-1+3,1,3);	
					outText("HIEU CHINH",1540+20,490,9,MAGENTA,3,1);
					
					break;
				}
				default:{
					setcolor(MAGENTA);
					rectangle(1532-1,255-1,1737+1,309+1);	
					rectBox(1532+1,255+1,1737-1,309-1,1,15);	
					outText("THEM HK",1562,274,9,MAGENTA,15,1);	
					
					rectangle(1532-1,367-1,1737+1,422+1);	
					rectBox(1532+1,367+1,1737-1,422-1,1,15);	
					outText("XOA HK",1560+10,387,9,MAGENTA,15,1);	

					rectangle(1532-1,475-1,1737+1,527+1+3);	
					rectBox(1532+1,475+1,1737-1,527-1+3,1,15);	
					outText("HIEU CHINH",1540+20,490,9,MAGENTA,15,1);
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
					nhapChuoi(SEARCH_CMND,1175-50,137,3,CMND_MAX-1,GREEN,1); 							
					setcolor(GREEN);
					rectangle(1170-1-50,130-1,1424-1+5,171-1); //searchborder

					if(strlen(SEARCH_CMND) == 0) {
						clearTableHK();		
						xuatDSHK(DS_HK,slHK,page,pageMAX);		
					}
					break;
				}
				case 7:{   // click button tim kiem
					if(strlen(SEARCH_CMND) == 0) {
						thongbao("Ban chua nhap vao ","so cmnd!");
						break;
					}else if(strlen(SEARCH_CMND) != 9){
						thongbao("So cmnd ","co 9 so!");
						break;
					}
					hk = SearchHK(DS_HANHKHACH.ds,SEARCH_CMND);
					if(hk == NULL){
						thongbao("Khong tim thay ","thong tin hanh khach!");
						break;
					}else{
						thongbao("Loading...","");
					}
					clearTableHK();					
					XuatHKSearchOnFirstRow(hk);
					hightlighHK(hk,1,1,BLACK,WHITE);	
					
					break;
				}
				case 8:{   // them HK
					if( slHK * sizeof(HANHKHACH) >= sizeMax ){
						thongbao("DS hanh khach day. ","Vui long thoat ra roi tro lai!");
						break;
					}
					windowsTHEMHK(DS_HANHKHACH, DS_HK);		
					itemsActive(3);
					windowsBackgroundCustomer();
					clearFulltable();
					drawTableHK(); 				
					if(slHK != DS_HANHKHACH.sl ){
						slHK++;			
						pageMAX = pageMax(DS_HANHKHACH.sl);						
					}															

					if(strlen(SEARCH_CMND) == 0){// khi o tim kiem rong	
						xuatDSHK(DS_HK,slHK,page,pageMAX);										
						if(hk!= NULL){ // highlight
							hightlighHK(hk,selectedHK,page,BLACK,WHITE);
						}									
					}
					else{   // khi co tim kiem				
						if(hk!= NULL){
							outText(SEARCH_CMND,1175-50,137,6,GREEN,15,1); 
							XuatHKSearchOnFirstRow(hk);								
							hightlighHK(hk,1,1,BLACK,WHITE);					
						}	
					}									
		
					break;
				}
				case 9:{  //xoa

					if(hk == NULL){
						thongbao("Hay chon hanh khach", " muon xoa!");
						break;
					}
					else if(isCustomerBookedTK(DS_CHUYENBAY,hk->info.soCMND)){
						thongbao("Hanh khach dang dat", " ve cho chuyen bay!");
						break;						
					}
					bool check = confirm("Ban co chac muon"," xoa hanh khach nay?");
					if(check){
					    deleteHKtemp(DS_HK, slHK,hk->info.soCMND);							
						deleteHK (DS_HANHKHACH.ds, hk->info.soCMND);
						DS_HANHKHACH.sl--;				
						hk = NULL;
						pageMAX = pageMax(DS_HANHKHACH.sl);		
						alert("Da xoa thong tin    "," hanh khach!                 ");		
						delay(1500);									
					}									
					clearFulltable();
					drawTableHK(); 			
					if(strlen(SEARCH_CMND) == 0){// khi o tim kiem rong	
						xuatDSHK(DS_HK,slHK,page,pageMAX);										
						if(hk!= NULL){ // highlight
							hightlighHK(hk,selectedHK,page,BLACK,WHITE);
						}									
					}
					else{   // khi co tim kiem				
						if(hk!= NULL){
							outText(SEARCH_CMND,1175-50,137,6,GREEN,15,1); 
							XuatHKSearchOnFirstRow(hk);								
							hightlighHK(hk,1,1,BLACK,WHITE);					
						}	
					}					
					break;
				}
				case 10:{   // hieu chinhh 
					if(hk == NULL){
						thongbao("Hay chon hanh khach muon", " thay doi thong tin!");
						break;
					}
					windowsCorrectionHK(hk);		
					int index = findIndexHK(DS_HK,slHK,hk->info.soCMND);
					DS_HK[index] = hk->info;					
					itemsActive(3);
					windowsBackgroundCustomer();
					
					clearFulltable();
					drawTableHK(); 			
					if(strlen(SEARCH_CMND) == 0){// khi o tim kiem rong	
						xuatDSHK(DS_HK,slHK,page,pageMAX);										
						if(hk!= NULL){ // highlight
							hightlighHK(hk,selectedHK,page,BLACK,WHITE);
						}									
					}
					else{   // khi co tim kiem				
						if(hk!= NULL){
							outText(SEARCH_CMND,1175-50,137,6,GREEN,15,1); 
							XuatHKSearchOnFirstRow(hk);								
							hightlighHK(hk,1,1,BLACK,WHITE);					
						}	
					}
					
					break;
				}
				case 11:{  // page truoc	
					if(strlen(SEARCH_CMND) == 0 && page > 1 ) {
						hk = NULL;
						clearTableHK();	
						xuatDSHK(DS_HK,slHK,--page,pageMAX);									
					}
					break;		
				}
				case 12:{  // page sau
					if(strlen(SEARCH_CMND) == 0 && page < pageMAX  ) {
						hk = NULL;
						clearTableHK();
						xuatDSHK(DS_HK,slHK,++page,pageMAX);											
					}					
					break;
				}
				case 13:{  // Khi click vao nodecb tren table => get p = nodecb duoc chon va highlight no sang len
					if(strlen(SEARCH_CMND) == 0){// khi o tim kiem rong	
						xuatDSHK(DS_HK,slHK,page,pageMAX);
						selectedHK = checkSelectTableNODE(x,y);    // vi tri HK tren table
						//
						int vitriHK = (page-1)*10 + selectedHK - 1;    //vitri hanhk khach trong ds_HK
						if(vitriHK >= slHK) break;
						else{
							hk = SearchHK(DS_HANHKHACH.ds, DS_HK[vitriHK].soCMND  );
						} 
						if(hk!= NULL){ // highlight
							hightlighHK(hk,selectedHK,page,BLACK,WHITE);
						}									
					}									
					break;
				}
				default:{

					if(selected > 0 && selected <6){
						delete[] DS_HK;						
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


