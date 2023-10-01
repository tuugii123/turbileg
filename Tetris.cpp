#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <dos.h>
#include <windows.h>

using namespace std;

int tetr[100][100];
bool bl = false;
bool lr = false;
bool c = false;
queue <int> Q;
queue <int> C;

int sx1, sx2, sx3, sx4;
int sy1, sy2, sy3, sy4;
int x1, x2, x3, x4;
int Y1, y2, y3, y4;
int d, p, w, t1;
int Rand, last;
int Lvl = 1, Speed = 125;
int Line;
int Rd;
int rd;

void textcolor(int fc,int bc=-1){
	if(fc<0 || fc>15)
		return;
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	if(bc>=0 && bc<16)
		SetConsoleTextAttribute(h,fc|bc*16);
	else
		SetConsoleTextAttribute(h,fc);
}

void textcolor(char *fc,char *bc=""){
	int x,y=16;
	char *colors[]={"Black","Blue","Green","Aqua","Red","Purple","Yellow","White","Gray",
	"LightBlue","LightGreen","LightAqua","LightRed","LightPurple","LightYellow","BrightWhite"};
	for(x=0;x<16;x++)
		if(strcmpi(colors[x],fc)==0)
			break;
	if(strlen(bc)>0)
		for(y=0;y<16;y++)
			if(strcmpi(colors[y],bc)==0)
				break;
	textcolor(x,y);
}

void textcolor(char *fc,int bc){
	int x;
	char *colors[]={"Black","Blue","Green","Aqua","Red","Purple","Yellow","White","Gray",
	"LightBlue","LightGreen","LightAqua","LightRed","LightPurple","LightYellow","BrightWhite"};
	for(x=0;x<16;x++)
		if(strcmpi(colors[x],fc)==0)
			break;
	textcolor(x,bc);
}

void textcolor(int fc,char *bc){
	int y;
	char *colors[]={"Black","Blue","Green","Aqua","Red","Purple","Yellow","White","Gray",
	"LightBlue","LightGreen","LightAqua","LightRed","LightPurple","LightYellow","BrightWhite"};
	if(strlen(bc)>0)
		for(y=0;y<16;y++)
			if(strcmpi(colors[y],bc)==0)
				break;
	textcolor(fc,y);
}

void Color(int x) {
	if (x == 1) textcolor("LightAqua");
	if (x == 2) textcolor("Blue");
	if (x == 3) textcolor("Yellow");
	if (x == 4) textcolor("LightGreen");
	if (x == 5) textcolor("Red");
	if (x == 6) textcolor("LightPurple");
	if (x == 7) textcolor("LightYellow");
	
	return ;
}

void FPS() {
	HANDLE hout;
	CONSOLE_CURSOR_INFO cursor;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cursor.dwSize=1;
	cursor.bVisible=false;
	SetConsoleCursorInfo(hout, &cursor);
}


void gotoxy (int x, int y) {
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}

void Kbhit () {
		if ( kbhit() ) {
		switch(getch())  {
			case 75 : { d = 1; } break;
			case 72 : { d = 2; } break;
			case 77 : { d = 3; } break;
			case 80 : { d = 4; } break; 
			case 32 : { d = 5; } break; //space
			case 99 : { d = 6; } break; //c
		}
 }
}

void LR(int d) {
	//Sleep(125); !!!!!!!!!!!!!!!!
	if (!tetr[x1][Y1 + 1] && !tetr[x2][y2 + 1] && !tetr[x3][y3 + 1] && !tetr[x4][y4 + 1]) {
		//if (!d) Sleep(150);
		
		Color(Rand);
		gotoxy(x1, Y1); cout << "  ";
		gotoxy(x2, y2); cout << "  ";
		gotoxy(x3, y3); cout << "  ";
		gotoxy(x4, y4); cout << "  ";
		Y1++; y2++;
		y3++; y4++;
		gotoxy(x1, Y1); cout << "[]";
		gotoxy(x2, y2); cout << "[]";
		gotoxy(x3, y3); cout << "[]";
		gotoxy(x4, y4); cout << "[]";
	}
	
}

void Svvder(int x1, int Y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	sx1 = x1; sx2 = x2; sx3 = x3; sx4 = x4;
	sy1 = Y1; sy2 = y2; sy3 = y3; sy4 = y4;
	while (!tetr[sx1][sy1 + 1] && !tetr[sx2][sy2 + 1] && !tetr[sx3][sy3 + 1] && !tetr[sx4][sy4 + 1]) {
		sy1 ++; sy2 ++;
		sy3 ++; sy4 ++;
	}
	
	textcolor("Gray");
	gotoxy(sx1, sy1); cout << "[]";
	gotoxy(sx2, sy2); cout << "[]";
	gotoxy(sx3, sy3); cout << "[]";
	gotoxy(sx4, sy4); cout << "[]";
}

