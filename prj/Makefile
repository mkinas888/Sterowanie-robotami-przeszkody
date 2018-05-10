#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

TRGDIR=/tmp/robot_scena

__start__: ./robot_scena
	./robot_scena

./robot_scena: obj obj/main.o obj/ObiektGraficzny.o\
           obj/lacze_do_gnuplota.o obj/Macierz2x2.o obj/Robot.o obj/Scena.o\
		   obj/Sciezka.o obj/Zbior_Wierzcholkow.o
	g++ -Wall -pedantic -std=c++11 -o ./robot_scena obj/main.o\
                        obj/lacze_do_gnuplota.o obj/ObiektGraficzny.o\
						obj/Macierz2x2.o obj/Robot.o obj/Scena.o\
						obj/Sciezka.o obj/Zbior_Wierzcholkow.o


obj:
	mkdir -p obj

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/ObiektGraficzny.hh inc/Wektor2D.hh inc/Macierz2x2.hh\
						inc/Scena.hh inc/ObiektGraficzny.hh inc/Robot.hh inc/Sciezka.hh\
						inc/Zbior_Wierzcholkow.hh inc/lacze_do_gnuplota.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/ObiektGraficzny.o: src/ObiektGraficzny.cpp inc/ObiektGraficzny.hh\
                       inc/Wektor2D.hh  inc/SWektor.hh inc/Zbior_Wierzcholkow.hh
	g++ -c ${CXXFLAGS} -o obj/ObiektGraficzny.o src/ObiektGraficzny.cpp

obj/Macierz2x2.o: src/Macierz2x2.cpp inc/Macierz2x2.hh inc/Wektor2D.hh
	g++ -c ${CXXFLAGS} -o obj/Macierz2x2.o src/Macierz2x2.cpp

obj/Robot.o: src/Robot.cpp inc/Robot.hh inc/Zbior_Wierzcholkow.hh inc/ObiektGraficzny.hh\
						inc/Sciezka.hh
	g++ -c ${CXXFLAGS} -o obj/Robot.o src/Robot.cpp

obj/Scena.o: src/Scena.cpp inc/Scena.hh inc/Robot.hh inc/Sciezka.hh
	g++ -c ${CXXFLAGS} -o obj/Scena.o src/Scena.cpp

obj/Sciezka.o: src/Sciezka.cpp inc/Sciezka.hh inc/Zbior_Wierzcholkow.hh
	g++ -c ${CXXFLAGS} -o obj/Sciezka.o src/Sciezka.cpp

obj/Zbior_Wierzcholkow.o: src/Zbior_Wierzcholkow.cpp inc/Zbior_Wierzcholkow.hh\
						inc/Wektor2D.hh
	g++ -c ${CXXFLAGS} -o obj/Zbior_Wierzcholkow.o src/Zbior_Wierzcholkow.cpp

clean:
	rm -f obj/*.o ./robot_scena
