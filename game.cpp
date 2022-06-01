#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include "cful.h"
#include "maap.h"

#pragma comment(lib, "user32")

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4




void gLoop(int);
int keyControl();
void init();
void titleDraw();
int menuDraw();
int gamemenuDraw();
void mapDraw();
void gotoxy(int x, int y);



int main () {
		::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
		
    init();
    while(1){
	
	titleDraw();
	int menuCode = menuDraw();
	if(menuCode==0){
		int n = gamemenuDraw();
		if(n==0) {
			gLoop(0);
		}else if(n==1){
		}   gLoop(1);
	}else if(menuCode==1){
		return 0;
	}else if(menuCode==2){
		
	}
	system("cls");

	

}	


	
	int keyCode = keyControl();

	return 0;
}



int keyControl(){ //키보드 컨트롤 
	char temp = getch();
	
	if(temp == 'w' || temp == 'W'){
		return UP;
	} else if(temp == 'a' || temp == 'A'){
		return LEFT;
	} else if(temp == 's' || temp == 'S'){
		return DOWN;
	} else if(temp == 'd' || temp == 'D'){
		return RIGHT;
	} else if(temp == ' ' || temp == ' '){ 
	 return SUBMIT;
	} 
		
	}


void init(){
	
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);

}

void titleDraw(){ //타이틀  
int x=59, y=10;
gotoxy(x,y+1);
	printf("▒▒■■■■■■■■          ▒▒■■■■          ▒▒■■■■■■  ▒▒■■■■■■■■\n");
	gotoxy(x,y+2);
	printf("▒▒■■■■■■■■          ▒▒■■■■          ▒▒■■■■■■  ▒▒■■■■■■■■\n");
	gotoxy(x,y+3);
	printf("▒▒■■          ▒▒■■  ▒▒■■      ▒▒■■  ▒▒■■              ▒▒■■\n");
	gotoxy(x,y+4);
	printf("▒▒■■          ▒▒■■  ▒▒■■      ▒▒■■  ▒▒■■              ▒▒■■\n");
	gotoxy(x,y+5);
	printf("▒▒■■■■■■■■      ▒▒■■      ▒▒■■  ▒▒■■              ▒▒■■\n");
	gotoxy(x,y+6);
	printf("▒▒■■■■■■■■      ▒▒■■■■■■■■  ▒▒■■              ▒▒■■■■■■■■\n");
	gotoxy(x,y+7);
	printf("▒▒■■  ▒▒■■          ▒▒■■■■■■■■  ▒▒■■              ▒▒■■■■■■■■\n");
	gotoxy(x,y+8);
	printf("▒▒■■  ▒▒■■          ▒▒■■      ▒▒■■  ▒▒■■              ▒▒■■\n");
	gotoxy(x,y+9);
	printf("▒▒■■      ▒▒■■      ▒▒■■      ▒▒■■  ▒▒■■              ▒▒■■\n");
	gotoxy(x,y+10);
	printf("▒▒■■      ▒▒■■      ▒▒■■      ▒▒■■  ▒▒■■              ▒▒■■\n");
	gotoxy(x,y+11);
	printf("▒▒■■          ▒▒■■  ▒▒■■      ▒▒■■      ▒▒■■■■■■  ▒▒■■■■■■■■\n");
	gotoxy(x,y+12);
	printf("▒▒■■          ▒▒■■  ▒▒■■      ▒▒■■      ▒▒■■■■■■  ▒▒■■■■■■■■\n");
	gotoxy(89,y+15);
	printf("●●●●●●  ●●●●●●\n");
	gotoxy(89,y+16);
	printf("          ●            ●\n");
	gotoxy(89,y+17);
	printf("●●●●●●  ●●●●●●\n");
	gotoxy(89,y+18);
	printf("●            ●          \n");
	gotoxy(89,y+19);
	printf("●●●●●●  ●●●●●●\n");

}

int menuDraw(){ //메인 메뉴 선택지 
	int y = 25;
	gotoxy(94, 25);
	printf("▶  Press to Start ");
	gotoxy(74, y+1);
	printf("A spcial button for those who without courage");
	while(1){
		int n = keyControl();
		switch(n){
			case UP: {
				if(y > 25){
					gotoxy(94-16, y);
					printf("  ");
					gotoxy(94, --y);
					printf("▶");
					
			  
				}
				break;
			}
			case DOWN: {
				if(y < 26) {
					gotoxy(94, y);
					printf("  ");
					gotoxy(94-16, ++y);
					printf("▶");
				}
				break;
			}
			case SUBMIT: {
				if (y == 25) {
                for (int i = 0; i < 3; i++)
                {
                    gotoxy(98, 25);
                    printf("              ");
                    Sleep(100);
                    gotoxy(98, 25);
                    printf("Press to Start");
                    Sleep(100);
                }
				Sleep(500);
            }

            else {
                for (int i = 0; i < 3; i++)
                {
                    gotoxy(32, 26); // 글귀에 알맞게 좌표변경
                    printf("                    Loser                     ");
                    Sleep(110);
                    gotoxy(32, 26);
                    printf("A spcial button for those who without courage ");
                    Sleep(110);
                }
                Sleep(500);
            }
				return y - 25;
			}
			
			
	}
	}
	
}







