#include <stdio.h>
#include <curses.h>
#include <unistd.h>

int
main ( void )
{
    WINDOW *ablak;
    ablak = initscr ();

    int x = 0;
    int y = 0;
    int xMovement = 1;
    int yMovement = 1;
    int maxX;
    int maxY;

    while(1) {

        getmaxyx ( ablak, maxY , maxX );

        mvprintw ( y, x, "O" );

        refresh ();
        usleep ( 100000 );

	clear();

        x = x + xMovement;
        y = y + yMovement;
	

        while ( x>=maxX-1 ) // right
	{ 
            xMovement = xMovement * -1;
		break;
        }
        while ( x<=0 ) // left
	{ 
            xMovement = xMovement * -1;
		break;
        }
        while ( y<=0 ) // up
	{ 
            yMovement = yMovement * -1;
		break;
        }
        while ( y>=maxY-1 ) // down
	{ 
            yMovement = yMovement * -1;
		break;
        }

    }

    return 0;
}

