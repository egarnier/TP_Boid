#include <stdio.h>
#include "bwindow.h"
#include "Boid.h"


int main()
{

	srand(time(NULL));

	bwindow win(640,480);
    printf("%d\n",win.init());

	Boid population1 = Boid();
	//population1.affiche();
    win.map();
    for(;;)
    {
	int ev = win.parse_event();
	switch(ev)
	{
	    case BKPRESS :
		printf("keypressed\n"); 
		printf("key : %s\n",win.get_lastkey());
		break;
	    case BBPRESS:
		printf("buttonpressed\n"); break;
	    case BEXPOSE:
		printf("expose\n"); break;
	    case BCONFIGURE:
		printf("configure\n"); break;
	}


	win.draw_fsquare(0,0,640,480,0xFFFFFF);
	win.draw_boid(&population1);

	//population1.affiche();
	


	/*win.draw_line(100,100,200,200,0xFF0000);
	win.draw_text(10,10,0x0,"Hello World",strlen("Hello World"));
	win.draw_square(200,200,220,220,0xFF00);
	win.draw_fsquare(400,400,440,440,0xFF00);*/

	// population1.proieMangee();
    }
	


	/*// Creation list of Agent
	srand(time(NULL));
	Boid population1;
	printf("Nb agent pop 1 : %d\n", population1.GetN());
	printf("\n\n");
	printf("Les coordonnées initiales de la population1 sont :\n");
	population1.affiche();
	printf("\n\n");
	printf("Les coordonnées après update :\n");
	population1.updatepos();
	population1.affiche();*/
	
    return 0;
}