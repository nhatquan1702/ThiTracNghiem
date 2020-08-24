#ifndef CAUHOI_H
#define CAUHOI_H
#include "MyFunction.h"
class CauHoi
{
	public:
		CauHoi();
		void nhapIDCauHoi();
		void nhapMaMH();
		void nhapNoiDung();
		void nhapA();
		void nhapB();
		void nhapC();
		void nhapD();
		void nhapDapAnDung();
		void inID();
		void inMaMH();
		void inNoiDung();
		void inA();
		void inB();
		void inC();
		void inD();
		void inDapAnDung();
		void inCauHoi();
		void setID(int id);
		void setMaMH(char ma[]);
		void setNoiDung(char nd[]);
		void setA(char a[]);
		void setB(char b[]);
		void setC(char c[]);
		void setD(char d[]);
		void setDapAnDung(char dad[]);
		int getID();
		char* getMaMH();
		char* getNoiDung();
		char* getA();
		char* getB();
		char* getC();
		char* getD();
		char* getDapAnDung();
		CauHoi* &getCauHoi();
		CauHoi* & getCauHoiTrai();
		CauHoi* & getCauHoiPhai();
		void setCauHoiTrai(CauHoi* cauhoitrai);
		void setCauHoiPhai(CauHoi* cauhoiphai);
		
	private:
		int idCauhoi;   //khoa
		char maMH[size_ma];
		char noiDung[size_noidung];
		char A[size_dapan];
		char B[size_dapan];
		char C[size_dapan];
		char D[size_dapan];
		char dapAnDung[2];
		
		CauHoi* cauHoiTrai;
		CauHoi* cauHoiPhai;
};

#endif