void Svvder_Clear(int x1, int Y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	gotoxy(x1, Y1); cout << "  ";
	gotoxy(x2, y2); cout << "  ";
	gotoxy(x3, y3); cout << "  ";
	gotoxy(x4, y4); cout << "  ";
}

void Delete() {
	//cout << "YES\n";
	for (int j = 24; j <= 44; j++) {
		bool bl = true;
		
		for (int i = 26; i <= 45; i+=2) {
			if (!tetr[i][j]) bl = false;
		}
		
		if (bl) {
			for (int i = 26; i <= 45; i+=2) {
				tetr[i][j] = 0;
				gotoxy(i, j);
				cout << "  ";
			}
			
			Line ++;
			gotoxy(20, 35); cout << "   ";
			textcolor("LightGreen");
			gotoxy(21, 35); cout << Line;
			if (Line % 10 == 0) {
				Lvl ++;
				if (Speed - 20 >= 25) Speed -= 20;
			}
			
			gotoxy(21, 36); cout << "   ";
			textcolor("LightGreen");
			gotoxy(22, 36); cout << Lvl;
			
			gotoxy(21, 37); cout << "   ";
			textcolor("LightGreen");
			gotoxy(22, 37); cout << 145 - Speed;
		}
	}
	
	int p = 25;
	while (p--) {
		for (int j = 24; j <= 44; j++) {
			bool bl = true;
			for (int i = 26; i <= 45; i+=2) {
				if (tetr[i][j]) bl = false;
			}
			
			if (bl) {
				for (int i = 26; i <= 45; i+=2) {
					swap(tetr[i][j], tetr[i][j - 1]);
					gotoxy(i, j - 1);
					cout << "  ";
					gotoxy(i, j);
					Color(tetr[i][j]);
					if (tetr[i][j]) cout << "[]";
				}
			}
		}
	}
}

void hold_clear() {
	gotoxy(16, 26); cout << "        ";
	gotoxy(16, 27); cout << "        ";
	
	return ;
}

void Cls(int Rand, int x1, int Y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	Color(Rand);
	gotoxy(x1, Y1); cout << "[]";
	gotoxy(x2, y2); cout << "[]";
	gotoxy(x3, y3); cout << "[]";
	gotoxy(x4, y4); cout << "[]";
}

void Print(int Rand, int x, int y) {
	Color(Rand);
	
	gotoxy(x, y);
	if (Rand == 1) {
		cout << "[][][][]";
		return ;
	}
	if (Rand == 2) {
		cout << "[]";
		gotoxy(x, y + 1);
		cout << "[][][]";
		return ;
	}
	if (Rand == 3) {
		gotoxy(x, y + 1);
		cout << "[][][]";
		gotoxy(x + 4, y);
		cout << "[]";
		return ;
	}
	if (Rand == 4) {
		gotoxy(x, y + 1);
		cout << "[][]";
		gotoxy(x + 2, y);
		cout << "[][]";
		return ;
	}
	if (Rand == 5) {
		cout << "[][]";
		gotoxy(x + 2, y + 1);
		cout << "[][]";
		return ;
	}
	if (Rand == 6) {
		gotoxy(x, y + 1);
		cout << "[][][]";
		gotoxy(x + 2, y);
		cout << "[]";
		return ;
	}
	if (Rand == 7) {
		gotoxy(x + 2,y);
		cout << "[][]";
		gotoxy(x + 2, y + 1);
		cout << "[][]";
		return ;
	}
}

