
//doc ghi file CHUYEN BAY
void writeFileCB(DANHSACHCB &DSCB) {
	fstream fileOutput("DANHSACHCB.txt", ios::out);
	if (fileOutput.fail())
	{
		cout << "Cannot open file at DANHSACHCB.txt " << endl;
		return;
	}	
	fileOutput << DSCB.sl <<"\n";
	for(NODECB p = DSCB.ds; p != NULL ; p=p->next){
		fileOutput << p->info.maCB<<'\n';
		fileOutput << p->info.sanBayDen <<'\n';
		fileOutput << p->info.soHieuMB<<'\n';
		fileOutput << p->info.thoiGian.gio<<" "<< p->info.thoiGian.phut <<" "<< p->info.thoiGian.ngay <<" "<<p->info.thoiGian.thang<< " "<<p->info.thoiGian.nam<<'\n';
		fileOutput << p->info.trangThai<<'\n';
		fileOutput << p->info.DSVE.sl<<'\n';
		fileOutput << p->info.DSVE.max<<'\n';
		for(int i=1;i<= p->info.DSVE.max ;i++){
			if(p->info.DSVE.ds[i] == "")continue;	
			else{
				fileOutput << i << " "<<p->info.DSVE.ds[i]<<'\n';
			}
		}
	}
	fileOutput.close();
	
}

void readFileCB(DANHSACHCB &DSCB, DANHSACHMB &DSMB){
	fstream fileInput("DANHSACHCB.txt", ios::in);
	if (fileInput.fail())
	{
		cout << "Cannot open file at DANHSACHCB.txt " << endl;
		return;
	}	
	fileInput >> DSCB.sl;

	for(int i = 1; i<= DSCB.sl ; i++ ){
		NODECB p = new nodecb;    
		p->next = NULL;    
		fileInput >> p->info.maCB; 
//		fileInput >> p->info.sanBayDen;  
		fileInput.ignore();
		fileInput.getline(p->info.sanBayDen, SBD_MAX);
		fileInput >> p->info.soHieuMB; 
		fileInput >>p->info.thoiGian.gio>>p->info.thoiGian.phut>>p->info.thoiGian.ngay>>p->info.thoiGian.thang>>p->info.thoiGian.nam;
		int trangthai;   fileInput >>trangthai;
		switch(trangthai){
			case 0: {
				p->info.trangThai = HUYCHUYEN;
				break;
			}
			case 1: {
				p->info.trangThai = CONVE;
				break;
			}		
			case 2: {
				p->info.trangThai = HETVE;
				break;
			}		
			case 3: {
				p->info.trangThai = HOANTAT;
				break;
			}					
		} 
		if(p->info.trangThai != HOANTAT && p->info.trangThai != HUYCHUYEN  ){     // check hoan tat nhung chuyen bay moi khi chay chuong trinh
			if(checkTimeHoanTatCB(p->info.thoiGian)){    
				p->info.trangThai = HOANTAT;	
				MAYBAY* mb = TimMayBayTheoSoHieu(DSMB,p->info.soHieuMB);
				mb->so_luot_thuc_hien ++;   // neu chuyen bay hoan tat thi so luot thuc hien cua may bay su dung chuyen bay do tang len 1
			} 	
		}
		
		fileInput >> p->info.DSVE.sl; 
		fileInput >> p->info.DSVE.max; 
		// index bat dau tu 1-> max. index la vi tri cho ngoi, noi dung chuoi tai vi tri index la chuoi string cmnd
		p->info.DSVE.ds = new string[p->info.DSVE.max+1];  

		// khoi tao ds ve co so cmnd la rong voi  tat ca chi so index
		for(int j = 1; j<= p->info.DSVE.max; j++){
			p->info.DSVE.ds[j] = "";   

		}
		
		int vitri; string soCMND;
		for(int j=1; j<= p->info.DSVE.sl; j++){
			fileInput >> vitri;
			fileInput >> soCMND;
			p->info.DSVE.ds[vitri] = soCMND; // index la vi tri, ndung la soCMND
			
		}		
		// them ds chuyenbay vao ds	
		if(DSCB.ds == NULL) DSCB.ds = p;
		else{
			NODECB Last = DSCB.ds;
			for( ;Last->next!=NULL;Last = Last->next);
			Last->next = p;
		}
	}
	CheckActiveAllPlane(DSCB,DSMB);
	fileInput.close();
}

// ===================void 
int DeleteCB(DANHSACHCB& DS_CHUYENBAY, char * maCB)
{
	NODECB p;
	if(DS_CHUYENBAY.ds == NULL) return 0;
	if( strcmp(DS_CHUYENBAY.ds->info.maCB,maCB) == 0)
	{
		p = DS_CHUYENBAY.ds;
		DS_CHUYENBAY.ds = p->next;
		delete p;
		DS_CHUYENBAY.sl--;
		return 1;
	}
	for(p = DS_CHUYENBAY.ds; p->next != NULL ; p=p->next ){
		if( strcmp(p->next->info.maCB,maCB) == 0 ){
			break;
		}
	}
	if(p->next!= NULL )
	{
		NODECB q = p->next;
		p->next = q->next;
		delete q;
		DS_CHUYENBAY.sl--;
		return 1;
	}
	return 0;
	
}

