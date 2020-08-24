#include "DSCauHoi.h"
#include "DSMonHoc.h"
DSCauHoi::DSCauHoi(){
	this->sizeCH=0;
	this->cauHoiGoc=NULL;
}
bool DSCauHoi::coCauHoi(CauHoi* ch){
	if(strcmp(ch->getA(),ch->getB())==0 || strcmp(ch->getA(),ch->getC())==0 || strcmp(ch->getA(),ch->getD())==0
		|| strcmp(ch->getB(),ch->getC())==0 || strcmp(ch->getB(),ch->getD())==0  || strcmp(ch->getC(),ch->getD())==0)
		return true;
	else return false;
}
CauHoi* DSCauHoi::trungID(CauHoi* ch){
	CauHoi *chTam = cauHoiGoc;
	while(chTam!=NULL && ch->getID()!=chTam->getID()){
		if(ch->getID()<chTam->getID())
			chTam=chTam->getCauHoiTrai();
		else chTam=chTam->getCauHoiPhai();
	}
	return chTam;
}


void DSCauHoi::insertCauHoi(CauHoi* &chGoc, int id, char maMH[],char nd[], 
							char a[], char b[], char c[], char d[], char dad[]){
	if(chGoc==NULL){
		chGoc = new CauHoi;
		chGoc->setID(id);
		chGoc->setMaMH(maMH);
		chGoc->setNoiDung(nd);
		chGoc->setA(a);
		chGoc->setB(b);
		chGoc->setC(c);
		chGoc->setD(d);
		chGoc->setDapAnDung(dad);
		chGoc->setCauHoiTrai(NULL);
		chGoc->setCauHoiPhai(NULL);
	}
	else{
		if(id<chGoc->getID())
			insertCauHoi(chGoc->getCauHoiTrai(),id,maMH,nd,a,b,c,d,dad);
		else if(id>chGoc->getID())
			insertCauHoi(chGoc->getCauHoiPhai(),id,maMH,nd,a,b,c,d,dad);
	}
}
void DSCauHoi::themCauHoi(){
		clrscr();
		veKhungThemCH(23,2,24,70,15);
		CauHoi* chMoi = new CauHoi();
		chMoi->nhapIDCauHoi();
		int idTam;
		idTam=chMoi->getID();
		chMoi=trungID(chMoi);
		if(chMoi!=NULL){
			textColor(12);
			gotoXY(24,27); cout<<"                                        ";
			gotoXY(24,27); cout<<"Cau hoi da ton tai!";
			gotoXY(24,28); cout<<"                                        ";
			gotoXY(24,28); cout<<"Nhan phim bat ky de thoat";
			textColor(15);
			_getch();
		}
		else{
			delete chMoi;
			chMoi = new CauHoi;
			chMoi->setID(idTam);
			chMoi->nhapMaMH();
			DSMonHoc ds;
			ds.dataIn();
			while(!ds.coMaMonHoc(chMoi->getMaMH())){
				textColor(12);
				gotoXY(24,7); cout<<"                                 ";
				gotoXY(24,7); cout<<"Ma khong ton tai! Nhap lai: ";
				textColor(15);
				chMoi->nhapMaMH();
			}
			chMoi->nhapNoiDung();
			chMoi->nhapA();
			chMoi->nhapB();
			chMoi->nhapC();
			chMoi->nhapD();
			while(coCauHoi(chMoi)){
				textColor(12);
				gotoXY(24,27); cout<<"                                          ";
				gotoXY(24,27); cout<<"Noi dung dap an bi trung! Nhap lai: ";
				textColor(15);
				gotoXY(24,12); cout<<"                                       ";
				chMoi->nhapA();
				gotoXY(24,15); cout<<"                                       ";
				chMoi->nhapB();
				gotoXY(24,28); cout<<"                                       ";
				chMoi->nhapC();
				gotoXY(24,21); cout<<"                                       ";
				chMoi->nhapD();
			}
			gotoXY(24,24); cout<<"                                       ";
			chMoi->nhapDapAnDung();
			insertCauHoi(cauHoiGoc, chMoi->getID(), chMoi->getMaMH(), chMoi->getNoiDung(), chMoi->getA(), 
							chMoi->getB(), chMoi->getC(), chMoi->getD(), chMoi->getDapAnDung());
			sizeCH++;
		}
}
void DSCauHoi::LNR(CauHoi* chGoc){
	if(chGoc != NULL){
		LNR(chGoc->getCauHoiTrai());
		chGoc->inCauHoi();
		LNR(chGoc->getCauHoiPhai());
	}
}

