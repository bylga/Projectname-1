#include<ncurses.h>
#include<assert.h>
#include<stdlib.h>
#define side 16
char board[side * side + 1];

typedef struct{
	int x;
	int y;
} player;

int main(){
	player p = {0};
	board[side * side] = '\0';

	for (int i = 1; i < side * side; i++){
		if (i % side == 0) board[i - 1] = '\n';
		else board[i - 1] = '.';
	}

	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	char fl = 1;
	int c;

	while(fl){
		printw(board);
		printw("\n x: %d, y: %d", p.x, p.y);
		move(0,0);
		refresh();
		c = getch();
		switch (c){
			case KEY_UP:
				p.y++;
				break;
			case KEY_DOWN:
				p.y--;
				break;
			case KEY_LEFT:
				p.x--;
				break;
			case KEY_RIGHT:
				p.x++;
				break;
			case 'P':
				fl = 0;
				break;
			default:
				break;
		}
	}
	endwin();
	return 0;
}