void insertCB(DANHSACHCB& DS_CHUYENBAY, CHUYENBAY x)
{
	NODECB p = new nodecb;   
	p->info = x;
	p->next = NULL;
	if(DS_CHUYENBAY.ds == NULL) DS_CHUYENBAY.ds = p;
	else
	{
		NODECB Last = DS_CHUYENBAY.ds;
		for( ;Last->next!=NULL;Last = Last->next);
		Last->next = p;
	}
	
	MAYBAY* mb = TimMayBayTheoSoHieu(DS_MAYBAY,p->info.soHieuMB);
	mb->active = false;   // CB dang su dung may bay nay thi active = fasle nghia la khong the xoa may bay khi chuyen bay nay chua hoan tat
	p->info.DSVE.max = mb->soCho; // goi ham check sl ve de dat o day
	p->info.DSVE.ds = new string[p->info.DSVE.max+1];  
	// khoi tao ds ve co so cmnd la rong voi  tat ca chi so index
	for(int j = 1; j<= p->info.DSVE.max; j++){
		p->info.DSVE.ds[j] = "";
	}	
	
	DS_CHUYENBAY.sl++;
}
void SEARCH_DSCB_MCB(DANHSACHCB& DSCB_SEARCH,char *MCB_SEARCH){
	NODECB p = DS_CHUYENBAY.ds;
	for(;p!= NULL; p=p->next){
		if(strstr( p->info.maCB,MCB_SEARCH) != NULL){
			insertCB(DSCB_SEARCH, p->info);
		}
	}
}
void SEARCH_DSCB_SBD(DANHSACHCB& DSCB_SEARCH,char *SBD_SEARCH){
	NODECB p = DS_CHUYENBAY.ds;
	for(;p!= NULL; p=p->next){
		if( p->info.trangThai == CONVE &&  strstr( p->info.sanBayDen,SBD_SEARCH) != NULL){
			insertCB(DSCB_SEARCH, p->info);
		}
	}
}

void AddDSCB_CONVE(DANHSACHCB& DS_CHUYENBAY, DANHSACHCB& DSCB_CONVE){
	for(NODECB p = DS_CHUYENBAY.ds; p!= NULL; p=p->next){
		if(p->info.trangThai == CONVE || p->info.trangThai == HETVE ){
			insertCB(DSCB_CONVE, p->info);
		}
	}
}
NODECB searchCB(NODECB ds, char maCB[]){
	NODECB p;
	for(p=ds ;p != NULL ; p=p->next)
	{
		if( strcmp(p->info.maCB,maCB)  == 0) return p;
	}
	return NULL;
}

void clearDSCB(DANHSACHCB& DSCB){
	if(DSCB.ds == NULL) return;
	NODECB p;
	while(DSCB.ds != NULL){
		p = DSCB.ds;
		DSCB.ds = DSCB.ds->next;
		delete p;
		DSCB.sl--;		
	}
}

bool isCustomerBookedTK(DANHSACHCB& DS_CHUYENBAY, char* SOCMND){
	for(NODECB p = DS_CHUYENBAY.ds; p!= NULL; p=p->next){
		if(p->info.trangThai != HUYCHUYEN && p->info.trangThai != HOANTAT ){
			for(int i = 1; i<= p->info.DSVE.max;i++){
				if(strcmp(SOCMND, p->info.DSVE.ds[i].c_str() ) == 0)   return true;
			}
		}
	}
	return false;
}
bool isPlaneUsingForFlight(DANHSACHCB & DSCB, char * SHMB ){
	for(NODECB p = DSCB.ds; p!= NULL; p=p->next){
		if(p->info.trangThai == HOANTAT || p->info.trangThai == HUYCHUYEN) continue;
		else if( strcmp(p->info.soHieuMB, SHMB) == 0 ){
			return true;				
		}
	}
	return false;	
}

bool isPlaneUsingForFlight_ignore(DANHSACHCB & DSCB,char* MACB, char * SHMB ){
	for(NODECB p = DSCB.ds; p!= NULL; p=p->next){
		if(p->info.trangThai == HOANTAT || p->info.trangThai == HUYCHUYEN) continue;
		else if(strcmp(p->info.maCB, MACB) != 0 && strcmp(p->info.soHieuMB, SHMB) == 0 ){
			return true;				
		}
	}
	return false;	
}

bool isTimePlaneUsing(DANHSACHCB& DSCB, char* SHMB, THOIGIAN tg){  // check xem thu vao thhoi diem nay thi may bay nay co dang duoc su dung hay khong ? sd cho new
	for(NODECB p = DSCB.ds; p!= NULL; p=p->next){
		if(p->info.trangThai == HOANTAT || p->info.trangThai == HUYCHUYEN) continue;
		else if( strcmp(p->info.soHieuMB, SHMB) == 0 ){
			if( CompareDate(p->info.thoiGian,tg) ) {
				return true;
			}				
		}

	}
	return false;
}
bool isTimePlaneUsing_ignoreFLight(DANHSACHCB& DSCB, char* MACB, char* SHMB, THOIGIAN tg){  // check xem thu vao thhoi diem nay thi may bay nay co dang duoc su dung hay khong ? sd cho correction
	for(NODECB p = DSCB.ds; p!= NULL; p=p->next){
		if(p->info.trangThai == HOANTAT || p->info.trangThai == HUYCHUYEN) continue;
		else if( strcmp(p->info.soHieuMB, SHMB) == 0 && strcmp(p->info.maCB, MACB ) != 0  ){
			if( CompareDate(p->info.thoiGian,tg) ) {
				return true;
			}				
		}

	}
	return false;
}

