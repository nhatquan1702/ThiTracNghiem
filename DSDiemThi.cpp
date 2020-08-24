#include "DSDiemThi.h"
DSDiemThi::DSDiemThi(){
	this->sizeDiem=0;
	this->diemFirst=NULL;
}
void DSDiemThi::khoiTao(){
	this->sizeDiem=0;
	this->diemFirst=NULL;
}
void DSDiemThi::dataIn(char maSV[]){
	fstream fileDiem;
	char ten[size_ma]="";
	strcat(ten,"DIEM_");
	strcat(ten, maSV);
	strcat(ten,".txt");
	fileDiem.open(ten, ios::in);
	char maMonTam[size_ma];
	float dTam;
	if(fileDiem.is_open()){
		Diem* diemTam = new Diem();
		while(fileDiem.getline(maMonTam,size_ma)){
			diemTam->setMaMH(maMonTam);
			fileDiem>>dTam;
			fileDiem.ignore();
			diemTam->setDiem(dTam);
			if(diemFirst==NULL) diemFirst=diemTam;
			else{
				Diem* tam = diemFirst;
				while(tam->getDiemNext()!=NULL)
					tam=tam->getDiemNext();
					tam->setDiemNext(diemTam);
					diemTam->setDiemNext(NULL);
			}
			sizeDiem++;
			diemTam = new Diem();
		}
	}
	else{
		//cout<<"Danh sach rong!";
	}
	fileDiem.close();
}
void DSDiemThi::dataOut(char maSV[]){
	fstream fileDiem;
	char ten[size_ma]="";
	strcat(ten,"DIEM_");
	strcat(ten, maSV);
	strcat(ten,".txt");
	fileDiem.open(ten, ios::out);
	if(sizeDiem!=0){
		for(Diem* dTam = diemFirst; dTam!=NULL; dTam=dTam->getDiemNext()){
			fileDiem<<dTam->getMaMH()<<endl;
			fileDiem<<dTam->getDiem()<<endl;
		}
	}
	textColor(10);
	gotoXY(17,23); cout<<"                                                                                    ";
	gotoXY(17,23);cout<<"Saved";
	fileDiem.close();
}
void DSDiemThi::inDSDiem(char maSV[]){
	if(diemFirst==NULL) cout<<endl;
	else{
		for(Diem* dTam=diemFirst; dTam!=NULL; dTam=dTam->getDiemNext())
			dTam->inDiem(); cout<<endl;
	}
}
void DSDiemThi::themDiem(char maSV[], char maTam[], float dTam){
	Diem* d = new Diem();
	d->setMaMH(maTam);
	d->setDiem(dTam);
	d->setDiemNext(NULL);
	sizeDiem++;
	if(diemFirst==NULL) diemFirst=d;
	else{
		Diem* tam = diemFirst;
		while(tam->getDiemNext()!=NULL)
			tam=tam->getDiemNext();
			tam->setDiemNext(d);
			d->setDiemNext(NULL);
	}		
}
bool DSDiemThi::coMaMon(char maMon[]){
	for(Diem* dTam=diemFirst; dTam!=NULL; dTam=dTam->getDiemNext()){
		if(strcmp(maMon,dTam->getMaMH())==0)
			return true;
	}
	return false;		
}
bool DSDiemThi::diem1Mon(char maMon[]){
	for(Diem* dTam=diemFirst; dTam!=NULL; dTam=dTam->getDiemNext()){
		if(strcmp(maMon,dTam->getMaMH())==0)
			return true;
	}
	return false;
}
