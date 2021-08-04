
int TimMayBay(DANHSACHMB &dsmb,char *S){
	int left =0, right = dsmb.sl-1;
	int j;
	while(left<=right){
		j=(left+right)/2;
		if(strcmp(dsmb.MAYBAY[j]->soHieuMB,S)==0)  return j;
    	if(strcmp(dsmb.MAYBAY[j]->soHieuMB,S)<0) left=j+1;
	  	else right=j-1;
	}
	return -1;
}
int ChenMayBay(DANHSACHMB &ds, MAYBAY &mb, int position){
	if(position < 0){
		printf("Vi tri them may bay khong hop le \n");
		return 0;
	}
	// neu position >= DSDS.n thi se them vao cuoi danh sach
	for(int i=ds.sl; i>position; i--){
		ds.MAYBAY[i] = ds.MAYBAY[i-1];
	}
	ds.MAYBAY[position] = new MAYBAY;
	*ds.MAYBAY[position] = mb;
	ds.sl++;
	return 1;
}
//
///*
// * Them MayBay khi nguoi dung nhap
// * Ham ThemMayBay se tu dong tim vi tri them thich hop
// * Bat loi: sohieu trung, soghe < 20
// */
int ThemMayBay(DANHSACHMB &ds, MAYBAY &mb){
	if(ds.sl > MB_MAX)
		return 0;
	else{
		// Duyet toan bo danh sach
		for(int i=0; i<ds.sl; i++)
			// Tim vi tri dau tien ma: mb.sohieu < MayBay[min_position].sohieu
			if(strcmp(mb.soHieuMB, ds.MAYBAY[i]->soHieuMB) < 0){
				ChenMayBay(ds, mb, i);
				// Insert xong thi return
				return 1;
			}
		//them vao cuoi danh sach
		ds.MAYBAY[ds.sl] = new MAYBAY;
		*ds.MAYBAY[ds.sl] = mb;
		ds.sl++;
		return 1;
	}
}
//// them vao cuoi ds sach may bay su dung khi doc file
int ThemCuoiDSMB(DANHSACHMB &ds, MAYBAY *mb){
	//danh sach day
	if(ds.sl == MAXMB_MAX) return 0;
	ds.MAYBAY[ds.sl++] = mb;
	return 1;
}

int XoaMayBay(DANHSACHMB &dsmb, char *sohieuMB){
	int i = TimMayBay(dsmb, sohieuMB);
	if(i<0) return 0;
	delete dsmb.MAYBAY[i];
    for (int j=i+1; j <dsmb.sl; j++){
       dsmb.MAYBAY[j-1]=dsmb.MAYBAY[j];    
	      	
	}
    dsmb.sl--;
    dsmb.MAYBAY[dsmb.sl] = NULL;  // them cai nay vi con tro MAYBAY* [sl-1] = MAYBAY* [sl]    nen khi xoa xong thi tren giao dien table maybay van xuat hien 2 lan trung lap (lq den giao dien)
    return 1;
}

