#ifndef DSMONHOC_H
#define DSMONHOC_H
#include "MonHoc.h"
//mang con tro
class DSMonHoc
{
	public:
		DSMonHoc();
		int getSizeMH();
		bool trungMaMH(MonHoc* mh);
		bool coMaMonHoc(char ma[]);
		void dataIn();
		void dataOut();
		void themMH();
		void inDSMH();
		int timMonHoc(char ma[]);
		MonHoc* lay1Mon(MonHoc *mhTam);
		bool monHocCoCauHoi(char maTam[]);
		void xoaMonHoc();
		void hieuChinhMH();
	private:
		int sizeMH;
		MonHoc* monhoc[MAXLIST_MH];
};

#endif
