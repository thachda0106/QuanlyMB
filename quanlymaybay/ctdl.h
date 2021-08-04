//========================================================
struct maybay
{
	char soHieuMB[SHMB_MAX];
	char loaiMB[LOAIMB_MAX];
	int soCho;
	
	int so_luot_thuc_hien;
	bool active;
	
	maybay(){
		so_luot_thuc_hien = 0;
		active = true;      //active = true la may bay nay co the xoa, active = fasle la may bay dang duoc su dung cho chuyen bay khong xoa duoc
	}
};
typedef maybay MAYBAY;
struct danhsachmb
{
	MAYBAY *MAYBAY[MB_MAX];
	int sl;
	
	danhsachmb(){
		sl = 0;
	}
	~danhsachmb(){
		while(sl){
			delete MAYBAY[--sl];
		}
	}
};
typedef danhsachmb DANHSACHMB;
DANHSACHMB DS_MAYBAY;

//========================================================

struct danhsachve
{
	string *ds = NULL;     
	int max; //so luong ve max la so cho ngoi tren may bay + 1    
	int sl = 0;
};
typedef danhsachve DANHSACHVE;
//========================================================
//========================================================

enum TRANGTHAI {HUYCHUYEN,CONVE,HETVE,HOANTAT};
struct THOIGIAN
{
	int ngay, thang, nam, gio, phut;
};
struct chuyenbay
{
	char maCB[MACB_MAX];
	char soHieuMB[SHMB_MAX];
	char sanBayDen[SBD_MAX];
	THOIGIAN thoiGian;
	TRANGTHAI trangThai;
	DANHSACHVE DSVE;
};
typedef chuyenbay CHUYENBAY;
struct nodecb
{
	CHUYENBAY info;
	nodecb* next;
};
typedef nodecb* NODECB;

struct danhsachcb
{
	NODECB ds = NULL;
	int sl = 0 ;

	~danhsachcb(){
		NODECB p;
		while(ds != NULL){
			p = ds;
			ds = ds->next;
			delete p;	
		}		
	}

};
typedef danhsachcb DANHSACHCB;
DANHSACHCB DS_CHUYENBAY;
//========================================================

enum PHAI{NAM,NU};
struct hanhkhach
{
	char soCMND[CMND_MAX];
	char ho[HO_MAX];
	char ten[TEN_MAX];
	PHAI gioiTinh;
};
typedef hanhkhach HANHKHACH;
struct nodehk
{
	HANHKHACH info; //su dung HANHKHACH.soCMND lam KEY
	nodehk* left = NULL;
	nodehk* right = NULL;
};
typedef nodehk* NODEHK;
struct danhsachhk
{
	NODEHK ds = NULL;
	int sl = 0;
	
	void deleteDS(NODEHK& ds){
		if(ds != NULL)
		{
			delete ds;
			deleteDS(ds->left);
			deleteDS(ds->right);	
		}
	}
	~danhsachhk(){
		deleteDS(ds);
	}
};
typedef danhsachhk DANHSACHHK;
DANHSACHHK DS_HANHKHACH;

//======================================================================

