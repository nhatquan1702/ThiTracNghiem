#ifndef DSDIEMTHI_H
#define DSDIEMTHI_H
#include "Diem.h"
//dslk
class DSDiemThi
{
	public:
		DSDiemThi();
		void khoiTao();
		void dataIn(char maSV[]);
		void dataOut(char maSV[]);
		void themDiem(char maSV[], char maTam[], float dTam);
		void inDSDiem(char maSV[]);
		bool coMaMon(char maMon[]);
		bool diem1Mon(char maMon[]);
	private:
		int sizeDiem;
		Diem* diemFirst;
};

#endif
