#ifndef DSSINHVIEN_H
#define DSSINHVIEN_H
#include "SinhVien.h"
#include "Diem.h"

//dslk

class DSSinhVien{
	public:
		DSSinhVien();
		void khoiTaoDSSV();
		bool kiemTraDSRong();
		bool trungMaSV(SinhVien* sv);
		SinhVien* coSV(char ma[]);
		bool coMaSV(char ma[]);
		bool coTK(char ma[], char pass[]);
		void dataIn(char maLop[]);
		void dataOut(char maLop[]);
		void inDSSinhVien();
		void svVaoMang(SinhVien* SV[], int &n);
		void in10SV(SinhVien* SV[], Diem* nD[], int k, char tenLop[], char tenMon[]);
		void inBangDiem1MonCua1Lop();
		void themSinhVien();
	private:
		int sizeSV;
		SinhVien* svFirst;
};

#endif
