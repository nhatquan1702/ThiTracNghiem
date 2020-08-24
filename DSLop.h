#ifndef DSLOP_H
#define DSLOP_H
#include "Lop.h"
//mang con tro
class DSLop
{
	public:
		DSLop();
		int getSizeLop();
		bool trungMaLop(Lop *l);
		void dataIn();
		void dataOut();
		void inDSLop();
		void themLop();
		void hieuChinhLop();
		int timMaLop(char malop[]);
		Lop* lay1Lop(Lop* tam);
		bool DSSVCoMaLop(char maL[]);
		void duyetDSLop(Lop* nlop[]);
		bool lopCoSV(SinhVien* sv);
		void xoaLop();
		int timNienKhoa(char nk[]);
		void inDSLopTheoNienKhoa();
		void layLoptheoNienKhoa(char nk[], Lop* LOP[], int &n);
		void in10(Lop* nLop[], int k);
		int laySizeLopTheoNienKhoa(char nk[]);
	private:
		int sizeLop;
		Lop* lop[MAXLIST_LOP];
};

#endif
