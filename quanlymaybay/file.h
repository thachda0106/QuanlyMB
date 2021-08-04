void readFILE(){
	DocMayBay(DS_MAYBAY);
	readFileCB(DS_CHUYENBAY,DS_MAYBAY);	
	loadFile(DS_HANHKHACH);
}

void writeFILE(){
	GhiMayBay(DS_MAYBAY);	
	writeFileCB(DS_CHUYENBAY);
	saveDSVaoFile(DS_HANHKHACH);
}
