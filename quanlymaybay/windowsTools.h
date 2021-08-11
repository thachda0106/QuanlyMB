void rectBox(int x1, int y1, int x2, int y2, int pattern,int background){
	setbkcolor(background);
	setcolor(background);
	rectangle(x1,y1,x2,y2);
	setfillstyle(pattern,background);
	floodfill(x1+1,y1+1,background);
}

void fillBox(int x, int y, int pattern,int background){
	setfillstyle(pattern,background);
	floodfill(x,y,background);
}
void outText(char s[], int x, int y,int font, int color,int background,int size){
	setbkcolor(background);
	setcolor(color);
	settextstyle(font,0,size);
	outtextxy(x,y,s);
}

void thongbao(char *s1, char *s2){
	outText(s1,1490,150+30,1,RED,11,1);
	outText(s2,1490,180+30,1,RED,11,1);
	delay(1000);
	outText(s1,1490,150+30,1,11,11,1);
	outText(s2,1490,180+30,1,11,11,1);
}

void thongbao_s2(char *s1, char *s2){
	outText(s1,1460,100,1,RED,11,1);
	outText(s2,1460,100+30,1,RED,11,1);
	delay(1000);
	outText(s1,1460,100,1,11,11,1);
	outText(s2,1460,100+30,1,11,11,1);
}

int checkXYConfirm(int x, int y){
	if(x>792 && x<876 && y>440 && y<483 ) return 1;
	else if(x>950 && x<1050 && y>440 && y<483) return 2;
	else return -1;
}

int checkConfirm(){
	int x,y;
	if(ismouseclick(WM_LBUTTONDOWN)){
		getmouseclick(WM_LBUTTONDOWN,x,y);
		int check = checkXYConfirm(x,y) ;
		if(check== 1 ) return 1;
		else if (check== 2) return 2;
		else return 0;
	}
	return -1;
}

bool confirm(char *s1, char *s2){
	setlinestyle(1,0,2);
	setcolor(YELLOW);
	rectangle(764-2,330-2,1104+2,540+2);
	rectBox(764,330,1104,540,1,7);
	rectangle(792-2,440-2,876+2,483+2);
	rectangle(950-2,440-2,1035+2,483+2);	
	rectBox(792,440,876,483,1,GREEN);
	rectBox(950,440,1050,483,1,RED);	
	outText(s1,804,360,1,15,7,1);
	outText(s2,804,400,1,15,7,1);
	outText("co",815,450,1,15,GREEN,1);
	outText("khong",965,450,1,15,RED,1);
	while(1){
		int i = checkConfirm();
		if(i == 1) return true;
		else if(i == 2) return false;
		else if(i == 0) {
			setcolor(RED);
			rectangle(764-2,330-2,1104+2,540+2);
		}
		delay(10);
	}
}

bool alert(char *s1, char *s2){
	setlinestyle(1,0,2);
	setcolor(YELLOW);
	rectangle(764-2,330-2,1104+2,540+2);
	rectBox(764,330,1104,540,1,7);	
	outText(s1,804,360,1,15,7,1);
	outText(s2,804,400,1,15,7,1);
}

int checkSelectTableNODE(int x, int y){
	if(x>490 && x< 1425 && y> 240 && y< 300 ){
		return 1;  
	}else if(x>490 && x< 1425 && y> 300 && y< 360 ){
		return 2;  
	}else if(x>490 && x< 1425 && y> 360 && y< 420 ){
		return 3; 
	}else if(x>490 && x< 1425 && y> 420 && y< 480 ){
		return 4; 
	}else if(x>490 && x< 1425 && y> 480 && y< 540 ){
		return 5; 
	}else if(x>490 && x< 1425 && y> 540 && y< 600 ){
		return 6; 
	}else if(x>490 && x< 1425 && y> 600 && y< 660 ){
		return 7; 
	}else if(x>490 && x< 1425 && y> 660 && y< 720 ){
		return 8;  
	}else if(x>490 && x< 1425 && y> 720 && y< 780  ){
		return 9;  
	}else if(x>490 && x< 1425 && y> 740 && y< 840 ){
		return 10; 	
	}else{
		return 1;
	}
}


