run: playGame.cpp Box.o Goldmine.o 
	g++ Box.o Goldmine.o playGame.cpp -o run
Goldmine.o: Goldmine.cpp Goldmine.h 
	g++ -c Goldmine.cpp
Box.o: Box.cpp Box.h
	g++ -c Box.cpp
clean: 
	rm -rf *.o Box.o Goldmine.o

