string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}
void showDSChoNgoi( DANHSACHVE* DSVE, int page, int pageMax){
	int max = DSVE->max;
	char pagination[10] = "",  strMax[4] = "", strPage[4] ="";
	itoa(page,strPage,10);
	itoa(pageMax,strMax,10);
	strcat(pagination,strPage);	
	strcat(pagination,"/");	
	strcat(pagination,strMax);	
	outText(pagination,1700,735,6,GREEN,11,1);
	
	char vitri[4]; 
	int x = 1200, y = 250;   // toa do x , y bat dau xuat
	if( page == 1 ){    // 1 trang
		for(int i= 1; i<= 15; i++, x+= 30){
			itoa(i,vitri,10);		
			if(i>10) x+=10;
			if(DSVE->ds[i] == ""){
				outText(vitri,x,y,9,GREEN,11,1);	
			}else{
				outText(vitri,x,y,9,RED,11,1);
			}
	
	
		}
		y+=40; x = 1200;
		for(int i = 16; i <= max; i++,x+=35){
			
			itoa(i,vitri,10);
			if(DSVE->ds[i] == ""){
				outText(vitri,x,y,9,GREEN,11,1);	
			}else{
				outText(vitri,x,y,9,RED,11,1);
			}
			if(i % 15 == 0){
				y+=40;	
				x = 1165;
			}
			if(i == 100){
				y+=40;	
				x = 1200;
				break;
			}
		}
		if(max > 100){
			for(int i = 101; i <= max; i++,x+=50){
				itoa(i,vitri,10);
				if(DSVE->ds[i] == ""){
					outText(vitri,x,y,9,GREEN,11,1);	
				}else{
					outText(vitri,x,y,9,RED,11,1);
				}
				if(i == 140) break;
				if(i % 10 == 0 ){
					y+=40;	
					x = 1150;
				} 
								
			}		
		}
	}
	else {  // trang > 1
		x = 1200, y = 250;   // toa do x , y bat dau xuat
		int i = 141 + (page-2) *110, maximum = i + 110;         //page 1 : 0- 140   page 2 : 141 - 250   page 3:  251 - 360 
		for( ; i <= max && i< maximum ; i++,x+=50){
			itoa(i,vitri,10);
			if(DSVE->ds[i] == ""){
				outText(vitri,x,y,9,GREEN,11,1);	
			}else{
				outText(vitri,x,y,9,RED,11,1);
			}
			if(i % 10 == 0 ){
				y+=40;	
				x = 1150;
			} 
		}		
		
	}
}
int getPageMAXDSVE(int slVE){
	int maxPAGE = 1;
	if(slVE <= 140 ) return maxPAGE;
	else{
		slVE-= 140;
		maxPAGE += slVE/110;
		slVE /= 110;
		if(slVE != 0) maxPAGE++;
	}
	return maxPAGE;
}
void bookVE(DANHSACHCB &DS_CHUYENBAY, DANHSACHHK& DS_HANHKHACH, NODECB& cb){
	outText(cb->info.maCB,1595,158,9,MAGENTA,11,2);
	int x = 0, y = 0, selected = -1, page =1, pageMax = getPageMAXDSVE(cb->info.DSVE.max); 	   
	
	DANHSACHVE *DSVE = &(cb->info.DSVE);  // lay danh sach ve de thay doi du lieu
	NODEHK p; 
	string soCMND; 
	HANHKHACH hk; 	
	hk.soCMND[0] = '\0'; hk.ho[0] = '\0'; hk.ten[0] ='\0'; int gioitinh = -1; char vitri[4] = ""; 
	cout<< hk.soCMND<<" "<<hk.ho<<" "<<hk.ten<<gioitinh<<endl;
	
	showDSChoNgoi(DSVE,page, pageMax); 
	bool checkEdit = true;
	while(1){

		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE,x,y);
			selected = checkSelectmouseBOOKTK(x,y);
			switch(selected){
				case 7:{
					outText("DAT VE",1260,920,9,YELLOW,BLUE,2);
					rectBox(1240,905,1390,960,1,BLUE);
					break;
				}
				case 8:{
					outText("THOAT",1550,920,9,YELLOW,RED,2);
					rectBox(1530,905,1670,960,1,RED);
					break;
				}
				default:{
					outText("DAT VE",1260,920,9,WHITE,GREEN,2);
					outText("THOAT",1550,920,9,WHITE,BLACK,2);
					rectBox(1240,905,1390,960,1,GREEN);
					rectBox(1530,905,1670,960,1,BLACK);
					break;
				}
			}			
		}
		else if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			selected = checkSelectmouseBOOKTK(x,y);
			switch(selected){
				case 1:{  // cmnd
					outText("					                                                                                        ",
					 430,250,6,11,11,1);		
					setcolor(BLUE);
					rectangle(420-2,280-2,760+2,340+2);
					setcolor(GREEN);
					rectangle(420-2,390-2,760+2,450+2);
					rectangle(420-2,500-2,760+2,560+2);
					rectangle(1450-2,720-2,1650+2,770+2);
					nhapChuoi(hk.soCMND,430,300,3,CMND_MAX-1,BLACK,1);
					p = SearchHK(DS_HANHKHACH.ds, hk.soCMND);
					if(p!= NULL){
						outText(hk.ho,430,410,6,WHITE,15,1);
						outText(hk.ten,430,520,6,WHITE,15,1);
						strcpy(hk.ho,p->info.ho);
						strcpy(hk.ten,p->info.ten);
						hk.gioiTinh = p->info.gioiTinh;
						outText(hk.ho,430,410,6,BLACK,15,1);
						outText(hk.ten,430,520,6,BLACK,15,1);
						if(hk.gioiTinh == NAM){
							setcolor(BLUE);
							circle(505+20,640,17);
							fillBox(525,640,1,BLUE);
							setcolor(GREEN);
							circle(505+20,640,18);	
							// 		
							setcolor(11);
							circle(685+20,640,17);
							fillBox(705,640,1,11);
							setcolor(GREEN);
							circle(685+20,640,18);
							gioitinh = 0; 
						}else{
							setcolor(BLUE);
							circle(685+20,640,17);
							fillBox(705,640,1,BLUE);
							setcolor(GREEN);
							circle(685+20,640,18);
							// 
							setcolor(11);
							circle(505+20,640,17);
							fillBox(525,640,1,11);
							setcolor(GREEN);
							circle(505+20,640,18);	
							gioitinh = 1;						
						}
						checkEdit = false;
					}else checkEdit = true;
					break;
				}
				case 2:{   // ho
					outText("					                                               ",
					 430,360,6,11,11,1);
					 if(!checkEdit) break;
					setcolor(BLUE);
					rectangle(420-2,390-2,760+2,450+2);
					setcolor(GREEN);
					rectangle(420-2,280-2,760+2,340+2);
					rectangle(420-2,500-2,760+2,560+2);
					rectangle(1450-2,720-2,1650+2,770+2);
					nhapChuoi(hk.ho,430,410,1,HO_MAX-1,BLACK,1);
					break;
				}
				case 3:{  // ten
					outText("					                                               ",
					 430,470,6,11,11,1);
					 if(!checkEdit) break;
					setcolor(BLUE);
					rectangle(420-2,500-2,760+2,560+2);
					setcolor(GREEN);
					rectangle(420-2,280-2,760+2,340+2);
					rectangle(420-2,390-2,760+2,450+2);
					rectangle(1450-2,720-2,1650+2,770+2);
					nhapChuoi(hk.ten,430,520,1,TEN_MAX-1,BLACK,1);				
					break;
				}
				case 4:{  // check box nam
					outText("					                                               ",
					 430,580,6,11,11,1);
					 if(!checkEdit) break;
					setcolor(GREEN);
					rectangle(420-2,280-2,760+2,340+2);
					rectangle(420-2,390-2,760+2,450+2);
					rectangle(420-2,500-2,760+2,560+2);
					rectangle(1450-2,720-2,1650+2,770+2);
					setcolor(BLUE);
					circle(505+20,640,17);
					fillBox(525,640,1,BLUE);
					setcolor(GREEN);
					circle(505+20,640,18);	
					// 		
					setcolor(11);
					circle(685+20,640,17);
					fillBox(705,640,1,11);
					setcolor(GREEN);
					circle(685+20,640,18);
					gioitinh = 0;
					break;
				}
				case 5:{ // check box nu
					outText("					                                               ",
					 430,580,6,11,11,1);
					 if(!checkEdit) break;
					setcolor(GREEN);
					rectangle(420-2,280-2,760+2,340+2);
					rectangle(420-2,390-2,760+2,450+2);
					rectangle(420-2,500-2,760+2,560+2);
					rectangle(1450-2,720-2,1650+2,770+2);
					setcolor(BLUE);
					circle(685+20,640,17);
					fillBox(705,640,1,BLUE);
					setcolor(GREEN);
					circle(685+20,640,18);
					// 
					setcolor(11);
					circle(505+20,640,17);
					fillBox(525,640,1,11);
					setcolor(GREEN);
					circle(505+20,640,18);
					gioitinh = 1;
					break;
				}
				case 6:{  // chon vi tri ngoi
					outText("					                                               ", 
					 1450,780,6,11,11,1);
					setcolor(BLUE);
					rectangle(1450-2,720-2,1650+2,770+2);	
					setcolor(GREEN);
					rectangle(420-2,280-2,760+2,340+2);
					rectangle(420-2,390-2,760+2,450+2);
					rectangle(420-2,500-2,760+2,560+2);
					nhapChuoi(vitri,1460,740,3,4-1,BLACK,1);
					break;
				}
				case 7:{  // dat ve
					int VITRI = atoi(vitri); 
					if(strlen(hk.soCMND) != 9){
						outText("So cmnd co 9 so!", 430,250,6,RED,11,1);
						break;
					}
					else if(strlen(hk.ho) == 0){
						outText("Khong duoc de trong!", 430,360,6,RED,11,1);
						break;
					}else if(strlen(hk.ten) == 0){
						outText("Khong duoc de trong!", 430,470,6,RED,11,1);
						break;
					}else if(gioitinh == -1){
						outText("Chon gioi tinh!", 430,580,6,RED,11,1);
						break;
					}
					else if(VITRI <= 0 || VITRI > DSVE->max || DSVE->ds[VITRI] != "" ){
						outText("Vi tri ngoi khong hop le!", 1450,780,6,RED,11,1);
						break;
					}
					else if(isMovingAtThesameTime(DS_CHUYENBAY,hk.soCMND,cb->info.thoiGian) ){
						outText("Ban da dat ve tren 1 chuyen bay, cung thoi diem nay!", 430,250,6,RED,11,1);
						break;
					}
					
					if(gioitinh == 0) hk.gioiTinh = NAM;
					else hk.gioiTinh = NU;
					// tim xem co so cmnd nay tren chuyen bay chua (moi nguoi chi dat duoc 1 ve)
					bool checksoCMND = false; 
					soCMND = convertToString(hk.soCMND, strlen(hk.soCMND) );
					for(int i=1;i<=DSVE->max;i++){
						if( soCMND == DSVE->ds[i]) {
							checksoCMND = true;
							break;
						}				
					}
					if(checksoCMND) {
						outText("Ban da dat ve tren chuyen bay nay!", 430,250,6,RED,11,1);
						break;
					}
					DSVE->ds[VITRI] = soCMND;      
					++DSVE->sl;          
					if(DSVE->sl == DSVE->max) cb->info.trangThai = HETVE;          
					if(p == NULL){
						themHK( hk, DS_HANHKHACH.ds); 
						DS_HANHKHACH.sl++;				
					}
					alert("BAN DA DA DAT","VE THANH CONG!");
					delay(1500);
					clearviewport();
					return;			
				}
				case 8:{  // thoat
					clearviewport();
					return;
					break;
				}
				case 9:{
					if(page > 1){
						clearDSVE();
						showDSChoNgoi(DSVE,--page, pageMax); 	
					}				
					break;
				}
				case 10:{
					if(page < pageMax){
						clearDSVE();
						showDSChoNgoi(DSVE,++page, pageMax); 	
					}
					break;
				}
				default:{  
					setcolor(GREEN);
					rectangle(420-2,280-2,760+2,340+2);
					rectangle(420-2,390-2,760+2,450+2);
					rectangle(420-2,500-2,760+2,560+2);
					rectangle(1450-2,720-2,1650+2,770+2);
					break;
				}
			}
		}
		delay(10);
	}		
}