int checkSelectMenuItems(int x, int y){
	if(x>83 && x< 350 && y> 217 && y< 278 ){
		return 1;  //mb
	}else if(x>83 && x< 350 && y> 331 && y< 392){
		return 2;  //cb
	}else if(x>83 && x< 350 && y> 444 && y< 504){
		return 3; //hk
	}else if(x>83 && x< 350 && y> 552 && y< 608){
		return 4; //dve
	}else if(x>83 && x< 350 && y> 648 && y< 704){
		return 5; //thoat
	}else if(x>1169-50 && x< 1423 && y> 130 && y< 170){
		return 6;  //search-box
	}else if(x>1440 && x< 1555 && y> 135 && y< 165){  
		return 7;  //search
	}
	else if(x>1532 && x< 1737 && y> 255 && y< 310){
		return 8;  //them
	}else if(x>1532 && x< 1737 && y> 368 && y< 423){
		return 9;  // huy
	}else if(x>1532 && x< 1737 && y> 475 && y< 530){
		return 10;  //thay doi
	}else if(x>1170 && x< 1200 && y> 880 && y< 910){
		return 11;  // page truoc		
	}else if(x>1367+20 && x< 1390+20 && y> 880 && y< 910){
		return 12;   //page sau
	}else if(x>490 && x< 1425 && y> 240 && y< 840){
		return 13;   // click table
	}
	else if(x>1532 && x< 1737 && y> 475-1+100 && y< 527+1+3+100){
		return 14;   // thong ke 
	}
	else{
		return -1;
	}
}
void clearWindows(){
	rectBox(440-1,165-55-1,1899-30-1,1040-1,1,WHITE); // table
	rectBox(440-1,165-55-1,1899-30-1,1040-1,1,11); // table

}
void clearFulltable(){
	rectBox(496-1,166-1+20,1428-1,820-1+20,1,WHITE); // table
	rectBox(496-1,166-1+20,1428-1,820-1+20,1,11); // table
}
void clearDSVE(){
	rectBox(1180-10+5,235-10+5,1755+10-5,695+10-5,1,WHITE);	
	rectBox(1180-10+5,235-10+5,1755+10-5,695+10-5,1,11);
//	setcolor(GREEN);
//	rectangle(1180-10,235-10,1755+10,695+10);	
}
int pageMax(int sl){
	int max = 0;
	if(sl == 0) return max;  // sl == 0
	else if(sl % 10 == 0) return sl/10;   //sl chia hhet 10

	while(sl > 10){       // sl > 10 va k chia het 10
		max = max + sl/10;
		sl = sl%10;
	}
	return  max + 1;
}

void clearTableCB(){
	int y = 260;    
    int dem = 1;
	for( ; dem <= 10; dem++){
		outText("DD",505,y,9,11,11,1);
		outText("DDDDDD",574,y,9,11,11,1);
		outText("DDDDDDDD",715,y,9,11,11,1);
		outText("DDDDDD",890,y,9,11,11,1);
		outText("DDDDDDDDDD",1040,y,9,11,11,1);
		outText("DDDDDDD",1265,y,9,11,11,1);
		y+=60;
	}
}

void clearTableMB(){
	int y = 260;    
    int dem = 1;
	for( ; dem <= 10; dem++){
		outText("DD",505,y,9,11,11,1);
		outText("DDDDDDDDDD",574+10,y,9,11,11,1);
		outText("DDDDDDDDDDDD",890-30,y,9,11,11,1);
		outText("DDDDDDDDD",1040+200,y,9,11,11,1);

		y+=60;
	}
}
void clearTableHK(){
	int y = 260;    
    int dem = 1;
	for( ; dem <= 10; dem++){
		outText("DD",505,y,9,11,11,1);
		outText("DDDDDDDDDD",570,y,9,11,11,1);
		outText("DDDDDDDDDD",820,y,9,11,11,1);
		outText("DDDDDDDDD",1130,y,9,11,11,1);
		outText("DDD",1335,y,9,11,11,1);
		y+=60;
	}
}

