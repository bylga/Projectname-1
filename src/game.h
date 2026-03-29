#include<ncurses.h>
#include<assert.h>
#define sidex 32
#define sidey 16
#define STARTX 16
#define STARTY 3
#ifndef GAMEIMPL
#define GAMEIMPL
#else

char board[sidex * (sidey + 1) + 1];
long long Turn = 0;

typedef struct{
	int x;
	int y;
} Player;

int clamp(int x, int left, int right){
	x = x < right ? x : right;
	x = x < left ? left : x;
	return x;
}

int movePlayer(int mv, Player * p){
	switch (mv){
		case KEY_UP:
			p->y--;
			break;
		case KEY_DOWN:
			p->y++;
			break;
		case KEY_LEFT:
			p->x--;
			break;
		case KEY_RIGHT:
			p->x++;
			break;
		case 'P':
			return 1;
		default:
			return 2;
	}
	p->x = clamp(p->x, 1, sidex);
	p->y = clamp(p->y, 1, sidey);
	return 0;
}

#endif