void Spin(int Rand) {
	int xx1, xx2, xx3, xx4;
	int yy1, yy2, yy3, yy4;
	int p = 3;
		
	bool T = false;	
	xx1 = x1; xx2 = x2; xx3 = x3; xx4 = x4;
	yy1 = Y1; yy2 = y2; yy3 = y3; yy4 = y4; 
	
	
	while (p--) {
		if (Rand == 1) {
			if (t1 == 0) {
				if (!tetr[x1 + 2][Y1 - 2] && !tetr[x2][y2 - 1] && !tetr[x3 - 2][y3] && !tetr[x4 - 4][y4 + 1]) {
					x1 += 2; Y1 -= 2;
					y2 -= 1;
					x3 -= 2;
					x4 -= 4; y4 += 1;
						
					T = true;		
					t1 ++;
				}
			}
			else if (t1 == 1) {
				if (!tetr[x1 - 2][Y1 + 2] && !tetr[x2][y2 + 1] && !tetr[x3 + 2][y3] && !tetr[x4 + 4][y4 - 1]) {
					x1 -= 2; Y1 += 2;
					y2 += 1;
					x3 += 2;
					x4 += 4; y4 -= 1;
					
					T = true;
					t1 ++;
				}
			}
			else if (t1 == 2) {
				if (!tetr[x1 + 4][Y1 - 2] && !tetr[x2 + 2][y2 - 1] && !tetr[x3][y3] && !tetr[x4 - 2][y4 + 1]) {
					x1 += 4; Y1 -= 2;
					x2 += 2; y2 -= 1;
					x4 -= 2; y4 += 1;
					
					T = true;	
					t1 ++;
				}
			}
			else if (t1 == 3) {
				if (!tetr[x1 - 4][Y1 + 2] && !tetr[x2 - 2][y2 + 1] && !tetr[x3][y3] && !tetr[x4 + 2][y4 - 1]) {
					x1 -= 4; Y1 += 2;
					x2 -= 2; y2 += 1;
					x4 += 2; y4 -= 1;
					
					T = true;
					t1 ++;
				}
			}
		}
		else if (Rand == 2) {
			if (t1 == 0) {
				if (!tetr[x1 + 2][Y1 - 1] && !tetr[x2][y2 - 2] && !tetr[x3 - 2][y3 - 1] && !tetr[x4 - 4][y4]) {
					x1 += 2; Y1 -= 1;
					y2 -= 2;
					x3 -= 2; y3 -= 1;
					x4 -= 4;
					
					T = true;
					t1 ++;
				}
			}
			else if (t1 == 1) {
				if (!tetr[x1 + 2][Y1 + 1] && !tetr[x2 + 4][y2] && !tetr[x3 + 2][y3 - 1] && !tetr[x4][y4 - 2]) {
					x1 += 2; Y1 += 1;
					x2 += 4;
					x3 += 2; y3 -= 1;
					y4 -= 2;
					
					T = true;
					t1 ++;
				}
			}
			else if (t1 == 2) {
				if (!tetr[x1 - 2][Y1 + 1] && !tetr[x2][y2 + 2] && !tetr[x3 + 2][y3 + 1] && !tetr[x4 + 4][y4]) {
					x1 -= 2; Y1 += 1;
					y2 += 2;
					x3 += 2; y3 += 1;
					x4 += 4;
					
					T = true;
					t1 ++;
				}
			}
			else if (t1 == 3) {
				if (!tetr[x1 - 2][Y1 - 1] && !tetr[x2 - 4][y2] && !tetr[x3 - 2][y3 + 1] && !tetr[x4][y4 + 2]) {
					x1 -= 2; Y1 -= 1;
					x2 -= 4;
					x3 -= 2; y3 += 1;
					y4 += 2;
					
					T = true;
					t1 ++;
				}
			}
		}
		else if (Rand == 3) {
			if (t1 == 0) {
				if (!tetr[x1][Y1 - 2] && !tetr[x2 - 2][y2 - 1] && !tetr[x3 - 4][y3] && !tetr[x4 - 2][y4 + 1]) {
					Y1 -= 2;
					x2 -= 2; y2 -= 1;
					x3 -= 4; 
					x4 -= 2; y4 += 1;
					
					T = true;
					t1 ++;	
				}
			}
			else if (t1 == 1) {
				if (!tetr[x1 + 4][Y1] && !tetr[x2 + 2][y2 - 1] && !tetr[x3][y3 - 2] && !tetr[x4 - 2][y4 - 1]) {
					x1 += 4;
					x2 += 2; y2 -= 1;
					y3 -= 2; 
					x4 -= 2; y4 -= 1;
					
					T = true;
					t1 ++;	
				}
			}
			else if (t1 == 2) {
				if (!tetr[x1][Y1 + 2] && !tetr[x2 + 2][y2 + 1] && !tetr[x3 + 4][y3] && !tetr[x4 + 2][y4 - 1]) {
					Y1 += 2;
					x2 += 2; y2 += 1;
					x3 += 4; 
					x4 += 2; y4 -= 1;
					
					T = true;
					t1 ++;	
				}
			}
			else if (t1 == 3) {
				if (!tetr[x1 - 4][Y1] && !tetr[x2 - 2][y2 + 1] && !tetr[x3][y3 + 2] && !tetr[x4 + 2][y4 + 1]) {
					x1 -= 4;
					x2 -= 2; y2 += 1;
					y3 += 2; 
					x4 += 2; y4 += 1;
					
					T = true;
					t1 ++;	
				}				
			}
		}
		else if (Rand == 4) {
			if (t1 == 0 || t1 == 2) {
				if (!tetr[x1][Y1 - 2] && !tetr[x2 - 2][y2 - 1] && !tetr[x3][y3] && !tetr[x4 - 2][y4 + 1]) {
					Y1 -= 2;
					x2 -= 2; y2 -= 1;
					x4 -= 2; y4 += 1;
					
					T = true;
					t1 ++;	
				}
			}
			else if (t1 == 1 || t1 == 3) {
				if (!tetr[x1][Y1 + 2] && !tetr[x2 + 2][y2 + 1] && !tetr[x3][y3] && !tetr[x4 + 2][y4 - 1]) {
					Y1 += 2;
					x2 += 2; y2 += 1;
					x4 += 2; y4 -= 1;
				
					T = true;
					t1 ++;
				}
			}
		}
		else if (Rand == 5) {
			if (t1 == 0 || t1 == 2) {
				if (!tetr[x1 + 2][Y1 - 1] && !tetr[x2][y2] && !tetr[x3 - 2][y3 - 1] && !tetr[x4 - 4][y4]) {
					x1 += 2; Y1 -= 1;
					x3 -= 2; y3 -= 1;
					x4 -= 4;
				
					T = true;
					t1 ++;
				}
			}
			else if (t1 == 1 || t1 == 3) {
				if (!tetr[x1 - 2][Y1 + 1] && !tetr[x2][y2] && !tetr[x3 + 2][y3 + 1] && !tetr[x4 + 4][y4]) {
					x1 -= 2; Y1 += 1;
					x3 += 2; y3 += 1;
					x4 += 4;
				
					T = true;
					t1 ++;
				}
			}
		}
		else if (Rand == 6) {
			if (t1 == 0) {
				if (!tetr[x1][Y1 - 2] && !tetr[x2 - 2][y2 - 1] && !tetr[x3][y3] && !tetr[x4 - 4][y4]) {
					Y1 -= 2;
					x2 -= 2; y2 -= 1;
					x4 -= 4;
				
					T = true;
					t1 ++;
				}
			}
			else if (t1 == 1) {
				if (!tetr[x1 + 4][Y1] && !tetr[x2 + 2][y2 - 1] && !tetr[x3][y3] && !tetr[x4][y4 - 2]) {
					x1 += 4;
					x2 += 2; y2 -= 1;
					y4 -= 2;
				
					T = true;
					t1 ++;
				}
			}
			else if (t1 == 2) {
				if (!tetr[x1][Y1 + 2] && !tetr[x2 + 2][y2 + 1] && !tetr[x3][y3] && !tetr[x4 + 4][y4]) {
					Y1 += 2;
					x2 += 2; y2 += 1;
					x4 += 4;
				
					T = true;
					t1 ++;
				}
			}
			else if (t1 == 3) {
				if (!tetr[x1 - 4][Y1] && !tetr[x2 - 2][y2 + 1] && !tetr[x3][y3] && !tetr[x4][y4 + 2]) {
					x1 -= 4;
					x2 -= 2; y2 += 1;
					y4 += 2;
				
					T = true;
					t1 ++;
				}
			}
		}
		
		if (!T && p == 2) {
			Y1 --; y2 --;
			y3 --; y4 --;
			if (tetr[x1][Y1] || tetr[x2][y2] || tetr[x3][y3] || tetr[x4][y4]) {
				Y1 --; y2 --;
				y3 --; y4 --;
			}
		}
		if (!T && p == 1) {
			Y1 --; y2 --;
			y3 --; y4 --;
			if (tetr[x1][Y1] || tetr[x2][y2] || tetr[x3][y3] || tetr[x4][y4]) {
				Y1 --; y2 --;
				y3 --; y4 --;
			}
		}
		if (!T && p == 0) {
			Y1 ++; y2 ++;
			y3 ++; y4 ++;
		}
		
		if (T) break;
	}
	
	gotoxy (xx1, yy1); cout << "  ";
	gotoxy (xx2, yy2); cout << "  ";
	gotoxy (xx3, yy3); cout << "  ";
	gotoxy (xx4, yy4); cout << "  ";
		
	Color(Rand);
	gotoxy (x1, Y1); cout << "[]";
	gotoxy (x2, y2); cout << "[]";
	gotoxy (x3, y3); cout << "[]";
	gotoxy (x4, y4); cout << "[]";
}

