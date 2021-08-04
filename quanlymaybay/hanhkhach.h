//============Doc File=====================
int loadFile(DANHSACHHK& DS_HANHKHACH){
	fstream file;
	file.open("DANHSACHHK.txt", ios::in);
	if(file.fail())
		return 0;  
	else{
		file >> DS_HANHKHACH.sl;
		for(int i=1; i<=DS_HANHKHACH.sl;i++){
			
			file.ignore();
			HANHKHACH x; int sex;
			file.getline(x.soCMND, CMND_MAX);
			file.getline(x.ho, HO_MAX );
			file.getline(x.ten, TEN_MAX);
			file >> sex;
			if(sex==0){
				x.gioiTinh = NAM ;
			}
			else x.gioiTinh = NU;		
			themHK(x,DS_HANHKHACH.ds);
		}
	}
	file.close();
	return 1;
}
//=========================================


//===============Ghi File==================
void writeHKVaoFile(NODEHK &z,fstream &file){
	if(z != NULL){
		file << z->info.soCMND <<endl;
		file <<z->info.ho <<endl;
		file << z->info.ten <<endl;
		file << z->info.gioiTinh <<endl;
		writeHKVaoFile(z->left,file);
		writeHKVaoFile(z->right,file);
	}
}

int saveDSVaoFile(DANHSACHHK& DS_HANHKHACH){
	fstream file;
	file.open("DANHSACHHK.txt", ios::out);
	file << DS_HANHKHACH.sl<< endl;
	if(DS_HANHKHACH.sl != 0) writeHKVaoFile(DS_HANHKHACH.ds,file);
	file.close();
	return 1;
}
//=========================================

void Xuat_NLR(NODEHK p){
	if(p != NULL)
	{
		cout<<"SO CMND: "<<p->info.soCMND<<endl;
		cout<<"HO: "<<p->info.ho<<endl;
		cout<<"TEN: "<<p->info.ten<<endl;
		cout<<"PHAI(NAM 0, NU 1) : "<<p->info.gioiTinh<<endl;
		Xuat_NLR(p->left);
		Xuat_NLR(p->right);	
	}
}
//void addDSHKTemp(NODEHK DSHK, HANHKHACH* DSHK_temp, int& sl){
//	if(DSHK != NULL)
//	{
//		DSHK_temp[sl++] = DSHK->info; 
//		addDSHKTemp(DSHK->left, DSHK_temp,sl);
//		addDSHKTemp(DSHK->right,DSHK_temp,sl);	
//	}
//}

void addDSHK(NODEHK DSHK,HANHKHACH* DS_HK , int& sl){
	if(DSHK != NULL)
	{
		DS_HK[sl++] = DSHK->info;
		addDSHK(DSHK->left, DS_HK,sl);
		addDSHK(DSHK->right,DS_HK,sl);	
	}
}
void XuatHKSearchOnFirstRow(NODEHK hk){
	if(hk == NULL) return;	
	int stt = 1,y = 260;    
	char chuoiSTT[4];
	// vi tri node mb tren ds may bay = stt
	itoa(stt,chuoiSTT,10); 
	outText(chuoiSTT,505,y,9,GREEN,11,1);
	outText(hk->info.ho,570,y,9,GREEN,11,1);	
	outText(hk->info.ten,820,y,9,GREEN,11,1);
	outText(hk->info.soCMND,1130,y,9,GREEN,11,1);	
	if(hk->info.gioiTinh == NAM){
		outText("Nam",1335,y,9,GREEN,11,1);	
	}else 	outText("Nu",1335,y,9,GREEN,11,1);	
	outText("TRANG 1/1 ",1210,885,9,GREEN,11,1);
}