void clearTableDSHKCB(){
	int y = 260;    
    int dem = 1;
	for( ; dem <= 10; dem++){
		outText("DD",370,y,9,11,11,1);
		outText("DD",460,y,9,11,11,1);
		outText("DDDDDDDDD",605,y,9,11,11,1);
		outText("DDDDDDDDDD",820,y,9,11,11,1);
		outText("DDDDDDDDDD",1100,y,9,11,11,1);
		outText("DDD",1335,y,9,11,11,1);
		y+=60;
	}
}

void clearTableDSMB_SLTH(){
	int y = 260;    
    int dem = 1;
	for( ; dem <= 10; dem++){
		outText("DD",615,y,9,11,11,1);
		outText("DDDDDDDDD",700,y,9,11,11,1);
		outText("DDDD",1000,y,9,11,11,1);

		y+=60;
	}
}


void clearFindDSCB(){
	int y = 260;    
    int dem = 1;
	for( ; dem <= 10; dem++){
		outText("DD",370,y,9,11,11,1);
		outText("DDDDDDD",465,y,9,11,11,1);
		outText("DDDD",640,y,9,11,11,1);
		outText("DDDDDDDDDD",765,y,9,11,11,1);
		outText("DDDDDDDDDD",1020,y,9,11,11,1);
		outText("DDDDDD",1290,y,9,11,11,1);
		y+=60;
	}
}