void Draw() {
	FPS();
	textcolor("LightGray");
	
	tetr[24][24] = tetr[46][24] = true;
	tetr[24][23] = tetr[46][23] = true;
	tetr[24][22] = tetr[46][22] = true;
	
	gotoxy(46, 46);
	for (int i = 25; i < 45; i++) {
		textcolor("LightPurple");
		gotoxy(25, i);
		cout << char(186);
		tetr[24][i] = true;
		
		gotoxy(46, i);
		cout << char(186);
		tetr[46][i] = true;
		
		if (i > 25) {
			textcolor("White");
			gotoxy(25, i - 1);
			cout << char(186);
			
			gotoxy(46, i - 1);
			cout << char(186);
		}
		
		Sleep(45);
	}
	
	textcolor("White");
	gotoxy(25, 44);		
	cout << char(186);
		
	gotoxy(46, 44);
	cout << char(186);
	
	//right
	for (int i = 25; i <= 38; i++) {
		gotoxy(57, i);
		cout << char(186);
	}
	
	gotoxy(46, 38);
	cout << char(204);
	for (int i = 47; i <= 56; i++) {
		gotoxy(i, 38);
		cout << char(205);
	}
	
	gotoxy(57, 38);
	cout << char(188);
	
	gotoxy(25, 45);
	cout << char(200);

	gotoxy(46, 45);
	cout << char(188);
	//right
	
	//left
	for(int i = 15; i <= 24; i++) {
		gotoxy(i, 29);
		cout << char(205);
	}
	
	gotoxy(25, 29);
	cout << char(185);
	
	//(14, 25)
	for (int i = 25; i <= 28; i++) {
		gotoxy(14, i);
		cout << char(186);
	}
	
	gotoxy(14, 29);
	cout << char(200);
	
	//-------------------------------
	for (int i = 15; i <= 24; i++) {
		gotoxy(i, 38);
		cout << char(205);
		gotoxy(i, 34);
		cout << char(205);
	}
	
	cout << char(185);
	gotoxy(25, 38);
	cout << char(185);
	gotoxy(14, 38);
	cout << char(200);
	gotoxy(14, 34);
	cout << char(201);
	gotoxy(14, 35); cout << char(186);
	gotoxy(14, 36); cout << char(186);
	gotoxy(14, 37); cout << char(186);
	
	//left
	
	int l = 26;
	int r = 45;
	while(l < r) {
		textcolor("LightPurple");
		gotoxy(l, 45);
		cout << char(205);
		tetr[l][45] = true;
		
		gotoxy(r, 45);
		cout << char(205);
		tetr[r][45] = true;
		
		Sleep(45);
		
		if (l > 26) {
			textcolor("White");
			gotoxy(l - 1, 45);
			cout << char(205);
				
			gotoxy(r + 1, 45);
			cout << char(205);
		}
		l ++;
		r --;
	}
	
	textcolor("White");
	gotoxy(l - 1, 45);
	cout << char(205);

	gotoxy(r + 1, 45);
	cout << char(205);
	
	gotoxy(15, 35);
	textcolor("White");
	cout << "Line: "; 
	textcolor("LightGreen");
	cout << Line << endl;
	gotoxy(15, 36);
	textcolor("White");
	cout << "Level: ";
	textcolor("LightGreen");
	cout << Lvl << endl;
	gotoxy(15, 37);
	textcolor("White");
	cout << "Speed: ";
	textcolor("LightGreen");
	cout << 145 - Speed << endl;
}

