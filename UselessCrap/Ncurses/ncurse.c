#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#define ESCAPE 27
#define BACKSPACE 8
#define DEL 127
#define LF 10
#define CR 13
int main(int argc,char * argv[])
{
	/*if(argc==0)
	{
		printf("Usage: Col [Text] [Color]\n");
		return 0;
	}*/
	//Init Ncurses:
	initscr();
	keypad(stdscr,TRUE);
	noecho();
	raw();
	int uinput;
	int Finished=0;
	//char* charBuffer;
	//charBuffer = malloc(sizeof(char*)*1000); //will store characters for saving
        
	while(Finished==0)
	{
		refresh();
		uinput = getch();
		switch(uinput)
		{
			case ESCAPE:{Finished = 1;}break;
			case LF:{printw("%c",uinput);}break;
			case BACKSPACE:{delch();}break;
			case DEL:
			{	
				//move(getcury()-1,getcurx());
				delch();
			}break;
			default:
			{
				
				if(unctrl(uinput) != 0 && strlen(unctrl(uinput))==1)
				{//Put macros here
					printw("%c",uinput);
				}
				else
				{
					//attron(A_BOLD);
					//printw("%c",uinput);
					//attroff(A_BOLD);
				}
			}break;
		}
	}
	//free(charBuffer);
	endwin();
	return 0;
}
