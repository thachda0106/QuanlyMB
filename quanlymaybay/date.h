int DayInLadder[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31};
int Presentday(){
	time_t hientai = time(0);
	tm *tg = localtime(&hientai);
	return tg->tm_mday;
}
int Presentmonth(){
	time_t hientai = time(0);
	tm *tg = localtime(&hientai);
	return 1+tg->tm_mon;
}
int Presentyear() {
	time_t hientai = time(0);
	tm *tg = localtime(&hientai);
	return 1900+tg->tm_year;
}
int Presenthour() {
	time_t hientai = time(0);
	tm *tg = localtime(&hientai);
	return tg->tm_hour;
}
int Presentmin() {
	time_t hientai = time(0);
	tm *tg = localtime(&hientai);
	return tg->tm_min;
}
bool DateTime(THOIGIAN &dt)
{
	if(dt.gio < 0 || dt.gio >= 24) return false;
	if(dt.phut < 0 || dt.phut >= 60) return false;
	if(dt.thang <= 0  || dt.thang > 12) return false;
	DayInLadder[2] = 28;
	if ((dt.nam % 400 == 0) || (dt.nam % 4 == 0 && dt.nam % 100 != 0))
		DayInLadder[2] = 29;
	if (dt.ngay > DayInLadder[dt.thang] || dt.ngay <= 0) return false;
	return true;
}
bool checkDateTimeValue(THOIGIAN &dt)
{
	if (!DateTime(dt)) return false;
	DayInLadder[2] = 28;
	if (dt.nam < Presentyear()) return false;
	if ((dt.nam == Presentyear()) && (dt.thang < Presentmonth()))  return false;
	if ((dt.nam % 400 == 0) || (dt.nam % 4 == 0 && dt.nam % 100 != 0))
		DayInLadder[2] = 29;
	if (dt.nam == Presentyear() && dt.thang == Presentmonth() && dt.ngay < Presentday()) return false;
	if (dt.nam == Presentyear() && dt.thang == Presentmonth() && dt.ngay == Presentday() && dt.gio < Presenthour()) return false;
	if (dt.nam == Presentyear() && dt.thang == Presentmonth() && dt.ngay == Presentday() && dt.gio == Presenthour() && dt.phut <= Presentmin()) return false;
	return true;
}
void CurrentTime(THOIGIAN &dt) {
	dt.ngay = Presentday();
	dt.thang = Presentmonth();
	dt.nam = Presentyear();
	dt.gio = Presenthour();
	dt.phut = Presentmin();
}

bool checkTimeHoanTatCB(THOIGIAN &dt){   // sang ngay moi la chuyen bay da hoan tat
	if(Presentyear() > dt.nam) return true;
	else if(Presentyear() == dt.nam  && Presentmonth() > dt.thang) return true;
	else if (Presentyear() == dt.nam  && Presentmonth() == dt.thang && Presentday() > dt.ngay) return true;
	return false;
}

bool CompareDate(THOIGIAN &a, THOIGIAN &b){
	if((a.ngay == b.ngay) && (a.thang == b.thang) && (a.nam == b.nam)) return true;
	return false;
}
bool CompareDateTime(THOIGIAN &a, THOIGIAN &b){
	if((a.gio == b.gio) &&(a.phut == b.phut) &&(a.ngay == b.ngay) && (a.thang == b.thang) && (a.nam == b.nam)) return true;
	return false;
}