void nhapChuoi(char s[],int x,int y,int kieuNhap,int max,int color,int size){
	setbkcolor(WHITE);
	setcolor(color);
	settextstyle(6,0,size);
	
	int length = strlen(s); // do dai chuoi s ban dau dua vao
	char nhay[] ={124,'\0'}; 
	char ChuoiNhay[max + 2] = "";
	strcat(ChuoiNhay,s);
	strcat(ChuoiNhay,nhay);
	outtextxy(x,y,ChuoiNhay); 
	
	char kytu; // kt kytu bat dc tu ban phim
	switch(kieuNhap){
		case 1:{ // cho phep nhap chu, co dau cach. ex NHAP HO TEN VA CHUAN HOA
			while(true && !ismouseclick(WM_LBUTTONDOWN)){
				if(kbhit()){
					kytu = getch();
					if(length > 0 && kytu == 8){
						setcolor(WHITE); 
						outtextxy(x,y,ChuoiNhay);	
						s[--length] = '\0';						
						ChuoiNhay[0] = '\0';
						strcat(ChuoiNhay,s);
						strcat(ChuoiNhay,nhay);					
						setcolor(color);
						outtextxy(x,y,ChuoiNhay);						
					}
					else if(length == max){
						continue;
					}
					else if( kytu == 32){
						int check = length -1;
						if(length == 0 ) continue;   // neu nhap ky tu dau la khoang trang
						else if( s[check] == 32) continue;  // neu nhap 2 ky tu khoang trang lien tiep
						else{
							s[length] = kytu;
							s[++length] = '\0';
							ChuoiNhay[0] = '\0';
							strcat(ChuoiNhay,s);
							strcat(ChuoiNhay,nhay);
							outtextxy(x,y,ChuoiNhay); 
						}
					}
					else if( ( kytu >= 97 && kytu <=122 ) || (kytu >=65 && kytu <= 90) ){
						int check = length -1;
						if(length == 0) {  // neu nhap chu dau tien thi in hoa
							if(( kytu >= 97 && kytu <=122 )) kytu-=32;
						}else if(s[check] == 32 && ( kytu >= 97 && kytu <=122 ) ){ // neu nhap chu sau dau cach thi in hoa len
							kytu -= 32;
						}else if(s[check] == 32 &&  (kytu >=65 && kytu <= 90)){  // neu nhap chu sau dau cah ma nhap InHOA thi giu nguyen
						}
						else if( (kytu >=65 && kytu <= 90) ){ // neu nhap chu hoa thi ve chu thuong
							kytu +=32;
						}						
						s[length] = kytu;
						s[++length] = '\0';
						ChuoiNhay[0] = '\0';
						strcat(ChuoiNhay,s);
						strcat(ChuoiNhay,nhay);
						outtextxy(x,y,ChuoiNhay); 
					}
									
				}
			}
			break;
		}
		case 2:{ // cho phep nhap chu, so, khong co dau cach. NHAP IN HOA
			while(true && !ismouseclick(WM_LBUTTONDOWN)){
				if(kbhit()){
					kytu = getch();
					if(length > 0 && kytu == 8){
						setcolor(WHITE); 
						outtextxy(x,y,ChuoiNhay);	
						s[--length] = '\0';						
						ChuoiNhay[0] = '\0';
						strcat(ChuoiNhay,s);
						strcat(ChuoiNhay,nhay);					
						setcolor(color);
						outtextxy(x,y,ChuoiNhay);
						
					}
					else if(length == max){
						continue;
					}else if( kytu >= 97 && kytu <=122 ){
						kytu -= 32;
						s[length] = kytu;
						s[++length] = '\0';
						ChuoiNhay[0] = '\0';
						strcat(ChuoiNhay,s);
						strcat(ChuoiNhay,nhay);
						outtextxy(x,y,ChuoiNhay); 
					}
					else if(  (kytu >=65 && kytu <= 90) || (kytu >=48 && kytu<= 57)){
						s[length] = kytu;
						s[++length] = '\0';
						ChuoiNhay[0] = '\0';
						strcat(ChuoiNhay,s);
						strcat(ChuoiNhay,nhay);
						outtextxy(x,y,ChuoiNhay); 
					}
									
				}
			}			
			break;
		}
		case 3:{ // chi nhap so || only number
			while(true && !ismouseclick(WM_LBUTTONDOWN)){
				if(kbhit()){
					kytu = getch();
					if(length > 0 && kytu == 8){
						setcolor(WHITE); 
						outtextxy(x,y,ChuoiNhay);	
						s[--length] = '\0';						
						ChuoiNhay[0] = '\0';
						strcat(ChuoiNhay,s);
						strcat(ChuoiNhay,nhay);					
						setcolor(color);
						outtextxy(x,y,ChuoiNhay);
						
					}
					else if(length == max){
						continue;
					}
					else if((kytu >=48 && kytu<= 57)){
						s[length] = kytu;
						s[++length] = '\0';
						ChuoiNhay[0] = '\0';
						strcat(ChuoiNhay,s);
						strcat(ChuoiNhay,nhay);
						outtextxy(x,y,ChuoiNhay); 
					}
									
				}
			}			
			break;
		}
		case 4:{ // cho phep nhap chu, co dau cach va dau '_'. ex NHAP HO TEN VA CHUAN HOA
			while(true && !ismouseclick(WM_LBUTTONDOWN)){
				if(kbhit()){
					kytu = getch();
					if(length > 0 && kytu == 8){
						setcolor(WHITE); 
						outtextxy(x,y,ChuoiNhay);	
						s[--length] = '\0';						
						ChuoiNhay[0] = '\0';
						strcat(ChuoiNhay,s);
						strcat(ChuoiNhay,nhay);					
						setcolor(color);
						outtextxy(x,y,ChuoiNhay);
						
					}
					else if(length == max){
						continue;
					}
					else if( kytu == 32){
						int check = length -1;
						if(length == 0 ) continue;   // neu nhap ky tu dau la khoang trang
						else if( s[check] == 32) continue;  // neu nhap 2 ky tu khoang trang lien tiep
						else{
							s[length] = kytu;
							s[++length] = '\0';
							ChuoiNhay[0] = '\0';
							strcat(ChuoiNhay,s);
							strcat(ChuoiNhay,nhay);
							outtextxy(x,y,ChuoiNhay); 
						}
					}
					else if( ( kytu >= 97 && kytu <=122 ) || (kytu >=65 && kytu <= 90) || (kytu >=48 && kytu<= 57) || kytu == 95  ){
						int check = length -1;
						if(length == 0) {  // neu nhap chu dau tien thi in hoa
							if(( kytu >= 97 && kytu <=122 )) kytu-=32;
						}else if(s[check] == 32 && ( kytu >= 97 && kytu <=122 ) ){ // neu nhap chu sau dau cach thi in hoa len
							kytu -= 32;
						}else if(s[check] == 32 &&  (kytu >=65 && kytu <= 90)){  // neu nhap chu sau dau cah ma nhap InHOA thi giu nguyen
						}
						else if( (kytu >=65 && kytu <= 90) ){ // neu nhap chu hoa thi ve chu thuong
							kytu +=32;
						}						
						s[length] = kytu;
						s[++length] = '\0';
						ChuoiNhay[0] = '\0';
						strcat(ChuoiNhay,s);
						strcat(ChuoiNhay,nhay);
						outtextxy(x,y,ChuoiNhay); 
					}
									
				}
			}			
			break;
		}
	}
	setcolor(WHITE); 
	outtextxy(x,y,ChuoiNhay);
	setcolor(color); 
	outtextxy(x,y,s);	
	
}

