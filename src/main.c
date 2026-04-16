/*
TODO: Add inventory      |- priority 1
TODO: Add other creatures|
TODO: Add saves          |- priority 2
*/
#define GAMEIMPL
#include"game.h"

static bool open = false;

void printLevel(FILE * Level){
	static int offset = 0;
	if (!open){
		offset = 0;
		char c = 0;
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
	else{
		fseek(Level, offset, 0);
		char c = 0;
		for (size_t i = 0; ((c = fgetc(Level)) != EOF) && (i < (mX + 1) * mY); i++){
			board[i] = c;
		}
		board[(mX + 1) * mY] = '\0';
	}
}

void GenMap(){
	mX = 32; mY = 16;
	board[mX * mY] = '\0';

	for (size_t i = 1; i < mY * (mX + 1); i++){
		if (i % (mX + 1) == 0) board[i - 1] = '\n';
		else board[i - 1] = '.';
	}
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

	do {

		if (CurLevel == 0){
			if (Level != NULL) {fclose(Level); Level = NULL; printw("%s", __BLANK); open = false;}
			GenMap();
		} else{
			if (Level == NULL) {Level = LoadLevel(CurLevel); printw("%s", __BLANK);}
			printLevel(Level);
		}

		board[p.x - 1 + (mX + 1) * (p.y - 1)] = '@';
		printw("%s", board);

		printw("\n x: %4d, y: %4d, CurLevel: %d", p.x, p.y, CurLevel);
		printw("\n mX: %3ld, mY: %3ld", mX, mY);
		move(0,0);
		refresh();
		
	} while((movePlayer(getch(), &p,  Level) == 0));

	endwin();
	return 0;
}
