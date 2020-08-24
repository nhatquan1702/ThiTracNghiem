#include "DSLop.h"

DSLop::DSLop(){
	this->sizeLop=0;
}
int DSLop::getSizeLop(){
	return this->sizeLop;
}
bool DSLop::trungMaLop(Lop *l){
	for(int i=0; i<sizeLop; i++){
		if(strcmp(l->getMaLop(),lop[i]->getMaLop())==0)
			return true;
	}
	return false;
}
void DSLop::dataIn(){
	this->sizeLop=0;
	fstream fileLop;
	fileLop.open("dsLop.txt", ios::in);
	if(fileLop.is_open()){ //.open tra ve true khi lien ket vs file nguoc lai tra ve false
		int i=0;
		char maLopTam[size_ma];
		char tenLopTam[size_tenlop];
		char nienKhoaTam[size_nienkhoa];
		if(kiemTraFileRong(fileLop))
			return;
		else{
			this->lop[i] = new Lop;
			 //int sang char co xuong dong bi loi dung fflush, ignore
			while(fileLop.getline(maLopTam,size_ma)){
				lop[i]->setMaLop(maLopTam);	
				fileLop.getline(tenLopTam,size_tenlop);
				lop[i]->setTenLop(tenLopTam);
				fileLop.getline(nienKhoaTam,size_nienkhoa);
				lop[i]->setNienKhoa(nienKhoaTam);
				i++;
				this->sizeLop++;
				if(i!=MAXLIST_LOP){
					lop[i]=new Lop;
				}
			}
		}
	}
	else{
		textColor(12);
		gotoXY(24,16); cout<<"                                 ";
		gotoXY(24,16); cout<<"Chua mo duoc file!!!";
		textColor(15);
	} 
	fileLop.close();
}
void DSLop::dataOut(){
	fstream fileLop;
	fileLop.open("dsLop.txt", ios::out);
	if(sizeLop!=MAXLIST_LOP){
		for(int i=0; i<sizeLop; i++){
			fileLop<<lop[i]->getMaLop()<<endl;
			fileLop<<lop[i]->getTenLop()<<endl;
			fileLop<<lop[i]->getNienKhoa()<<endl;
		}
	}
	textColor(15);
	gotoXY(24,16); cout<<"                                 ";
	gotoXY(24,16); cout<<"Saved";
	fileLop.close();
}
void DSLop::inDSLop(){
	if(sizeLop==0)cout<<"Danh sach rong!!!\n";
	for(int i=0; i<sizeLop; i++){
		cout<<"Lop thu "<<i+1<<": \n";
		lop[i]->inLop();
	}
}
void DSLop::themLop(){
	int vitri=this->sizeLop; char luachon=13;
	while(this->sizeLop<MAXLIST_LOP && luachon == 13){
		clrscr();
		veKhungThemLop(23,2,12,70,15);
		this->lop[vitri] = new Lop;
		this->lop[vitri]->nhapMaLop();
		while(trungMaLop(this->lop[vitri])){
			textColor(12);
			gotoXY(24,4); cout<<"                          ";
			gotoXY(24,4); cout<<"Da ton tai!Nhap lai: ";
			textColor(15);
			gotoXY(24,3); cout<<"                          ";
			this->lop[vitri]->nhapMaLop();
		}
		fstream fileLop;
		char tam[size_ma]="";
		strcat(tam,lop[vitri]->getMaLop());
		strcat(tam,".txt");
		fileLop.open(tam, ios::out);
		this->lop[vitri]->nhapTenLop();
		this->lop[vitri]->nhapNienKhoa();
		vitri++; this->sizeLop++;
		textColor(10);
		gotoXY(24,16); cout<<"                                 ";
		gotoXY(24,16); cout<< "Esc: Thoat- Enter tiep tuc them";
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
	if(this->sizeLop==MAXLIST_LOP){
		textColor(12);
		gotoXY(24,16); cout<<"                                 ";
		gotoXY(24,16); cout<<"Danh sach day! Khong the them!";
		textColor(10);
		gotoXY(24,17); cout<<"                                 ";
		gotoXY(24,17); cout<<"Nhan phim bat ky de thoat";
		textColor(15);
		_getch();
	}
}
int DSLop::timMaLop(char malop[]){
	for(int i = 0; i<sizeLop; i++){
		if(strcmp(malop,lop[i]->getMaLop())==0)
			return i;
	}
	return -1;
}
Lop* DSLop::lay1Lop(Lop* tam){
	for(int i = 0; i<sizeLop; i++){
		if(strcmp(tam->getMaLop(),lop[i]->getMaLop())==0)
			return tam;
	}
	return NULL;
}
int DSLop::timNienKhoa(char nk[]){
	for(int i=0; i<sizeLop; i++){
		if(strcmp(nk, lop[i]->getNienKhoa())==0)
			return i;
	}
	return -1;
}
void DSLop::in10(Lop* nlop[], int k){
	veKhungInLopTheoNK(5,2,22,110,15);
	for(int i=0, j=5; i<9, j<25; i++, j+=2 ){
		if(nlop[i+k]==NULL){
			gotoXY(7,j); cout<<"   ";
			gotoXY(7,j); cout<<i+k+1;  
			gotoXY(15,j); cout<<"                   "; 
			gotoXY(40,j); cout<<"                                     ";
			gotoXY(100,j); cout<<"             ";
		}
		else{
			gotoXY(7,j); cout<<"   ";
			gotoXY(7,j); cout<<i+k+1;  
			gotoXY(15,j); cout<<"                   "; 
			gotoXY(15,j); nlop[i+k]->inMaLop(); 
			gotoXY(40,j); cout<<"                                     ";
			gotoXY(40,j); nlop[i+k]->inTenLop();
			gotoXY(100,j); cout<<"             ";
			gotoXY(100,j); nlop[i+k]->inNienKhoa();	
		}
				
	}
}
void DSLop::layLoptheoNienKhoa(char nk[], Lop* LOP[], int &n){
	for(int i=0; i<sizeLop; i++){
		if(strcmp(nk, lop[i]->getNienKhoa())==0){
			LOP[n]=lop[i];
			n++;
		}
	}	
}
int DSLop::laySizeLopTheoNienKhoa(char nk[]){
	int dem=0;
	for(int i=0; i<sizeLop; i++){
		if(strcmp(nk, lop[i]->getNienKhoa())==0)
			dem++;
	}
	return dem;
}
void DSLop::inDSLopTheoNienKhoa(){
	while(sizeLop!=0){
		clrscr(); 
		veKhung(23,8,3,70,15);
		Lop* lopTam = new Lop;
		char luachon = _getch();
		do{
			textColor(10);
			textColor(15);
			lopTam->nhapNienKhoa();
			if(this->timNienKhoa(lopTam->getNienKhoa())==-1){
				textColor(12);
				gotoXY(24,10); cout<<"                                           ";
				gotoXY(24,10); cout<<"Khong tim thay! Nhap lai: ";
				textColor(15);
			}
		} while(this->timNienKhoa(lopTam->getNienKhoa())==-1);
		
		int n = laySizeLopTheoNienKhoa(lopTam->getNienKhoa());
		int tongTrang = ((n-1)/10)+1;
		int page=0; int soTrang = 1; 
		Lop* LOP[tongTrang*10];
		for(int i=n; i<tongTrang*10; i++)
			LOP[i]=NULL;
		int m=0;
		layLoptheoNienKhoa(lopTam->getNienKhoa(), LOP, m);
		showConsoleCursor(false);
		while(1){
			system("color 07");
			in10(LOP, page);
			textColor(10);
			gotoXY(6,25); cout<<"                                                     ";
			gotoXY(6,25); cout << "ESC: Thoat | A: Trang truoc | D: Trang sau";
			gotoXY(106,25); cout<<"                  ";
			gotoXY(106,25); cout <<"Trang "<<soTrang<<"/"<<tongTrang;
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
	if(sizeLop==0) {
		clrscr();
		textColor(10);
		cout<<"Danh sach rong!!!\n";
		cout<<"Nhan phim bat ky de thoat";
		textColor(15);
		_getch();
	}
}
bool DSLop::DSSVCoMaLop(char maL[]){
	for(int i=0; i<sizeLop; i++){
		if(strcmp(maL,lop[i]->getMaLop())==0){
			return true;
		}
	}
	return false;
}
bool DSLop::lopCoSV(SinhVien* sv){
	for(int i=0; i<sizeLop; i++){
		lop[i]->dsSV.dataIn(lop[i]->getMaLop());
		if(lop[i]->dsSV.trungMaSV(sv)){
			return true;
		}
	}
	return false;
}

void DSLop::duyetDSLop(Lop* nLop[]){
	for(int i=0; i<sizeLop; i++){
		nLop[i]=lop[i];
	}
}
void DSLop::xoaLop(){ 
	char luachon=13;
	while(luachon==13 && sizeLop!=0){
		clrscr();
		veKhungThemLop(23,2,12,70,15);
		Lop* lopTam = new Lop;
		int flag=0;
		while(flag<2){
			flag=0;
			gotoXY(24,3); cout<<"                                ";
			gotoXY(24,3); lopTam->nhapMaLop();
			if(this->timMaLop(lopTam->getMaLop())==-1){
				flag=0;
				textColor(12);
				gotoXY(24,4); cout<<"                                ";
				gotoXY(24,4); cout<<"Khong tim thay! Nhap lai: ";
				textColor(15);
				continue;
			}	
			else flag++;
			
//			Lop* lopOK = dsLop.lay1Lop(lopTam);
//			lopOK->dsSV.dataIn(lopOK->getMaLop());
//			if(!lopOK->dsSV.kiemTraDSRong()){
				
			DSSinhVien dssv;
			dssv.dataIn(lopTam->getMaLop());
			if(!dssv.kiemTraDSRong()){
				flag=0;
				textColor(12);
				gotoXY(24,4); cout<<"                                 ";
				gotoXY(24,4); cout<<"Lop da co sinh vien! Nhap lai: ";
				textColor(15);
			}	
			else flag++;
		}
		textColor(10);
		gotoXY(24,4); cout<<"                                          ";
		gotoXY(24,4); cout<<"OK";
		int i = this->timMaLop(lopTam->getMaLop());
		textColor(10);
		gotoXY(24,16); cout<<"                                 ";
		gotoXY(24,16); cout<<"Ban co chac muon xoa?";
		textColor(10);
		gotoXY(24,17); cout<<"                                 ";
		gotoXY(24,17); cout<<"Enter: Xoa- Esc: Thoat";
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
		Lop* tmp = lop[i];
		for(i; i<sizeLop-1; i++)
			lop[i]=lop[i+1];
		sizeLop--;
		delete tmp;
		delete lopTam;
		textColor(10);
		gotoXY(24,16); cout<<"                                  ";
		gotoXY(24,16); cout<<"Deleted";
		textColor(10);
		gotoXY(24,17); cout<<"                                  ";
		gotoXY(24,17); cout<<"Enter: Tiep tuc xoa- Esc: Thoat";
		textColor(15);
		while (1){
			char key = _getch();
			if (key == 13) {
				luachon = 13; break;
			}
			else if (key == 27) {
				luachon = 27; break;
			}
		}
	}
	if(sizeLop==0) {
		textColor(10);
		gotoXY(24,18); cout<<"                                       ";
		gotoXY(24,18); cout<<"Danh sach rong! Khong the xoa";
		textColor(15);
	}
}
void DSLop::hieuChinhLop(){
	int luachon=13; char key;
	Lop *lopTam = new Lop;
	while(sizeLop!=0 && luachon==13){
		clrscr();
		veKhungThemLop(23,2,12,70,15);
		do{
			gotoXY(24,3); cout<<"                             ";
			gotoXY(24,3); lopTam->nhapMaLop();
			if(timMaLop(lopTam->getMaLop())==-1){
				textColor(12);
				gotoXY(24,4); cout<<"                             ";
				gotoXY(24,4); cout<<"Khong tim thay!Nhap lai: ";
				textColor(15);
			}
		}while(timMaLop(lopTam->getMaLop())==-1);
		int i=timMaLop(lopTam->getMaLop());
		textColor(10);
		gotoXY(24,7); cout<<"                             ";
		gotoXY(24,7); cout<<"Nhan phim 1 sua ten lop";
		textColor(10);
		gotoXY(24,10); cout<<"                             ";
		gotoXY(24,10); cout<<"Nhan phim 2 sua nien khoa";
		textColor(15);
		while(1){
			key=_getch();
			if(key==49){	
				Lop *tmp = new Lop;
				tmp->nhapTenLop();
				lop[i]->setTenLop(tmp->getTenLop());
				break;
			}
			else if(key==50){
				Lop *tmp = new Lop;
				tmp->nhapNienKhoa();
				lop[i]->setNienKhoa(tmp->getNienKhoa());
				break;
			}
			
		}
		textColor(10);
		gotoXY(24,16); cout<<"                                       ";
		gotoXY(24,16); cout<<"Enter: Tiep tuc hieu chinh- ESC: Thoat";
		textColor(15);
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
	if (sizeLop==0) {
		textColor(12);
		gotoXY(24,16); cout<<"                                     ";
		gotoXY(24,16); cout<<"Danh sach rong! Khong the hieu chinh";
		textColor(15);
	}
}