void correctionMB(DANHSACHMB& DSMB,MAYBAY*& mb){
	char soHieuMB[SHMB_MAX] ="",loaiMB[LOAIMB_MAX]="",soCho[4]="";
	strcpy(soHieuMB,mb->soHieuMB);
	strcpy(loaiMB,mb->loaiMB);
	itoa(mb->soCho,soCho,10);
	outText(soHieuMB,770,270,6,BLACK,WHITE,1);				
	outText(loaiMB,770,380,6,BLACK,WHITE,1);				
	outText(soCho,770,490,6,BLACK,WHITE,1);	
	
	
	int selected,x,y;
	while(1){
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			selected = checkSelectmouseNEWCB(x,y);
			switch(selected){
				case 2:{ // nhap loai mb
					outText("                                                                                    ",
					 760,325,6,RED,11,1);
					setcolor(BLUE);
					rectangle(760-2,350+10-2,1100+2,410+10+2);	
					setcolor(GREEN);
					rectangle(760-2,240+10-2,1100+2,300+10+2);
					rectangle(760-2,460+10-2,1100+2,520+10+2);				
					nhapChuoi(loaiMB,770,380,4,20-1,BLACK,1);	
					break;
				}
				case 3:{ //nhap so cho
					if(isPlaneUsingForFlight(DS_CHUYENBAY,mb->soHieuMB)){		
						break;
					}				
					outText("                                                                                    ",
					 760,440,6,RED,11,1);									 
					setcolor(BLUE);	
					rectangle(760-2,460+10-2,1100+2,520+10+2);		
					setcolor(GREEN);
					rectangle(760-2,240+10-2,1100+2,300+10+2);
					rectangle(760-2,350+10-2,1100+2,410+10+2);	

					nhapChuoi(soCho,770,490,3,4-1,BLACK,1);	
					break;
				}
				case 9:{   // luu
					int SoGhe = atoi(soCho);

					if(strlen(loaiMB) == 0){
						outText("Khong duoc de trong!", 760,325,1,RED,11,1);
						break;
					}
					else if(SoGhe < 20){
						outText("So cho ngoi phai >=20!", 760,440,1,RED,11,1);
						break;
					}
					else if( mb->soCho == SoGhe && strcmp(mb->loaiMB,loaiMB) == 0  ){  // neu k co thay doi
						alert("KHONG CO ","THAY DOI!");
						delay(1000);
						clearviewport();
						return;
					}
					bool check = confirm("Ban co chac chac","muon luu khong?");
					if(check){
						strcpy(mb->soHieuMB,soHieuMB);
						strcpy(mb->loaiMB,loaiMB);
						mb->soCho = SoGhe;	
					}
					clearviewport();
					return;										
				}
				case 10:{   // xoa may bay chon
					if(mb->active == false){
						thongbao_s2("May bay nay dang duoc","su dung cho chuyen bay!");
						break;
					}
					bool check = confirm("Ban co chac muon", "xoa may bay nay?");
					if(check) {
						XoaMayBay(DS_MAYBAY, mb->soHieuMB);
						mb = NULL;
						clearviewport();
						return;
					}
					else {
						windowsBackgroundEditMB("     ~  HIEU CHINH MAY BAY  ~");
						outText(soHieuMB,770,270,6,BLACK,WHITE,1);				
						outText(loaiMB,770,380,6,BLACK,WHITE,1);				
						outText(soCho,770,490,6,BLACK,WHITE,1);	
					}
					break;
				}				
				case 11:{   // thoat		
					clearviewport();		
					return; 
					break;
				}
				default:{
					setcolor(GREEN);
					rectangle(760-2,240+10-2,1100+2,300+10+2);
					rectangle(760-2,350+10-2,1100+2,410+10+2);	
					rectangle(760-2,460+10-2,1100+2,520+10+2);		
					break;
				}
			}
		}
		delay(100);
	}	
}
void newMB(DANHSACHMB &DSMB){
	char soHieuMB[SHMB_MAX] ="",loaiMB[LOAIMB_MAX]="",soCho[4]="";
	int selected,x,y;
	while(1){
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			selected = checkSelectmouseNEWCB(x,y);
			switch(selected){
				case 1:{  // nhap SHMB
					outText("                                                                                    ",
					 760,220,6,RED,11,1);
					setcolor(BLUE);
					rectangle(760-2,240+10-2,1100+2,300+10+2);			
					setcolor(GREEN);
					rectangle(760-2,350+10-2,1100+2,410+10+2);	
					rectangle(760-2,460+10-2,1100+2,520+10+2);	
					nhapChuoi(soHieuMB,770,270,2,SHMB_MAX-1,BLACK,1);		
					break;
				}
				case 2:{ // nhap loai mb
					outText("                                                                                    ",
					 760,325,6,RED,11,1);				
					setcolor(BLUE);
					rectangle(760-2,350+10-2,1100+2,410+10+2);	
					setcolor(GREEN);
					rectangle(760-2,240+10-2,1100+2,300+10+2);
					rectangle(760-2,460+10-2,1100+2,520+10+2);				
					nhapChuoi(loaiMB,770,380,4,20-1,BLACK,1);	
					break;
				}
				case 3:{ //nhap so cho
					outText("                                                                                    ",
					 760,440,6,RED,11,1);				
					setcolor(BLUE);	
					rectangle(760-2,460+10-2,1100+2,520+10+2);		
					setcolor(GREEN);
					rectangle(760-2,240+10-2,1100+2,300+10+2);
					rectangle(760-2,350+10-2,1100+2,410+10+2);	

					nhapChuoi(soCho,770,490,3,4-1,BLACK,1);	
					break;
				}
				case 9:{   // them
					int SoGhe = atoi(soCho);

					if(strlen(soHieuMB) == 0){
						outText("Khong duoc de trong!", 760,220,1,RED,11,1);
						break;
					}else if(strlen(loaiMB) == 0){
						outText("Khong duoc de trong!", 760,325,1,RED,11,1);
						break;
					}
					else if( (TimMayBayTheoSoHieu(DSMB,soHieuMB) ) != NULL ){
						outText("So hieu may bay da ton tai!", 760,220,1,RED,11,1);
						break;
					}
					else if(SoGhe < 20){
						outText("So cho ngoi phai >=20!", 760,440,1,RED,11,1);
						break;
					}
					MAYBAY mb;
					strcpy(mb.soHieuMB,soHieuMB);
					strcpy(mb.loaiMB,loaiMB);
					mb.soCho = SoGhe;

					ThemMayBay(DSMB, mb);
					
					bool check = confirm("Da them May bay!","Ban co muon thoat?");
					if(check){
						clearviewport();
						return;	
					} 
					else {
						windowsBackgroundEditMB("         ~  THEM MAY BAY  ~");
						// xoa du lieu cu
						soHieuMB[0]='\0'; soCho[0]='\0'; loaiMB[0]='\0';
						outText("DDDDDDDDDDDDDD",770,270,9,WHITE,WHITE,1);
						outText("DDDDDDDDDDDDDD",770,380,9,WHITE,WHITE,1);
						outText("DDDDDDDDDDDDDD",770,490,9,WHITE,WHITE,1);					
					}										
					break;
				}
				case 10:{   // clear du lieu
					soCho[0]='\0'; soHieuMB[0]='\0'; loaiMB[0]='\0';
					outText("DDDDDDDDDDDDDD",770,270,9,WHITE,WHITE,1);
					outText("DDDDDDDDDDDDDD",770,380,9,WHITE,WHITE,1);
					outText("DDDDDDDDDDDDDD",770,490,9,WHITE,WHITE,1);
					break;
				}				
				case 11:{   // thoat		
					clearviewport();		
					return; 
					break;
				}
				default:{
					setcolor(GREEN);
					rectangle(760-2,240+10-2,1100+2,300+10+2);
					rectangle(760-2,350+10-2,1100+2,410+10+2);	
					rectangle(760-2,460+10-2,1100+2,520+10+2);		
					break;
				}
			}
		}
		delay(100);
	}
}

