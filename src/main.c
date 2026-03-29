#define GAMEIMPL
#include"game.h"

int main(){
	Player p = {0};
	p.x = STARTX;
	p.y = STARTY;
	
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	int c;

	do{
		board[sidex * sidey] = '\0';
		for (int i = 1; i < sidey * (sidex + 1); i++){
			if (i % (sidex + 1) == 0) board[i - 1] = '\n';
			else board[i - 1] = '.';
		}

		board[p.x - 1 + (sidex + 1) * (p.y - 1)] = '@';

		printw("%s\n", board);
		printw("\n x: %4d, y: %4d", p.x, p.y);
		move(0,0);
		refresh();
	} while((movePlayer(getch(), &p) == 0));

	endwin();
	return 0;
}
