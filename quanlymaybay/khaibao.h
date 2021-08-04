void windowsPlane();
void windowsFlight();
void windowsTicket();
void windowsCustomer();
void rectBox(int x1, int y1, int x2, int y2, int pattern,int background);
void outText(char s[], int x, int y,int font, int color,int background,int size);
void nhapChuoi(char s[],int x,int y,int kieuNhap,int max,int color,int size);
int pageMax(int sl);
void formatDate(char thoigian[], char gio[], char phut[], char ngay[], char thang[], char nam[] );
void clearTableCB();
int windowsMain();
bool windowsMenu(int selected);
int itemsActive(int selected);

void readFILE();
void writeFILE();
void writeFileCB(DANHSACHCB &DSCB);
void readFileCB(DANHSACHCB &DSCB, DANHSACHMB &DSMB);
void hightlighNODECB(NODECB p, int vitri, int STTpage, int color, int background);
void insertCB(DANHSACHCB& DS_CHUYENBAY, CHUYENBAY x);
void clearDSCB(DANHSACHCB& DSCB);
NODECB searchCB(NODECB ds, char maCB[]);
void xuatDSCB(DANHSACHCB& DSCB, int& STTpage);
void cancelCB(DANHSACHCB &DSCB);
void newCB(DANHSACHCB &DSCB);
void correctionCB(DANHSACHCB &DSCB, NODECB &p);
void cancelVE(DANHSACHCB& DS_CHUYENBAY, DANHSACHHK& DS_HANHKHACH);
void bookVE(DANHSACHCB &DS_CHUYENBAY, DANHSACHHK& DS_HANHKHACH, NODECB& cb);
bool confirm(char *s1, char *s2);
bool alert(char *s1, char *s2);
void thongbao(char *s1, char *s2);
void thongbao_s2(char *s1, char *s2);
void clearFulltable();
void clearDSVE();
void drawTableCB();
void drawTableMB();
void windowsBackground();
int checkSelectmouseNEWCB(int x, int y);
int checkSelectmouseBOOKTK(int x, int y);
int checkSelectmouseNEWHK(int x, int y);
bool isCustomerBookedTK(DANHSACHCB& DS_CHUYENBAY, char* SOCMND);
void fillBox(int x, int y, int pattern,int background);
void windowsThemMB();
void windowsBackgroundEditMB(char * title);
void windowsBackgroundEditCB(char * title);
void formatChuoi(char s[]);
string convertToString(char* a, int size);
void clearFulltable();

//MayBay
int TimMayBay(DANHSACHMB &dsmb,char *S);
int ChenMayBay(DANHSACHMB &ds, MAYBAY &mb, int position);
int ThemMayBay(DANHSACHMB &ds, MAYBAY &mb);
int ThemCuoiDSMB(DANHSACHMB &ds, MAYBAY *mb);
int SuaMayBay(DANHSACHMB &dsmb, MAYBAY &mb, int i);
int XoaMayBay(DANHSACHMB &dsmb, char *sohieuMB);
MAYBAY* TimMayBayTheoSoHieu(DANHSACHMB &dsmb, char *s);
void DocMayBay(DANHSACHMB &dsmb);
void GhiMayBay(DANHSACHMB &dsmb);
bool isPlaneUsingForFlight(DANHSACHCB & DSCB, char * SHMB );
//===============================================

int loadFile(DANHSACHHK& DS_HANHKHACH);
void writeHKVaoFile(NODEHK &z,fstream &file);
int saveDSVaoFile(DANHSACHHK& DS_HANHKHACH);
int checkHK(NODEHK t, char CMND[CMND_MAX]);
NODEHK SearchHK (NODEHK root, char* SOCMND);
void themHK( HANHKHACH x, NODEHK &z);
void findReplace(NODEHK &x, NODEHK &y);
void deleteHK(NODEHK &t, char* soCMND);
void addDSHK(NODEHK DSHK,HANHKHACH* DS_HK , int& sl);
void deleteHKtemp(HANHKHACH* DS_HK,int& slHK, char* soCMND);
void InsertOrder_DSHK (HANHKHACH* DS_HK, HANHKHACH hk, int slHK);
int findIndexHK(HANHKHACH* DS_HK, int& slHK, char* soCMND );