void xuatDSHK(HANHKHACH* DS_HK,int slHK, int STTpage, int max){   // STTpage la trang hien tai tren table 
	char MAXpage[4], chuoiSTTpage[4] ;   // cho phan trang toi da 3 so 
	char pagination[] = "TRANG "; // text xd vi tri trang tren man hinh
	itoa(max,MAXpage,10 ); itoa(STTpage,chuoiSTTpage,10 );   // chuyen sang chuoi de noi chuoi
	strcat(pagination,chuoiSTTpage);
	strcat(pagination,"/");
	strcat(pagination,MAXpage);  
	outText(pagination ,1210,885,9,GREEN,11,1);  // outtext xd vitri
	
	int stt = (STTpage*10 - 9 ) - 1 , y = 260;    // vi tri HK dau tien theo trang, xuat stt node tren table va toa do xuat y. bat dau tu vitri 1 theo trang 1/maxpage
	char chuoiSTT[4];

	for(int i = stt; i<= stt+9 ; i++ ){
		if(i >= slHK) break;
		itoa(i+1,chuoiSTT,10); 
		outText(chuoiSTT,505,y,9,GREEN,11,1);
		outText(DS_HK[i].ho,570,y,9,GREEN,11,1);
		outText(DS_HK[i].ten,820,y,9,GREEN,11,1);
		outText(DS_HK[i].soCMND,1130,y,9,GREEN,11,1);	
		if(DS_HK[i].gioiTinh == NAM){ 
			outText("Nam",1335,y,9,GREEN,11,1);	
		}else 	outText("Nu",1335,y,9,GREEN,11,1);	
		y+=60; 		
	}
}