//void nhapChuoi(char s[],int x,int y,int kieuNhap,int max,int color,int size){
//	setbkcolor(WHITE);
//	setcolor(color);
//	settextstyle(6,0,size);
//	outtextxy(x,y,s); // moi vao thi xuat chuoi s tai toado: x,y
//	
//	int length = strlen(s); // do dai chuoi s ban dau dua vao
//	
//	char deleted[max+1], deleted_dd[max+1], deleted_INHOA[max+1]  ;// mang dung de xoa hang
//	for(int i = 0; i< max; i++){
//		deleted[i]='d';
//	    deleted_INHOA[i] ='D';
//	}
//	for(int i = 0; i< max-5; i++){   // vi font chu k deu nen xoa het chu cai lon cho ca chu cai nhap thuong thi bi qua nen uoc chung giam di 5
//	    deleted_dd[i] ='D';
//	}   
//	deleted[max] ='\0';  // mang deleted ki tu cuoi = '\0'
//	deleted_INHOA[max] ='\0';	
//	deleted_dd[max-5]='\0';
//
//	char kytu; // kt kytu bat dc tu ban phim
//	switch(kieuNhap){
//		case 1:{ // cho phep nhap chu, co dau cach. ex NHAP HO TEN VA CHUAN HOA
//			while(true && !ismouseclick(WM_LBUTTONDOWN)){
//				if(kbhit()){
//					kytu = getch();
//					if(length > 0 && kytu == 8){
//						setcolor(WHITE); 
//						outtextxy(x,y,deleted_dd);
//
//						s[--length] = '\0';
//						setcolor(color);
//						outtextxy(x,y,s);
//						
//					}
//					else if(length == max){
//						continue;
//					}
//					else if( kytu == 32){
//						int check = length -1;
//						if(length == 0 ) continue;   // neu nhap ky tu dau la khoang trang
//						else if( s[check] == 32) continue;  // neu nhap 2 ky tu khoang trang lien tiep
//						else{
//							s[length] = kytu;
//							s[++length] = '\0';
//							outtextxy(x,y,s);
//						}
//					}
//					else if( ( kytu >= 97 && kytu <=122 ) || (kytu >=65 && kytu <= 90) ){
//						int check = length -1;
//						if(length == 0) {  // neu nhap chu dau tien thi in hoa
//							if(( kytu >= 97 && kytu <=122 )) kytu-=32;
//						}else if(s[check] == 32 && ( kytu >= 97 && kytu <=122 ) ){ // neu nhap chu sau dau cach thi in hoa len
//							kytu -= 32;
//						}else if(s[check] == 32 &&  (kytu >=65 && kytu <= 90)){  // neu nhap chu sau dau cah ma nhap InHOA thi giu nguyen
//						}
//						else if( (kytu >=65 && kytu <= 90) ){ // neu nhap chu hoa thi ve chu thuong
//							kytu +=32;
//						}						
//						s[length] = kytu;
//						s[++length] = '\0';
//						outtextxy(x,y,s);
//					}
//									
//				}
//			}
//			
//			break;
//		}
//		case 2:{ // cho phep nhap chu, so, khong co dau cach. NHAP IN HOA
//			while(true && !ismouseclick(WM_LBUTTONDOWN)){
//				if(kbhit()){
//					kytu = getch();
//					if(length > 0 && kytu == 8){
//						setcolor(WHITE); 
//						outtextxy(x,y,deleted_INHOA);
//						
//						s[--length] = '\0';
//						setcolor(color);
//						outtextxy(x,y,s);
//						
//					}
//					else if(length == max){
//						continue;
//					}else if( kytu >= 97 && kytu <=122 ){
//						kytu -= 32;
//						s[length] = kytu;
//						s[++length] = '\0';
//						outtextxy(x,y,s);
//					}
//					else if(  (kytu >=65 && kytu <= 90) || (kytu >=48 && kytu<= 57)){
//						s[length] = kytu;
//						s[++length] = '\0';
//						outtextxy(x,y,s);
//					}
//									
//				}
//			}
//			
//			break;
//		}
//		case 3:{ // chi nhap so || only number
//			while(true && !ismouseclick(WM_LBUTTONDOWN)){
//				if(kbhit()){
//					kytu = getch();
//					if(length > 0 && kytu == 8){
//						setcolor(WHITE); 
//						outtextxy(x,y,deleted);
//
//						s[--length] = '\0';
//						setcolor(color);
//						outtextxy(x,y,s);
//						
//					}
//					else if(length == max){
//						continue;
//					}
//					else if((kytu >=48 && kytu<= 57)){
//						s[length] = kytu;
//						s[++length] = '\0';
//						outtextxy(x,y,s);
//					}
//									
//				}
//			}
//			break;
//		}
//		case 4:{ // cho phep nhap chu, co dau cach va dau '_'. ex NHAP HO TEN VA CHUAN HOA
//			while(true && !ismouseclick(WM_LBUTTONDOWN)){
//				if(kbhit()){
//					kytu = getch();
//					if(length > 0 && kytu == 8){
//						setcolor(WHITE); 
//						outtextxy(x,y,deleted_dd);
//
//						s[--length] = '\0';
//						setcolor(color);
//						outtextxy(x,y,s);
//						
//					}
//					else if(length == max){
//						continue;
//					}
//					else if( kytu == 32){
//						int check = length -1;
//						if(length == 0 ) continue;   // neu nhap ky tu dau la khoang trang
//						else if( s[check] == 32) continue;  // neu nhap 2 ky tu khoang trang lien tiep
//						else{
//							s[length] = kytu;
//							s[++length] = '\0';
//							outtextxy(x,y,s);
//						}
//					}
//					else if( ( kytu >= 97 && kytu <=122 ) || (kytu >=65 && kytu <= 90) || (kytu >=48 && kytu<= 57) || kytu == 95  ){
//						int check = length -1;
//						if(length == 0) {  // neu nhap chu dau tien thi in hoa
//							if(( kytu >= 97 && kytu <=122 )) kytu-=32;
//						}else if(s[check] == 32 && ( kytu >= 97 && kytu <=122 ) ){ // neu nhap chu sau dau cach thi in hoa len
//							kytu -= 32;
//						}else if(s[check] == 32 &&  (kytu >=65 && kytu <= 90)){  // neu nhap chu sau dau cah ma nhap InHOA thi giu nguyen
//						}
//						else if( (kytu >=65 && kytu <= 90) ){ // neu nhap chu hoa thi ve chu thuong
//							kytu +=32;
//						}						
//						s[length] = kytu;
//						s[++length] = '\0';
//						outtextxy(x,y,s);
//					}
//									
//				}
//			}
//			
//			break;
//		}
//	}
//	
//}