void CheckActiveAllPlane(DANHSACHCB& DSCB, DANHSACHMB& DSMB){      // sau khi check hoan tat nhung chuyen bay thi check active tat ca may bay
	for(int i=0; i<DSMB.sl;i++){
		DSMB.MAYBAY[i]->active = true;	
		for(NODECB p = DSCB.ds; p!=NULL ; p=p->next){
			if(p->info.trangThai != HOANTAT && p->info.trangThai != HUYCHUYEN  ){     
				if( strcmp(p->info.soHieuMB, DSMB.MAYBAY[i]->soHieuMB) == 0 ){
					DSMB.MAYBAY[i]->active = false;
					break;
				} 	
			}
		}	
	}
}
void findDSMB_SEARCH(DANHSACHMB& DS_MAYBAY, DANHSACHMB& DSMB_SEARCH, char* SHMB){
	for(int i = 0; i< DS_MAYBAY.sl; i++){
		if(strstr(DS_MAYBAY.MAYBAY[i]->soHieuMB, SHMB) != NULL){
			DSMB_SEARCH.MAYBAY[DSMB_SEARCH.sl] = DS_MAYBAY.MAYBAY[i];	
			DSMB_SEARCH.sl++;
			
		}
	}
}

MAYBAY* searchTableMB(DANHSACHMB& DSMB, int STTpage, int vitri){
	int vitriMB = (STTpage-1)*10 + vitri;    //vitri la vi tri mb tren table
	if(vitriMB > DSMB.sl) return NULL;
	return DSMB.MAYBAY[vitriMB-1];
}

