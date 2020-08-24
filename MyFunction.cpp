#include "MyFunction.h"

int Min(int a, int b){
    return (a < b ? a : b);
}
void swap(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void tronMang(int* a, int n){
	srand(time(NULL));
	int min;
	int max = n - 1;
	int swapVitri;
	int i = 0;
	while (i < max){
		
		min = i + 1;
		swapVitri = rand() % (max - min + 1) + min;
		swap( &a[i], &a[swapVitri]);
		i++;
	}
	int j=0;
	for(j; j<max; j++){
		if(a[j]==250) break;
		swap(&a[max-1],&a[j]);
	}
}
void randID(int size){
	fstream fileRand;
	fileRand.open("randID.txt", ios::out);
	int a[size];
	for(int i=0; i<size; i++)
		a[i]=i;
	tronMang(a, size);
	for (int i = 0; i < size; i++)
		fileRand<<a[i]<<endl;
	cout<<"Da rand!!!\n";
	fileRand.close();
}
void randPage(int size){
	fstream fileRand;
	fileRand.open("randPage.txt", ios::out);
	int a[size];
	for(int i=0; i<size; i++)
		a[i]=i;
	tronMang(a, size);
	for (int i = 0; i < size; i++)
		fileRand<<a[i]<<endl;
	fileRand.close();
}
//void randID(){
//	
//	srand((int)time(0));
//    int r;
//    int maxN=MAX_ID;
//    int minN=0;
//    int cnt=MAX_ID;
//    map<int, bool> vis;
//    for(int i = 0; i < cnt; ++i){
//        // Random cho toi khi r chua co trong map vis
//        do{
//            r = minN + rand() % (maxN + 1 - minN);
//        }while(vis.find(r) != vis.end());
//        fileRand<<r<<endl;
//        vis[r] = true;
//    }    
//}
void SetColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
 
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;
 
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void clearConsoleToColors(int ForgC, int BackC)
{
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	//Get the handle to the current output buffer...
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//This is used to reset the carat/cursor to the top left.
	COORD coord = { 0, 0 };
	//A return value... indicating how many chars were written
	//not used but we need to capture this since it will be
	//written anyway (passing NULL causes an access violation).
	DWORD count;
	//This is a structure containing all of the console info
	// it is used here to find the size of the console.
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	//Here we will set the current color
	SetConsoleTextAttribute(hStdOut, wColor);
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		//This fills the buffer with a given character (in this case 32=space).
		FillConsoleOutputCharacter(hStdOut, (TCHAR)32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
		FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
		//This will set our cursor position for the next print statement.
		SetConsoleCursorPosition(hStdOut, coord);
	}
}
void showConsoleCursor(bool showFlag)				
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}
void SetBGColor(WORD color){
	HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
} 
void gotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void textColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void resetMauMacDinh() {
	textColor(15);
}
void clrscr(){
	CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;
	HANDLE  hConsoleOut;
	COORD   Home = { 0,0 };
	DWORD   dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
} 
bool kiemTraPhimMuiTen() {
	bool isKeyUp = GetKeyState(VK_UP) & 0x8000;
	bool isKeyDown = GetKeyState(VK_DOWN) & 0x8000;
	bool isKeyRight = GetKeyState(VK_RIGHT) & 0x8000;
	bool isKeyLeft = GetKeyState(VK_LEFT) & 0x8000;
	if (isKeyDown || isKeyLeft || isKeyRight || isKeyUp)
		return true;
	else return false;
}

