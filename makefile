test.out: main.o bwindow.o Boid.o Agent.o
	g++ -g -o test.out main.o bwindow.o Boid.o Agent.o -lX11 -L/usr/X11R6/lib

main.o: main.cpp
	g++ -g -c main.cpp 

bwindow.o: bwindow.cpp bwindow.h
	g++ -g -c bwindow.cpp

Boid.o: Boid.cpp Boid.h Agent.h
	g++ -g -c Boid.cpp

Agent.o: Agent.cpp Agent.h
	g++ -g -c Agent.cpp

clean :
	rm *.o *.out