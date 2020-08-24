#include "Display.h"

void Menu1() {
	int vitrix = 30; int vitriy = 5; int mau = 15;
	string str[10];
	str[1] = "1. THEM LOP       ";
	str[2] = "2. XOA LOP        ";
	str[3] = "3. HIEU CHINH LOP ";
	str[4] = "4. VE MENU CHINH  ";
	int vitri = 1;
	showConsoleCursor(false);
	while (1) {
		veKhung(23,2,20,60,15);
		system("color 07");
		for (int i = 1; i <= 4; i++) {
			if (i == vitri) mau = 160;
			else mau = 15;
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
			clearConsoleToColors(7, 0);
			if (vitri == 1) {
				clrscr();
				system("color 07");
				DSLop ds;
				ds.dataIn();
				ds.themLop();
				textColor(10);
				gotoXY(24,16); cout<<"                                       ";
				gotoXY(24,16); cout << "Ban co muon luu lai khong?";
				gotoXY(24,17); cout<<"                                       ";
				gotoXY(24,17); cout << "Enter de luu lai- Esc de huy";
				textColor(15);
				char luachon = _getch();
				if (luachon == 13) {
					ds.dataOut();
					gotoXY(24,17); cout<<"                                       ";
					gotoXY(24,17); cout<<"Nhan phim bat ki de thoat";
					_getch();
				}
				textColor(15); clrscr();
			}
			else if (vitri == 2) {
				clrscr();
				system("color 07");
				DSLop ds;
				ds.dataIn();
				ds.xoaLop();
				textColor(10);
				gotoXY(24,16); cout<<"                                       ";
				gotoXY(24,16); cout << "Ban co muon luu lai khong?";
				gotoXY(24,17); cout<<"                                       "; 
				gotoXY(24,17); cout << "Enter de luu lai- Esc de huy";
				textColor(15);
				char luachon = _getch();
				if (luachon == 13) {
					ds.dataOut();
					gotoXY(24,17); cout<<"                                       ";
					gotoXY(24,17); cout<<"Nhan phim bat ki de thoat";
					_getch();
				}
				textColor(15); clrscr();
			}
			else if (vitri == 3) {
				clrscr(); system("color 07");
				DSLop ds;
				ds.dataIn();
				ds.hieuChinhLop();
				textColor(10);
				gotoXY(24,16); cout<<"                                       ";
				gotoXY(24,16); cout << "Ban co muon luu lai khong?";
				textColor(10);
				gotoXY(24,17); cout<<"                                       ";
				gotoXY(24,17); cout << "Enter de luu lai- Esc de huy";
				textColor(15);
				char luachon = _getch();
				if (luachon == 13) {
					ds.dataOut();
					gotoXY(24,17); cout<<"                                       ";
					gotoXY(24,17); cout<<"Nhan phim bat ki de thoat";
					_getch();
				}
				textColor(15); clrscr();
			}
			else if (vitri == 4) {
				clrscr();
				break;
			}
		}
	}
}
void Menu2() {
	int vitrix = 30; int vitriy = 5; int mau = 15;
	string str[10];
	str[1] = "1. IN DANH SACH LOP THEO NIEN KHOA ";
	str[2] = "2. VE MENU CHINH                   ";
	int vitri = 1;
	showConsoleCursor(false);
	while (1) {
		veKhung(23,2,20,60,15);
		system("color 07");
		for (int i = 1; i <= 2; i++) {
			if (i == vitri) mau = 160;
			else mau = 15;
			ThanhMenu(vitrix, vitriy + i, mau, str[i]);
		}
		char key = _getch();
		if (key == 119 || key==72) {
			if (vitri == 1) {
				vitri = 2;
			}
			else vitri--;
		}
		else if (key == 115 || key==80) {
			if (vitri == 2)vitri = 1;
			else vitri++;
		}
		else if (key == 13) {
			clearConsoleToColors(7, 0);
			if (vitri == 1) {
				clrscr();
				system("color 07");
				DSLop ds;
				ds.dataIn();
				ds.inDSLopTheoNienKhoa();
			}
			else if (vitri == 2) {
				clrscr();
				break;
			}
		}
	}
	textColor(15); clrscr();
}
void Menu3() {
int vitrix = 30; int vitriy = 5; int mau = 15;
	string str[10];
	str[1] = "1. THEM SINH VIEN VAO LOP ";
	str[2] = "2. VE MENU CHINH          ";
	int vitri = 1;
	showConsoleCursor(false);
	while (1) {
		veKhung(23,2,20,60,15);
		system("color 07");
		for (int i = 1; i <= 2; i++) {
			if (i == vitri) mau = 160;
			else mau = 15;
			ThanhMenu(vitrix, vitriy + i, mau, str[i]);
		}
		char key = _getch();
		if (key == 119 || key==72) {
			if (vitri == 1) {
				vitri = 2;
			}
			else vitri--;
		}
		else if (key == 115 || key==80) {
			if (vitri == 2)vitri = 1;
			else vitri++;
		}
		else if (key == 13) {
			clearConsoleToColors(7, 0);
			if (vitri == 1) {
				clrscr();
				system("color 07");
				veKhung(23,2,3,70,15);
				Lop* lopTam = new Lop;
				gotoXY(24,3); cout<<"Nhap ma lop: ";
				gotoXY(24,4); lopTam->nhapMaLop();
				DSLop dsLop;
				dsLop.dataIn();
				while(!dsLop.DSSVCoMaLop(lopTam->getMaLop())){
					gotoXY(24,3); cout<<"                                       ";
					gotoXY(24,3); cout<<"Khong ton tai ma lop! Nhap lai: ";
					gotoXY(24,4); cout<<"                                       ";
					gotoXY(24,4); lopTam->nhapMaLop();
				}
				Lop* lopOK = dsLop.lay1Lop(lopTam);
				lopOK->dsSV.dataIn(lopTam->getMaLop());
				lopOK->dsSV.themSinhVien();
				textColor(10);
				gotoXY(24,18); cout<<"                                                ";
				gotoXY(24,18); cout << "Ban co muon luu lai khong?";
				gotoXY(24,19); cout<<"                                                ";
				gotoXY(24,19); cout << "Enter de luu lai- Esc de huy";
				char luachon = _getch();
				if (luachon == 13) {
					lopOK->dsSV.dataOut(lopTam->getMaLop());
					gotoXY(24,19); cout<<"                                       ";
					gotoXY(24,19); cout<<"Nhan phim bat ky de thoat";
					_getch();
				}
				textColor(15); clrscr();
			}
			else if (vitri == 2) {
				clrscr();
				break;
			}
		}
	}
}
void Menu4() {
	int vitrix = 30; int vitriy = 5; int mau = 15;
	string str[10];
	str[1] = "1. THEM MON HOC       ";
	str[2] = "2. XOA MON HOC        ";
	str[3] = "3. HIEU CHINH MON HOC ";
	str[4] = "4. VE MENU CHINH      ";
	int vitri = 1;
	showConsoleCursor(false);
	while (1) {
		veKhung(23,2,20,60,15);
		system("color 07");
		for (int i = 1; i <= 4; i++) {
			if (i == vitri) mau = 160;
			else mau = 15;
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
			clearConsoleToColors(7, 0);
			if (vitri == 1) {
				clrscr();
				system("color 07");
				DSMonHoc dsmh;
				dsmh.dataIn();
				dsmh.themMH();
				textColor(10);
				gotoXY(24,13); cout<<"                                       ";
				gotoXY(24,13); cout << "Ban co muon luu lai khong?";
				gotoXY(24,14); cout<<"                                       ";
				gotoXY(24,14); cout << "Enter: luu lai thong tin- Esc: huy";
				textColor(10);
				char luachon = _getch();
				if (luachon == 13) {
					dsmh.dataOut();
					gotoXY(24,16); cout<<"Nhan phim bat ky de thoat";
					gotoXY(24,16); cout<< "                                             ";
					textColor(15);
					_getch();
				}
				textColor(15); clrscr();
			}
			else if (vitri == 2) {
				clrscr();
				system("color 07");
				DSMonHoc dsmh;
				dsmh.dataIn();
				dsmh.xoaMonHoc();
				textColor(12);
				gotoXY(24, 13); cout<<"                                       ";
				gotoXY(24, 13); cout << "Ban co muon luu lai khong?";
				gotoXY(24, 14); cout<<"                                       ";
				gotoXY(24, 14); cout << "Enter de luu lai- Esc de huy";
				char luachon = _getch();
				if (luachon == 13) {
					dsmh.dataOut();
					gotoXY(24,16); cout<<"Nhan phim bat ky de thoat";
					gotoXY(24,16); cout<< "                                             ";
					textColor(15);
					_getch();
				}
				textColor(15); clrscr();
			}
			else if (vitri == 3) {
				clrscr(); system("color 07");
				DSMonHoc dsmh;
				dsmh.dataIn();
				dsmh.hieuChinhMH();
				textColor(12);
				gotoXY(24, 13); cout<<"                                       ";
				gotoXY(24, 13); cout <<"Ban co muon luu lai khong?";
				gotoXY(24, 14); cout<<"                                       ";
				gotoXY(24, 14); cout << "Enter de luu lai- Esc de huy";
				char luachon = _getch();
				if (luachon == 13) {
					dsmh.dataOut();
					gotoXY(24,16); cout<<"Nhan phim bat ky de thoat";
					gotoXY(24,16); cout<< "                                             ";
					textColor(15);
					_getch();
				}
				textColor(15); clrscr();
			}
			else if (vitri == 4) {
				clrscr();
				break;
			}
		}
	}
}
void Menu5() {
	int vitrix = 30; int vitriy = 5; int mau = 15;
	string str[3];
	str[1] = "1. THEM CAU HOI THI  ";
	str[2] = "2. VE MENU CHINH     ";
	int vitri = 1;
	showConsoleCursor(false);
	while (1) {
		veKhung(23,2,20,60,15);
		system("color 07");
		for (int i = 1; i <= 2; i++) {
			if (i == vitri) mau = 160;
			else mau = 15;
			ThanhMenu(vitrix, vitriy + i, mau, str[i]);
		}
		char key = _getch();
		if (key == 119 || key==72) {
			if (vitri == 1) {
				vitri = 2;
			}
			else vitri--;
		}
		else if (key == 115 || key==80) {
			if (vitri == 2)vitri = 1;
			else vitri++;
		}
		else if (key == 13) {
			clearConsoleToColors(7, 0);
			if (vitri == 1) {
				clrscr();
				system("color 07");
				DSCauHoi dsch;
				dsch.dataIn();
				dsch.themCauHoi();
				textColor(10);
				gotoXY(24,28); cout<<"                                                  ";
				gotoXY(24,28); cout << "Ban co muon luu lai khong?";
				gotoXY(24,29); cout<<"                                                  ";
				gotoXY(24,29); cout << "Enter de luu lai- Esc de huy";
				textColor(15);
				char luachon = _getch();
				if (luachon == 13) {
					dsch.dataOut();
					textColor(10);
					gotoXY(24,28); cout<<"                                          ";
					gotoXY(24,28); cout<<"Nhan phim bat ky de thoat";
					_getch();
				}
				textColor(15); clrscr();
			}
			else if (vitri == 2) {
				clrscr();
				break;
			}
		}
	}
}
void Menu6() {
	int vitrix = 30; int vitriy = 5; int mau = 15;
	string str[3];
	str[1] = "1. THI THU           ";
	str[2] = "2. VE MENU CHINH     ";
	int vitri = 1;
	showConsoleCursor(false);
	while (1) {
		veKhung(23,2,20,60,15);
		system("color 07");
		for (int i = 1; i <= 2; i++) {
			if (i == vitri) mau = 160;
			else mau = 15;
			ThanhMenu(vitrix, vitriy + i, mau, str[i]);
		}
		char key = _getch();
		if (key == 119 || key==72) {
			if (vitri == 1) {
				vitri = 2;
			}
			else vitri--;
		}
		else if (key == 115 || key==80) {
			if (vitri == 2)vitri = 1;
			else vitri++;
		}
		else if (key == 13) {
			clearConsoleToColors(7, 0);
			if (vitri == 1) {
				clrscr();
				system("color 07");
				ChiTietDeThi ctdt;
				ctdt.gvThiThu();
			}
			else if (vitri == 2) {
				clrscr();
				break;
			}
		}
	}
}
void Menu7() {
	int vitrix = 30; int vitriy = 5; int mau = 15;
	string str[3];
	str[1] = "1. IN CHI TIET CAU HOI DA THI 1 MON CUA 1 SINH VIEN ";
	str[2] = "2. VE MENU CHINH                                    ";
	int vitri = 1;
	showConsoleCursor(false);
	while (1) {
		veKhung(23,2,20,60,15);
		system("color 07");
		for (int i = 1; i <= 2; i++) {
			if (i == vitri) mau = 160;
			else mau = 15;
			ThanhMenu(vitrix, vitriy + i, mau, str[i]);
		}
		char key = _getch();
		if (key == 119 || key==72) {
			if (vitri == 1) {
				vitri = 2;
			}
			else vitri--;
		}
		else if (key == 115 || key==80) {
			if (vitri == 2)vitri = 1;
			else vitri++;
		}
		else if (key == 13) {
			clearConsoleToColors(7, 0);
			if (vitri == 1) {
				clrscr();
				system("color 07");
				ChiTietDeThi ctdt;
				ctdt.inChiTietBaiThi();
			}
			else if (vitri == 2) {
				clrscr();
				break;
			}
		}
	}
}
void Menu8() {
	int vitrix = 30; int vitriy = 5; int mau = 15;
	string str[3];
	str[1] = "1. IN BANG DIEM THI 1 MON CUA 1 LOP ";
	str[2] = "2. VE MENU CHINH                    ";
	int vitri = 1;
	showConsoleCursor(false);
	while (1) {
		veKhung(23,2,20,60,15);
		system("color 07");
		for (int i = 1; i <= 2; i++) {
			if (i == vitri) mau = 160;
			else mau = 15;
			ThanhMenu(vitrix, vitriy + i, mau, str[i]);
		}
		char key = _getch();
		if (key == 119 || key==72) {
			if (vitri == 1) {
				vitri = 2;
			}
			else vitri--;
		}
		else if (key == 115 || key==80) {
			if (vitri == 2)vitri = 1;
			else vitri++;
		}
		else if (key == 13) {
			clearConsoleToColors(7, 0);
			if (vitri == 1) {
				clrscr();
				system("color 07");
				DSSinhVien dssv;
				DSSinhVien();
				dssv.inBangDiem1MonCua1Lop();
			}
			else if (vitri == 2) {
				clrscr();
				break;
			}
		}
	}
}
void Menu() {
	int vitrix = 30; int vitriy = 5; int mau = 15;
	string str[10];
	str[1] = "1. CAP NHAT DANH SACH LOP                           ";
	str[2] = "2. IN DANH SACH LOP THEO 1 NIEN KHOA                ";
	str[3] = "3. THEM SINH VIEN VAO LOP                           ";
	str[4] = "4. CAP NHAT DANH SACH MON HOC                       ";
	str[5] = "5. THEM CAU HOI THI                                 ";
	str[6] = "6. GIAO VIEN THI THU                                ";
	str[7] = "7. IN CHI TIET CAU HOI DA THI 1 MON CUA 1 SINH VIEN ";
	str[8] = "8. IN BANG DIEM THI 1 MON CUA 1 LOP                 ";
	str[9] = "9. THOAT UNG DUNG                                   ";
	int vitri = 1;
	showConsoleCursor(false);
	while (1) {
		veKhung(23,2,20,65,15);
		system("color 07");
		for (int i = 1; i <= 9; i++) {
			if (i == vitri) mau = 160;
			else mau = 15;
			ThanhMenu(vitrix, vitriy + i, mau, str[i]);
		}
		char key = _getch();
		if (key == 119 || key==72) {
			if (vitri == 1) {
				vitri = 9;
			}
			else vitri--;
		}
		else if (key == 115 || key==80) {
			if (vitri == 9)vitri = 1;
			else vitri++;
		}
		else if (key == 13) {
			clearConsoleToColors(7, 0);
			if (vitri == 1) {
				 Menu1();
			}
			else if (vitri == 2) {
				 Menu2();
			}
			else if (vitri == 3) {
				Menu3();
			}
			else if (vitri == 4) {
				Menu4();
			}
			else if (vitri == 5) {
				Menu5();
			}
			else if (vitri == 6) {
				Menu6();
			}
			else if (vitri == 7) {
				Menu7();
			}
			else if (vitri == 8) {
				Menu8();
			}
			else if (vitri == 9) {
				cout << "BAN CO THUC SU MUON THOAT" << endl;
				cout << "Yes: Enter | No: Esc" << endl;
				bool thoat = false;
				char key;
				while (1) {
					key = _getch();
					if (key == 13) {
						thoat = true;
						break;
					}
					else if (key == 27)break;
				}
				if (thoat) {
					clrscr();
					textColor(15);
					break;
				}
			}
		}
	}
}