bool isMovingAtThesameTime(DANHSACHCB& DSCB, char* soCMND, THOIGIAN tg){
	for(NODECB p = DSCB.ds; p!= NULL; p=p->next){
		if(p->info.trangThai != HOANTAT && p->info.trangThai != HUYCHUYEN && CompareDateTime(p->info.thoiGian, tg)){		
			for(int i=1;i<=p->info.DSVE.max;i++){
				if( soCMND == p->info.DSVE.ds[i]) {
					return true;
				}				
			}	
		}

	}
	return false; 	
}

void formatDate(char thoigian[], char gio[], char phut[], char ngay[], char thang[], char nam[] ){
	thoigian[0]='\0';
	if(strlen(gio) == 1){
		thoigian[0] = '0';
		thoigian[1] = '\0';
	}
	strcat(thoigian,gio);
	thoigian[2] = ':';
	thoigian[3] = '\0';
	if(strlen(phut) == 1){
		thoigian[3] = '0';
		thoigian[4] = '\0';
	}
	strcat(thoigian,phut);
	thoigian[5] =' ';
	thoigian[6] = '\0';
	if(strlen(ngay) == 1){
		thoigian[6] = '0';
		thoigian[7] = '\0';
	}
	strcat(thoigian,ngay);
	thoigian[8]='/';
	thoigian[9] = '\0';
	if(strlen(thang) == 1){
		thoigian[9] = '0';
		thoigian[10] = '\0';
	}
	strcat(thoigian,thang);
	thoigian[11] = '/';
	thoigian[12] = '\0';
	strcat(thoigian,nam);
}
void formatTime(char thoigian[], char ngay[], char thang[], char nam[] ){
	thoigian[0]='\0';
	if(strlen(ngay) == 1){
		thoigian[0] = '0';
		thoigian[1] = '\0';
	}
	strcat(thoigian,ngay);
	thoigian[2]='/';
	thoigian[3] = '\0';
	if(strlen(thang) == 1){
		thoigian[3] = '0';
		thoigian[4] = '\0';
	}
	strcat(thoigian,thang);
	thoigian[5] = '/';
	thoigian[6] = '\0';
	strcat(thoigian,nam);
}
void xuatFindDSCB(DANHSACHCB& DSCB, int& STTpage){
	int max = pageMax(DSCB.sl);  // lay so trang	 
	char MAXpage[4], chuoiSTTpage[4] ;   // cho phan trang toi da 3 so 
	char pagination[] = "TRANG "; // text xd vi tri trang tren man hinh
	itoa(max,MAXpage,10 ); itoa(STTpage,chuoiSTTpage,10 );   // chuyen sang chuoi de noi chuoi
	strcat(pagination,chuoiSTTpage);
	strcat(pagination,"/");
	strcat(pagination,MAXpage);  
	outText(pagination ,1210,885,9,GREEN,11,1);  // outtext xd vitri
	
	int stt = STTpage*10 - 9 , y = 260;    // vi tri node dau tien theo trang, xuat stt node tren table va toa do xuat y 
	char chuoiSTT[4], soVeTrong[4]; // 
	char thoigian[18],gio[3],phut[3],ngay[3],thang[3],nam[5];  // 11:12 03/04/2000    page 1: 1-10   2: 11-20 3: 21-30
	
	NODECB ds = DSCB.ds;     // xuat 10 node bat dau tu node ds
	for(int i = 1; i < stt; i++){    // tim  vi tri node ds theo trang
		ds = ds->next;
	}

    int dem = 1;
	for( ; ds!=NULL ; ds=ds->next){
		int vetrong = ds->info.DSVE.max-  ds->info.DSVE.sl;
		itoa(vetrong, soVeTrong,10);
		itoa(ds->info.thoiGian.gio, gio,10);
		itoa(ds->info.thoiGian.phut, phut,10);
		itoa(ds->info.thoiGian.ngay, ngay,10);
		itoa(ds->info.thoiGian.thang, thang,10);
		itoa(ds->info.thoiGian.nam, nam,10);		
		formatDate(thoigian,gio,phut,ngay,thang,nam);		
		itoa(stt,chuoiSTT,10);
		
		outText(chuoiSTT,370,y,9,GREEN,11,1);
		outText(ds->info.maCB,465,y,9,GREEN,11,1);
		outText(soVeTrong,640,y,9,GREEN,11,1);
		outText(thoigian,765,y,9,GREEN,11,1);
		outText(ds->info.sanBayDen,1020,y,9,GREEN,11,1);
		switch(ds->info.trangThai){
			case CONVE:{
				outText("Con ve",1290,y,9,GREEN,11,1);
				break;
			}
			case HETVE:{
				outText("Het ve",1290,y,9,GREEN,11,1);	
				break;
			}
		}		
		y+=60; stt++; dem++;
		if(dem >10) break;  // neu xuat du 10 node dung hoac Den cuoi ds NULL thi dung
	}
}
                                                         
