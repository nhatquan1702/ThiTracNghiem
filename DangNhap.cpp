#include "DangNhap.h"
#include "DSSinhVien.h"
#include "DSLop.h"
void dangNhap(){
	int luachon=13;
	while(luachon==13){
		clrscr();
		char id[15]; char pass[15];
		system("color 0");
		clrscr();	
		veKhungDangNhap();
		textColor(15);
		gotoXY(40,11); nhapChuVaSo(id,15);
		inHoaTatCa(id);
		gotoXY(40,14); nhapPass(pass,20);
		if((strcmp(id,"GV")==0 && strcmp(pass,"GV")==0)
			|| (strcmp(id,"GV")==0 && strcmp(pass,"gv")==0)){
			clrscr();
			Menu();
		}
		else{
			DSLop dsLop;
			dsLop.dataIn();
			int n = dsLop.getSizeLop();
			Lop* lop[n];
			dsLop.duyetDSLop(lop);
			for(int i=0; i<n; i++){
				lop[i]->dsSV.dataIn(lop[i]->getMaLop());
				if(lop[i]->dsSV.coTK(id,pass)){
					clrscr();
					SinhVien* tam = lop[i]->dsSV.coSV(id);
					ChiTietDeThi ct;
					ct.svThi(tam);
				}
			}	
		}
		textColor(12);
		gotoXY(37,17); cout<<"                                          ";
		gotoXY(37,17); cout<<"Tai khoan hoac mat khau khong chinh xac\n";
		gotoXY(37,18); cout<<"                                          ";
		gotoXY(37,18); cout<<"ENTER: Dang nhap | ESC: Thoat";
		textColor(15);
		while (1) {
			char key = _getch();
			if (key == 13) {
				luachon = 13; break;
			}
			else if (key == 27) {
				luachon = 27;
				clrscr(); 
				gotoXY(0,0); cout<<"Ket thuc chuong trinh!";
				cout<<endl;
				break;
			}
		}
	}
}