void nhapChuVaSo(char chuoi[], int size) {
	char* tam = new char[size];
	int i = 0; char key; int dem = 0;
	while (1){
		if (_kbhit()){
			key = _getch();
			if (dem < size-1 ){
				 if (((key >= 65 && key <= 90) || (key >= 97 && key <= 122) 
				 		|| (key == 32) || (key >= 48 && key <= 57))&&!kiemTraPhimMuiTen()){
					tam[i] = key;
					cout << tam[i];
					i++; dem++;
				}
				else if (key == 13){
					if (dem != 0) {
						cout << endl;
						tam[i] = '\0';
						break;
					}
				}
				else if (key == 8){
					if (i != 0){
						cout << "\b" << " " << "\b";
						i--; dem--;
						tam[i] = '\0';
					}
				}
			}
			else{
				if (key == 13) {
					cout << endl;
					tam[i] = '\0';
					break;
				}
				else if (key == 8){
					if (i != 0){
						cout << "\b" << " " << "\b";
						i--; dem--;
						tam[i] = '\0';
					}
				}
			}
		}
	}
	for (int j = 0; j < strlen(tam)+1; j++)
		chuoi[j] = tam[j];
}
void nhapMa(char chuoi[], int size) {
	char* tam = new char[size];
	int i = 0; char key; int dem = 0;
	while (1){
		if (_kbhit()){
			key = _getch();
			if (dem < size-1 ){
				 if (((key >= 65 && key <= 90) || (key >= 97 && key <= 122) 
				 		|| (key >= 48 && key <= 57))&&!kiemTraPhimMuiTen()){
					tam[i] = key;
					cout << tam[i];
					i++; dem++;
				}
				else if (key == 13){
					if (dem != 0) {
						cout << endl;
						tam[i] = '\0';
						break;
					}
				}
				else if (key == 8){
					if (i != 0){
						cout << "\b" << " " << "\b";
						i--; dem--;
						tam[i] = '\0';
					}
				}
			}
			else{
				if (key == 13) {
					cout << endl;
					tam[i] = '\0';
					break;
				}
				else if (key == 8){
					if (i != 0){
						cout << "\b" << " " << "\b";
						i--; dem--;
						tam[i] = '\0';
					}
				}
			}
		}
	}
	for (int j = 0; j < strlen(tam)+1; j++)
		chuoi[j] = tam[j];
}
void nhapPass(char chuoi[], int size) {
	char* tam = new char[size];
	int i = 0; char key; int dem = 0;
	while (1){
		if (_kbhit()){
			key = _getch();
			if (dem < size-1 ){
				 if (((key >= 65 && key <= 90) || (key >= 97 && key <= 122) 
				 		|| (key == 32) || (key==46) || (key==95) || (key >= 48 && key <= 57))&&!kiemTraPhimMuiTen()){
					tam[i] = key;
					cout << "*";
					i++; dem++;
				}
				else if (key == 13){
					if (dem != 0) {
						cout << endl;
						tam[i] = '\0';
						break;
					}
				}
				else if (key == 8){
					if (i != 0){
						cout << "\b" << " " << "\b";
						i--; dem--;
						tam[i] = '\0';
					}
				}
			}
			else{
				if (key == 13) {
					cout << endl;
					tam[i] = '\0';
					break;
				}
				else if (key == 8){
					if (i != 0){
						cout << "\b" << " " << "\b";
						i--; dem--;
						tam[i] = '\0';
					}
				}
			}
		}
	}
	for (int j = 0; j < strlen(tam)+1; j++)
		chuoi[j] = tam[j];
}
void nhapChu(char chuoi[], int size) {
	char* tam = new char[size];
	int i = 0; char key; int dem = 0;
	while (1){
		if (_kbhit()){
			key = _getch();
			if (dem < size - 1){
				if (((key >= 65 && key <= 90) || (key >= 97 && key <= 122) ||
					 (key == 32)) && !kiemTraPhimMuiTen()) {
					tam[i] = key;
					cout << tam[i];
					i++; dem++;
				}
				else if (key == 13){
					if (dem != 0) {
						cout << endl;
						tam[i] = '\0';
						break;
					}
				}
				else if (key == 8){
					if (i != 0){
						cout << "\b" << " " << "\b";
						i--; dem--;
						tam[i] = '\0';
					}
				}
			}
			else{
				if (key == 13) {
					cout << endl;
					tam[i] = '\0';
					break;
				}
				else if (key == 8){
					if (i != 0){
						cout << "\b" << " " << "\b";
						i--; dem--;
						tam[i] = '\0';
					}
				}
			}
		}
	}
	for (int j = 0; j < strlen(tam) + 1; j++)
		chuoi[j] = tam[j];
}
void nhapDAD(char chuoi[], int size) {
	char* tam = new char[size];
	int i = 0; char key; int dem = 0;
	while (1){
		if (_kbhit()){
			key = _getch();
			if (dem < size - 1){
				if (((key >= 65 && key <= 68) || (key >= 97 && key <= 100) ||
					 (key == 32)) && !kiemTraPhimMuiTen()) {
					tam[i] = key;
					cout << tam[i];
					i++; dem++;
				}
				else if (key == 13){
					if (dem != 0) {
						cout << endl;
						tam[i] = '\0';
						break;
					}
				}
				else if (key == 8){
					if (i != 0){
						cout << "\b" << " " << "\b";
						i--; dem--;
						tam[i] = '\0';
					}
				}
			}
			else{
				if (key == 13) {
					cout << endl;
					tam[i] = '\0';
					break;
				}
				else if (key == 8){
					if (i != 0){
						cout << "\b" << " " << "\b";
						i--; dem--;
						tam[i] = '\0';
					}
				}
			}
		}
	}
	for (int j = 0; j < strlen(tam) + 1; j++)
		chuoi[j] = tam[j];
}
bool kiemTraRong(char chuoi[]){
	int i = 0;
	while (chuoi[i] == ' ')i++;
	if (strlen(chuoi) == i){
		return 1;
	}
	else return 0;
}
void xoaKhoangTrang(char chuoi[]){
	//xoa 2 kc ke nhau
	int n = strlen(chuoi);
	for (int i = 0; i < n; i++){
		if (chuoi[i] == chuoi[i + 1] && chuoi[i] == ' '){
			for (int j = i + 1; j < n; j++)
				chuoi[j] = chuoi[j + 1];
			n--;i--;
		}
	}
	chuoi[n] = '\0';
	//xoa dau
	int i = 0;
	if (chuoi[i] == ' ') 
		for (i; i < strlen(chuoi); i++)
			chuoi[i] = chuoi[i + 1];
	//xoa cuoi
	int j = strlen(chuoi) - 1;
	if (chuoi[j] == ' ')chuoi[j] = '\0';
}

