#include "Lop.h"

Lop::Lop(){
	strcpy(this->maLop,"");
	strcpy(this->tenLop,"");
	strcpy(this->nienKhoa,"");
	this->dsSV.khoiTaoDSSV();
}
void Lop::nhapMaLop(){
	textColor(15);
	gotoXY(24,3); cout<<"                                       ";
	gotoXY(24,3); cout<<"Nhap ma lop: ";
	textColor(15);
	nhapMa(this->maLop,size_ma);
	while(kiemTraRong(this->maLop)){
		textColor(12);
		gotoXY(24,4); cout<<"                              ";
		gotoXY(24,4); cout<<"Nhap lai ma lop: ";
		textColor(15);
		nhapMa(this->maLop,size_ma);
	}
	xoaKhoangTrang(this->maLop);
	inHoaTatCa(this->maLop);
	textColor(10);
	gotoXY(24,4); cout<<"                                       ";
	gotoXY(24,4); cout<<"OK";
	textColor(15);
}
void Lop::nhapTenLop(){
	textColor(15);
	gotoXY(24,6); cout<<"                                      ";
	gotoXY(24,6); cout<<"Nhap ten lop: ";
	nhapChuVaSo(this->tenLop,size_tenlop);
	while(kiemTraRong(this->tenLop)){
		textColor(12);
		gotoXY(24,7); cout<<"                                      ";
		gotoXY(24,7); cout<<"Khong de trong!Nhap lai: ";
		textColor(15);
		nhapChuVaSo(this->tenLop,size_tenlop);
	}
	xoaKhoangTrang(this->tenLop);
	inHoaTatCa(this->tenLop);
	textColor(10);
	gotoXY(24,7); cout<<"                                     ";
	gotoXY(24,7); cout<<"OK";
	textColor(15);
}
void Lop::nhapNienKhoa(){
	textColor(15);
	gotoXY(24,9); cout<<"                                        ";
	gotoXY(24,9); cout<<"Nhap nien khoa: ";
	nhapNK(this->nienKhoa,size_nienkhoa);
	while(kiemTraRong(this->nienKhoa)){
		textColor(12);
		gotoXY(24,10); cout<<"                                   ";
		gotoXY(24,10); cout<<"Khong de trong! Nhap lai: ";
		textColor(15);
		nhapNK(this->nienKhoa,size_nienkhoa);
	}
	xoaKhoangTrang(this->nienKhoa);
	textColor(10);
	gotoXY(24,10); cout<<"                                     ";
	gotoXY(24,10); cout<<"OK";
	textColor(15);
}
void Lop::inMaLop(){
	cout<<this->maLop;
}
void Lop::inTenLop(){
	cout<<this->tenLop;
}
void Lop::inNienKhoa(){
	cout<<this->nienKhoa;
}
void Lop::inLop(){
	cout<<setw(20)<<left;this->inMaLop();
	cout<<setw(20)<<left;this->inTenLop();
	this->inNienKhoa();cout<<setw(10)<<right; cout<<"\n";
}
void Lop::setMaLop(char ma[]){
	strcpy(this->maLop,ma);
}
void Lop::setTenLop(char ten[]){
	strcpy(this->tenLop,ten);
}
void Lop::setNienKhoa(char nk[]){
	strcpy(this->nienKhoa,nk);
}
char* Lop::getMaLop(){
	return this->maLop;
}
char* Lop::getTenLop(){
	return this->tenLop;
}
char* Lop::getNienKhoa(){
	return this->nienKhoa;
}
