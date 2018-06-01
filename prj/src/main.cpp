#include <iostream>
#include <iomanip>
#include <fstream>
#include <unistd.h>
#include "Fabryka.hh"
#include "Wektor2D.hh"
#include "Macierz2x2.hh"
#include "Scena.hh"
#include "ObiektGraficzny.hh"
#include "Robot.hh"
#include "Przeszkoda.hh"
#include "Sciezka.hh"
#include "Zbior_Wierzcholkow.hh"
#include "lacze_do_gnuplota.hh"



using namespace std;

Fabryka Fabryka::_Fabryka;

int main()
{
	Scena S;
	char Znak;
  	Wektor2D W(0.0,0.0), Tmp(0.0,0.0);
	int Kat;
	double NowaSzybkosc, Skala, Dlugosc;
  
	S.TworzListy();
	S.ZapiszDoPliku();

  do
    {
	cout << "Aktualnie wybrany robot ma wspolrzedne:" << S.PokazPolozenieRobota() << endl << endl;
	cout << "s - selekcja robota" << endl;
	cout << "z - zmiana szybkosci ruchu robota" << endl;
	cout << "c - zmien rozmiar robota" << endl;
	cout << "r - dodaj wybranego robota" << endl;
	cout << "e - usun wybranego robota" << endl;
	cout << "o - obrot robota" << endl;
	cout << "j - jazda na wprost" << endl << endl;
	cout << "b - obroc wybrana preszkode" << endl;
	cout << "d - przesun wybrana przeszkode"<< endl;
	cout << "a - dodaj nowa przeszkode" << endl;
	cout << "u - usun wybrana przeszkode" << endl << endl;
	cout << "t - zadaj translacje rysunku" << endl;
	cout << "p - powrot do pierwotnego ustawienia" << endl << endl;
	cout << "w - wyswietl ponownie menu" << endl << endl;
	cout << "k - zakoncz dzialanie programu" << endl << endl;
	cout << "Twoj wybor (w - wyswietl menu) >";
	cin >> Znak;
	cout << endl;
      
	switch(Znak)
	{
		case 's':
			S.SelekcjaRobota();
			break;
		case 'z':
			cout << "Podaj nowa szybkosc ruchu w [j/s]" << endl;
			cout << "Nowa szybkosc to:";
			cin >> NowaSzybkosc;
			S.ZmienPredkosc(NowaSzybkosc);
			break;
		case 'c':
			cout << "Podaj nowa skale robota" << endl;
			cin >> Skala;
			S.SkalujRobota(Skala);
			break;
		case 'r':
			S.DodajRobota();
			break;
		case 'e':
			S.UsunRobota();
			break;
		case 'o':
			cout << "Podaj wartosc kata obrotu w stopniach" << endl;
			cout << "Kat obrotu to:";
			cin >> Kat;
			S.AnimujObrot(Kat);
			break;
		case 'j':
			cout << "Podaj dlugosc ruchu robota naprzod" << endl;
			cout << "Dlugosc drogi:";
			cin >> Dlugosc;
			S.AnimujJazde(Dlugosc);
			break;
		case 'b':
			S.ObrocPrzeszkode();
			break;
		case 'd':
			S.PrzesunPrzeszkode();
			break;
		case 'a':
			S.DodajPrzeszkode();
			break;
		case 'u':
			S.UsunPrzeszkode();
			break;
		case 't':
			cout << "Podaj wspolrzedne wektora translacji" << endl;
			cout << "Wspolrzedne to:";
			cin >> W;
			Tmp = Tmp - W;
			S.Przesun(W);
			break;
		case 'p':
			S.Przesun(Tmp);
			Tmp = Wektor2D(0.0,0.0);
			break;
		case 'w':
			break;
		case 'k':
			break;
	}
    } while(Znak != 'k');
}