void xuatDSHKCuaCB(string* DS_CMNDHK,int* DS_CHONGOI,int slHK, int STTpage, int max){   // STTpage la trang hien tai tren table 
	char MAXpage[4], chuoiSTTpage[4] ;   // cho phan trang toi da 3 so 
	char pagination[] = "TRANG "; // text xd vi tri trang tren man hinh
	itoa(max,MAXpage,10 ); itoa(STTpage,chuoiSTTpage,10 );   // chuyen sang chuoi de noi chuoi
	strcat(pagination,chuoiSTTpage);
	strcat(pagination,"/");
	strcat(pagination,MAXpage);  
	outText(pagination ,1210,885,9,GREEN,11,1);  // outtext xd vitri
	
	int stt = STTpage*10 - 9 , y = 260;    // vi tri HK dau tien theo trang, xuat stt node tren table va toa do xuat y. bat dau tu vitri 1 theo trang 1/maxpage
	char chuoiSTT[4], chongoi[4];

	NODEHK hk = NULL;
	char SO_CMND[CMND_MAX] = "";
	for(int i = stt; i<= stt+9 ; i++ ){
		if(i > slHK) break;
		strcpy(SO_CMND,DS_CMNDHK[i].c_str());		
		hk = SearchHK(DS_HANHKHACH.ds, SO_CMND );      
		if(hk == NULL) {  // du phong tranh truong hop outtext NULL->info
		 	cout<<"loi xuatDSHK/n";
		 	return;
		}
		itoa(i,chuoiSTT,10); itoa(DS_CHONGOI[i],chongoi,10); 
		outText(chuoiSTT,370,y,9,GREEN,11,1);			
		outText(chongoi,460,y,9,GREEN,11,1);
		outText(hk->info.soCMND,605,y,9,GREEN,11,1);
		outText(hk->info.ho,820,y,9,GREEN,11,1);
		outText(hk->info.ten,1100,y,9,GREEN,11,1);	
		if(hk->info.gioiTinh == NAM){
			outText("Nam",1335,y,9,GREEN,11,1);	
		}else 	outText("Nu",1335,y,9,GREEN,11,1);	
		y+=60; 		
	}
}
void correctionHK(NODEHK& hk){
	char SO_CMND[CMND_MAX] ="",HO[HO_MAX]="",TEN[TEN_MAX]="";
	int selected,x,y, gioitinh = -1;
	strcpy(SO_CMND,hk->info.soCMND);
	strcpy(HO,hk->info.ho);
	strcpy(TEN,hk->info.ten);
	if(hk->info.gioiTinh == 0){
		setcolor(BLUE);
		circle(505+20+370,640,17);
		fillBox(505+20+370,640,1,BLUE);
		setcolor(GREEN);
		circle(505+20+370,640,18);
					// 
		setcolor(11);
		circle(685+20+370,640,17);
		fillBox(685+20+370,640,1,11);
		setcolor(GREEN);
		circle(685+20+370,640,18);		
		gioitinh = 0;
	} 
	else{
		setcolor(BLUE);
		circle(685+20+370,640,17);
		fillBox(685+20+370,640,1,BLUE);
		setcolor(GREEN);
		circle(685+20+370,640,18);
					// 
		setcolor(11);
		circle(505+20+370,640,17);
		fillBox(505+20+370,640,1,11);
		setcolor(GREEN);
		circle(505+20+370,640,18);		
		gioitinh = 1;
	
	}
	outText(SO_CMND,430+370,300,6,BLACK,15,1);		
	outText(HO,430+370,410,6,BLACK,15,1);
	outText(TEN,430+370,520,6,BLACK,15,1);
	while(1){
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE,x,y);
			selected = checkSelectmouseNEWHK(x,y);
			switch(selected){
				case 6:{
					outText("LUU",1260-550,920,9,BLACK,BLUE,2);
					rectBox(1240-550,905,1390-550,960,1,BLUE);
					outText("THOAT",1550-550,920,9,WHITE,BLACK,2);					
					rectBox(1530-550,905,1670-550,960,1,BLACK);
					break;
				}
				case 7:{
					outText("LUU",1260-550,920,9,WHITE,GREEN,2);
					rectBox(1240-550,905,1390-550,960,1,GREEN);
					outText("THOAT",1550-550,920,9,BLACK,RED,2);					
					rectBox(1530-550,905,1670-550,960,1,RED);
					break;
				}
				default:{
					outText("LUU",1260-550,920,9,WHITE,GREEN,2);
					rectBox(1240-550,905,1390-550,960,1,GREEN);
					outText("THOAT",1550-550,920,9,WHITE,BLACK,2);					
					rectBox(1530-550,905,1670-550,960,1,BLACK);
					break;
				}
			}			
		}
		else if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			selected = checkSelectmouseNEWHK(x,y);
			switch(selected){
				case 2:{ // nhap ho
					outText("                                                                                    ",
					 430+370,360,6,RED,11,1);
					setcolor(BLUE);
					rectangle(420-2+370,390-2,760+2+370,450+2);					
					setcolor(GREEN);
					rectangle(420-2+370,280-2,760+2+370,340+2);
					rectangle(420-2+370,500-2,760+2+370,560+2);	
					nhapChuoi(HO,430+370,410,1,HO_MAX-1,BLACK,1);
					break;
				}
				case 3:{ //nhap ten
					outText("                                                                                    ",
					 430+370,470,6,RED,11,1);
					setcolor(BLUE);
					rectangle(420-2+370,500-2,760+2+370,560+2);						
					setcolor(GREEN);
					rectangle(420-2+370,280-2,760+2+370,340+2);	
					rectangle(420-2+370,390-2,760+2+370,450+2);
					nhapChuoi(TEN,430+370,520,1,TEN_MAX-1,BLACK,1);
					break;
				}
				case 4:{  // check box nam
					outText("                                                                                    ",
					 430+370,590,6,RED,11,1);
					setcolor(GREEN);
					rectangle(420-2+370,280-2,760+2+370,340+2);
					rectangle(420-2+370,390-2,760+2+370,450+2);
					rectangle(420-2+370,500-2,760+2+370,560+2);	
					setcolor(BLUE);
					circle(505+20+370,640,17);
					fillBox(505+20+370,640,1,BLUE);
					setcolor(GREEN);
					circle(505+20+370,640,18);
					// 
					setcolor(11);
					circle(685+20+370,640,17);
					fillBox(685+20+370,640,1,11);
					setcolor(GREEN);
					circle(685+20+370,640,18);		
					gioitinh = 0;
					break;				
				}
				case 5:{  // check box nu
					outText("                                                                                    ",
					 430+370,590,6,RED,11,1);
					setcolor(GREEN);
					rectangle(420-2+370,280-2,760+2+370,340+2);
					rectangle(420-2+370,390-2,760+2+370,450+2);
					rectangle(420-2+370,500-2,760+2+370,560+2);	
					setcolor(BLUE);
					circle(685+20+370,640,17);
					fillBox(685+20+370,640,1,BLUE);
					setcolor(GREEN);
					circle(685+20+370,640,18);
					// 
					setcolor(11);
					circle(505+20+370,640,17);
					fillBox(505+20+370,640,1,11);
					setcolor(GREEN);
					circle(505+20+370,640,18);		
					gioitinh = 1;	
					break;
				}
				case 6:{  // luu
					 if(strlen(HO) == 0){
						outText("Khong duoc de trong!", 430+370,360,6,RED,11,1);
						break;
					}else if(strlen(TEN) == 0){
						outText("Khong duoc de trong!", 430+370,470,6,RED,11,1);
						break;
					}else if(gioitinh == -1){
						outText("Chon gioi tinh!",430+370,590,6,RED,11,1);
						break;
					}
	
					
					bool check = confirm("Ban co chac muon luu","thong tin hanh khach?");					
					if(check){
						strcpy(hk->info.soCMND,SO_CMND);
						strcpy(hk->info.ho,HO);
						strcpy(hk->info.ten,TEN);
						if(gioitinh == 0) hk->info.gioiTinh = NAM;
						else hk->info.gioiTinh = NU;	
						alert("Da thay doi thong tin   ","hanh khach!                  ");			
						delay(1200);		
						clearviewport();						
					}
					return;
				}
				case 7:{ //thoat
					clearviewport();
					return;
				}									
				default:{
					setcolor(GREEN);
					rectangle(420-2+370,280-2,760+2+370,340+2);
					rectangle(420-2+370,390-2,760+2+370,450+2);
					rectangle(420-2+370,500-2,760+2+370,560+2);		
					break;
				}
			}
		}
		delay(100);
	}		
}
void newHK(DANHSACHHK& DS_HANHKHACH, HANHKHACH* DS_HKxuat){
	char SO_CMND[CMND_MAX] ="",HO[HO_MAX]="",TEN[TEN_MAX]="";
	int selected,x,y, gioitinh = -1;
	while(1){
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE,x,y);
			selected = checkSelectmouseNEWHK(x,y);
			switch(selected){
				case 6:{
					outText("THEM",1260-550,920,9,BLACK,BLUE,2);
					rectBox(1240-550,905,1390-550,960,1,BLUE);
					outText("THOAT",1550-550,920,9,WHITE,BLACK,2);					
					rectBox(1530-550,905,1670-550,960,1,BLACK);
					break;
				}
				case 7:{
					outText("THEM",1260-550,920,9,WHITE,GREEN,2);
					rectBox(1240-550,905,1390-550,960,1,GREEN);
					outText("THOAT",1550-550,920,9,BLACK,RED,2);					
					rectBox(1530-550,905,1670-550,960,1,RED);
					break;
				}
				default:{
					outText("THEM",1260-550,920,9,WHITE,GREEN,2);
					rectBox(1240-550,905,1390-550,960,1,GREEN);
					outText("THOAT",1550-550,920,9,WHITE,BLACK,2);					
					rectBox(1530-550,905,1670-550,960,1,BLACK);
					break;
				}
			}			
		}
		else if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			selected = checkSelectmouseNEWHK(x,y);
			switch(selected){
				case 1:{  // nhap SHMB
					outText("                                                                                    ",
					 430+370,250,6,RED,11,1);
					setcolor(BLUE);
					rectangle(420-2+370,280-2,760+2+370,340+2);					
					setcolor(GREEN);
					rectangle(420-2+370,390-2,760+2+370,450+2);
					rectangle(420-2+370,500-2,760+2+370,560+2);		
					nhapChuoi(SO_CMND,430+370,300,3,CMND_MAX-1,BLACK,1);				
					break;
				}
				case 2:{ // nhap ho
					outText("                                                                                    ",
					 430+370,360,6,RED,11,1);
					setcolor(BLUE);
					rectangle(420-2+370,390-2,760+2+370,450+2);					
					setcolor(GREEN);
					rectangle(420-2+370,280-2,760+2+370,340+2);
					rectangle(420-2+370,500-2,760+2+370,560+2);	
					nhapChuoi(HO,430+370,410,1,HO_MAX-1,BLACK,1);
					break;
				}
				case 3:{ //nhap ten
					outText("                                                                                    ",
					 430+370,470,6,RED,11,1);
					setcolor(BLUE);
					rectangle(420-2+370,500-2,760+2+370,560+2);						
					setcolor(GREEN);
					rectangle(420-2+370,280-2,760+2+370,340+2);	
					rectangle(420-2+370,390-2,760+2+370,450+2);
					nhapChuoi(TEN,430+370,520,1,TEN_MAX-1,BLACK,1);
					break;
				}
				case 4:{  // check box nam
					outText("                                                                                    ",
					 430+370,590,6,RED,11,1);
					setcolor(GREEN);
					rectangle(420-2+370,280-2,760+2+370,340+2);
					rectangle(420-2+370,390-2,760+2+370,450+2);
					rectangle(420-2+370,500-2,760+2+370,560+2);	
					setcolor(BLUE);
					circle(505+20+370,640,17);
					fillBox(505+20+370,640,1,BLUE);
					setcolor(GREEN);
					circle(505+20+370,640,18);
					// 
					setcolor(11);
					circle(685+20+370,640,17);
					fillBox(685+20+370,640,1,11);
					setcolor(GREEN);
					circle(685+20+370,640,18);		
					gioitinh = 0;
					break;				
				}
				case 5:{  // check box nu
					outText("                                                                                    ",
					 430+370,590,6,RED,11,1);
					setcolor(GREEN);
					rectangle(420-2+370,280-2,760+2+370,340+2);
					rectangle(420-2+370,390-2,760+2+370,450+2);
					rectangle(420-2+370,500-2,760+2+370,560+2);	
					setcolor(BLUE);
					circle(685+20+370,640,17);
					fillBox(685+20+370,640,1,BLUE);
					setcolor(GREEN);
					circle(685+20+370,640,18);
					// 
					setcolor(11);
					circle(505+20+370,640,17);
					fillBox(505+20+370,640,1,11);
					setcolor(GREEN);
					circle(505+20+370,640,18);		
					gioitinh = 1;	
					break;
				}
				case 6:{  // them
					if(strlen(SO_CMND) != 9){
						outText("So cmnd co 9 so!",  430+370,250,6,RED,11,1);
						break;
					}else if(checkHK(DS_HANHKHACH.ds,SO_CMND)){
						outText("Thong tin hanh khach da ton tai!",  430+370,250,6,RED,11,1);
						break;						
					}
					else if(strlen(HO) == 0){
						outText("Khong duoc de trong!", 430+370,360,6,RED,11,1);
						break;
					}else if(strlen(TEN) == 0){
						outText("Khong duoc de trong!", 430+370,470,6,RED,11,1);
						break;
					}else if(gioitinh == -1){
						outText("Chon gioi tinh!",430+370,590,6,RED,11,1);
						break;
					}
					HANHKHACH hk;
					strcpy(hk.soCMND,SO_CMND);
					strcpy(hk.ho,HO);
					strcpy(hk.ten,TEN);
					if(gioitinh == 0) hk.gioiTinh = NAM;
					else hk.gioiTinh = NU;
					themHK( hk, DS_HANHKHACH.ds); 
//					DS_HKxuat[DS_HANHKHACH.sl] = hk;		/// insert order
					InsertOrder_DSHK(DS_HKxuat,hk,DS_HANHKHACH.sl);
					DS_HANHKHACH.sl++;	

					alert("Da them thong tin","hanh khach!");
					delay(1500);
					clearviewport();
					return;
				}
				case 7:{ //thoat
					clearviewport();
					return;
				}									
				default:{
					setcolor(GREEN);
					rectangle(420-2+370,280-2,760+2+370,340+2);
					rectangle(420-2+370,390-2,760+2+370,450+2);
					rectangle(420-2+370,500-2,760+2+370,560+2);		
					break;
				}
			}
		}
		delay(100);
	}	
}
//================ktra HK==================
int checkHK(NODEHK t, char CMND[CMND_MAX]){
	if(t != NULL){
		NODEHK px = t;
		while(px != NULL)
		{
			if(strcmp(px->info.soCMND, CMND) == 0)
			 return 1;
			else if(strcmp(t->info.soCMND, CMND) > 0)
			 px=px->left;
			else px=px->right;
		}
	}
	return 0;
}
//=========================================

