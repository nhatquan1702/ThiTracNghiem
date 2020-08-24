#include "ChiTietDeThi.h"
#include "DSCauHoi.h"
#include "DSMonHoc.h"
#include "DSDiemThi.h"
#include "CauHoi.h"
#include "DSLop.h"
ChiTietDeThi::ChiTietDeThi(){
}
void ChiTietDeThi::dataOut(char maSV[], char maMon[], int soCau, int soPhut, int dsID[], string* cauTraLoi){
	fstream fileCT;
	char tenFile[50]="CTDT_";
	strcat(tenFile,maMon);
	strcat(tenFile,"_");
	strcat(tenFile,maSV);
	strcat(tenFile,".txt");
	textColor(10);
	fileCT.open(tenFile, ios::out);
	if(fileCT.is_open()){
		fileCT<<soCau<<endl;
		fileCT<<soPhut<<endl;
		for(int i=0; i<soCau; i++){
			fileCT<<dsID[i]<<endl;
		}
		for(int i=0; i<soCau; i++){
			fileCT<<cauTraLoi[i]<<endl;
		}
	}
	else{
		cout<<"Chua mo file!";
	}
	fileCT.close();
}

void startTimerJob(int time_in_second){
	int a,b,c;
	gotoXY(16,4); cout<<"So phut: ";
	cin>>a;
	b=a*60;
	c=59;
	while(time_in_second>0){
		textColor(14);
		gotoXY(86,3); cout<<"Thoi gian con lai:";
		gotoXY(92,4); cout<<a-1<<":"<<c<<endl;
		//sleep(1);
		b--; c--;
		if(b%60==0){
			a--; c=59;
		}	
		time_in_second--;
	}
	gotoXY(86,4); cout<<"                ";
	gotoXY(86,4); cout<<"Het thoi gian!"<<endl;
	textColor(15);
}
void startTimer(int n){
	thread timer(startTimerJob,n);
	timer.join();
}
void ChiTietDeThi::getCauHoi(DSCauHoi ds){
	ds.dataIn();
	
}
void ChiTietDeThi::svThi(SinhVien* svThi){
	while(1){
		char maMonTam[size_ma];
		int time=0; int soCau=0; int page=0;
		DSCauHoi ds;
		ds.dataIn();
		int n=ds.getSizeCH(); int m=0; // n la tat ca cau hoi, m la so cau cua mon hoc co ma x
		
		clrscr();
		veKhungThemMH(23,2,9,70,15);
		textColor(15);
		gotoXY(24,3); cout<<"                            ";
		gotoXY(24,3); cout<<"Nhap ma mon hoc: ";
		nhapMa(maMonTam,size_ma);
		inHoaTatCa(maMonTam);
		svThi->dsDiemDaThi.dataIn(svThi->getMaSV());
		while(svThi->dsDiemDaThi.coMaMon(maMonTam)){
			textColor(12); 
			gotoXY(24,12); cout<<"                                                ";
			gotoXY(24,12); cout<<"Mon hoc nay da thi! Nhap lai ";
			textColor(15);
			gotoXY(24,3); cout<<"                            ";
			gotoXY(24,3); cout<<"Nhap ma mon hoc: ";
			nhapMa(maMonTam,size_ma);
			inHoaTatCa(maMonTam);
		}
		
		textColor(10);
		gotoXY(24,12); cout<<"                                                ";
		gotoXY(24,12); cout<<"OK";
		textColor(15);
		CauHoi* CH[n];
		ds.cayVaoMang(ds.getCauHoiGoc(),CH, maMonTam, m);
		int a=Min(m,n);
		if(a<=0){
			clrscr();
			textColor(12);
			cout<<"Mon hoc nay khong ton tai hoac chua co cau hoi thi!\n";
			cout<<"Nhan phim bat ky de thoat\n";
			_getch();
			break;
		}
		gotoXY(24,6); cout<<"                            ";
		gotoXY(24,6); cout<<"Nhap so cau hoi: ";
		nhapSoInt(soCau,4);
		while(soCau>a || soCau<=0){
			textColor(12); 
			gotoXY(24,12); cout<<"                                                ";
			gotoXY(24,12); cout<<"So cau hoi lon hon [0] va khong qua "<<"["<<a<<"]"; cout<<" Nhap lai";
			textColor(15);
			gotoXY(24,6); cout<<"                            ";
			gotoXY(24,6); cout<<"Nhap so cau hoi: ";
			nhapSoInt(soCau,4);
		}
		gotoXY(24,12); cout<<"                                                ";
		gotoXY(24,12); cout<<"OK";
		int b[a];
		for(int i=0; i<a; i++)
			b[i]=i;
		tronMang(b, a);
		gotoXY(24,9); cout<<"                            ";
		gotoXY(24,9); cout<<"Nhap so phut thi: ";
		nhapSoInt(time,4);
		
		
		int hh=0,mm=0,ss=0;
		hh = time/60;
		mm = time-hh*60;
		thread clock;
		clrscr();
		clock = thread(printClock,hh,mm,ss);
		string* cauTL=new string[soCau];
		for(int i=0; i<soCau; i++)
			cauTL[i]="X";
			
		stop_time = 1;
		int vitrix = 17; int vitriy = 10; int mau = 15;
		string str[10];
		int vitri = 1;
		showConsoleCursor(false);
		while (stop_time!=0 ) {
				system("color 07");
				for (int i = 1; i <= 4; i++) {
					if (i == vitri) mau = 160;
					else mau = 15;
					veKhungThi(15,2,20,90,15);
					
					str[1] = "[ A ]: "; gotoXY(25,11); CH[b[page]]->inA();
					str[2] = "[ B ]: "; gotoXY(25,12); CH[b[page]]->inB();
					str[3] = "[ C ]: "; gotoXY(25,13); CH[b[page]]->inC();
					str[4] = "[ D ]: "; gotoXY(25,14); CH[b[page]]->inD();
					gotoXY(16,3); cout<<"THI TRAC NGHIEM MON: "<<maMonTam;
					gotoXY(64,3); cout<<"TONG SO CAU HOI: "<<soCau;
					gotoXY(16,4); cout<<"MSSV: "<<svThi->getMaSV()<<"- "<<svThi->getHo()<<" "<<svThi->getTen();
					gotoXY(86,3); cout<<"Thoi gian con lai:";
					gotoXY(17,8); cout<<"CAU "<<page+1<<": "; CH[b[page]]->inNoiDung();
					textColor(10);
					gotoXY(87,7); cout<<"CAU "<<page+1<<": ";cout<<"Chon "; cout<<cauTL[page];
					textColor(15);
					gotoXY(17,21); cout<<"      ESC: Nop Bai | A: Cau truoc | D: Cau sau | W: Len | S: Xuong | ENTER: Chon";
					ThanhMenu(vitrix, vitriy + i, mau, str[i]);
				}
				char key = _getch();
				if (key == 119 || key==72) {
					if (vitri == 1) {
						vitri = 4;
					}
					else vitri--;
				}
				else if (key == 115 || key==80) {
					if (vitri == 4)vitri = 1;
					else vitri++;
				}
				else if (key == 13) {
					if (vitri == 1) {
						system("color 07");
						cauTL[page]="A";
						textColor(15);
//						char luachon = _getch();
//						if (luachon == 13) {
							gotoXY(87,9);cout<<"         ";
							textColor(10);
							gotoXY(87,9);cout<<"Saved!";
//						}
						textColor(15); 
					}
					else if (vitri == 2) {
						system("color 07");
//						gotoXY(87,7); cout<<"                  ";
//						textColor(10);
//						gotoXY(87,7); cout<<"CAU "<<page+1<<": ";cout<<"Chon B";
						cauTL[page]="B";
						char luachon = _getch();
						if (luachon == 13) {
							gotoXY(87,9);cout<<"         ";
							textColor(10);
							gotoXY(87,9);cout<<"Saved!";
						}
						textColor(15); 
					}
					else if (vitri == 3) {
						system("color 07");
//						gotoXY(87,7); cout<<"                  ";
//						textColor(10);
//						gotoXY(87,7); cout<<"CAU "<<page+1<<": ";cout<<"Chon C";
						cauTL[page]="C";
						char luachon = _getch();
						if (luachon == 13) {
							gotoXY(87,9);cout<<"         ";
							textColor(10);
							gotoXY(87,9);cout<<"Saved!";
						}
						textColor(15); 
					}
					else if (vitri == 4) {
						system("color 07");
//						gotoXY(87,7); cout<<"                  ";
//						textColor(10);
//						gotoXY(87,7); cout<<"CAU "<<page+1<<": ";cout<<"Chon D";
						cauTL[page]="D";
						char luachon = _getch();
						if (luachon == 13) {
							gotoXY(87,9);cout<<"         ";
							textColor(10);
							gotoXY(87,9);cout<<"Saved!";
						}
						textColor(15); 
					}
				}
				else if(key==97 || key==75){
					if(page==0)
						_getch();
					else page--;
				}
				else if(key==100 || key==77){
					if(page==soCau-1)
						_getch();
					else page++;
				}
				else if(key==27){
					stop_time = 0;
					textColor(15);
					cout << endl; break;
				}
			}
		if(stop_time==0){
					float diem=0; int dung=0;
					for(int i=0; i<soCau; i++){
						if(strcmp(CH[b[i]]->getDapAnDung(), stringToChar(cauTL[i]))==0){
							dung++;
						}	
					}
					diem = (float) (dung*10)/soCau;
					textColor(10);
					gotoXY(17,21); cout<<"                                                                                    ";
					gotoXY(17,21); cout<<"BAN DAT "<<"["<<diem<<"]"<<" DIEM! HAY TIEP TUC CO GANG!";
					textColor(15);
					svThi->dsDiemDaThi.khoiTao();
					svThi->dsDiemDaThi.dataIn(svThi->getMaSV());
					svThi->dsDiemDaThi.themDiem(svThi->getMaSV(), maMonTam,diem);
					
					svThi->dsDiemDaThi.dataOut(svThi->getMaSV());
					
					int dsID[soCau];
					for(int i=0; i<soCau; i++){
						dsID[i]=CH[b[i]]->getID();
					}
					this->dataOut(svThi->getMaSV(), maMonTam, soCau,time, dsID, cauTL);
					textColor(12);
					gotoXY(17,13); cout<<"                                                                                    ";
					gotoXY(17,23); cout<<"HET THOI GIAN. NHAN PHIM BAT KY DE THOAT";
					textColor(15);
					_getch();
					clrscr();
					clock.join();
					clearConsoleToColors(0,0);
					break;
			}	
//		textColor(15);
//		gotoXY(0,0); cout<<"                     ";
//		gotoXY(0,0); cout<<"NHAN PHIM BAT KY";
//		cout<<endl;
//		_getch();
//		gotoXY(0,0); cout<<"                     ";
//		break;
	}
}
void ChiTietDeThi::gvThiThu(){
	while(1){
		char maMonTam[size_ma];
		int time=0; int soCau=0; int page=0; 
		DSMonHoc dsmh;
		dsmh.dataIn();
		DSCauHoi ds;
		ds.dataIn();
		int n=ds.getSizeCH(); int m=0; // n la tat ca cau hoi, m la so cau cua mon hoc co ma x
		
		clrscr();
		veKhungThemMH(23,2,9,70,15);
		textColor(15);
		gotoXY(24,3); cout<<"                            ";
		gotoXY(24,3); cout<<"Nhap ma mon hoc: ";
		nhapChuVaSo(maMonTam,size_ma);
		inHoaTatCa(maMonTam);
		while(!dsmh.coMaMonHoc(maMonTam)){
			textColor(12); 
			gotoXY(24,12); cout<<"                                                ";
			gotoXY(24,12); cout<<"Ma khong ton tai! Nhap lai ";
			textColor(15);
			gotoXY(24,3); cout<<"                            ";
			gotoXY(24,3); cout<<"Nhap ma mon hoc: ";
			nhapChuVaSo(maMonTam,size_ma);
			inHoaTatCa(maMonTam);
		}
		CauHoi* CH[n];
		ds.cayVaoMang(ds.getCauHoiGoc(),CH, maMonTam, m);
		int a=Min(m,n);
		gotoXY(24,6); cout<<"                            ";
		gotoXY(24,6); cout<<"Nhap so cau hoi: ";
		nhapSoInt(soCau,4);
		while(soCau>a || soCau<=0){
			textColor(12); 
			gotoXY(24,12); cout<<"                                                ";
			gotoXY(24,12); cout<<"So cau hoi lon hon [0] va khong qua "<<"["<<a<<"]"; cout<<" Nhap lai";
			textColor(15);
			gotoXY(24,6); cout<<"                            ";
			gotoXY(24,6); cout<<"Nhap so cau hoi: ";
			nhapSoInt(soCau,4);
		}
		gotoXY(24,12); cout<<"                                                ";
		gotoXY(24,12); cout<<"OK";
		
		gotoXY(24,9); cout<<"                            ";
		gotoXY(24,9); cout<<"Nhap so phut thi: ";
		nhapSoInt(time,4);
		
		
		int k[a]; int b[soCau];
		for(int i=0; i<a; i++)
			k[i]=i;
		tronMang(k, a);
		for(int i=0; i<soCau; i++)
			b[i]=k[i];
			
		int hh=0,mm=0,ss=0;
		hh = time/60;
		mm = time-hh*60;
		thread clock;
		clrscr();
		clock = thread(printClock,hh,mm,ss);
		
		string* cauTL=new string[soCau];
		for(int i=0; i<soCau; i++)
			cauTL[i]="X";
			
		stop_time = 1;
		int vitrix = 17; int vitriy = 10; int mau = 15;
		string str[10];
		int vitri = 1;
		showConsoleCursor(false);
		while (stop_time!=0 ) {
			system("color 07");
			for (int i = 1; i <= 4; i++) {
				if (i == vitri) mau = 160;
				else mau = 15;
				veKhungThi(15,2,20,90,15);
					
				str[1] = "[ A ]: "; gotoXY(25,11); CH[b[page]]->inA();
				str[2] = "[ B ]: "; gotoXY(25,12); CH[b[page]]->inB();
				str[3] = "[ C ]: "; gotoXY(25,13); CH[b[page]]->inC();
				str[4] = "[ D ]: "; gotoXY(25,14); CH[b[page]]->inD();
					
				gotoXY(16,3); cout<<"THI TRAC NGHIEM MON: "<<maMonTam;
				gotoXY(64,3); cout<<"TONG SO CAU HOI: "<<soCau;
				gotoXY(16,4); cout<<"GIAO VIEN THI THU";
				gotoXY(86,3); cout<<"Thoi gian con lai:";
				gotoXY(17,8); cout<<"CAU "<<page+1<<": "; CH[b[page]]->inNoiDung();
				gotoXY(87,7); cout<<"                  ";
				textColor(10);
				gotoXY(87,7); cout<<"CAU "<<page+1<<": ";cout<<"Chon "; cout<<cauTL[page];
				textColor(15);
				gotoXY(17,21); cout<<"      ESC: Nop Bai | A: Cau truoc | D: Cau sau | W: Len | S: Xuong | ENTER: Chon";
				ThanhMenu(vitrix, vitriy + i, mau, str[i]);
			}
			char key = _getch();
			if (key == 119 || key==72) {
				if (vitri == 1) {
					vitri = 4;
				}
				else vitri--;
			}
			else if (key == 115 || key==80) {
				if (vitri == 4)vitri = 1;
				else vitri++;
			}
			else if (key == 13) {
				//clearConsoleToColors(7, 0);
				if (vitri == 1) {
					//clrscr();
					system("color 07");
					cauTL[page]="A";
					textColor(15);
//					char luachon = _getch();
//					if (luachon == 13) {
						gotoXY(87,9);cout<<"         ";
						textColor(10);
						gotoXY(87,9);cout<<"Saved!";
//					}
					textColor(15); //clrscr();
				}
				else if (vitri == 2) {
					//clrscr();
					system("color 07");
//					gotoXY(87,7); cout<<"                  ";
//					textColor(10);
//					gotoXY(87,7); cout<<"CAU "<<page+1<<": ";cout<<"Chon B";
					cauTL[page]="B";
//					char luachon = _getch();
//					if (luachon == 13) {
						gotoXY(87,9);cout<<"         ";
						textColor(10);
						gotoXY(87,9);cout<<"Saved!";
//					}
					textColor(15); //clrscr();
				}
				else if (vitri == 3) {
					//clrscr();
					system("color 07");
//					gotoXY(87,7); cout<<"                  ";
//					textColor(10);
//					gotoXY(87,7); cout<<"CAU "<<page+1<<": ";cout<<"Chon C";
					cauTL[page]="C";
//					char luachon = _getch();
//					if (luachon == 13) {
						gotoXY(87,9);cout<<"         ";
						textColor(10);
						gotoXY(87,9);cout<<"Saved!";
//						}
						textColor(15); //clrscr();
					}
				else if (vitri == 4) {
					//clrscr();
					system("color 07");
//					gotoXY(87,7); cout<<"                  ";
//					textColor(10);
//					gotoXY(87,7); cout<<"CAU "<<page+1<<": ";cout<<"Chon D";
					cauTL[page]="D";
//					char luachon = _getch();
//					if (luachon == 13) {
						gotoXY(87,9);cout<<"         ";
						textColor(10);
						gotoXY(87,9);cout<<"Saved!";
//					}
					textColor(15); //clrscr();
				}
			}
			else if(key==97 || key==75){
				if(page==0)
					_getch();
				else page--;
			}
			else if(key==100 || key==77){
				if(page==soCau-1)
					_getch();
				else page++;
			}
			else if(key==27){	
//				float diem=0; int dung=0;
//				for(int i=0; i<soCau; i++){
//					if(strcmp(CH[b[i]]->getDapAnDung(),cauTraLoi[i])==0){
//						dung++;
//					}	
//				}
//				diem = (float) (dung*10)/soCau;
//				textColor(10);
//				gotoXY(17,21); cout<<"                                                                                    ";
//				gotoXY(17,21); cout<<"BAN DAT "<<"["<<diem<<"]"<<" DIEM! HAY TIEP TUC CO GANG!";
//				textColor(15);
//				getch();
				//clrscr();
				stop_time = 0;
				textColor(15);
				cout << endl; break;
			}
		}
		if(stop_time==0){
			float diem=0; int dung=0;
			for(int i=0; i<soCau; i++){
				if(strcmp(CH[b[i]]->getDapAnDung(),stringToChar(cauTL[i]))==0){
					dung++;
				}	
			}
			diem = (float) (dung*10)/soCau;
			textColor(10);
			gotoXY(17,21); cout<<"                                                                                    ";
			gotoXY(17,21); cout<<"BAN DAT "<<"["<<diem<<"]"<<" DIEM! HAY TIEP TUC CO GANG!";
			textColor(15);
			textColor(12);
			gotoXY(17,23); cout<<"                                                                                    ";
			gotoXY(17,23); cout<<"HET THOI GIAN! NHAN PHIM BAT KY DE THOAT";
			textColor(15);
			_getch();
			clearConsoleToColors(0,0);
			clrscr();
			clock.join();
			break;
		}
	}		
}
void ChiTietDeThi::inBaiThi(SinhVien *svTam){
	int time=0; int soCau=0; int page=0; int dsID[soCau]; 
	DSMonHoc dsmh;
	dsmh.dataIn();
	DSCauHoi ds;
	ds.dataIn();
	MonHoc* mhTam = new MonHoc;
	clrscr();
	veKhung(23,2,3,70,15);
	textColor(15);
	gotoXY(24,3); cout<<"                                           ";
	gotoXY(24,3); mhTam->nhapMaMH();
	while(!dsmh.coMaMonHoc(mhTam->getMaMH())){
		textColor(12); 
		gotoXY(24,4); cout<<"                                                ";
		gotoXY(24,4); cout<<"Ma khong ton tai! Nhap lai ";
		textColor(15);
		gotoXY(24,3); cout<<"                                       ";
		gotoXY(24,3); mhTam->nhapMaMH();
	}
	svTam->dsDiemDaThi.dataIn(svTam->getMaSV());
	if(!svTam->dsDiemDaThi.diem1Mon(mhTam->getMaMH())){
		clrscr();
		textColor(12);
		gotoXY(24,4); cout<<"                                                           ";
		gotoXY(24,4); cout<<"Mon hoc nay sinh vien chua thi! Nhan phim bat ky de thoat";
		textColor(15);
		_getch();
		return;
	}
	
	textColor(10);
	gotoXY(24,4); cout<<"                                        ";
	gotoXY(24,4); cout<<"OK!";
	textColor(15);
		//mo file chi tiet de thi
	fstream fileCT;  string cauTL="";
	char tenFile[50]="CTDT_";
	strcat(tenFile,mhTam->getMaMH());
	strcat(tenFile,"_");
	strcat(tenFile,svTam->getMaSV());
	strcat(tenFile,".txt");
	fileCT.open(tenFile, ios::in);
	if(fileCT.is_open()){
		fileCT>>soCau;
		fileCT>>time;
		for(int i=0; i<soCau; i++){
			fileCT>>dsID[i];
		}	
		for(int i=0; i<soCau; i++){
			string t;
			fileCT>>t;
			cauTL+=t;
		}	
	}
	else{
		cout<<"Chua mo file!";
	}
	while(1){
		clrscr();
		veKhungThi(15,2,20,90,15);
		CauHoi* chTam = ds.coID(dsID[page]);
		gotoXY(17,11); cout<<"[ A ]: "; gotoXY(25,11); chTam->inA();
		gotoXY(17,12); cout<<"[ B ]: "; gotoXY(25,12); chTam->inB();
		gotoXY(17,13); cout<<"[ C ]: "; gotoXY(25,13); chTam->inC();
		gotoXY(17,14); cout<<"[ D ]: "; gotoXY(25,14); chTam->inD();
		textColor(10);			
		gotoXY(16,3); cout<<"THI TRAC NGHIEM MON: "<<mhTam->getMaMH();
		gotoXY(64,3); cout<<"TONG SO CAU HOI: "<<soCau;
		gotoXY(16,4); cout<<"MSSV: "<<svTam->getMaSV()<<"- "<<svTam->getHo()<<" "<<svTam->getTen();
		gotoXY(86,3); cout<<"Thoi gian lam bai: "; 
		gotoXY(92,4); cout<<time<<" phut";
		textColor(15);
		gotoXY(17,8); cout<<"CAU "<<page+1<<": "; chTam->inNoiDung();
		gotoXY(87,8); cout<<"CAU "<<page+1<<": ";cout<<"Chon "; cout<<cauTL[page];
		textColor(10);
		gotoXY(17,21); cout<<"ESC: Thoat | A: Cau truoc | D: Cau sau";
		textColor(15);
		char key = _getch();
		if(key==97 || key==75){
			if(page==0)
				_getch();
			else page--;
		}
		else if(key==100 || key==77){
			if(page==soCau-1)
				_getch();
			else page++;
		}
		else if(key==27){	
			textColor(15);
			fileCT.close();
			clrscr();
			cout << endl; break;
		}
	}
	clrscr();
	textColor(15);
	gotoXY(0,0); cout<<"                         ";
	gotoXY(0,0); cout<<"NHAN PHIM BAT KY";
	_getch();
	gotoXY(0,0); cout<<"                         ";
}
void ChiTietDeThi::inChiTietBaiThi(){
	int luachon=13;
	while(luachon==13){
		clrscr();
		textColor(15);
		char id[15];
		veKhung(23,2,3,70,15);
		textColor(15);
		gotoXY(24,3); cout<<"                                           ";
		gotoXY(24,3); cout<<"Nhap MSSV: "; nhapChuVaSo(id,15);
		inHoaTatCa(id);
		DSLop dsLop;
		dsLop.dataIn();
		int n = dsLop.getSizeLop();
		Lop* lop[n];
		dsLop.duyetDSLop(lop);
		for(int i=0; i<n; i++){
			lop[i]->dsSV.dataIn(lop[i]->getMaLop());
			if(lop[i]->dsSV.coMaSV(id)){
				clrscr();
				SinhVien* tam = lop[i]->dsSV.coSV(id);
				ChiTietDeThi ct;
				ct.inBaiThi(tam);
			}		
		}
		textColor(12);
		gotoXY(24,4); cout<<"                                              ";
		gotoXY(24,4); cout<<"Ma khong ton tai! ENTER: Nhap lai | ESC thoat ";
		textColor(15);
		while (1) {
			char key = _getch();
			if (key == 13) {
				luachon = 13; break;
			}
			else if (key == 27) {
				luachon = 27;
				clrscr(); 
				cout<<endl;
				break;
			}
		} 
	}		
}