void cancelVE(DANHSACHCB& DS_CHUYENBAY, DANHSACHHK & DS_HANHKHACH, NODECB& cb ){
	outText(cb->info.maCB,1595,158,9,MAGENTA,11,2);
	int x = 0, y = 0, selected = -1, index = -1, page = 1, pageMax = getPageMAXDSVE(cb->info.DSVE.max); 	  
	bool isBooked = false;
	DANHSACHVE *DSVE = &(cb->info.DSVE);  // lay danh sach ve de thay doi du lieu
	NODEHK p; 
	string soCMND; 	char SOCMND[CMND_MAX] = "";
	HANHKHACH hk; 	
	hk.soCMND[0] = '\0'; hk.ho[0] = '\0'; hk.ten[0] ='\0'; int gioitinh = -1; char vitri[4] = ""; 
	cout<< hk.soCMND<<" "<<hk.ho<<" "<<hk.ten<<gioitinh<<endl;
	showDSChoNgoi(DSVE,page, pageMax); 
	while(1){

		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE,x,y);
			selected = checkSelectmouseBOOKTK(x,y);
			switch(selected){
				case 7:{
					outText("HUY VE",1260,920,9,YELLOW,BLUE,2);
					rectBox(1240,905,1390,960,1,BLUE);
					break;
				}
				case 8:{
					outText("THOAT",1550,920,9,YELLOW,RED,2);
					rectBox(1530,905,1670,960,1,RED);
					break;
				}
				default:{
					outText("HUY VE",1260,920,9,WHITE,GREEN,2);
					outText("THOAT",1550,920,9,WHITE,BLACK,2);
					rectBox(1240,905,1390,960,1,GREEN);
					rectBox(1530,905,1670,960,1,BLACK);
					break;
				}
			}			
		}
		else if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			selected = checkSelectmouseBOOKTK(x,y);
			switch(selected){
				case 1:{  // cmnd
					outText("                                                                   ",
					 430,250,6,11,11,1);
					setcolor(BLUE);
					rectangle(420-2,280-2,760+2,340+2);
					setcolor(GREEN);
					rectangle(420-2,390-2,760+2,450+2);
					rectangle(420-2,500-2,760+2,560+2);
					rectangle(1450-2,720-2,1650+2,770+2);
					nhapChuoi(SOCMND,430,300,3,CMND_MAX-1,BLACK,1);
					if(strlen(SOCMND) == 0){
						outText("Hay dien so cmnd!", 430,250,6,RED,11,1);
						break;
					}else if(strlen(SOCMND) !=9){
						outText("So cmnd co 9 so!", 430,250,6,RED,11,1);
						break;	
					}
					soCMND = convertToString(SOCMND,strlen(SOCMND));
					isBooked = false;	
					for(index=1; index<= DSVE->max; index++){
						if(DSVE->ds[index] == soCMND){
							isBooked = true;
							break;
						} 
					}
					if(!isBooked){
						outText("So cmnd chua dat ve tren chuyen bay nay!", 430,250,6,RED,11,1);
						break;
					}							
					p = SearchHK(DS_HANHKHACH.ds, SOCMND);
					if(p!= NULL){
						outText(hk.ho,430,410,6,WHITE,15,1);
						outText(hk.ten,430,520,6,WHITE,15,1);
						outText(vitri,1460,740,6,WHITE,15,1);	
						//	
						strcpy(hk.ho,p->info.ho);
						strcpy(hk.ten,p->info.ten);
						hk.gioiTinh = p->info.gioiTinh;
						outText(hk.ho,430,410,6,BLACK,15,1);
						outText(hk.ten,430,520,6,BLACK,15,1);
						if(hk.gioiTinh == 0){
							setcolor(BLUE);
							circle(505+20,640,17);
							fillBox(525,640,1,BLUE);
							setcolor(GREEN);
							circle(505+20,640,18);	
							// 		
							setcolor(11);
							circle(685+20,640,17);
							fillBox(705,640,1,11);
							setcolor(GREEN);
							circle(685+20,640,18);
							gioitinh = 0;
						}else{
							setcolor(BLUE);
							circle(685+20,640,17);
							fillBox(705,640,1,BLUE);
							setcolor(GREEN);
							circle(685+20,640,18);
							// 
							setcolor(11);
							circle(505+20,640,17);
							fillBox(525,640,1,11);
							setcolor(GREEN);
							circle(505+20,640,18);							
						}
						itoa(index,vitri,10);
						outText(vitri,1460,740,6,BLACK,15,1);		
					}
					break;
				}
				case 7:{  // HUY VE
					if(!isBooked ){
						outText("So cmnd chua dat ve.(so cmnd co 9 so)!", 430,250,6,RED,11,1);	
						break;					
					}
					bool check = confirm("Ban co chac muon","huy ve khong?");
					if(check){
						DSVE->ds[index] = "";
						--DSVE->sl;
						if(cb->info.trangThai == HETVE) cb->info.trangThai = CONVE;        
						alert("Ban da huy ve thanh","cong!               ");		
						delay(1500);					
					}
					clearviewport();
					return;
				}
				case 8:{  // thoat
					clearviewport();
					return;
					break;
				}
				case 9:{
					if(page > 1){
						clearDSVE();
						showDSChoNgoi(DSVE,--page, pageMax); 	
					}				
					break;
				}
				case 10:{
					if(page < pageMax){
						clearDSVE();
						showDSChoNgoi(DSVE,++page, pageMax); 	
					}
					break;
				}				
				default:{  
					setcolor(GREEN);
					rectangle(420-2,280-2,760+2,340+2);
					rectangle(420-2,390-2,760+2,450+2);
					rectangle(420-2,500-2,760+2,560+2);
					rectangle(1450-2,720-2,1650+2,770+2);
					break;
				}
			}
		}
		delay(10);
	}		
		
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	
	

