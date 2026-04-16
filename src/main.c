/*
TODO: Add inventory      |- priority 1
TODO: Add other creatures|
TODO: Add saves          |- priority 2
*/
#define GAMEIMPL
#include"game.h"

void printLevel(FILE * Level){
	while((c = getchar()) != '\n'){
		
	}
}

void GenMap(){
	board[sidex * sidey] = '\0';
	for (int i = 1; i < sidey * (sidex + 1); i++){
		if (i % (sidex + 1) == 0) board[i - 1] = '\n';
		else board[i - 1] = '.';
	}
}

int main(){
	Player p = {0};
	p.x = STARTX;
	p.y = STARTY;
	FILE * Level = NULL;
	int mX = 0, mY = 0;
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);

	do{
		if (CurLevel == 0){
			if (Level != NULL) {fclose(Level); Level = NULL; clear();}
			GenMap();
			board[p.x - 1 + (sidex + 1) * (p.y - 1)] = '@';
			mX = 32; mY = 16;
			printw("%s\n", board);
		}
		else{
			if (Level == NULL) {Level = LoadLevel(CurLevel); clear();}
			printLevel(Level);
		}
		printw("\n x: %4d, y: %4d", p.x, p.y);
		move(0,0);
		refresh();
	} while((movePlayer(getch(), &p,  Level) == 0));

	endwin();
	return 0;
}
