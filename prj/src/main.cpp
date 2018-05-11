#include <iostream>
#include <iomanip>
#include <fstream>
#include <unistd.h>
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

int main()
{
	Scena S;
  // Wektor2D W, Tmp(0.0,0.0), Z(0.0,0.0), Init;
  // char Znak;
  // int Kat, _Kat, Ilek;
  // double Dlugosc, NowaSzybkosc, _Dlg, Ilej, Skala;
  // unsigned int microsec = 1000;
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
	 char dupa;
  
   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
	S.TworzListy();
	S.ZapiszDoPliku();
	do{
		S.PrzesunPrzeszkode();
		S.ZapiszDoPliku();
		cin >> dupa;
	} while(dupa != 'a');
	// cout << "Zadaj poczatkowa pozycje robota" << endl;
	// cin >> Init;
	// Scena Sc(Init);
  // Sc.ZapiszSciezke();
  // do
  //   {
  //     Sc.RZapiszDoPliku("figury/Robot.dat");
  //     Sc.SZapiszDoPliku("figury/Sciezka.dat");
  //     Lacze.Rysuj();
  //     cout << "z - zmiana szybkosci ruchu robota" << endl;
	// 		cout << "c - zmien rozmiar robota" << endl;
  //     cout << "o - obrot robota" << endl;
  //     cout << "j - jazda na wprost" << endl << endl;
  //     cout << "t - zadaj translacje rysunku" << endl;
  //     cout << "p - powrot do pierwotnego ustawienia" << endl << endl;
  //     cout << "w - wyswietl ponownie menu" << endl << endl;
  //     cout << "k - zakoncz dzialanie programu" << endl << endl;
  //     cout << "Twoj wybor (w - wyswietl menu) >";
  //     cin >> Znak;
  //     cout << endl;
      
  //     switch(Znak)
	// {
	// case 'z':
	//   cout << "Podaj nowa szybkosc ruchu w [j/s]" << endl;
	//   cout << "Nowa szybkosc to:";
	//   cin >> NowaSzybkosc;
	//   Sc.ZmienPredkosc(NowaSzybkosc);
	//   break;
	// case 'c':
	// 	cout << "Podaj nowa skale robota" << endl;
	// 	cin >> Skala;
	// 	Sc.SkalujRobota(Skala);
	// 	Sc.RZapiszDoPliku("figury/Robot.dat");
	// 	Lacze.Rysuj();
	// 	break;
	// case 'o':
	//   cout << "Podaj wartosc kata obrotu w stopniach" << endl;
	//   cout << "Kat obrotu to:";
	//   cin >> Kat;
	//   _Kat = 1;
	//   Ilek = Kat/_Kat;
	//   for(int i=0;i<Ilek;i++) {
	//     usleep(microsec);
	//     Sc.ObrotAnimuj(_Kat);
	//     Sc.RZapiszDoPliku("figury/Robot.dat");
	//     Lacze.Rysuj();
	//   }
	//   Sc.RZapiszDoPliku("figury/Robot.dat");
	//   Sc.SZapiszDoPliku("figury/Sciezka.dat");
	//   Lacze.Rysuj();
	//   _Kat = 0;
	//   break;
	// case 'j':
	//   cout << "Podaj dlugosc ruchu robota naprzod" << endl;
	//   cout << "Dlugosc drogi:";
	//   cin >> Dlugosc;
	//   _Dlg = Sc.WezR().ZwrocSzybkosc()*1;
	//   Ilej = Dlugosc/_Dlg;
	//   for(int i=0;i<Ilej;i++) {
	//     usleep(microsec);
	//     Sc.JazdaAnimuj(_Dlg);
	//     Sc.RZapiszDoPliku("figury/Robot.dat");;
	//     Lacze.Rysuj();
	//   }
	//   Sc.ZapiszSciezke();
	//   Sc.RZapiszDoPliku("figury/Robot.dat");
	//   Sc.SZapiszDoPliku("figury/Sciezka.dat");
	//   Lacze.Rysuj();
	//   _Dlg = 0;
	//   break;
	// case 't':
	//   cout << "Podaj wspolrzedne wektora translacji" << endl;
	//   cout << "Wspolrzedne to:";
	//   cin >> W;
	//   Tmp = Tmp - W;
	//   Sc.Przesun(W);
	//   Sc.RZapiszDoPliku("figury/Robot.dat");
	//   Sc.SZapiszDoPliku("figury/Sciezka.dat");
	//   Lacze.Rysuj();
	//   break;
	// case 'p':
	//   Sc.Przesun(Tmp);
	//   Sc.RZapiszDoPliku("figury/Robot.dat");
	//   Sc.SZapiszDoPliku("figury/Sciezka.dat");
	//   break;
	// case 'w':
	//   break;
	// case 'k':
	//   break;
	// }
  //   } while(Znak != 'k');
}
