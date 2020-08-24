#include "DSMonHoc.h"
#include "DSCauHoi.h"

DSMonHoc::DSMonHoc(){
	this->sizeMH=0;
}
int DSMonHoc::getSizeMH(){
	return this->sizeMH;
}
bool DSMonHoc::trungMaMH(MonHoc *mh){
	for(int i=0; i<sizeMH ; i++){
		if(strcmp(mh->getMaMH(),this->monhoc[i]->getMaMH())==0)
			return true;
	}
	return false;
}
void DSMonHoc::dataIn(){
	fstream filemh;
	filemh.open("dsMonHoc.txt", ios::in);
	if(filemh.is_open()){
		int i=0;
		char maTam[size_ma];
		char tenTam[size_tenMH];
		if(kiemTraFileRong(filemh)) return;
		else{
			this->monhoc[i] = new MonHoc;
			while(filemh.getline(maTam,size_ma)){
				monhoc[i]->setMaMH(maTam);
				filemh.getline(tenTam,size_tenMH);
				monhoc[i]->settenMH(tenTam);
				i++; sizeMH++;
				if(i!=MAXLIST_MH)
					monhoc[i] = new MonHoc;
			}
		}
	}
	else {
		textColor(12);
		gotoXY(24,9); cout<< "                                             ";
		gotoXY(24,9); cout<<"Chua mo duoc file!";
		textColor(15);
	}
	filemh.close();
}
void DSMonHoc::themMH(){
	tiep:
	char luachon=13;
	while(sizeMH<MAXLIST_MH && luachon==13){
		clrscr();
		veKhungThemMH(23,2,9,70,15);
		MonHoc* mh = new MonHoc;
		mh->nhapMaMH();
		while(trungMaMH(mh)){
			textColor(12);
			gotoXY(24,4); cout<<"                          ";
			gotoXY(24,4); cout<<"Da ton tai! Nhap lai: ";
			textColor(15);
			gotoXY(24,3); cout<<"                          ";
			mh->nhapMaMH();
		}
		mh->nhapTenMH();
		int j, k;
		for(j=0; j<sizeMH && strcmp(monhoc[j]->getMaMH(),mh->getMaMH())<0;j++);
		for(k=sizeMH-1; k>=j ; k--)
			monhoc[k+1]=monhoc[k];
		monhoc[j] = new MonHoc;
		monhoc[j]->setMaMH(mh->getMaMH());
		monhoc[j]->settenMH(mh->getTenMH());
		sizeMH++;
		textColor(10);
		gotoXY(24,9); cout<<"                                 ";
		gotoXY(24,9); cout<< "Esc: Thoat- Enter tiep tuc them";
		textColor(15);
		while (1) {
			if (_kbhit()) {
				luachon = _getch();
				if (luachon == 27) {
					cout << endl; break;
				}
				else if (luachon == 13) {
					cout << endl; goto tiep;
				}
			}
		}
	}
	if(sizeMH==MAXLIST_MH){
		textColor(12);
		gotoXY(24,9); cout<< "                                             ";
		gotoXY(24,9);cout<<"Danh sach day! Khong the them!";
		gotoXY(24,10); cout<< "                                             ";
		gotoXY(24,10);cout<<"Nhan phim bat ky de thoat\n";
		textColor(15);
		_getch();
	}
}
void DSMonHoc::dataOut(){
	fstream filemh;
	filemh.open("dsMonHoc.txt", ios::out);
	if(sizeMH!=MAXLIST_MH){
		for(int i=0; i<sizeMH; i++){
			filemh<<monhoc[i]->getMaMH()<<endl;
			filemh<<monhoc[i]->getTenMH()<<endl;
		}
	}
	gotoXY(24,15); cout<< "                                             ";
	gotoXY(24,15); cout<<"Saved";
	filemh.close();
}
void DSMonHoc::inDSMH(){
 	if(sizeMH==0) cout<<"Danh sach rong!!!\n";
 	for(int i=0; i<sizeMH; i++){
 		cout<<"Mon hoc thu "<<i+1<<": \n";
 		monhoc[i]->inMonHoc();
	 }
}
int DSMonHoc::timMonHoc(char ma[]){
	for(int i=0; i<sizeMH; i++){
		if(strcmp(ma,monhoc[i]->getMaMH())==0)
			return i;
	}
	return -1;
}
MonHoc* DSMonHoc::lay1Mon(MonHoc* mhTam){
	for(int i=0; i<sizeMH; i++){
		if(strcmp(mhTam->getMaMH(),monhoc[i]->getMaMH())==0)
			return mhTam;
	}
	return NULL;
}
bool DSMonHoc::coMaMonHoc(char ma[]){
	for(int i=0; i<sizeMH; i++){
		if(strcmp(ma,monhoc[i]->getMaMH())==0)
			return true;
	}
	return false;
}
bool DSMonHoc::monHocCoCauHoi(char maTam[]){
	DSCauHoi dsch;
	dsch.dataIn();
	int n = dsch.getSizeCH();
	int m=0;
	CauHoi* CH[n];
	dsch.cayVaoMang(dsch.getCauHoiGoc(), CH, maTam, m);
	if(m==0)
		return false;
	else return true;
}
void DSMonHoc::xoaMonHoc(){
	int luachon=13;
	while(sizeMH!=0 && luachon==13){
		clrscr();
		veKhung(23,2,3,70,15);
		MonHoc *mhTam = new MonHoc;
		do{
			gotoXY(24,3); cout<< "                                          ";
			gotoXY(24,3); mhTam->nhapMaMH();
			if(timMonHoc(mhTam->getMaMH())==-1){
				textColor(12);
				gotoXY(24,4); cout<< "                                    ";
				gotoXY(24,4); cout<<"Khong tim thay! Nhap lai: ";
				textColor(15);
				gotoXY(24,3); cout<< "                                    ";
			}	
		} while(timMonHoc(mhTam->getMaMH())==-1);
		if(this->monHocCoCauHoi(mhTam->getMaMH())){
			clrscr();
			textColor(12);
			gotoXY(0,0); cout<< "                                    ";
			gotoXY(0,0); cout<<"Mon hoc nay da co cau hoi!";
			textColor(15);
			gotoXY(0,1); cout<< "Nhan phim bat ky de thoat";
			_getch();
			break;
		}
		else{
			textColor(10);
			gotoXY(24,13); cout<< "                                             ";
			gotoXY(24,13); cout<<"Ban co chac muon xoa?";
			textColor(10);
			gotoXY(24,14); cout<< "                                             ";
			gotoXY(24,14); cout<<"Enter: Xoa- Esc: Thoat";
			textColor(15);
			while (1) {
				char key = _getch();
				if (key == 13) {
					luachon = 13; break;
				}
				else if (key == 27) {
					luachon = 27; return;
				}
			}
			int i = timMonHoc(mhTam->getMaMH());
			MonHoc* tmp = monhoc[i];
			for(i; i<sizeMH-1; i++)
				monhoc[i]=monhoc[i+1];
			sizeMH--;
			delete mhTam; delete tmp;
			textColor(10);
			gotoXY(24,13); cout<<"                                        ";
			gotoXY(24,13); cout<<"Deleted";
		}
		textColor(10);
		gotoXY(24,14); cout<<"                                        ";
		gotoXY(24,14); cout<<"Enter: Tiep tuc xoa- Esc: Thoat";
		textColor(15);
		while (1) {
			char key = _getch();
			if (key == 13) {
				luachon = 13; break;
			}
			else if (key == 27) {
				luachon = 27; break;
			}
		}
	}
	if(sizeMH==0) {
		textColor(12);
		gotoXY(24,13); cout<<"                                        ";
		gotoXY(24,13);cout<<"Danh sach rong! Khong the xoa";
		gotoXY(24,14); cout<<"                                        ";
		gotoXY(24,14); cout<<"Nhan phim bat ky de thoat";
		textColor(15);
		_getch();
	}
}
void DSMonHoc::hieuChinhMH(){
	int luachon=13; char key;
	MonHoc *mhTam = new MonHoc;
	while(sizeMH!=0 && luachon==13){
		clrscr();
		veKhungThemMH(23,2,9,70,15);
		do{
			gotoXY(24,3); cout<<"                          ";
			mhTam->nhapMaMH();
			if(timMonHoc(mhTam->getMaMH())==-1){
				textColor(12);
				gotoXY(24,4); cout<< "                                     ";
				gotoXY(24,4); cout<<"Khong tim thay! Nhap lai: ";
				textColor(15);
				gotoXY(24,3); cout<< "                                     ";
			}	
		} while(timMonHoc(mhTam->getMaMH())==-1);
		int i = timMonHoc(mhTam->getMaMH());
		textColor(10);
		gotoXY(24,7); cout<<"                                     ";
		gotoXY(24,7); cout<<"Nhan phim 1 chinh sua ten mon hoc";
		while (1) {
			key = _getch();
		if(key==49){
				MonHoc* tmp = new MonHoc;
				textColor(10);
				gotoXY(24,6); cout<<"                                    ";
				gotoXY(24,6); tmp->nhapTenMH();
				textColor(15);
				monhoc[i]->settenMH(tmp->getTenMH());
				break;
			}
		}
		textColor(10);
		gotoXY(24,13); cout<<"                                            ";
		gotoXY(24,13); cout << "Enter: Tiep tuc hieu chinh- ESC: Thoat";
		textColor(10);
		while (1) {
			key = _getch();
			if (key == 13) {
				luachon = 13; break;
			}
			else if (key == 27) {
				luachon = 27; break;
			}
		}
	}
	if (sizeMH==0) {
		textColor(12);
		gotoXY(24,9); cout<<"                                           ";
		gotoXY(24,9); cout<<"Danh sach rong! Khong the hieu chinh";
		textColor(15);
	}
}
