all:
	g++-8 -std=c++1z -c main.cpp Bird.cpp Pipes.cpp Score.cpp Collision.cpp Text.cpp -lstdc++fs

	g++-8 -std=c++1z main.o Bird.o Pipes.o Score.o Collision.o Text.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lstdc++fs

	./sfml-app
