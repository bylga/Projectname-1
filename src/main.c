/*
TODO: Add inventory      |- priority 1
TODO: Add other creatures|
TODO: Add saves          |- priority 2
*/
#include<stdbool.h>
static int offset = 0;
#define GAMEIMPL
#include"game.h"
void printLevel(FILE * Level){
	char c = 0;
	if (!open){
		offset = 0;
		char buf[BUFSIZ];

		int i = 0;

		for (; (c = fgetc(Level)) != ' '; i++){
			assert(c != EOF);
			buf[i] = c;
		}

		buf[i + 1] = '\0';
		mX = atoi(buf);

		offset += i + 1;
		i = 0;

		for (; (c = fgetc(Level)) != '\n'; i++){
			assert(c != EOF);
			buf[i] = c;
		}

		buf[i + 1] = '\0';
		mY = atoi(buf);

		open = true;
		offset += i + 1;
	}
	fseek(Level, offset, 0);
	c = 0;
	for (size_t i = 0; ((c = fgetc(Level)) != EOF) && (i < (mX + 1) * mY); i++){
		board[i] = c;
	}
	board[(mX + 1) * mY] = '\0';
}

void GenMap(){
	mX = 32; mY = 16;
	offset = 6;

	for (size_t i = 1; i < mY * (mX + 1); i++){
		if (i % (mX + 1) == 0) board[i - 1] = '\n';
		else if (i == 55) board[i - 1] = '>';
		else board[i - 1] = '.';
	}
	board[(mX + 1) * mY] = '\0';
	FILE * temp = fopen("levels/lvl00000.lvl", "w");
	fprintf(temp, "%lu %lu\n", mX, mY);
	fprintf(temp, board);
	fclose(temp);
}

int main(){
	Player p = {0};
	p.x = STARTX;
	p.y = STARTY;
	FILE * Level = NULL;
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	Level = LoadLevel(CurLevel);
	do {
		printLevel(Level);

		board[p.x - 1 + (mX + 1) * (p.y - 1)] = '@';
		printw("%s", board);

		printw("\n x: %4d, y: %4d, CurLevel: %d", p.x, p.y, CurLevel);
		printw("\n mX: %3ld, mY: %3ld Tile: %lu TileType: %c\n", mX, mY, p.x + mX * (p.y - 1) + offset, CheckTile(Level, p.x, p.y));
		printw("%p\n", Level);
		move(0,0);
		refresh();

	} while((movePlayer(getch(), &p,  &Level) == 0));

	endwin();
	return 0;
}
