#include <stdio.h>
#include "bwindow.h"
#include "Boid.h"


int main()
{
    /*bwindow win(640,480);
    printf("%d\n",win.init());
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
	win.draw_point(100,100,0xFF00);
	win.draw_line(100,100,200,200,0xFF0000);
	win.draw_text(10,10,0x0,"Hello World",strlen("Hello World"));
	win.draw_square(200,200,220,220,0xFF00);
	win.draw_fsquare(400,400,440,440,0xFF00);
    }*/

	
	// Creation of lists of Agent


	printf("A1 !\n");
	Agent A1;
		printf("A2 !\n");
	Agent A2 = Agent();
		printf("A3 !\n");
	Agent A3 = Agent(10,12);
		printf("A4 !\n");
	Agent A4 = Agent(10,12,5,4);
	int a = A4.getXi()[0];
	printf("%d\n",a);
	Boid population1 = Boid(A1);
	population1.AddAgent(A4);
	population1.AddAgent(A3);
	printf("nb de pop : %d\n",population1.getN());
	printf("yo je suis dans le main\n");
	printf("coucou\n");
	int test2 = (population1[1]).getXi()[0];
	printf("%d\n", test2);
	/*Boid population2 = Boid(A3);
	population2.AddAgent(A4);*/

	//delete population1;
	printf("Si j'arrive ici c'est la folie ;)\n");

    return 0;
}
