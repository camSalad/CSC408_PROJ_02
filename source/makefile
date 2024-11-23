CC = g++ -c -Wall -ansi -pedantic -std=c++20 
LN = g++

myprog: main.o Parser.o MyScanner.o
	$(LN) -o myprog main.o Parser.o MyScanner.o

main.o: main.cpp Parser.hpp MyScanner.hpp
	$(CC) main.cpp

Parser.o: Parser.cpp Parser.hpp MyScanner.hpp
	$(CC) Parser.cpp

MyScanner.o: MyScanner.cpp Parser.hpp MyScanner.hpp
	$(CC) MyScanner.cpp

MyScanner.cpp: automata.l MyScanner.hpp
	flex++ automata.l

Parser.hpp: prog.bis MyScanner.hpp
	bison prog.bis

Parser.cpp: prog.bis MyScanner.hpp
	bison prog.bis


clean:
	/bin/rm -f *~ *.o myprog Parser.cpp Parser.hpp MyScanner.cpp