void xuatDSCB(DANHSACHCB& DSCB, int& STTpage){
	int max = pageMax(DSCB.sl);  // lay so trang	 
	char MAXpage[4], chuoiSTTpage[4] ;   // cho phan trang toi da 3 so 
	char pagination[] = "TRANG "; // text xd vi tri trang tren man hinh
	itoa(max,MAXpage,10 ); itoa(STTpage,chuoiSTTpage,10 );   // chuyen sang chuoi de noi chuoi
	strcat(pagination,chuoiSTTpage);
	strcat(pagination,"/");
	strcat(pagination,MAXpage);  
	outText(pagination ,1210,885,9,GREEN,11,1);  // outtext xd vitri
	
	int stt = STTpage*10 - 9 , y = 260;    // vi tri node dau tien theo trang, xuat stt node tren table va toa do xuat y 
	char chuoiSTT[4]; // 
	char thoigian[18],gio[3],phut[3],ngay[3],thang[3],nam[5];  // 11:12 03/04/2000    page 1: 1-10   2: 11-20 3: 21-30
	
	NODECB ds = DSCB.ds;     // xuat 10 node bat dau tu node ds
	for(int i = 1; i < stt; i++){    // tim  vi tri node ds theo trang
		ds = ds->next;
	}

    int dem = 1;
	for( ; ds!=NULL ; ds=ds->next){
		
		itoa(ds->info.thoiGian.gio, gio,10);
		itoa(ds->info.thoiGian.phut, phut,10);
		itoa(ds->info.thoiGian.ngay, ngay,10);
		itoa(ds->info.thoiGian.thang, thang,10);
		itoa(ds->info.thoiGian.nam, nam,10);		
		formatDate(thoigian,gio,phut,ngay,thang,nam);
			
		itoa(stt,chuoiSTT,10);
		outText(chuoiSTT,505,y,9,GREEN,11,1);
		outText(ds->info.maCB,574,y,9,GREEN,11,1);
		outText(ds->info.sanBayDen,715,y,9,GREEN,11,1);
		outText(ds->info.soHieuMB,890,y,9,GREEN,11,1);
		outText(thoigian,1040,y,9,GREEN,11,1);
		switch(ds->info.trangThai){
			case HUYCHUYEN:{
				outText("Huy chuyen",1265,y,9,GREEN,11,1);
				break;
			}
			case CONVE:{
				outText("Con ve",1290,y,9,GREEN,11,1);
				break;
			}
			case HETVE:{
				outText("Het ve",1290,y,9,GREEN,11,1);	
				break;
			}
			case HOANTAT:{
				outText("Hoan tat",1280,y,9,GREEN,11,1);
				break;
			}
		}		
		y+=60; stt++; dem++;
		if(dem >10) break;  // neu xuat du 10 node dung hoac Den cuoi ds NULL thi dung
	}
}
void findDSCB(DANHSACHCB& DSCB_ROOT, DANHSACHCB& DSCB,THOIGIAN tg,char *sanBayDen){
	for(NODECB p = DSCB_ROOT.ds; p!= NULL; p=p->next){
		if(CompareDate(p->info.thoiGian, tg) && strstr(p->info.sanBayDen, sanBayDen) != NULL && p->info.trangThai != HOANTAT  && p->info.trangThai != HUYCHUYEN  ){
			insertCB(DSCB, p->info);
		}
	}
}
void cancelCB(DANHSACHCB &DSCB){
	char macb[MACB_MAX];
	cout<<"Nhap ma chuyen may can huy:";cin>>macb;
	NODECB p = searchCB(DSCB.ds,macb);
	if(p == NULL) cout<<"Khong co chuyen bay nay!"<<endl;
	else {
		p->info.trangThai = HUYCHUYEN;
		cout<<"DA HUY CHUYEN BAY"<<endl;
	}
}