//================Tim HK===================
NODEHK SearchHK (NODEHK root, char* SOCMND)
{
   NODEHK p = root;
   while (p != NULL && strcmp(p->info.soCMND, SOCMND) != 0){
   		if(strcmp(p->info.soCMND,SOCMND)>0)
    	    p = p->left;
   		else
       	    p = p->right; 	
	}
	return(p); 		
}

//================Them HK==================
void themHK( HANHKHACH x, NODEHK &z){

	if(z == NULL){
		z = new nodehk;
		z->info= x;
		z->left = NULL; 
		z->right = NULL;
	}
	else if(strcmp(z->info.soCMND,x.soCMND) > 0) themHK(x,z->left);
	else if(strcmp(z->info.soCMND,x.soCMND) < 0) themHK(x,z->right);
	
}
//=========================================

//==========Tim NODE thay the==============
void findReplace(NODEHK &x, NODEHK &y){
	if(y->left != NULL){
		findReplace(x,y->left);
	}
	else{
		x->info=y->info;
		x=y;
		y=y->right;
	}
}
//=========================================

//=============Xoa HK======================
void deleteHK(NODEHK &t, char* soCMND){	     
	if(t != NULL){
		if (strcmp(t->info.soCMND,soCMND)== 0){
			NODEHK temp =t;
			if(t->left == NULL){
				t=t->right;
			}
			else if(t->right == NULL){
				t=t->left;
			}
			else{
				findReplace(temp, t->right);
			}
			delete temp;
		}
		else if(strcmp(t->info.soCMND,soCMND)>0)
			deleteHK(t->left,soCMND);
		else
			deleteHK(t->right,soCMND);
	}
}
void InsertOrder_DSHK (HANHKHACH* DS_HK, HANHKHACH hk, int slHK){
	int i, j;
	for (i=0; i <slHK && strcmp(DS_HK[i].ten, hk.ten) < 0 ; i++ );
	for ( j = slHK-1; j >=i  ; j--) 
	   DS_HK[j+1]= DS_HK[j];
	DS_HK[i]= hk;
}


