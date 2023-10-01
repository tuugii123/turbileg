#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <dos.h>
#include <windows.h>

using namespace std;

int x, y, friutx, friuty, Score, fast = 90, d = 2;
queue < int > X, Y;
bool gameover=false;
bool B[102][102] = { false };
char c;

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

void gotoxy (int x, int y) {
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}

void Kbhit () {
		if ( kbhit() ) {
		switch(getch()){
			case 72 : { if ( d != 3 ) d=1; } break;
			case 77 : { if ( d != 4 ) d=2; } break;
			case 80 : { if ( d != 1 ) d=3; } break;
			case 75 : { if ( d != 2 ) d=4; } break;
			case 102 : fast -= 10; break;
			case 108 : fast += 10; break;
		}
	}
}

void Draw () {
	gotoxy ( 5, 5 );
	
	textcolor("Yellow");
	cout << char ( 201 );
	for ( int i = 6; i < 48; i ++ ) {
		cout << char ( 205 );
	}
	
	cout << char ( 187 );
	for ( int i = 6; i < 28; i ++ ) {
		gotoxy ( 5, i );
		cout << char ( 186 );
		gotoxy ( 48, i );
		cout << char ( 186 );
	}
	
	gotoxy ( 5, 28 );
	
	cout << char ( 200 );
	for ( int i = 6; i < 48; i ++  ) {
		cout << char ( 205 );
	}
	
	cout << char ( 188 );
	
	x = y = 10;
	B[x][y] = true;
	
	X.push ( x );
	Y.push ( y );
	
	srand(time(0));
	friutx = rand() % 41 + 6;
	friuty = rand() % 22 + 6;
	if ( friutx % 2 == 1 ) friutx = 14;
	
	gotoxy ( friutx, friuty );
	
	textcolor("Green");
	printf("()");
	
	gotoxy ( 50, 15 );
	cout << "Score: ";
	gotoxy ( 50, 16 );
	cout << "Speed: ";
	gotoxy ( 50, 18 );
	
	textcolor("White");
	cout << "Press [F] to Speed +";
	gotoxy ( 50, 19 );
	cout << "Press [L] to Speed -";
}

void Game () {
	Sleep ( fast );
	srand(time(0));
	
	//
	HANDLE hout;
	CONSOLE_CURSOR_INFO cursor;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cursor.dwSize=1;
	cursor.bVisible=false;
	SetConsoleCursorInfo(hout, &cursor);
	//
	
	gotoxy ( 57, 15 );
	printf("%lld", Score);
	gotoxy ( 57, 16 );
	cout << "           ";
	gotoxy ( 57, 16 );
	cout << 220 - fast;
	
	Kbhit();
		
	if ( d == 1 ) {
		if ( y - 1 <= 5 ) y = 27;
		else y --;
	}
	else if ( d == 2 ) {
		if ( x + 2 >= 48 ) x = 6;
		else x += 2;
	}
	else if ( d == 3 ) {
		if ( y + 1 >= 28 ) y = 6;
		else y ++;
	}
	else if ( d == 4 ) {
		if ( x - 2 <= 5 ) x = 46;
		else x -= 2;
	}
	
	X.push ( x );
	Y.push ( y );
	
	if ( B[x][y] ) {
		gameover = true;
		
		return;
	}
	
	B[x][y] = true;

	if ( x != friutx || y != friuty ) {
		gotoxy ( X.front(), Y.front() );
		B[X.front()][Y.front()] = false;
		printf("  ");
		X.pop();
		Y.pop();
	}
	else {
		do {
			friutx = rand() % 41 + 6;
			friuty = rand() % 22 + 6;
			if ( friutx % 2 == 1 ) friutx = 14;
		}while ( B[friutx][friuty] );
	
		textcolor("Green");
		gotoxy ( friutx, friuty );
		
		printf("()");
		
		Score += 10;
	}
	
	textcolor("LightAqua");
	gotoxy ( x, y );
	
	printf("[]");
	
	Kbhit();
}	

int main () {
	cin.tie();
	cout.tie();
	
	Draw();
	while ( !gameover ) {
		Game();
	}
	
	getch();	
}
