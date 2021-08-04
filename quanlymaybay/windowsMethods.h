


//=========================================================================================
void rectBox(int x1, int y1, int x2, int y2, int pattern,int background);
void outText(char s[], int x, int y,int font, int color,int background,int size);
//void clearShow(){
//	
////	rectBox(440+3,165-55+3,1899-30-4,1040-4,1,11);	
//	for(int x=440+3,y = 165-55+3;y<1040-4 ;y++ ){
//		outText("DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD",x,y,6,4,11,3);
//	}
//}
//=========================================================================================

void rectBox(int x1, int y1, int x2, int y2, int pattern,int background){
	setbkcolor(background);
	setcolor(background);
	rectangle(x1,y1,x2,y2);
	setfillstyle(pattern,background);
	floodfill(x1+1,y1+1,background);
}

void outText(char s[], int x, int y,int font, int color,int background,int size){
	setbkcolor(background);
	setcolor(color);
	settextstyle(font,0,size);
	outtextxy(x,y,s);
}
