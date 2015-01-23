test.out: main.o bwindow.o Boid.o Agent.o Obstacle.o Predateur.o
	g++ -Wall -g -o test.out main.o bwindow.o Boid.o Agent.o Predateur.o Obstacle.o -lX11 -L/usr/X11R6/lib

main.o: main.cpp Agent.h Boid.h bwindow.h Obstacle.h Predateur.h params.h
	g++ -g -c main.cpp 

bwindow.o: bwindow.cpp bwindow.h
	g++ -g -c bwindow.cpp

Boid.o: Boid.cpp Boid.h Agent.h Obstacle.h Predateur.h params.h
	g++ -g -c -o Boid.o Boid.cpp

Agent.o: Agent.cpp Agent.h params.h
	g++ -g -c -o Agent.o Agent.cpp

Obstacle.o: Obstacle.cpp Obstacle.h
	g++ -g -c -o Obstacle.o Obstacle.cpp

Predateur.o: Predateur.cpp Predateur.h Agent.h
	g++ -g -c -o Predateur.o Predateur.cpp

clean :
	rm *.o *.out