#include "Diem.h"

Diem::Diem(){
	strcpy(this->maMh,"");
	this->diem=0;
	this->diemNext=NULL;
}

void Diem::inMaMH(){
	cout<<"Ma mon hoc: "<<this->maMh<<endl;
} 
void Diem::inD(){
	cout<<"Diem: "<<this->diem<<endl;
}
void Diem::inDiem(){
	this->inMaMH();
	this->inD();
}
void Diem::setMaMH(char ma[]){
	strcpy(this->maMh,ma);
}
void Diem::setDiem(float d){
	this->diem=d;
}
char* Diem::getMaMH(){
	return this->maMh;
}
float Diem::getDiem(){
	return this->diem;
}
void Diem::setDiemNext(Diem* d){
	this->diemNext=d;
}
Diem* Diem::getDiemNext(){
	return this->diemNext;
}