int charToInt(char chuoi[], int sl)   
{
	int i = 0;
	int kq = 0; int t = 1;
	for (int i = 0; i < sl; i++)
	{
		kq = kq + (((int)(chuoi[sl - i - 1]) - 48) * t);
		t = t * 10;
	}
	return kq;
}
int charToInt(char chuoi[]) {
	int i = 0;
	int kq = 0; int t = 1;
	for (int i = 0; i<strlen(chuoi); i++)
	{
		kq = kq + (((int)(chuoi[strlen(chuoi) - i - 1]) - 48) * t);
		t = t * 10;
	}
	return kq;
}
void nhapSoChar(char a[], int size) {
	char *ID = new char[size];
	int i = 0; char key; int dem = 0;
	while (1)
	{
		key = _getch();
		if (dem < size - 1)
		{
			if (key >= 48 && key <= 57)  
			{
				ID[i] = key;
				cout << ID[i];
				i++; dem++;
			}
			else if (key == 13)  
			{
				if (dem != 0) {
					cout << endl;
					ID[i] = '\0';
					break;
				}
			}
			else if (key == 8) 
			{
				if (i != 0)
				{
					cout << "\b" << " " << "\b";
					i--; dem--;
					ID[i] = '\0';
				}
			}
		}
		else                      
		{
			if (key == 13)
			{
				if (dem != 0) {
					cout << endl;
					ID[i] = '\0';
					break;
				}
			}
			else if (key == 8)
			{
				if (i != 0)
				{
					cout << "\b" << " " << "\b";
					i--; dem--;
					ID[i] = '\0';
				}
			}
		}
	}
	for (int j = 0; j < strlen(ID) + 1; j++)
		a[j] = ID[j];
}
void nhapSoInt(int &so, int size)
{
	char *ID = new char[size];
	int i = 0; char key; int dem = 0;
	while (1)
	{
		key = _getch();
		if (dem < size-1)
		{
			if (key >= 48 && key <= 57)  
			{
				ID[i] = key;
				cout << ID[i];
				i++; dem++;
			}
			else if (key == 13) 
			{
				if (dem != 0) {
					cout << endl;
					ID[i] = '\0';
					break;
				}
			}
			else if (key == 8)
			{
				if (i != 0)
				{
					cout << "\b" << " " << "\b";
					i--; dem--;
					ID[i] = '\0';
				}
			}
		}
		else                         
		{
			if (key == 13)
			{
				if (dem != 0) {
					cout << endl;
					ID[i] = '\0';
					break;
				}
			}
			else if (key == 8)
			{
				if (i != 0)
				{
					cout << "\b" << " " << "\b";
					i--; dem--;
					ID[i] = '\0';
				}
			}
		}
	}
	so = charToInt(ID, dem);
	delete ID;
}
void nhapNK(char chuoi[], int size) {
	char *c = new char[size];
	int i = 0; char key; int dem = 0;
	while (1){
		key = _getch();
		if (dem < size - 1){
			if (key >= 48 && key <= 57 || key==44 || key==45 || key==95){
				c[i] = key;
				cout << c[i];
				i++; dem++;
			}
			else if (key == 13){
				if (dem != 0) {
					cout << endl;
					c[i] = '\0';
					break;
				}
			}
			else if (key == 8){
				if (i != 0){
					cout << "\b" << " " << "\b";
					i--; dem--;
					c[i] = '\0';
				}
			}
		}
		else{
			if (key == 13){
				if (dem != 0) {
					cout << endl;
					c[i] = '\0';
					break;
				}
			}
			else if (key == 8){
				if (i != 0){
					cout << "\b" << " " << "\b";
					i--; dem--;
					c[i] = '\0';
				}
			}
		}
	}
	for (int j = 0; j < strlen(c) + 1; j++)
		chuoi[j] = c[j];
}
void nhapNoiDungCH(char chuoi[], int size) {
	char *c = new char[size];
	int i = 0; char key; int dem = 0;
	while (1){
		key = _getch();
		if (dem < size - 1){
			if (key >= 32 && key <= 126){
				c[i] = key;
				cout << c[i];
				i++; dem++;
			}
			else if (key == 13){
				if (dem != 0) {
					cout << endl;
					c[i] = '\0';
					break;
				}
			}
			else if (key == 8){
				if (i != 0){
					cout << "\b" << " " << "\b";
					i--; dem--;
					c[i] = '\0';
				}
			}
		}
		else{
			if (key == 13){
				if (dem != 0) {
					cout << endl;
					c[i] = '\0';
					break;
				}
			}
			else if (key == 8){
				if (i != 0){
					cout << "\b" << " " << "\b";
					i--; dem--;
					c[i] = '\0';
				}
			}
		}
	}
	for (int j = 0; j < strlen(c) + 1; j++)
		chuoi[j] = c[j];
}
void inHoaTatCa(char chuoi[]) {
	for (int i=0; i < strlen(chuoi); i++) {
		if (chuoi[i] >= 97 && chuoi[i] <= 122) {
			chuoi[i] = chuoi[i] - 32;
		}
	}
}
bool kiemTraFileRong(fstream &file) {
	if (!file.is_open()) {
		cout << "Chua mo duoc file!!!" << endl;
		return false;
	}
	else {
		file.seekp(0, ios::end);
		size_t size = file.tellg();
		file.seekp(0, ios::beg);
		if (size == 0)
			return true;
		else
			return false;
	}
}
char* stringToChar(string a) {
	int size = a.length()+1;
	char* tam = new char[size];
	for (int i = 0; i < size; i++) {
		tam[i] = a[i];
	}
	tam[size] = '\0';
	return tam;
}
string charToString(char* a, int size) { 
    int i; 
    string s = "";
    for (i = 0; i < size; i++) { 
        s = s + a[i]; 
        
    } 
    return s; 
} 
int inputKey(){
	if (_kbhit()){
		int key = _getch();

		if (key == 224){
			key = _getch();
			return key + 1000;
		}
		return key;
	}
	else{
		return -1;
	}
	return -1;
}
void veKhung(int x, int y, char cao, char rong, int mau) {
	textColor(mau);
	char ngang=205; char doc=186;
	for (int i = 0; i < rong; i++) {
		gotoXY(i+x, 0+y);
	    cout << ngang;
		gotoXY(i+x, cao+y);
		cout << ngang;
    }
    for (int i = 0; i < cao; i++) {
		gotoXY(0+x, i+y);
		cout << doc;
		gotoXY(rong+x, i+y);
		cout << doc;
    }
	char a = 201;
	gotoXY(0+x, 0+y);
	cout << a;
	char b = 200;
	gotoXY(0+x, cao+y);
	cout << b;
	char c = 187;
	gotoXY(rong+x, 0+y);
	cout << c;
	char d = 188;
	gotoXY(rong+x, cao+y);
	cout << d;
	gotoXY(1+x, 1+y);
}
void veKhungThemMH(int x, int y, char cao, char rong, int mau) {
	textColor(mau);
	char ngang=205; char doc=186;
	for (int i = 0; i < rong; i++) {
		gotoXY(i+x, 0+y);
	    cout << ngang;
		gotoXY(i+x, cao+y);
		cout << ngang;
    }
    for(int i=0; i<rong; i++){
    	gotoXY(i+x, 3+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 6+y);
    	cout<<ngang;
	}
    for (int i = 0; i < cao; i++) {
		gotoXY(0+x, i+y);
		cout << doc;
		gotoXY(rong+x, i+y);
		cout << doc;
    }
	char a = 201;
	gotoXY(0+x, 0+y);
	cout << a;
	char b = 200;
	gotoXY(0+x, cao+y);
	cout << b;
	char c = 187;
	gotoXY(rong+x, 0+y);
	cout << c;
	char d = 188;
	gotoXY(rong+x, cao+y);
	cout << d;
	gotoXY(1+x, 1+y);
}
void veKhungThemLop(int x, int y, char cao, char rong, int mau) {
	textColor(mau);
	char ngang=205; char doc=186;
	for (int i = 0; i < rong; i++) {
		gotoXY(i+x, 0+y);
	    cout << ngang;
		gotoXY(i+x, cao+y);
		cout << ngang;
    }
    for(int i=0; i<rong; i++){
    	gotoXY(i+x, 3+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 6+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 9+y);
    	cout<<ngang;
	}
    for (int i = 0; i < cao; i++) {
		gotoXY(0+x, i+y);
		cout << doc;
		gotoXY(rong+x, i+y);
		cout << doc;
    }
	char a = 201;
	gotoXY(0+x, 0+y);
	cout << a;
	char b = 200;
	gotoXY(0+x, cao+y);
	cout << b;
	char c = 187;
	gotoXY(rong+x, 0+y);
	cout << c;
	char d = 188;
	gotoXY(rong+x, cao+y);
	cout << d;
	gotoXY(1+x, 1+y);
}
void veKhungThemSV(int x, int y, char cao, char rong, int mau) {
	textColor(mau);
	char ngang=205; char doc=186;
	for (int i = 0; i < rong; i++) {
		gotoXY(i+x, 0+y);
	    cout << ngang;
		gotoXY(i+x, cao+y);
		cout << ngang;
    }
    for(int i=0; i<rong; i++){
    	gotoXY(i+x, 3+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 6+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 9+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 12+y);
    	cout<<ngang;
	}
    for (int i = 0; i < cao; i++) {
		gotoXY(0+x, i+y);
		cout << doc;
		gotoXY(rong+x, i+y);
		cout << doc;
    }
	char a = 201;
	gotoXY(0+x, 0+y);
	cout << a;
	char b = 200;
	gotoXY(0+x, cao+y);
	cout << b;
	char c = 187;
	gotoXY(rong+x, 0+y);
	cout << c;
	char d = 188;
	gotoXY(rong+x, cao+y);
	cout << d;
	gotoXY(1+x, 1+y);
}
void veKhungThemCH(int x, int y, char cao, char rong, int mau) {
	textColor(mau);
	char ngang=205; char doc=186;
	for (int i = 0; i < rong; i++) {
		gotoXY(i+x, 0+y);
	    cout << ngang;
		gotoXY(i+x, cao+y);
		cout << ngang;
    }
    for(int i=0; i<rong; i++){
    	gotoXY(i+x, 3+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 6+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 9+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 12+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 15+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 18+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 21+y);
    	cout<<ngang;
	}
    for (int i = 0; i < cao; i++) {
		gotoXY(0+x, i+y);
		cout << doc;
		gotoXY(rong+x, i+y);
		cout << doc;
    }
	char a = 201;
	gotoXY(0+x, 0+y);
	cout << a;
	char b = 200;
	gotoXY(0+x, cao+y);
	cout << b;
	char c = 187;
	gotoXY(rong+x, 0+y);
	cout << c;
	char d = 188;
	gotoXY(rong+x, cao+y);
	cout << d;
	gotoXY(1+x, 1+y);
}
void veKhungInLopTheoNK(int x, int y, char cao, char rong, int mau) {
	clrscr();
	textColor(10);
	gotoXY(6,3); cout<<"STT";
	gotoXY(20,3); cout<<"MA LOP";
	gotoXY(62,3); cout<<"TEN LOP";
	gotoXY(100,3); cout<<"NIEN KHOA";
	textColor(15);
	textColor(mau);
	char ngang=205; char doc=186;
	for (int i = 0; i < rong; i++) {
		gotoXY(i+x, 0+y);
	    cout << ngang;
		gotoXY(i+x, cao+y);
		cout << ngang;
    }
    for(int i=0; i<rong; i++){
    	gotoXY(i+x, 2+y);
    	cout<<ngang;
	}
    for(int i=0; i<rong; i++){
    	gotoXY(i+x, 4+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 6+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 8+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 10+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 12+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 14+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 16+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 18+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 20+y);
    	cout<<ngang;
	}
	for(int i=1; i<cao; i++){
    	gotoXY(5+x, i+y);
    	cout<<doc;
	}
	for(int i=1; i<cao; i++){
    	gotoXY(30+x, i+y);
    	cout<<doc;
	}
	for(int i=1; i<cao; i++){
    	gotoXY(90+x, i+y);
    	cout<<doc;
	}
    for (int i = 0; i < cao; i++) {
		gotoXY(0+x, i+y);
		cout << doc;
		gotoXY(rong+x, i+y);
		cout << doc;
    }
	char a = 201;
	gotoXY(0+x, 0+y);
	cout << a;
	char b = 200;
	gotoXY(0+x, cao+y);
	cout << b;
	char c = 187;
	gotoXY(rong+x, 0+y);
	cout << c;
	char d = 188;
	gotoXY(rong+x, cao+y);
	cout << d;
	gotoXY(1+x, 1+y);
}
void veKhungInBangDiem1MonCua1Lop(int x, int y, char cao, char rong, int mau, char tenLop[], char tenMon[]) {
	clrscr();
	textColor(14);
	gotoXY(44,3); cout << "MA LOP: "<<tenLop; cout<<" | "; cout<<"MA MON HOC: "; cout<<tenMon;
	textColor(10);
	gotoXY(8,5); cout<<"STT";
	gotoXY(22,5); cout<<"MSSV";
	gotoXY(64,5); cout<<"HO TEN";
	gotoXY(103,5); cout<<"DIEM";
	textColor(15);
	textColor(mau);
	char ngang=205; char doc=186;
	for (int i = 0; i < rong; i++) {
		gotoXY(i+x, 0+y);
	    cout << ngang;
		gotoXY(i+x, cao+y);
		cout << ngang;
    }
    for(int i=0; i<rong; i++){
    	gotoXY(i+x, 2+y);
    	cout<<ngang;
	}
    for(int i=0; i<rong; i++){
    	gotoXY(i+x, 4+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 6+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 8+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 10+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 12+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 14+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 16+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 18+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 20+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 22+y);
    	cout<<ngang;
	}
	for(int i=3; i<cao; i++){
    	gotoXY(5+x, i+y);
    	cout<<doc;
	}
	for(int i=3; i<cao; i++){
    	gotoXY(30+x, i+y);
    	cout<<doc;
	}
	for(int i=3; i<cao; i++){
    	gotoXY(90+x, i+y);
    	cout<<doc;
	}
    for (int i = 0; i < cao; i++) {
		gotoXY(0+x, i+y);
		cout << doc;
		gotoXY(rong+x, i+y);
		cout << doc;
    }
	char a = 201;
	gotoXY(0+x, 0+y);
	cout << a;
	char b = 200;
	gotoXY(0+x, cao+y);
	cout << b;
	char c = 187;
	gotoXY(rong+x, 0+y);
	cout << c;
	char d = 188;
	gotoXY(rong+x, cao+y);
	cout << d;
	gotoXY(1+x, 1+y);
}
void veKhungDangNhap(){
	textColor(15);
	gotoXY(51,6); cout<<"DANG NHAP";
	veKhung(50,5,2,10,15);
	textColor(15);
	gotoXY(31,11); cout<<"USER: ";
	veKhung(37,10,2,40,15);
	textColor(15);
	gotoXY(31,14); cout<<"PASS: ";
	veKhung(37,13,2,40,15);
	veKhung(24,2,22,60,15);
}
void veKhungThi(int x, int y, char cao, char rong, int mau) {
	textColor(mau);
	char ngang=205; char doc=186;
	for (int i = 0; i < rong; i++) {
		gotoXY(i+x, 0+y);
	    cout << ngang;
		gotoXY(i+x, cao+y);
		cout << ngang;
    }
    for(int i=0; i<rong; i++){
    	gotoXY(i+x, 3+y);
    	cout<<ngang;
	}
	for(int i=0; i<rong; i++){
    	gotoXY(i+x, 18+y);
    	cout<<ngang;
	}
	for(int i=1; i<cao-2; i++){
    	gotoXY(rong-21+x, i+y);
    	cout<<doc;
	}
    for (int i = 0; i < cao; i++) {
		gotoXY(0+x, i+y);
		cout << doc;
		gotoXY(rong+x, i+y);
		cout << doc;
    }
	char a = 201;
	gotoXY(0+x, 0+y);
	cout << a;
	char b = 200;
	gotoXY(0+x, cao+y);
	cout << b;
	char c = 187;
	gotoXY(rong+x, 0+y);
	cout << c;
	char d = 188;
	gotoXY(rong+x, cao+y);
	cout << d;
	gotoXY(1+x, 1+y);
}

void ThanhMenu(int vitrix, int vitriy, int mau, string title){
	gotoXY(vitrix, vitriy);
	textColor(mau);
	cout << title;
	resetMauMacDinh();
}
