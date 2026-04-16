#include"BLANK.h"
#include<ncurses.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#define STARTX 16
#define STARTY 3
#ifndef GAMEIMPL
#define GAMEIMPL
#else

int CurLevel = 0;
char board[BUFSIZ];
long long Turn = 0;

enum Levels {
	test = 0,
	test1,
	END
};
/* TODO: Imploment debug level selection */

typedef struct{
	int x;
	int y;
} Player;

int clamp(int x, int left, int right){
	x = x < right ? x : right;
	x = x < left ? left : x;
	return x;
}

size_t mX = 32; size_t mY = 16;

int movePlayer(int mv, Player * p,  FILE * Level){
	enum Levels lvl = END;
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
			if (Level != NULL) {fclose(Level); Level = NULL;}
			return 1;
		case 'C':
			CurLevel += 1;
			CurLevel %= END;
			return 0;
		default:
			return 0;
	}
	p->x = clamp(p->x, 1, mX);
	p->y = clamp(p->y, 1, mY);
	return 0;
}

void itoa(char buf[], int x, size_t size){
	size--;
	buf[size] = '\0';
	while (size > 0){
		size--;
		buf[size] = x % 10 + '0';
		x /= 10;
	}
}

FILE * LoadLevel(int LevelNumber){

	char __BUF[6];
	char lvl[BUFSIZ] = "";
	FILE * Level;
	itoa(__BUF, LevelNumber, 6);

	strcat(lvl, "./levels/lvl"); strcat(lvl, __BUF); strcat(lvl, ".lvl");

	Level = fopen(lvl, "r");
	if (Level == NULL) fprintf(stderr, "There is no such level as %d", CurLevel);

	return Level;
}
#endif

#include"Inventory.h"