void gotoxy(int x, int y){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int gamemenuDraw(){ //자동차 미리보기  
	int x=63, y=18;
	system("cls");
	gotoxy(0,0); 
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	Sleep(50);
	gotoxy(0,1); 
	printf("■                                                          ■\n");
	Sleep(50);
	gotoxy(0,2);
	printf("■       _______________________                            ■\n");
	Sleep(50);
	gotoxy(0,3);
	printf("■      /||     ＼               ＼                         ■\n");
	Sleep(50);
	gotoxy(0,4);
	printf("■     / ||       ＼               ＼                       ■\n");
	Sleep(50);
	gotoxy(0,5);
	printf("■    /  ||         '----____________'----____              ■\n");
	Sleep(50);
	gotoxy(0,6);
	printf("■   |   |￣￣￣￣￣|        '----____________'----____     ■\n");
	Sleep(50);
	gotoxy(0,7);
	printf("■   |   | ￣       |              ■■＼〓〓======〓〓＼   ■\n");
	Sleep(50);
	gotoxy(0,8);
	printf("■   |□□□□□□□□□□□□□□□□□|□□□□□□□□|  ■\n");
	Sleep(50);
	gotoxy(0,9);
	printf("■   ＼  / ＼                / ＼       |  ■■=RACE=■■|  ■\n");
	Sleep(50);
	gotoxy(0,10);
	printf("■     ＼|○|＼ □□□□□□/|○|＼□□/_□□□□□□□□/  ■\n");
	Sleep(50);
	gotoxy(0,11);
	printf("■       ＼_/_/ ￣￣￣￣￣￣ ＼_/_/￣￣  ￣￣￣＼_/_/￣￣   ■\n");
	Sleep(50);
	gotoxy(0,12);
	printf("■   ◁                                                ▷   ■\n");
	Sleep(50);
	gotoxy(0,13);
	printf("■                                                          ■\n");
	Sleep(50);
	gotoxy(0,14);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	
	Sleep(50); //차 세부사항 
	gotoxy(x+1,1);
	printf("Sprinter Trueno GT-APEX [AE86]\n");
	Sleep(50);
	gotoxy(x+1,2);
	printf("구동방식/변속단:FR/5단\n");
	Sleep(50);
	gotoxy(x+1,3);
	printf("엔진:4A-GEU\n");
	gotoxy(x+1,4);
	printf("엔진형식:1.6L 자연흡기직렬 4기통\n");
	Sleep(50);
	gotoxy(x+1,5);
	printf("마력:130hp\n");
	Sleep(50);
	gotoxy(x+1,6);
	printf("토크:15.2kg.m\n");
	Sleep(50);
	gotoxy(x+1,4);
	printf("엔진형식:1.6L 자연흡기직렬 4기통\n");
	Sleep(50);
	gotoxy(x+1,5);
	printf("마력:130hp\n");
	Sleep(50);
	gotoxy(x+1,6);
	printf("토크:15.2kg.m\n");
	Sleep(50);
	

	gotoxy(53,y);
	printf("▶RACE!");
	Sleep(50);
	gotoxy(55,y+1);
	printf("EVEN MORE TERRIFYING RACE!!!!");
	Sleep(50);
	gotoxy(55,y+2);
	printf("main menu");
	
	while(1){
		int n=keyControl();
		switch(n){
			case UP:{
				if(y>18){
					gotoxy(53,y);
					printf("  ");
					gotoxy(53,--y);
					printf("▶");
				}
				break;
			}
			
			case DOWN: {
				if(y<20) {
					gotoxy(53,y);
					printf("  ");
					gotoxy(53,++y);
					printf("▶");
				}
				break;
			}
			
			case SUBMIT: {
				return 0;
			}
		}
	}
	
	
	
	
	
}

void gLoop(int mapCode){
	
	int playing = 1;
	
	if(mapCode == 0){
		memcpy(tempMap, gamemap1, sizeof(tempMap));
	}else if(mapCode == 1){
		memcpy(tempMap, gamemap2, sizeof(tempMap));
	}else if(mapCode == 2){
		memcpy(tempMap, menumap, sizeof(tempMap));
	}
	
	mapDraw();
	
	while(playing){
	}
}




void mapDraw(){
	system("cls");
	int h, w;
	

	
	

	for(h=0; h<50; h++){
		for(w=0; w<190; w++){
			char temp = tempMap[h][w];
			if(temp == '0'){
				printf(BG_COLOR(0,176,240)" " RESET);//light blue
			}else if(temp == '1'){
				printf(BG_COLOR(255,0,0)" " RESET);//red
			}else if(temp == '2'){
				printf(BG_COLOR(242,242,242)" " RESET);//light gray
			}else if(temp == '3'){
				printf(BG_COLOR(0,153,0)" " RESET);//green
			}else if(temp == '4'){
				printf(BG_COLOR(64,64,64)" " RESET);//gray
			}else if(temp == '.'){
				printf(BG_COLOR(13,13,13)" " RESET);//black
			}else if(temp == '^'){
				printf(BG_COLOR(255,49,59)" " RESET);//light red
			}else if(temp == '*'){
				printf(BG_COLOR(168,4,16)" " RESET);//dark red
			}else if(temp == '#'){
				printf(BG_COLOR(255,255,0)" " RESET);//yellow
			}else if(temp == '8'){
				printf(BG_COLOR(38,38,38)" " RESET);//dark gray
			}else if(temp == '9'){
				printf(BG_COLOR(255,255,255)" " RESET);//white
			}else if(temp == '5'){
				printf(BG_COLOR(0,122,0)" " RESET);//dark green
			}
		}
		printf("\n");
	}

}	