void DSCauHoi::cayVaoMang(CauHoi *chGoc, CauHoi* CH[], char maMon[], int &n){
	if(chGoc!=NULL){
		cayVaoMang(chGoc->getCauHoiTrai(), CH, maMon, n);
		if(strcmp(chGoc->getMaMH(), maMon)==0){
			CH[n]=chGoc;
			n++;
		}
		cayVaoMang(chGoc->getCauHoiPhai(), CH, maMon, n);
	}
}
void DSCauHoi::inDSCauHoi(){
	if(cauHoiGoc==NULL) cout<<"Danh sach rong!!!\n";
	else LNR(cauHoiGoc);
} 
void DSCauHoi::dataIn(){
	fstream fileCH;
	fileCH.open("dsCauHoi.txt", ios::in);
	if(fileCH.is_open()){
		int idTam;
		char maTam[size_ma];
		char ndTam[size_noidung];
		char aTam[size_dapan];
		char bTam[size_dapan];
		char cTam[size_dapan];
		char dTam[size_dapan];
		char dadTam[2];
		if(kiemTraFileRong(fileCH)) return;
		else{
			CauHoi *chTam = new CauHoi;
			while(fileCH>>idTam){
				fileCH.ignore();
				fileCH.getline(maTam,size_ma);
				fileCH.getline(ndTam,size_noidung);
				fileCH.getline(aTam,size_dapan);
				fileCH.getline(bTam,size_dapan);
				fileCH.getline(cTam,size_dapan);
				fileCH.getline(dTam,size_dapan);
				fileCH.getline(dadTam,2);
				insertCauHoi(cauHoiGoc,idTam,maTam,ndTam,aTam,bTam,cTam,dTam,dadTam);
				sizeCH++;
				chTam = new CauHoi;
			}		
		}
	}
	else {
		textColor(12);
		gotoXY(24,27); cout<<"                                          ";
		gotoXY(24,27); cout<<"Chua mo duoc file!";
	}
	fileCH.close();
}
void DSCauHoi::xuatFile(CauHoi* chGoc, fstream &file){
	if(chGoc!=NULL) {
		xuatFile(chGoc->getCauHoiTrai(),file);
		file<<chGoc->getID()<<endl;
		file<<chGoc->getMaMH()<<endl;
		file<<chGoc->getNoiDung()<<endl;
		file<<chGoc->getA()<<endl;
		file<<chGoc->getB()<<endl;
		file<<chGoc->getC()<<endl;
		file<<chGoc->getD()<<endl;
		file<<chGoc->getDapAnDung()<<endl;
		xuatFile(chGoc->getCauHoiPhai(),file);
	}
} 
void DSCauHoi::dataOut(){
	fstream fileCH;
	fileCH.open("dsCauHoi.txt", ios::out);
	if(sizeCH != 0)
		xuatFile(cauHoiGoc,fileCH);
	textColor(10);
	gotoXY(24,27); cout<<"                                          ";
	gotoXY(24,27); cout<<"Saved";
	fileCH.close();
}
CauHoi* & DSCauHoi::getCauHoiGoc(){
	return this->cauHoiGoc;
}
int DSCauHoi::getSizeCH(){
	return this->sizeCH;
}
CauHoi* DSCauHoi::coID(int idTam){
	CauHoi *chTam = cauHoiGoc;
	while(chTam!=NULL && idTam!=chTam->getID()){
		if(idTam<chTam->getID())
			chTam=chTam->getCauHoiTrai();
		else chTam=chTam->getCauHoiPhai();
	}
	return chTam;
}