void XuatMBSearchOnFirstRow(MAYBAY* MAYBAY){
	if(MAYBAY == NULL) return;	
	int stt = 1,y = 260;    
	char chuoiSTT[4], soCho[5];
	// vi tri node mb tren ds may bay = stt-1
	itoa(stt,chuoiSTT,10); itoa(MAYBAY->soCho,soCho,10);
	outText(chuoiSTT,505,y,9,GREEN,11,1);
	outText(MAYBAY->soHieuMB,574+10,y,9,GREEN,11,1);
	outText(MAYBAY->loaiMB,890-30,y,9,GREEN,11,1);
	outText(soCho,1040+200,y,9,GREEN,11,1);		
	outText("TRANG 1/1 ",1210,885,9,GREEN,11,1);
}

void xuatDSMB(DANHSACHMB& DSMB, int& STTpage){   // STTpage la trang hien tai tren table
	int max = pageMax(DSMB.sl);  // lay so trang	 
	char MAXpage[4], chuoiSTTpage[4] ;   // cho phan trang toi da 3 so 
	char pagination[] = "TRANG "; // text xd vi tri trang tren man hinh
	itoa(max,MAXpage,10 ); itoa(STTpage,chuoiSTTpage,10 );   // chuyen sang chuoi de noi chuoi
	strcat(pagination,chuoiSTTpage);
	strcat(pagination,"/");
	strcat(pagination,MAXpage);  
	outText(pagination ,1210,885,9,GREEN,11,1);  // outtext xd vitri
	
	int stt = STTpage*10 - 9 , y = 260;    // vi tri node MB dau tien theo trang, xuat stt node tren table va toa do xuat y 
	char chuoiSTT[4], soCho[5];

	// vi tri node mb tren ds may bay = stt-1
	for(int i = stt -1 ; i<= stt+8 ; i++ ){
		if(DSMB.MAYBAY[i] == NULL || i>=DSMB.sl) break;
		itoa(i+1,chuoiSTT,10); itoa(DSMB.MAYBAY[i]->soCho,soCho,10);
		outText(chuoiSTT,505,y,9,GREEN,11,1);
		outText(DSMB.MAYBAY[i]->soHieuMB,574+10,y,9,GREEN,11,1);
		outText(DSMB.MAYBAY[i]->loaiMB,890-30,y,9,GREEN,11,1);
		outText(soCho,1040+200,y,9,GREEN,11,1);		
		y+=60; 
	}
}
void xuatDSMB_SLTH(DANHSACHMB& DSMB, int STTpage){   
	int max = pageMax(DSMB.sl);  // lay so trang	 
	char MAXpage[4], chuoiSTTpage[4] ;   // cho phan trang toi da 3 so 
	char pagination[] = "TRANG "; // text xd vi tri trang tren man hinh
	itoa(max,MAXpage,10 ); itoa(STTpage,chuoiSTTpage,10 );   // chuyen sang chuoi de noi chuoi
	strcat(pagination,chuoiSTTpage);
	strcat(pagination,"/");
	strcat(pagination,MAXpage);  
	outText(pagination ,1210-400,885,9,GREEN,11,1);  // outtext xd vitri
	
	int stt = STTpage*10 - 9 , y = 260;    // vi tri node MB dau tien theo trang, xuat stt node tren table va toa do xuat y 
	char chuoiSTT[4], soLuotTH[6];

	// vi tri node mb tren ds may bay = stt-1
	for(int i = stt -1 ; i<= stt+8 ; i++ ){
		if(DSMB.MAYBAY[i] == NULL || i>=DSMB.sl) break;
		itoa(i+1,chuoiSTT,10); itoa(DSMB.MAYBAY[i]->so_luot_thuc_hien,soLuotTH,10);
		outText(chuoiSTT,615,y,9,GREEN,11,1);
		outText(DSMB.MAYBAY[i]->soHieuMB,700,y,9,GREEN,11,1);		
		outText(soLuotTH,1000,y,9,GREEN,11,1);
		y+=60; 
	}
}
// tim may bay da co trong danh sach
MAYBAY* TimMayBayTheoSoHieu(DANHSACHMB &dsmb, char *s){
	if(dsmb.sl == 0) return NULL;
	for(int i=0;i<dsmb.sl;i++){
		if(strcmp(dsmb.MAYBAY[i]->soHieuMB,s)==0) return dsmb.MAYBAY[i];
	}
	return NULL;
}
void Sort(DANHSACHMB &dsmb,int low, int high)
{ 
	MAYBAY *temp;
    int i=low;
    int j=high;
    int x = dsmb.MAYBAY[(low+high)/2]->so_luot_thuc_hien;
    do
    {
      while (dsmb.MAYBAY[i]->so_luot_thuc_hien > x)  i++;
      while (dsmb.MAYBAY[j]->so_luot_thuc_hien < x)  j--;
      if (i<=j)
    	{ 
			temp = dsmb.MAYBAY[i];
			dsmb.MAYBAY[i] = dsmb.MAYBAY[j];
			dsmb.MAYBAY[j] = temp;
			i++ ;  j--;
   		}
	}
	while (i<=j);
	if (low<j)
		Sort(dsmb,low,j);
	if (i<high)
		Sort(dsmb,i,high);
}

