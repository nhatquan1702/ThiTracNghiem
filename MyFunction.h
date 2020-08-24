#ifndef MYFUNCTION_H
#define MYFUNCTION_H

#define TRUE 1
#define FALSE 0
#define MAXLIST_MH 300
#define MAXLIST_LOP 500
#define size_ma 15
#define size_ho 30
#define size_ten 10
#define size_phai 5
#define size_pass 20
#define size_tenlop 20
#define size_tenMH 50
#define size_nienkhoa 10
#define size_noidung 55
#define size_dapan 60

#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15
#define key_Up		1072
#define key_Down	1080
#define key_Left	1075
#define key_Right	1077

#include <ctime>
#include <time.h>
#include <iostream>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <sstream>
#include "Global.h"
#include "Th_clock.h"

using namespace std;

int Min(int a, int b);
void startTimer(int n);
void startTimerJob(int time_in_second);
void swap(int* a, int* b);
void tronMang(int* a, int n);
void randID(int size);
void randPage(int size);
void clearConsoleToColors(int ForgC, int BackC);
void clrscr();
void gotoXY(int column, int line);
void textColor(int color);
void showConsoleCursor(bool showFlag);
void resetMauMacDinh();
void SetBGColor(WORD color);
void SetColor(WORD color);
bool kiemTraPhimMuiTen();
void nhapChuVaSo(char chuoi[], int size);
void nhapPass(char chuoi[], int size);
void nhapMa(char chuoi[], int size);
void nhapChu(char chuoi[], int size);
void nhapDAD(char chuoi[], int size);
void nhapSoChar(char chuoi[], int size);
void nhapNK(char chuoi[], int size);
void nhapNoiDungCH(char chuoi[], int size);
void nhapSoInt(int &so, int size);
void nhapSoFloat(float &so, int size);
bool kiemTraRong(char chuoi[]);
void xoaKhoangTrang(char chuoi[]);
int charToInt(char chuoi[], int sl);
float charToFloat(char chuoi[], int sl);
int charToInt(char chuoi[]);
void inHoaTatCa(char chuoi[]);
bool kiemTraFileRong(fstream &file);
char* stringToChar(string a);
string charToString(char* a, int size);
void veKhung(int x, int y, char cao, char rong, int mau);
void veKhungThemMH(int x, int y, char cao, char rong, int mau);
void veKhungThemLop(int x, int y, char cao, char rong, int mau);
void veKhungInLopTheoNK(int x, int y, char cao, char rong, int mau);
void veKhungInBangDiem1MonCua1Lop(int x, int y, char cao, char rong, int mau, char tenLop[], char tenMon[]);
void veKhungDangNhap();
void veKhungThemSV(int x, int y, char cao, char rong, int mau);
void veKhungThemCH(int x, int y, char cao, char rong, int mau);
void veKhungThi(int x, int y, char cao, char rong, int mau);
void ThanhMenu(int vitrix, int vitriy, int mau, string title);
int inputKey();

#endif