void Tetris() {
	FPS();
	
	if (C.size() > 1 || Q.size() < 4) cout << "fffffffffffffffffffff\n";
	srand(time(0));
	if (!bl) {		
		if (Rand >= 0) {
			Rand = Q.front();
			rd = rand() % 7 + 1;
			while(Rd == rd) {
				rd = rand() % 7 + 1;
			}
			Rd = rd;
			
			Q.push(Rd);
			Q.pop();
		}
		else {
			Rand *= -1;
			Rd = rd;
		}
	
		queue <int> W = Q;
		
		for (int i = 47; i <= 56; i++) {
			for (int j = 25; j <= 37; j++) {
				gotoxy(i, j);
				cout << " ";
			}
		}
		
		for (int i = 26; i <= 36; i+=3) {
			gotoxy(48 ,i);
			int dw = W.front();
			W.pop();
			
			Print(dw, 48, i);			
		}	
		
		if (Rand == 1) {
			x1 = 32; Y1 = 23;
			x2 = 34; y2 = 23;
			x3 = 36; y3 = 23;
			x4 = 38; y4 = 23;
			p = 1;
		}
		else if (Rand == 2) {
			x1 = 32; Y1 = 22;
			x2 = 32; y2 = 23;
			x3 = 34; y3 = 23;
			x4 = 36; y4 = 23;
			p = 2;			
		}
		else if (Rand == 3) {
			x1 = 32; Y1 = 23;
			x2 = 34; y2 = 23;
			x3 = 36; y3 = 23;
			x4 = 36; y4 = 22;
			p = 3;
		}
		else if (Rand == 4) {
			x1 = 32; Y1 = 23;
			x2 = 34; y2 = 23;
			x3 = 34; y3 = 22;
			x4 = 36; y4 = 22;
			p = 4;
		}
		else if (Rand == 5) {
			x1 = 32; Y1 = 22;
			x2 = 34; y2 = 22;
			x3 = 34; y3 = 23;
			x4 = 36; y4 = 23;
			p = 5;
		}
		else if (Rand == 6) {
			x1 = 32; Y1 = 23;
			x2 = 34; y2 = 23;
			x3 = 34; y3 = 22;
			x4 = 36; y4 = 23;
			p = 6;
		}
		else if (Rand == 7) {
			x1 = 34; Y1 = 23;
			x2 = 36; y2 = 23;
			x3 = 34; y3 = 22;
			x4 = 36; y4 = 22;
			p = 7;
		}
		
		if (tetr[x1][Y1] || tetr[x2][y2] || tetr[x3][y3] || tetr[x4][y4]) {
			system("cls");
			textcolor("White");
			gotoxy(50, 50);
			gotoxy(5, 32); cout << "   GGGGGGGGGGGG         A         M           M   EEEEEEEEEE     OOOOO     V           V   EEEEEEEEEE   RRRRR  ";
			gotoxy(5, 33); cout << "  G                    A A        M M       M M   E             O     O     V         V    E            R    R ";
			gotoxy(5, 34); cout << " G                    A   A       M   M   M   M   E            O       O     V       V     E            R    R ";
			gotoxy(5, 35); cout << "G       GGGGGGG      AAAAAAA      M     M     M   EEEEEEEEEE   O       O      V     V      EEEEEEEEEE   RRRRR  ";
			gotoxy(5, 36); cout << " G            G     A       A     M           M   E            O       O       V   V       E            R   R  ";
			gotoxy(5, 37); cout << "  G           G    A         A    M           M   E             O     O         V V        E            R    R ";
			gotoxy(5, 38); cout << "   GGGGGGGGGGGG   A           A   M           M   EEEEEEEEEE     OOOOO           V         EEEEEEEEEE   R     R";
			while(1) {
				getch();
			}
		}
		
		Svvder(x1, Y1, x2, y2, x3, y3, x4, y4);
		Color(p);
		bl = true;
	}
	else {		
		w = 100;
		while(w--) {
			FPS();
			Kbhit();
			Kbhit();
			Kbhit();
			Kbhit();
			Kbhit();
			Kbhit();		
			
			if (d == 1) {
				if (!tetr[x1 - 2][Y1] && !tetr[x2 - 2][y2] && !tetr[x3 - 2][y3] && !tetr[x4 - 2][y4]) {
					Color(Rand);
					gotoxy(x1, Y1); cout << "  ";
					gotoxy(x2, y2); cout << "  ";
					gotoxy(x3, y3); cout << "  ";
					gotoxy(x4, y4); cout << "  ";
					x1-=2; x2-=2;
					x3-=2; x4-=2;
					gotoxy(x1, Y1); cout << "[]";
					gotoxy(x2, y2); cout << "[]";
					gotoxy(x3, y3); cout << "[]";
					gotoxy(x4, y4); cout << "[]";

					Svvder_Clear(sx1, sy1, sx2, sy2, sx3, sy3, sx4, sy4);
					Svvder(x1, Y1, x2, y2, x3, y3, x4, y4);
					Cls(Rand, x1, Y1, x2, y2, x3, y3, x4, y4);
				}
				
				d = 0;
			}
			if (d == 2) {
				t1 = t1 % 4;
				Spin(Rand);
				
				Svvder_Clear(sx1, sy1, sx2, sy2, sx3, sy3, sx4, sy4);
				Svvder(x1, Y1, x2, y2, x3, y3, x4, y4);
				Cls(Rand, x1, Y1, x2, y2, x3, y3, x4, y4);
				d = 0;
			}
			if (d == 3) {
				if (!tetr[x1 + 2][Y1] && !tetr[x2 + 2][y2] && !tetr[x3 + 2][y3] && !tetr[x4 + 2][y4]) {
					Color(Rand);
					gotoxy(x1, Y1); cout << "  ";
					gotoxy(x2, y2); cout << "  ";
					gotoxy(x3, y3); cout << "  ";
					gotoxy(x4, y4); cout << "  ";
					x1+=2; x2+=2;
					x3+=2; x4+=2;
					gotoxy(x1, Y1); cout << "[]";
					gotoxy(x2, y2); cout << "[]";
					gotoxy(x3, y3); cout << "[]";
					gotoxy(x4, y4); cout << "[]";
				
					Svvder_Clear(sx1, sy1, sx2, sy2, sx3, sy3, sx4, sy4);
					Svvder(x1, Y1, x2, y2, x3, y3, x4, y4);
					Cls(Rand, x1, Y1, x2, y2, x3, y3, x4, y4);
				}
				
				d = 0;
			}
			if (d == 5) {
				gotoxy(x1, Y1); cout << "  ";
				gotoxy(x2, y2); cout << "  ";
				gotoxy(x3, y3); cout << "  ";
				gotoxy(x4, y4); cout << "  ";
				
				while (!tetr[x1][Y1 + 1] && !tetr[x2][y2 + 1] && !tetr[x3][y3 + 1] && !tetr[x4][y4 + 1]) {
					Y1 ++;
					y2 ++;
					y3 ++;
					y4 ++;					
				}
				
				Color(Rand);
				gotoxy(x1, Y1); cout << "[]";
				gotoxy(x2, y2); cout << "[]";
				gotoxy(x3, y3); cout << "[]";
				gotoxy(x4, y4); cout << "[]";
				tetr[x1][Y1] = tetr[x2][y2] = tetr[x3][y3] = tetr[x4][y4] = Rand;
				
				d = 0;
				
				return ;
			}
			if (d == 6 && !c) {
				gotoxy(x1, Y1); cout << "  ";		
				gotoxy(x2, y2); cout << "  ";
				gotoxy(x3, y3); cout << "  ";
				gotoxy(x4, y4); cout << "  ";
				hold_clear();
				
				if (C.empty()) {
					C.push(-1 * Rand);
					Print(Rand, 16, 26);
				}
				else {
					C.push(-1 * Rand);
					Print(Rand, 16, 26);
					Rand = C.front();
					C.pop();	
				}
				
				Svvder_Clear(sx1, sy1, sx2, sy2, sx3, sy3, sx4, sy4);
				bl = false;
				c = true;	
				d = 0;
				t1 = 0;
				return ;	
			}
		}
		if (!tetr[x1][Y1 + 1] && !tetr[x2][y2 + 1] && !tetr[x3][y3 + 1] && !tetr[x4][y4 + 1]) {
			Color(Rand);
			gotoxy(x1, Y1); cout << "  ";
			gotoxy(x2, y2); cout << "  ";
			gotoxy(x3, y3); cout << "  ";
			gotoxy(x4, y4); cout << "  ";
			Y1++; y2++;
			y3++; y4++;
			gotoxy(x1, Y1); cout << "[]";
			gotoxy(x2, y2); cout << "[]";
			gotoxy(x3, y3); cout << "[]";
			gotoxy(x4, y4); cout << "[]";
		}
		else {
			w = 6e3;
			int time = 6e3;
			while (w--) {
				FPS();
				Kbhit();
				Kbhit();
				Kbhit();
				Kbhit();
				Kbhit();
				Kbhit();
			
				if (time - w > 4000) break;
		
				if (d == 1) {
					if (!tetr[x1 - 2][Y1] && !tetr[x2 - 2][y2] && !tetr[x3 - 2][y3] && !tetr[x4 - 2][y4]) {
						Color(Rand);
						gotoxy(x1, Y1); cout << "  ";
						gotoxy(x2, y2); cout << "  ";
						gotoxy(x3, y3); cout << "  ";
						gotoxy(x4, y4); cout << "  ";
						x1-=2; x2-=2;
						x3-=2; x4-=2;
						gotoxy(x1, Y1); cout << "[]";
						gotoxy(x2, y2); cout << "[]";
						gotoxy(x3, y3); cout << "[]";
						gotoxy(x4, y4); cout << "[]";
						Svvder_Clear(sx1, sy1, sx2, sy2, sx3, sy3, sx4, sy4);
						Svvder(x1, Y1, x2, y2, x3, y3, x4, y4);
						Cls(Rand, x1, Y1, x2, y2, x3, y3, x4, y4);
					}
					
					time = w;
					d = 0;	
				}
				if (d == 2) {
					t1 = t1 % 4;
					Spin(Rand);
					
					Svvder_Clear(sx1, sy1, sx2, sy2, sx3, sy3, sx4, sy4);
					Svvder(x1, Y1, x2, y2, x3, y3, x4, y4);
					Cls(Rand, x1, Y1, x2, y2, x3, y3, x4, y4);
					
					time = w;
					d = 0;
				}
				if (d == 3) {
					if (!tetr[x1 + 2][Y1] && !tetr[x2 + 2][y2] && !tetr[x3 + 2][y3] && !tetr[x4 + 2][y4]) {
						Color(Rand);
						gotoxy(x1, Y1); cout << "  ";
						gotoxy(x2, y2); cout << "  ";
						gotoxy(x3, y3); cout << "  ";
						gotoxy(x4, y4); cout << "  ";
						x1+=2; x2+=2;
						x3+=2; x4+=2;
						gotoxy(x1, Y1); cout << "[]";
						gotoxy(x2, y2); cout << "[]";
						gotoxy(x3, y3); cout << "[]";
						gotoxy(x4, y4); cout << "[]";
						Svvder_Clear(sx1, sy1, sx2, sy2, sx3, sy3, sx4, sy4);
						Svvder(x1, Y1, x2, y2, x3, y3, x4, y4);
						Cls(Rand, x1, Y1, x2, y2, x3, y3, x4, y4);
					}
					
					time = w;
					d = 0;	
				}
				if (d == 5) {
					gotoxy(x1, Y1); cout << "  ";
					gotoxy(x2, y2); cout << "  ";
					gotoxy(x3, y3); cout << "  ";
					gotoxy(x4, y4); cout << "  ";
					
					while (!tetr[x1][Y1 + 1] && !tetr[x2][y2 + 1] && !tetr[x3][y3 + 1] && !tetr[x4][y4 + 1]) {
						Y1 ++;
						y2 ++;
						y3 ++;
						y4 ++;					
					}
					
					Color(Rand);
					gotoxy(x1, Y1); cout << "[]";
					gotoxy(x2, y2); cout << "[]";
					gotoxy(x3, y3); cout << "[]";
					gotoxy(x4, y4); cout << "[]";	
					
					d = 0;
					time = w;
					return ;
				}
				if (d == 6 && !c) {
					gotoxy(x1, Y1); cout << "  ";		
					gotoxy(x2, y2); cout << "  ";
					gotoxy(x3, y3); cout << "  ";
					gotoxy(x4, y4); cout << "  ";
					
					if (C.empty()) {
						C.push(Rand);
					}
					else {
						C.push(-1 * Rand);
						Rand = C.front();
						C.pop();
					}
					
					Svvder_Clear(sx1, sy1, sx2, sy2, sx3, sy3, sx4, sy4);
				
					c = true;
					bl = false;
					d = 0;
					t1 = 0;
					return ;	
				}	
				
				//LR(d);
				if (!tetr[x1][Y1 + 1] && !tetr[x2][y2 + 1] && !tetr[x3][y3 + 1] && !tetr[x4][y4 + 1]) {
					Color(Rand);
					gotoxy(x1, Y1); cout << "  ";
					gotoxy(x2, y2); cout << "  ";
					gotoxy(x3, y3); cout << "  ";
					gotoxy(x4, y4); cout << "  ";
					Y1++; y2++;
					y3++; y4++;
					gotoxy(x1, Y1); cout << "[]";
					gotoxy(x2, y2); cout << "[]";
					gotoxy(x3, y3); cout << "[]";
					gotoxy(x4, y4); cout << "[]";
					Sleep(Speed);
				}
			}
			
			tetr[x1][Y1] = tetr[x2][y2] = tetr[x3][y3] = tetr[x4][y4] = Rand;
			bl = false;
			c = false;
			t1 = 0;
			Delete();
		}
	}
	
	if (d) {
		Sleep(10);
		d = 0;
	}
	else Sleep(Speed);
}