void newCB(DANHSACHCB &DSCB){
	CHUYENBAY cb;
	char thoigian[18] ="",gio[3] ="",phut[3]="",ngay[3]="",thang[3]="",nam[5]="",maCB[MACB_MAX] ="",sanBayDen[SBD_MAX]="",soHieuMB[SHMB_MAX]="";
	int selected,x,y;
	while(1){
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			selected = checkSelectmouseNEWCB(x,y);
			switch(selected){
				case 1:{  // nhap ma cb
					outText("                                                                                    ",
					 760,220,6,RED,11,1);
					setcolor(BLUE);
					rectangle(760-2,240+10-2,1100+2,300+10+2);			
					setcolor(GREEN);
					rectangle(760-2,350+10-2,1100+2,410+10+2);	
					rectangle(760-2,460+10-2,1100+2,520+10+2);	
					rectangle(760-2,570+10-2,800+2,630+10+2);
					rectangle(820-2,570+10-2,860+2,630+10+2);
					rectangle(900-2,570+10-2,940+2,630+10+2);
					rectangle(960-2,570+10-2,1000+2,630+10+2);
					rectangle(1020-2,570+10-2,1100+2,630+10+2);	
					nhapChuoi(maCB,770,270,2,MACB_MAX-1,BLACK,1);		
					break;
				}
				case 2:{ // nhap sbd
					outText("                                                                                    ",
					 760,325,6,RED,11,1);
					setcolor(BLUE);
					rectangle(760-2,350+10-2,1100+2,410+10+2);	
					setcolor(GREEN);
					rectangle(760-2,240+10-2,1100+2,300+10+2);
					rectangle(760-2,460+10-2,1100+2,520+10+2);	
					rectangle(760-2,570+10-2,800+2,630+10+2);
					rectangle(820-2,570+10-2,860+2,630+10+2);
					rectangle(900-2,570+10-2,940+2,630+10+2);
					rectangle(960-2,570+10-2,1000+2,630+10+2);
					rectangle(1020-2,570+10-2,1100+2,630+10+2);				
					nhapChuoi(sanBayDen,770,380,1,SBD_MAX-1,BLACK,1);	
					break;
				}
				case 3:{ //nhap shmb
					outText("                                                                                    ",
					 760,440,6,RED,11,1);
					setcolor(BLUE);	
					rectangle(760-2,460+10-2,1100+2,520+10+2);		
					setcolor(GREEN);
					rectangle(760-2,240+10-2,1100+2,300+10+2);
					rectangle(760-2,350+10-2,1100+2,410+10+2);	
					rectangle(760-2,570+10-2,800+2,630+10+2);
					rectangle(820-2,570+10-2,860+2,630+10+2);
					rectangle(900-2,570+10-2,940+2,630+10+2);
					rectangle(960-2,570+10-2,1000+2,630+10+2);
					rectangle(1020-2,570+10-2,1100+2,630+10+2);	
					nhapChuoi(soHieuMB,770,490,2,SHMB_MAX-1,BLACK,1);	
					break;
				}
				case 4:{ //gio
					outText("                                                                                    ",
					 760,550,6,RED,11,1);
					setcolor(BLUE);					
					rectangle(760-2,570+10-2,800+2,630+10+2);	
					setcolor(GREEN);
					rectangle(760-2,240+10-2,1100+2,300+10+2);
					rectangle(760-2,350+10-2,1100+2,410+10+2);	
					rectangle(760-2,460+10-2,1100+2,520+10+2);	
					rectangle(820-2,570+10-2,860+2,630+10+2);
					rectangle(900-2,570+10-2,940+2,630+10+2);
					rectangle(960-2,570+10-2,1000+2,630+10+2);
					rectangle(1020-2,570+10-2,1100+2,630+10+2);	
					nhapChuoi(gio,770-5,600,3,2,BLACK,1);
					break;
				}
				case 5:{ //phut
					outText("                                                                                    ",
					 760,550,6,RED,11,1);
					setcolor(BLUE);					
					rectangle(820-2,570+10-2,860+2,630+10+2);	
					setcolor(GREEN);
					rectangle(760-2,240+10-2,1100+2,300+10+2);
					rectangle(760-2,350+10-2,1100+2,410+10+2);	
					rectangle(760-2,460+10-2,1100+2,520+10+2);	
					rectangle(760-2,570+10-2,800+2,630+10+2);
					rectangle(900-2,570+10-2,940+2,630+10+2);
					rectangle(960-2,570+10-2,1000+2,630+10+2);
					rectangle(1020-2,570+10-2,1100+2,630+10+2);	
					nhapChuoi(phut,830-5,600,3,2,BLACK,1);
					break;
				}
				case 6:{ //ngay
					outText("                                                                                    ",
					 760,550,6,RED,11,1);
					setcolor(BLUE);				
					rectangle(900-2,570+10-2,940+2,630+10+2);	
					setcolor(GREEN);
					rectangle(760-2,240+10-2,1100+2,300+10+2);
					rectangle(760-2,350+10-2,1100+2,410+10+2);	
					rectangle(760-2,460+10-2,1100+2,520+10+2);	
					rectangle(760-2,570+10-2,800+2,630+10+2);
					rectangle(820-2,570+10-2,860+2,630+10+2);
					rectangle(960-2,570+10-2,1000+2,630+10+2);
					rectangle(1020-2,570+10-2,1100+2,630+10+2);	
					nhapChuoi(ngay,910-5,600,3,2,BLACK,1);		
					break;
				}
				case 7:{ //thang
					outText("                                                                                    ",
					 760,550,6,RED,11,1);
					setcolor(BLUE);				
					rectangle(960-2,570+10-2,1000+2,630+10+2);		
					setcolor(GREEN);
					rectangle(760-2,240+10-2,1100+2,300+10+2);
					rectangle(760-2,350+10-2,1100+2,410+10+2);	
					rectangle(760-2,460+10-2,1100+2,520+10+2);	
					rectangle(760-2,570+10-2,800+2,630+10+2);
					rectangle(820-2,570+10-2,860+2,630+10+2);
					rectangle(900-2,570+10-2,940+2,630+10+2);
					rectangle(1020-2,570+10-2,1100+2,630+10+2);		
					nhapChuoi(thang,970-5,600,3,2,BLACK,1);		
					break;
				}
				case 8:{ //nam
					outText("                                                                                    ",
					 760,550,6,RED,11,1);
					setcolor(BLUE);				
					rectangle(1020-2,570+10-2,1100+2,630+10+2);		
					setcolor(GREEN);
					rectangle(760-2,240+10-2,1100+2,300+10+2);
					rectangle(760-2,350+10-2,1100+2,410+10+2);	
					rectangle(760-2,460+10-2,1100+2,520+10+2);	
					rectangle(760-2,570+10-2,800+2,630+10+2);
					rectangle(820-2,570+10-2,860+2,630+10+2);
					rectangle(900-2,570+10-2,940+2,630+10+2);
					rectangle(960-2,570+10-2,1000+2,630+10+2);
					nhapChuoi(nam,1030,600,3,4,BLACK,1);
					break;
				}
				case 9:{   // them
					THOIGIAN tg;
					tg.gio = atoi(gio);
					tg.phut = atoi(phut);
					tg.ngay = atoi(ngay);
					tg.thang = atoi(thang);
					tg.nam = atoi(nam);
					if(strlen(maCB) == 0){
						outText("Khong duoc de trong!", 760,220,1,RED,11,1);
						break;
					}else if(strlen(sanBayDen) == 0){
						outText("Khong duoc de trong!", 760,325,1,RED,11,1);
						break;
					}
					else if(searchCB(DS_CHUYENBAY.ds,maCB) != NULL){
						outText("Ma CB da ton tai!    ", 760,220,1,RED,11,1);
						break;
					}
					else if( (TimMayBayTheoSoHieu(DS_MAYBAY,soHieuMB) ) == NULL ){
						outText("So hieu may bay khong ton tai!", 760,440,1,RED,11,1);
						break;
					}
					else if(!checkDateTimeValue(tg)){
						outText("Thoi gian khong hop le!", 760,550,1,RED,11,1);
						break;
					}
					
					strcpy(cb.maCB,maCB);
					strcpy(cb.sanBayDen,sanBayDen);
					strcpy(cb.soHieuMB,soHieuMB);
					cb.thoiGian = tg;
					cb.trangThai = CONVE;
					//  check xem thu vao thhoi diem nay thi may bay nay co dang duoc su dung hay khong ?
					if(isTimePlaneUsing(DSCB,soHieuMB,tg)){
						outText("Thoi diem nay, may bay dang duoc su dung!", 760,550,1,RED,11,1);
						break;
					}
					insertCB(DSCB, cb);
					
					bool check = confirm("Da them chuyen bay!","Ban co muon thoat?");
					if(check){
						clearviewport();
						return;
					} 
					else {
						clearviewport();
						windowsBackgroundEditCB(" ~  THEM CHUYEN BAY MOI  ~  ");
						// xoa du lieu cu
						gio[0]='\0'; phut[0]='\0'; ngay[0]='\0'; thang[0]='\0'; nam[0]='\0'; sanBayDen[0]='\0'; maCB[0]='\0'; soHieuMB[0]='\0';
						outText("DDDDDDDDDDDDDD",770,270,9,WHITE,WHITE,1);
						outText("DDDDDDDDDDDDDD",770,380,9,WHITE,WHITE,1);
						outText("DDDDDDDDDDDDDD",770,490,9,WHITE,WHITE,1);
						outText("Dd",765,600,9,WHITE,WHITE,1);
						outText("Dd",825,600,9,WHITE,WHITE,1);
						outText("Dd",905,600,9,WHITE,WHITE,1);
						outText("Dd",965,600,9,WHITE,WHITE,1);
						outText("DDD",1030,600,9,WHITE,WHITE,1);
						
					}										
					break;
				}
				case 10:{   // clear du lieu
					gio[0]='\0'; phut[0]='\0'; ngay[0]='\0'; thang[0]='\0'; nam[0]='\0'; sanBayDen[0]='\0'; maCB[0]='\0'; soHieuMB[0]='\0';
					outText("DDDDDDDDDDDDDD",770,270,9,WHITE,WHITE,1);
					outText("DDDDDDDDDDDDDD",770,380,9,WHITE,WHITE,1);
					outText("DDDDDDDDDDDDDD",770,490,9,WHITE,WHITE,1);
					outText("Dd",765,600,9,WHITE,WHITE,1);
					outText("Dd",825,600,9,WHITE,WHITE,1);
					outText("Dd",905,600,9,WHITE,WHITE,1);
					outText("Dd",965,600,9,WHITE,WHITE,1);
					outText("DDD",1030,600,9,WHITE,WHITE,1);

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
					rectangle(760-2,570+10-2,800+2,630+10+2);
					rectangle(820-2,570+10-2,860+2,630+10+2);
					rectangle(900-2,570+10-2,940+2,630+10+2);
					rectangle(960-2,570+10-2,1000+2,630+10+2);
					rectangle(1020-2,570+10-2,1100+2,630+10+2);		
					break;
				}
			}
		}
		delay(100);
	}
}

