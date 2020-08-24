#ifndef DIEM_H
#define DIEM_H
#include "MyFunction.h"

class Diem
{
	public:
		Diem();
		void inMaMH();
		void inD();
		void inDiem();
		void setMaMH(char ma[]);
		void setDiem(float d);
		float getDiem();
		char *getMaMH();
		void setDiemNext(Diem* d);
		Diem* getDiemNext();
	private:
		char maMh[size_ma];
		float diem;
		
		Diem* diemNext;
};

#endif