int main() {
	/*
	textcolor("Black"); cout << "[] ";
	textcolor("Blue"); cout << "[] ";
	textcolor("Green"); cout << "[] ";
	textcolor("Aqua"); cout << "[] ";
	textcolor("Red"); cout << "[] ";
	textcolor("Purple"); cout << "[] ";
	textcolor("LightBlue"); cout << "[] ";
	textcolor("LightGreen"); cout << "[] ";
	textcolor("LightAqua"); cout << "[] ";
	textcolor("LightRed"); cout << "[] ";
	textcolor("LightPurple"); cout << "[] ";
	textcolor("LightYellow"); cout << "[] ";
	textcolor("BrightWhite"); cout << "[] ";
	while(1) {
		getch();
	}
	*/
	
	Draw();
	srand(time(0));
	
	Rd = rand() % 7 + 1;
	Q.push(Rd);
	
	rd = Rd;
	
	while (rd == Rd) {
		Rd = rand() % 7 + 1;
	}
	Q.push(Rd);
	rd = Rd;
	while(rd == Rd) {
		Rd = rand() % 7 + 1;
	}
	Q.push(Rd);
	rd = Rd;
	while(rd == Rd) {
		Rd = rand() % 7 + 1;
	}
	Q.push(Rd);
	
	while(true) {
		Tetris();
	}
	
	return 0;
}


/*
    
		 	GGGGGGGGGGGG         A         M           M   EEEEEEEEEE     OOOOO     V        	V   EEEEEEEEEE   RRRRR														                                                          
		   G                    A A        M M       M M   E             O     O     V		   V	E			 R    R 						
		  G                    A   A       M   M   M   M   E            O    	O	  V	      V	    E		   	 R    R						
		 G       GGGGGGG      AAAAAAA      M     M     M   EEEEEEEEEE   O       O      V     V      EEEEEEEEEE   RRRRR             										
		  G            G     A       A     M           M   E            O	    O		V   V		E			 R   R  							
		   G           G    A         A    M           M   E             O     O		 V V		E			 R    R 							
		    GGGGGGGGGGGG   A           A   M           M   EEEEEEEEEE     OOOOO           V         EEEEEEEEEE   R     R                     				
			   
*/			   
			   
			   
			   
			   
			   
			   
