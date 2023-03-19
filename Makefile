all: compile link

compile:
	g++ -Isrc/include -c flappy.cpp
	g++ -Isrc/include -c main.cpp

link:
	g++ main.o flappy.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system