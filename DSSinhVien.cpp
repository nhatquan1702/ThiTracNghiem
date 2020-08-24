#include "DSSinhVien.h"
#include "DSLop.h"
#include "DSDiemThi.h"
#include "DSMonHoc.h"
DSSinhVien::DSSinhVien(){
	this->sizeSV=0;
	this->svFirst=NULL;
}
void DSSinhVien::khoiTaoDSSV(){
	this->sizeSV=0;
	this->svFirst=NULL;
}
bool DSSinhVien::kiemTraDSRong(){
	if(svFirst==NULL) return true;
	else return false;
}
bool DSSinhVien::trungMaSV(SinhVien* sv)
{
	SinhVien* svTam = svFirst;
		for(svTam; svTam!=NULL; svTam=svTam->getSvNext()){
			if(strcmp(svTam->getMaSV(),sv->getMaSV())==0)
				return true;
		}
	return false;
}
void DSSinhVien::dataIn(char maLop[]){
	fstream fileSV;
	char tam[size_ma]="";
	strcat(tam,maLop);
	strcat(tam,".txt");
	fileSV.open(tam, ios::in);
	char maTam[size_ma];
	char hoTam[size_ho];
	char tenTam[size_ten];
	int pTam; Phai phaiTam;
	char passTam[size_pass];
	if(fileSV.is_open()) {
		SinhVien* svTam = new SinhVien();
		while(fileSV.getline(maTam,size_ma)){
			svTam->setMaSV(maTam);
			fileSV.getline(hoTam,size_ho);
			svTam->setHo(hoTam);
			fileSV.getline(tenTam,size_ten);
			svTam->setTen(tenTam);
			fileSV>>pTam;
			fileSV.ignore();
			if(pTam==0) phaiTam=nam;
			else if(pTam==1) phaiTam=nu;
			svTam->setPhai(phaiTam);
			fileSV.getline(passTam,size_pass);
			svTam->setPass(passTam);
			if(svFirst==NULL) svFirst=svTam;
			else{
				SinhVien* tmp = svFirst;
				while(tmp->getSvNext()!=NULL)
				tmp=tmp->getSvNext();
				tmp->setSvNext(svTam);
				svTam->setSvNext(NULL);
			}
			sizeSV++;
			svTam=new SinhVien();
		}
	}
//	else{
//		textColor(10);
//		gotoXY(24,21); cout<<"                                   ";
//		gotoXY(24,21); 
//	}
	fileSV.close();
}
void DSSinhVien::dataOut(char maLop[]){
	fstream fileSV;
	char tam[size_ma]="";
	strcat(tam,maLop);
	strcat(tam,".txt");
	fileSV.open(tam, ios::out);
	if(sizeSV!=0){
		for(SinhVien* svTam = svFirst; svTam!=NULL; svTam=svTam->getSvNext()){
			fileSV<<svTam->getMaSV()<<endl;
			fileSV<<svTam->getHo()<<endl;
			fileSV<<svTam->getTen()<<endl;
			fileSV<<svTam->getPhai()<<endl;
			fileSV<<svTam->getPass()<<endl;
		}
	}
	textColor(10);
	gotoXY(24,18); cout<<"                                   ";
	gotoXY(24,18); cout<<"Saved";
	fileSV.close();
}
void DSSinhVien::inDSSinhVien(){
	if(svFirst==NULL) cout<<"Danh sach rong!!!\n";
	else{
		for(SinhVien* svTam=svFirst; svTam!=NULL; svTam=svTam->getSvNext())
			svTam->inSinhVien();
	}
}
void DSSinhVien::themSinhVien(){
	int luachon=13;
	while(luachon==13){
		clrscr();
		veKhungThemSV(23,2,15,70,15);
		SinhVien *svMoi = new SinhVien();
		svMoi->nhapMaSV();
		DSLop dsLop;
		dsLop.dataIn();
		while(dsLop.lopCoSV(svMoi)){
			textColor(12);
			gotoXY(24,4); cout<<"                                   ";
			gotoXY(24,4); cout<<"Da ton tai! Nhap lai: ";
			textColor(15);
			gotoXY(24,3); cout<<"                                   ";
			svMoi->nhapMaSV();
		}
		svMoi->nhapHo();
		svMoi->nhapTen();
		svMoi->nhapPhai();
		svMoi->nhapPassword();
		
		svMoi->setSvNext(NULL);
		sizeSV++;
		if(svFirst==NULL) svFirst=svMoi;
		else{
			SinhVien *svTam = svFirst;
			while(svTam->getSvNext()!=NULL)
			svTam = svTam->getSvNext();
			svTam->setSvNext(svMoi);
			svMoi->setSvNext(NULL);
		}
		textColor(10);
		gotoXY(24,18); cout<<"                                   ";
		gotoXY(24,18); cout << "Esc: Thoat- Enter: tiep tuc them";
		textColor(15);
		while (1) {
			if (_kbhit()) {
				luachon = _getch();
				if (luachon == 27) {
					cout << endl; break;
				}
				else if (luachon == 13) {
					cout << endl; break;
				}
			}
		}
	}
}
bool DSSinhVien::coMaSV(char ma[]){
	SinhVien* svTam = svFirst;
		for(svTam; svTam!=NULL; svTam=svTam->getSvNext()){
			if(strcmp(svTam->getMaSV(),ma)==0)
				return true;
		}
	return false;
}
SinhVien* DSSinhVien::coSV(char ma[]){
	SinhVien* svTam = svFirst;
		for(svTam; svTam!=NULL; svTam=svTam->getSvNext()){
			if(strcmp(svTam->getMaSV(),ma)==0)
				return svTam;
		}
	return NULL;
}
bool DSSinhVien::coTK(char ma[], char pass[]){
	SinhVien* svTam = svFirst;
		for(svTam; svTam!=NULL; svTam=svTam->getSvNext()){
			if(strcmp(svTam->getMaSV(),ma)==0 && strcmp(svTam->getPass(),pass)==0)
				return true;
		}
	return false;
}
void DSSinhVien::svVaoMang(SinhVien* SV[], int &n){
	SinhVien* svTam = svFirst;
	for(svTam; svTam!=NULL; svTam=svTam->getSvNext()){
		SV[n]=svTam;
		n++;
	}
}
void DSSinhVien::in10SV(SinhVien* nSV[], Diem* nD[], int k, char maLop[], char maMon[]){
	veKhungInBangDiem1MonCua1Lop(7,2,24,105,15,maLop, maMon);
	for(int i=0, j=7; i<9, j<27; i++, j+=2 ){
		if(nSV[i+k]==NULL){
			gotoXY(9,j); cout<<"   ";
			gotoXY(9,j); cout<<i+k+1;  
			gotoXY(17,j); cout<<"                   "; 
			gotoXY(42,j); cout<<"                                     ";
			gotoXY(101,j); cout<<"        ";
		}
		else{
			gotoXY(9,j); cout<<"   ";
			gotoXY(9,j); cout<<i+k+1;  
			gotoXY(17,j); cout<<"                   "; 
			gotoXY(17,j); nSV[i+k]->inMaSV();
			gotoXY(42,j); cout<<"                                     ";
			gotoXY(42,j); nSV[i+k]->inHoTen();
			if(nSV[i+k]->dsDiemDaThi.diem1Mon(maMon)==-1){
				gotoXY(101,j); cout<<"         ";
				gotoXY(101,j); cout<<"chua thi";
			}
			else{
				gotoXY(101,j); cout<<"         ";
				gotoXY(101,j); cout<<nSV[i+k]->dsDiemDaThi.diem1Mon(maMon);	
			}	
		}			
	}
}
void DSSinhVien::inBangDiem1MonCua1Lop(){
	while(1){
		clrscr(); 
		veKhung(23,2,3,70,15);
		Lop* lopTam = new Lop;
		gotoXY(24,3); cout<<"                                    ";
		gotoXY(24,3); lopTam->nhapMaLop();
		DSLop dsLop;
		dsLop.dataIn();
		while(!dsLop.DSSVCoMaLop(lopTam->getMaLop())){
			textColor(12);
			gotoXY(24,4); cout<<"                                       ";
			gotoXY(24,4); cout<<"Khong ton tai ma lop! Nhap lai: ";
			gotoXY(24,3); cout<<"                                       ";
			textColor(15);
			gotoXY(24,3); lopTam->nhapMaLop();
		}
		Lop* lopOK = dsLop.lay1Lop(lopTam);
		textColor(10);
		gotoXY(24,4); cout<<"                                        ";
		gotoXY(24,4); cout<<"OK!";
		textColor(15);
		MonHoc* mhTam = new MonHoc;
		gotoXY(24,4); cout<<"                                        ";
		gotoXY(24,3); cout<<"                                         ";
		gotoXY(24,3); mhTam->nhapMaMH();
		DSMonHoc dsmh;
		dsmh.dataIn();
		while(!dsmh.coMaMonHoc(mhTam->getMaMH())){
			textColor(12);
			gotoXY(24,4); cout<<"                                       ";
			gotoXY(24,4); cout<<"Khong ton tai mon hoc! Nhap lai: ";
			gotoXY(24,3); cout<<"                                       ";
			textColor(15);
			gotoXY(24,3); mhTam->nhapMaMH();
		}
		MonHoc* mhOK = dsmh.lay1Mon(mhTam);
		textColor(10);
		gotoXY(24,4); cout<<"                                        ";
		gotoXY(24,4); cout<<"OK!";
		textColor(15);
		lopOK->dsSV.dataIn(lopOK->getMaLop());
		int tongTrang = ((sizeSV-1)/10)+1;
		int page=0; int soTrang = 1; 
		SinhVien* SV[tongTrang*10];
		Diem* D[tongTrang*10];
		for(int i=sizeSV; i<tongTrang*10; i++)
			SV[i]=NULL;
		int m=0; int t=0;
		lopOK->dsSV.svVaoMang(SV, m);
		for(int i=0; i<m; i++){
			SV[i]->dsDiemDaThi.dataIn(SV[i]->getMaSV());
		}
		showConsoleCursor(false);
		while(1){
			system("color 07");
			in10SV(SV,D, page, lopOK->getMaLop(), mhOK->getMaMH());
			textColor(10);
			gotoXY(8,27); cout<<"                                                     ";
			gotoXY(8,27); cout << "ESC: Thoat | A: Trang truoc | D: Trang sau";
			gotoXY(103,27); cout<<"                  ";
			gotoXY(103,27); cout <<"Trang "<<soTrang<<"/"<<tongTrang;
			textColor(15);
			
			char key=getch();
			if (key == 97 || key == 75){
				if (page == 0)
					_getch();
				else{
					page=page-10;
					soTrang--;
				} 
			}
			else if (key == 100 || key == 77){
				if (page == tongTrang*10-10){
					_getch();
				}
				else{
					page=page+10;
					soTrang++;
				}
			}
			else if (key == 27) {
				clrscr();
				break;
			}
		}
		clrscr();
		gotoXY(0,0); cout<<"                         ";
		gotoXY(0,0); cout<<"NHAN PHIM BAT KY";
		_getch();
		gotoXY(0,0); cout<<"                         ";
		break;
	}
}
