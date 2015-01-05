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

	
	// Creation list of Agent

	Agent A1 = Agent(1.1, 1.2, 1.3, 1.5);
	Agent A2 = Agent(2, 2.3, 2.4, 2);
	Agent A3 = Agent(13, 14);
	Agent A4 = Agent(10, 12, 5, 4);
	Boid* population1 = new Boid();
	population1->AddAgent(A1);
	population1->AddAgent(A2);
	population1->AddAgent(A3);
	population1->AddAgent(A4);
	printf("Nb agent pop 1 : %d\n", population1->GetN());
	printf("la pos de l'agent 4  de pop 1 est %f - %f\n", population1->GetAgent(3).GetXi()[0], population1->GetAgent(3).GetXi()[1] );
	A4.updatepos();
	printf("pos update de A4 %f - %f \n",A4.GetXi()[0], A4.GetXi()[1] );
	
	printf("Vitesse de A1 et A2 avant speed1 :\n%f - %f\n%f - %f\n", A1.GetVi()[0], A1.GetVi()[1], A2.GetVi()[0], A2.GetVi()[1]);
	A1.speed1(population1->GetPop(), population1->GetN(), 0);
	printf("Vitesse de A1 et A2 après speed1 :\n%f - %f\n%f - %f\n", A1.GetVi()[0], A1.GetVi()[1], A2.GetVi()[0], A2.GetVi()[1]);
	
    return 0;
}
