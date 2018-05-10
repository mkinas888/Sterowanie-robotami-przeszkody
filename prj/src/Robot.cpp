#include <cmath>
#include "Macierz2x2.hh"
#include "Robot.hh"

#define PI 3.14159265
#define ROZMIAR 2


/*!
 * \file
 * \brief Definicja metod klasy Robot
 * 
 * Zawiera definicję metod klasy Robot
 */

/*!
 * \brief Konstruktor robota umieszczający go na początkowej pozycji
 */

Robot::Robot() {
  Kat = 0;
  Rozmiar = 10;
  Szybkosc  = 1.0;
  Polozenie = Wektor2D( 100.0, 50.0);
  ZW_lok.Dodaj(Wektor2D( Rozmiar, 0.0));
  ZW_lok.Dodaj(Wektor2D(  0.0, Rozmiar));
  ZW_lok.Dodaj(Wektor2D(-Rozmiar, Rozmiar));
  ZW_lok.Dodaj(Wektor2D(-Rozmiar, -Rozmiar));
  ZW_lok.Dodaj(Wektor2D  (0.0, -Rozmiar));
  ZW_lok.Dodaj(Wektor2D( Rozmiar, 0.0));
  for(int i = 0; i < ZW_lok.RozmiarZbioru(); i++){
    ZW.Dodaj(Lok2Glob(ZW_lok[i]));
  }
}

/*!
 * \brief Konstruktor robota umieszczający go na zadanej pozycji
 */

Robot::Robot(Wektor2D WekInit) {
  Kat = 0;
  Rozmiar = 10;
  Szybkosc  = 1.0;
  Polozenie = WekInit;
  ZW_lok.Dodaj(Wektor2D( Rozmiar, 0.0));
  ZW_lok.Dodaj(Wektor2D(  0.0, Rozmiar));
  ZW_lok.Dodaj(Wektor2D(-Rozmiar, Rozmiar));
  ZW_lok.Dodaj(Wektor2D(-Rozmiar, -Rozmiar));
  ZW_lok.Dodaj(Wektor2D  (0.0, -Rozmiar));
  ZW_lok.Dodaj(Wektor2D( Rozmiar, 0.0));
  for(int i = 0; i < ZW_lok.RozmiarZbioru(); i++){
    ZW.Dodaj(Lok2Glob(ZW_lok[i]));
  }
}

/*!
 * \brief Metoda pozwalająca przeskalowac rozmiar robota
 * \param[in] Skala - wspolczynnik przeskalowania robota
 */

void Robot::ZmienRozmiarRobota(double Skala) {
  Rozmiar = Rozmiar * Skala;
  ZW.Usun();
  ZW_lok.Usun();
  ZW_lok.Dodaj(Wektor2D( Rozmiar, 0.0));
  ZW_lok.Dodaj(Wektor2D(  0.0, Rozmiar));
  ZW_lok.Dodaj(Wektor2D(-Rozmiar, Rozmiar));
  ZW_lok.Dodaj(Wektor2D(-Rozmiar, -Rozmiar));
  ZW_lok.Dodaj(Wektor2D  (0.0, -Rozmiar));
  ZW_lok.Dodaj(Wektor2D( Rozmiar, 0.0));
  for(int i = 0; i < ZW_lok.RozmiarZbioru(); i++){
    ZW.Dodaj(Lok2Glob(ZW_lok[i]));
  }
}

/*!
 * \brief Metoda pozwalająca przesunąć robota o zadany wektor
 * \param[in] W - zadany wektor translacji
 * \param[out] Robot po translacji
 */

void Robot::Przesun (const Wektor2D& W)
{
  Polozenie = Polozenie + W;
  Przelicz();
}
void Robot::Jedz (double Dlugosc) {
  double Przesun_x, Przesun_y;
  Przesun_x = cos(PI*Kat/180) * Dlugosc;
  Przesun_y = sin(PI*Kat/180) * Dlugosc;
  Przesun(Wektor2D (Przesun_x,Przesun_y));
	  
}

/*!
 * \brief Metoda pozwalająca obracać robota o zadany kąt
 * \param[in] Kat - zadany kąt obrotu
 */

void Robot::Obroc(int _Kat)
{
  Kat = Kat + _Kat;
  Przelicz();
}

/*!
 * \brief Metoda przeliczająca współrzędne lokalne na globalne
 */

Wektor2D Robot::Lok2Glob(Wektor2D in)
{
  return Macierz2x2(Kat)*in + Polozenie;
}

void Robot::Przelicz(void)
{
  for(int i = 0; i < ZW_lok.RozmiarZbioru(); i++){
    ZW[i] = Lok2Glob(ZW_lok[i]);
  }
}
  
  