void formatChuoi(char s[]){
	if(strlen(s) == 1){
		s[1] = s[0];
		s[0] = '0';
		s[2] = '\0';
	}
}

void correctionCB(DANHSACHCB &DSCB, NODECB &p){
	char thoigian[18] ="",gio[3] ="",phut[3]="",ngay[3]="",thang[3]="",nam[5]="", maCB[MACB_MAX] = "" , sanBayDen[SBD_MAX]=  "", soHieuMB[SHMB_MAX]= "";
	strcpy(maCB, p->info.maCB );
	strcpy(sanBayDen, p->info.sanBayDen);
	strcpy(soHieuMB, p->info.soHieuMB );

	itoa(p->info.thoiGian.gio,gio,10); formatChuoi(gio);
	itoa(p->info.thoiGian.phut,phut,10); formatChuoi(phut);
	itoa(p->info.thoiGian.ngay,ngay,10); formatChuoi(ngay);
	itoa(p->info.thoiGian.thang,thang,10); formatChuoi(thang);
	itoa(p->info.thoiGian.nam,nam,10);
	outText(maCB,770,270,9,BLACK,WHITE,1);
	outText(sanBayDen,770,380,9,BLACK,WHITE,1);
	outText(soHieuMB,770,490,9,BLACK,WHITE,1);
	outText(gio,770-5,600,9,BLACK,WHITE,1);
	outText(phut,830-5,600,9,BLACK,WHITE,1);
	outText(ngay,910-5,600,9,BLACK,WHITE,1);
	outText(thang,970-5,600,9,BLACK,WHITE,1);
	outText(nam,1030,600,9,BLACK,WHITE,1);
	int selected,x,y;
	
	while(1){
	
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			selected = checkSelectmouseNEWCB(x,y);
			switch(selected){
				case 2:{ // hieu chinh sbd
					outText("                                                                                    ",
					 760,325,6,RED,11,1);
					setcolor(BLUE);
					rectangle(760-2,350+10-2,1100+2,410+10+2);	
					setcolor(GREEN);
					rectangle(760-2,240+10-2,1100+2,300+10+2);
					rectangle(760-2,460+10-2,1100+2,520+10+2);	
					rectangle(760-2,570+10-2,800+2,630+10+2);
					rectangle(820-2,570+10-2,860+2,630+10+2);
					rectangle(900-2,570+10-2,940+2,630+10+2);
					rectangle(960-2,570+10-2,1000+2,630+10+2);
					rectangle(1020-2,570+10-2,1100+2,630+10+2);				
					nhapChuoi(sanBayDen,770,380,1,SBD_MAX-1,BLACK,1);	
					break;
				}
				case 3:{ //hieu chinh shmb
					if(p->info.DSVE.sl > 0 || p->info.trangThai == HUYCHUYEN || p->info.trangThai==HOANTAT){
						break;
					}
					outText("                                                                                    ",
					 760,440,6,RED,11,1);
					setcolor(BLUE);	
					rectangle(760-2,460+10-2,1100+2,520+10+2);		
					setcolor(GREEN);
					rectangle(760-2,240+10-2,1100+2,300+10+2);
					rectangle(760-2,350+10-2,1100+2,410+10+2);	
					rectangle(760-2,570+10-2,800+2,630+10+2);
					rectangle(820-2,570+10-2,860+2,630+10+2);
					rectangle(900-2,570+10-2,940+2,630+10+2);
					rectangle(960-2,570+10-2,1000+2,630+10+2);
					rectangle(1020-2,570+10-2,1100+2,630+10+2);	
					nhapChuoi(soHieuMB,770,490,2,SHMB_MAX-1,BLACK,1);	
					break;
				}
				case 4:{ // hieu chinh gio
					outText("                                                                                    ",
					 760,550,6,RED,11,1);
					setcolor(BLUE);					
					rectangle(760-2,570+10-2,800+2,630+10+2);	
					setcolor(GREEN);
					rectangle(760-2,240+10-2,1100+2,300+10+2);
					rectangle(760-2,350+10-2,1100+2,410+10+2);	
					rectangle(760-2,460+10-2,1100+2,520+10+2);	
					rectangle(820-2,570+10-2,860+2,630+10+2);
					rectangle(900-2,570+10-2,940+2,630+10+2);
					rectangle(960-2,570+10-2,1000+2,630+10+2);
					rectangle(1020-2,570+10-2,1100+2,630+10+2);	
					nhapChuoi(gio,770-5,600,3,2,BLACK,1);
					break;
				}
				case 5:{ //hieu chinh phut
					outText("                                                                                    ",
					 760,550,6,RED,11,1);
					setcolor(BLUE);					
					rectangle(820-2,570+10-2,860+2,630+10+2);	
					setcolor(GREEN);
					rectangle(760-2,240+10-2,1100+2,300+10+2);
					rectangle(760-2,350+10-2,1100+2,410+10+2);	
					rectangle(760-2,460+10-2,1100+2,520+10+2);	
					rectangle(760-2,570+10-2,800+2,630+10+2);
					rectangle(900-2,570+10-2,940+2,630+10+2);
					rectangle(960-2,570+10-2,1000+2,630+10+2);
					rectangle(1020-2,570+10-2,1100+2,630+10+2);	
					nhapChuoi(phut,830-5,600,3,2,BLACK,1);
					break;
				}
				case 6:{ //hieu chinh ngay
					outText("                                                                                    ",
					 760,550,6,RED,11,1);
					setcolor(BLUE);				
					rectangle(900-2,570+10-2,940+2,630+10+2);	
					setcolor(GREEN);
					rectangle(760-2,240+10-2,1100+2,300+10+2);
					rectangle(760-2,350+10-2,1100+2,410+10+2);	
					rectangle(760-2,460+10-2,1100+2,520+10+2);	
					rectangle(760-2,570+10-2,800+2,630+10+2);
					rectangle(820-2,570+10-2,860+2,630+10+2);
					rectangle(960-2,570+10-2,1000+2,630+10+2);
					rectangle(1020-2,570+10-2,1100+2,630+10+2);	
					nhapChuoi(ngay,910-5,600,3,2,BLACK,1);		
					break;
				}
				case 7:{ //hieu chinh thang
					outText("                                                                                    ",
					 760,550,6,RED,11,1);
					setcolor(BLUE);				
					rectangle(960-2,570+10-2,1000+2,630+10+2);		
					setcolor(GREEN);
					rectangle(760-2,240+10-2,1100+2,300+10+2);
					rectangle(760-2,350+10-2,1100+2,410+10+2);	
					rectangle(760-2,460+10-2,1100+2,520+10+2);	
					rectangle(760-2,570+10-2,800+2,630+10+2);
					rectangle(820-2,570+10-2,860+2,630+10+2);
					rectangle(900-2,570+10-2,940+2,630+10+2);
					rectangle(1020-2,570+10-2,1100+2,630+10+2);		
					nhapChuoi(thang,970-5,600,3,2,BLACK,1);		
					break;
				}
				case 8:{ //hieu chinh nam
					outText("                                                                                    ",
					 760,550,6,RED,11,1);
					setcolor(BLUE);				
					rectangle(1020-2,570+10-2,1100+2,630+10+2);		
					setcolor(GREEN);
					rectangle(760-2,240+10-2,1100+2,300+10+2);
					rectangle(760-2,350+10-2,1100+2,410+10+2);	
					rectangle(760-2,460+10-2,1100+2,520+10+2);	
					rectangle(760-2,570+10-2,800+2,630+10+2);
					rectangle(820-2,570+10-2,860+2,630+10+2);
					rectangle(900-2,570+10-2,940+2,630+10+2);
					rectangle(960-2,570+10-2,1000+2,630+10+2);
					nhapChuoi(nam,1030,600,3,4,BLACK,1);
					break;
				}
				case 9:{   // luu
					THOIGIAN tg;
					tg.gio = atoi(gio);
					tg.phut = atoi(phut);
					tg.ngay = atoi(ngay);
					tg.thang = atoi(thang);
					tg.nam = atoi(nam);
					if(strlen(sanBayDen) == 0){
						outText("Khong duoc de trong!", 760,325,1,RED,11,1);
						break;
					}
					else if( (TimMayBayTheoSoHieu(DS_MAYBAY,soHieuMB) ) == NULL ){
						outText("So hieu may bay khong ton tai!", 760,440,1,RED,11,1);
						break;
					}					
					else if(!checkDateTimeValue(tg)){
						outText("Thoi gian khong hop le!", 760,550,1,RED,11,1);
						break;
					}
					else if( strcmp(p->info.sanBayDen,sanBayDen) == 0 &&  strcmp(p->info.soHieuMB,soHieuMB) == 0 &&  CompareDateTime(p->info.thoiGian,tg) ){  // neu k co thay doi
						alert("KHONG CO ","THAY DOI!");
						delay(1000);
						clearviewport();
						return;
					}
					else if( isTimePlaneUsing_ignoreFLight(DSCB,p->info.maCB,soHieuMB,tg)){  // xem thu may bay nay co dc su dung vao tg nay khong
						outText("Thoi diem nay may bay dang co chuyen bay!", 760,550,1,RED,11,1);
						break;
					}															
					bool check = confirm("ban co chac chan !","muon luu chuyen bay?");
					if(check){
						strcpy(p->info.sanBayDen,sanBayDen);
						if( strcmp(p->info.soHieuMB,soHieuMB) != 0){
							strcpy(p->info.soHieuMB,soHieuMB);
							MAYBAY* mb = TimMayBayTheoSoHieu(DS_MAYBAY,p->info.soHieuMB);
							p->info.DSVE.max = mb->soCho; // 
							delete []p->info.DSVE.ds;
							p->info.DSVE.ds = new string[p->info.DSVE.max+1];  
							// khoi tao ds ve co so cmnd la rong voi  tat ca chi so index
							for(int j = 1; j<= p->info.DSVE.max; j++){
								p->info.DSVE.ds[j] = "";
							}	
						}						
						p->info.thoiGian = tg;
					}		
					clearviewport();
					return;								
				}
				case 10:{   // xoa NODECb
					if(p->info.DSVE.sl > 0 ){
						thongbao_s2("Chuyen bay nay da","co nguoi dat ve!");
						break;
					}
					bool check = confirm("Ban co chac muon", "xoa chuyen bay nay?");
					if(check){	
						if(!isPlaneUsingForFlight_ignore(DS_CHUYENBAY,p->info.maCB,p->info.soHieuMB)){
							MAYBAY* mb = TimMayBayTheoSoHieu(DS_MAYBAY,p->info.soHieuMB);
							mb->active = true;
						}
						DeleteCB(DSCB,p->info.maCB);
						p = NULL;
						clearviewport();						
						return;
					}else{
						clearviewport();
						windowsBackgroundEditCB(" ~  HIEU CHINH CHUYEN BAY  ~  ");
						outText(maCB,770,270,9,BLACK,WHITE,1);
						outText(sanBayDen,770,380,9,BLACK,WHITE,1);
						outText(soHieuMB,770,490,9,BLACK,WHITE,1);
						outText(gio,770,600,9,BLACK,WHITE,1);
						outText(phut,830,600,9,BLACK,WHITE,1);
						outText(ngay,910,600,9,BLACK,WHITE,1);
						outText(thang,970,600,9,BLACK,WHITE,1);
						outText(nam,1030,600,9,BLACK,WHITE,1);
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
					rectangle(760-2,570+10-2,800+2,630+10+2);
					rectangle(820-2,570+10-2,860+2,630+10+2);
					rectangle(900-2,570+10-2,940+2,630+10+2);
					rectangle(960-2,570+10-2,1000+2,630+10+2);
					rectangle(1020-2,570+10-2,1100+2,630+10+2);		
					break;
				}
			}
		}
		delay(100);
	}
}


























