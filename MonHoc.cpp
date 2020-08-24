#include "MonHoc.h"

MonHoc::MonHoc(){
	strcpy(this->maMH,"");
	strcpy(this->tenMH,"");
}
void MonHoc::nhapMaMH(){
	textColor(15);
	gotoXY(24,3); cout<<"                                               ";
	gotoXY(24,3); cout<<"Nhap ma mon hoc: ";
	textColor(15);
	nhapMa(this->maMH,size_ma);
	while(kiemTraRong(this->maMH)){
		textColor(12);
		gotoXY(24,4); cout<<"                                   ";
		gotoXY(24,4); cout<<"Nhap lai ma mon hoc: ";
		textColor(15);
		nhapMa(this->maMH,size_ma);
	}
	xoaKhoangTrang(this->maMH);
	inHoaTatCa(this->maMH);
	textColor(10);
	gotoXY(24,4); cout<<"                                    ";
	gotoXY(24,4); cout<<"OK";
	textColor(15);
}
void MonHoc::nhapTenMH(){
	textColor(15);
	gotoXY(24,6); cout<<"                                       ";
	gotoXY(24,6); cout<<"Nhap ten mon hoc: ";
	textColor(15);
	nhapChuVaSo(this->tenMH,size_tenMH);
	while(kiemTraRong(this->tenMH)){
		textColor(12);
		gotoXY(24,7); cout<<"                                       ";
		gotoXY(24,7); cout<<"Nhap lai ten mon hoc: ";
		textColor(15);
		nhapChuVaSo(this->tenMH,size_tenMH);
		textColor(15);
	}
	xoaKhoangTrang(this->tenMH);
	inHoaTatCa(this->tenMH);
	textColor(10);
	gotoXY(24,7); cout<<"                                        ";
	gotoXY(24,7); cout<<"OK";
	textColor(15);
}
void MonHoc::inMaMH(){
	cout<<"Ma mon hoc: "<<this->maMH<<endl;
}
void MonHoc::inTenMH(){
	cout<<"Ten mon hoc: "<<this->tenMH<<endl;
}
void MonHoc::inMonHoc(){
	this->inMaMH();
	this->inTenMH();
}

void MonHoc::setMaMH(char ma[]){
	strcpy(this->maMH,ma);
}
void MonHoc::settenMH(char ten[]){
	strcpy(this->tenMH,ten);
}
char* MonHoc::getMaMH(){
	return this->maMH;
}
char* MonHoc::getTenMH(){
	return this->tenMH;
}
