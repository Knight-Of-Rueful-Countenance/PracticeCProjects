

#include "windowmover.h"


int main(int argc,char* argv[])
{
	initscr();
	keypad(stdscr, TRUE);
	raw();
	noecho();
	_Bool EXIT= FALSE;
	while(!EXIT) 
	{	
		getch();
		refresh();
	}
	endwin();
	return 0;
}


