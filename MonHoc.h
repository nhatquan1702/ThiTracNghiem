#ifndef MONHOC_H
#define MONHOC_H
#include "MyFunction.h"
class MonHoc
{
	public:
		MonHoc();
		void nhapMaMH();
		void nhapTenMH();
		void inMaMH();
		void inTenMH();
		void inMonHoc();
		void setMaMH(char ma[]);
		void settenMH(char ten[]);
		char* getMaMH();
		char* getTenMH();
	private:
		char maMH[size_ma];
		char tenMH[size_tenMH];
};

#endif
