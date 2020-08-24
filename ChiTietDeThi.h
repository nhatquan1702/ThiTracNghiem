#ifndef CHITIETDETHI_H
#define CHITIETDETHI_H
#include "MyFunction.h"
#include "DSCauHoi.h"
#include "SinhVien.h"

class ChiTietDeThi
{
	public:
		ChiTietDeThi();
		void startTimerJob(int time_in_second);
		void getCauHoi(DSCauHoi ds);
		void svThi(SinhVien *svThi);
		void gvThiThu();// giao vien thi
		void startTimer(int n);
		void dataOut(char maSV[], char maMon[], int soCau, int soPhut, int dsID[], string* cauTraLoi);
		void inBaiThi(SinhVien *svTam);
		void inChiTietBaiThi();
	private:
		string* cauTraLoi;
};

#endif

