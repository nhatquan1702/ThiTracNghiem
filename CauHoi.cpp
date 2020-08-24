#include "CauHoi.h"

CauHoi::CauHoi(){
	strcpy(this->maMH,"");
	strcpy(this->noiDung,"");
	strcpy(this->A,"");
	strcpy(this->B,"");
	strcpy(this->C,"");
	strcpy(this->D,"");
	strcpy(this->dapAnDung,"");
	this->idCauhoi=0;
	cauHoiTrai=cauHoiPhai=NULL;
}
void CauHoi::nhapIDCauHoi(){
	fstream fileRand;
	fileRand.open("randID.txt", ios::in);
	int n=0; 
	int a[100000];
	if(fileRand.is_open()){
		if(kiemTraFileRong(fileRand)) return;
		else{
			fileRand>>n;
			for(int i=0; i<n; i++){	
				fileRand>>a[i];
			}
			idCauhoi=a[n-1];
			n--;
			fileRand.close();		
		}
	}
	fileRand.open("randID.txt", ios::out);
	fileRand<<n<<endl;
	for(int i=0; i<n; i++)
		fileRand<<a[i]<<endl;
	fileRand.close();
	textColor(15);
	gotoXY(24,3); cout<<"                                       ";
	gotoXY(24,3); cout<<"ID cau hoi: "; cout<<idCauhoi;
	while(idCauhoi<0){
		textColor(12);
		gotoXY(24,4); cout<<"                                       ";
		gotoXY(24,4); cout<<"ID khong de trong!Nhap lai: ";
		textColor(15);
		return;
	}

	fileRand.close();
	textColor(10);
	gotoXY(24,4); cout<<"                                       ";
	gotoXY(24,4); cout<<"OK";
	textColor(15);
}
void CauHoi::nhapMaMH(){
	textColor(15);
	gotoXY(24,6); cout<<"                                       ";
	gotoXY(24,6); cout<<"Nhap ma mon hoc: ";
	nhapMa(this->maMH,size_ma);
	while(kiemTraRong(this->maMH)){
		textColor(12);
		gotoXY(24,7); cout<<"                                 ";
		gotoXY(24,7); cout<<"Nhap lai: ";
		textColor(15);
		nhapMa(this->maMH,size_ma);
	}
	xoaKhoangTrang(this->maMH);
	inHoaTatCa(this->maMH);
	textColor(10);
	gotoXY(24,7); cout<<"                                     ";
	gotoXY(24,7); cout<<"OK";
	textColor(15);
}
void CauHoi::nhapNoiDung(){
	textColor(15);
	gotoXY(24,9); cout<<"                                       ";
	gotoXY(24,9); cout<<"Nhap noi dung cau hoi: ";
	nhapNoiDungCH(this->noiDung,size_noidung);
	while(kiemTraRong(this->noiDung)){
		textColor(12);
		gotoXY(24,10); cout<<"                                       ";
		gotoXY(24,10); cout<<"Nhap lai: ";
		textColor(15);
		nhapNoiDungCH(this->noiDung,size_noidung);
	}
	xoaKhoangTrang(this->noiDung);
	inHoaTatCa(this->noiDung);
	textColor(10);
	gotoXY(24,10); cout<<"                                     ";
	gotoXY(24,10); cout<<"OK";
	textColor(15);
}
void CauHoi::nhapA(){
	textColor(15);
	gotoXY(24,12); cout<<"                                       ";
	gotoXY(24,12); cout<<"Nhap noi dung dap an A: ";
	nhapChuVaSo(this->A,size_dapan);
	while(kiemTraRong(this->A)){
		textColor(12);
		gotoXY(24,13); cout<<"                                       ";
		gotoXY(24,13); cout<<"Nhap lai: ";
		textColor(15);
		nhapChuVaSo(this->A,size_dapan);
	}
	xoaKhoangTrang(this->A);
	inHoaTatCa(this->A);
	textColor(10);
	gotoXY(24,13); cout<<"                                     ";
	gotoXY(24,13); cout<<"OK";
	textColor(15);
}
void CauHoi::nhapB(){
	textColor(15);
	gotoXY(24,15); cout<<"                                       ";
	gotoXY(24,15); cout<<"Nhap noi dung dap an B: ";
	nhapChuVaSo(this->B,size_dapan);
	while(kiemTraRong(this->B)){
		textColor(12);
		gotoXY(24,16); cout<<"                                       ";
		gotoXY(24,16); cout<<"Nhap lai: ";
		textColor(12);
		nhapChuVaSo(this->B,size_dapan);
	}
	xoaKhoangTrang(this->B);
	inHoaTatCa(this->B);
	textColor(10);
	gotoXY(24,16); cout<<"                                     ";
	gotoXY(24,16); cout<<"OK";
	textColor(15);
}
void CauHoi::nhapC(){
	textColor(15);
	gotoXY(24,18); cout<<"                                       ";
	gotoXY(24,18); cout<<"Nhap noi dung dap an C: ";
	nhapChuVaSo(this->C,size_dapan);
	while(kiemTraRong(this->C)){
		textColor(12);
		gotoXY(24,19); cout<<"                                       ";
		gotoXY(24,19); cout<<"Nhap lai: ";
		textColor(15);
		nhapChuVaSo(this->C,size_dapan);
	}
	xoaKhoangTrang(this->C);
	inHoaTatCa(this->C);
	textColor(10);
	gotoXY(24,19); cout<<"                                     ";
	gotoXY(24,19); cout<<"OK";
	textColor(15);
}
void CauHoi::nhapD(){
	textColor(15);
	gotoXY(24,21); cout<<"                                       ";
	gotoXY(24,21); cout<<"Nhap noi dung dap an D: ";
	nhapChuVaSo(this->D,size_dapan);
	while(kiemTraRong(this->D)){
		textColor(12);
		gotoXY(24,22); cout<<"                                       ";
		gotoXY(24,22); cout<<"Nhap lai: ";
		textColor(15);
		nhapChuVaSo(this->D,size_dapan);
	}
	xoaKhoangTrang(this->D);
	inHoaTatCa(this->D);
	textColor(10);
	gotoXY(24,22); cout<<"                                     ";
	gotoXY(24,22); cout<<"OK";
	textColor(15);
}
void CauHoi::nhapDapAnDung(){
	textColor(15);
	gotoXY(24,24); cout<<"                                       ";
	gotoXY(24,24); cout<<"Nhap dap an Dung: ";
	nhapDAD(this->dapAnDung,2);
	while(kiemTraRong(this->dapAnDung)){
		textColor(12);
		gotoXY(24,25); cout<<"                                       ";
		gotoXY(24,25); cout<<"Nhap lai: ";
		textColor(15);
		nhapDAD(this->dapAnDung,2);
	}
	xoaKhoangTrang(this->dapAnDung);
	inHoaTatCa(this->dapAnDung);
	textColor(10);
	gotoXY(24,25); cout<<"                                     ";
	gotoXY(24,25); cout<<"OK";
	textColor(15);
}
void CauHoi::inID(){
	cout<<"ID: "<<this->idCauhoi<<endl;
}
void CauHoi::inMaMH(){
	cout<<"Ma mon hoc: "<<this->maMH<<endl;
}
void CauHoi::inNoiDung(){
	gotoXY(24,8); cout<<"                                                       ";
	gotoXY(24,8); cout<<this->noiDung;
}
void CauHoi::inA(){
	gotoXY(25,11); cout<<"                                                  ";
	gotoXY(25,11); cout<<this->A; 
}
void CauHoi::inB(){
	gotoXY(25,12); cout<<"                                                  ";
	gotoXY(25,12); cout<<this->B;
}
void CauHoi::inC(){
	gotoXY(25,13); cout<<"                                                  ";
	gotoXY(25,13); cout<<this->C;
}
void CauHoi::inD(){
	gotoXY(25,14); cout<<"                                                  ";
	gotoXY(25,14); cout<<this->D;
}
void CauHoi::inDapAnDung(){
	cout<<"Dap an dung: "<<this->dapAnDung<<endl;
}
void CauHoi::inCauHoi(){
	this->inID();
	this->inMaMH();
	this->inNoiDung();
	this->inA();
	this->inB();
	this->inC();
	this->inD();
	this->inDapAnDung();
}
void CauHoi::setID(int id){
	this->idCauhoi = id;
}
void CauHoi::setMaMH(char ma[]){
	strcpy(this->maMH,ma);
}
void CauHoi::setNoiDung(char nd[]){
	strcpy(this->noiDung,nd);
}
void CauHoi::setA(char a[]){
	strcpy(this->A,a);
}
void CauHoi::setB(char b[]){
	strcpy(this->B,b);
}
void CauHoi::setC(char c[]){
	strcpy(this->C,c);
}
void CauHoi::setD(char d[]){
	strcpy(this->D,d);
}
void CauHoi::setDapAnDung(char dad[]){
	strcpy(this->dapAnDung,dad);
}
int CauHoi::getID(){
	return this->idCauhoi;
}
char* CauHoi::getMaMH(){
	return this->maMH;
}
char* CauHoi::getNoiDung(){
	return this->noiDung;
}
char* CauHoi::getA(){
	return this->A;
}
char* CauHoi::getB(){
	return this->B;
}
char* CauHoi::getC(){
	return this->C;
}
char* CauHoi::getD(){
	return this->D;
}
char* CauHoi::getDapAnDung(){
	return this->dapAnDung;
}
CauHoi* & CauHoi::getCauHoiTrai(){
	return this->cauHoiTrai;
}
CauHoi* & CauHoi::getCauHoiPhai(){
	return this->cauHoiPhai;
}
CauHoi* & CauHoi::getCauHoi(){
	CauHoi* tam = new CauHoi;
	tam->getID();
	tam->getMaMH();
	tam->getNoiDung();
	tam->getA();
	tam->getB();
	tam->getC();
	tam->getD();
	tam->getDapAnDung();
	return tam;
}
void CauHoi::setCauHoiTrai(CauHoi* cauhoitrai){
	cauhoitrai=this->cauHoiTrai;
}
void CauHoi::setCauHoiPhai(CauHoi* cauhoiphai){
	cauhoiphai=this->cauHoiPhai;
}