void Quick_Sort(DANHSACHMB& dsmb)
{
	if(dsmb.sl == 0){
		cout<<"Sap xep that bai";
		return;
	}
	Sort(dsmb,0,dsmb.sl-1);
	cout<<"Sap xep thanh cong";
}
//

void GetDSMB(DANHSACHMB& DS_MAYBAY, DANHSACHMB& DSMB){
	for(int i =0; i< DS_MAYBAY.sl; i++){
		DSMB.MAYBAY[i] = new MAYBAY;
		*DSMB.MAYBAY[i] =  *DS_MAYBAY.MAYBAY[i];
		DSMB.sl++;
	}
}

void DocMayBay(DANHSACHMB &dsmb) {
	int n;
	dsmb.sl = 0;
	fstream f("DANHSACHMB.txt", ios::in);
	if(!f.is_open()){
		cout<< "Loi mo file de doc "<<endl;
		return;
	}
	f >> n;
	for(int i = 0; i < n; i++){
		MAYBAY *mb = new MAYBAY;
		f.ignore();
		f.getline(mb->soHieuMB, SHMB_MAX);
		f.getline(mb->loaiMB, LOAIMB_MAX);
		f >> mb->soCho;
		f >> mb->so_luot_thuc_hien;
		f >> mb->active;
		ThemCuoiDSMB(dsmb, mb);
	}
	cout<< "Doc file MB thanh cong"<<endl;
	f.close();
}
void GhiMayBay(DANHSACHMB &dsmb){ 
	fstream f;
	f.open("DANHSACHMB.txt", ios::out);
	f << dsmb.sl << endl;
	if (dsmb.sl != 0) {
		for (int i = 0; i < dsmb.sl; i++) {
			f << dsmb.MAYBAY[i]->soHieuMB << endl;
			f << dsmb.MAYBAY[i]->loaiMB << endl;
			f << dsmb.MAYBAY[i]->soCho << endl;
			f << dsmb.MAYBAY[i]->so_luot_thuc_hien << endl;
			f << dsmb.MAYBAY[i]->active << endl;
		}
	}
	f.close();
}
