#ifndef LOP_H
#define LOP_H
#include "MyFunction.h"
#include "SinhVien.h"
#include "DSSinhVien.h"
class Lop
{
	public:
		Lop();
		void nhapMaLop();
		void nhapTenLop();
		void nhapNienKhoa();
		void inMaLop();
		void inTenLop();
		void inNienKhoa();
		void inLop();
		void setMaLop(char ma[]);
		void setTenLop(char ten[]);
		void setNienKhoa(char nk[]);
		char* getMaLop();
		char* getTenLop();
		char* getNienKhoa();
		
		DSSinhVien dsSV;//con tro den danh sach sinh vien thuoc lop do
	private:
		char maLop[size_ma];
		char tenLop[size_tenlop];
		char nienKhoa[size_nienkhoa];
};

#endif
