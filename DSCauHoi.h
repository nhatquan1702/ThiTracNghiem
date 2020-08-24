#ifndef DSCAUHOI_H
#define DSCAUHOI_H
#include "CauHoi.h"
//cay nhi phan tim kiem
class DSCauHoi
{
	public:
		DSCauHoi();
		void insertCauHoi(CauHoi* &chGoc, int id, char maMH[],char nd[], char a[], char b[], char c[], char d[], char dad[]);
		void themCauHoi();
		bool coCauHoi(CauHoi* ch);
		CauHoi* trungID(CauHoi *ch);
		CauHoi* coID(int idTam);
		void LNR(CauHoi* chGoc);
		void inDSCauHoi();
		void cayVaoMang(CauHoi *chGoc, CauHoi* dsCH[], char maMon[], int &n);
		void dataIn();
		void xuatFile(CauHoi* chGoc, fstream &file);
		void dataOut();
		CauHoi* &getCauHoiGoc();
		int getSizeCH();
	private:
		int sizeCH;
		CauHoi* cauHoiGoc;
};

#endif