void SortDSHK(HANHKHACH* DS_HK, int slHK){
  HANHKHACH min;   // hanh khach co ten the abc be nhat
  int i,j , min_Index;
  for (i=0; i< slHK-1; i++)
  {
    min = DS_HK[i];    
	min_Index = i;
    for (j=i+1; j<slHK; j++)
      	if ( strcmp(DS_HK[j].ten, min.ten) < 0 ){
     		min = DS_HK[j];
			min_Index=j;
      }
    // swap hk[i] vs hk[min_Index]
    min = DS_HK[min_Index] ;   
 	DS_HK[min_Index] = DS_HK[i];   
	DS_HK[i] = min;
  }
}

void deleteHKtemp(HANHKHACH* DS_HK,int& slHK, char* soCMND){
	int index = -1;
	for( int i =0; i< slHK; i++){
		if(strcmp(DS_HK[i].soCMND, soCMND ) == 0){
			index = i;
			break;
		}
	}
	if(index == -1 ) return;
	else{
		for(int j = index + 1; j< slHK; j++){
			DS_HK[j-1] = DS_HK[j];
		}
		slHK--;
	}
}
int findIndexHK(HANHKHACH* DS_HK, int& slHK, char* soCMND ){
	for(int i = 0;i<slHK; i++){
		if(strcmp(DS_HK[i].soCMND, soCMND ) == 0){
			return i;
		}
	}
	return -1;
}
