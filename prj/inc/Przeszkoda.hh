#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH
#include <iostream>
#include <fstream>
#include "Zbior_Wierzcholkow.hh"
#include "Macierz2x2.hh"
#include "ObiektGraficzny.hh"

/*!
 * \file Sciezka.hh
 * \brief Definicja klasy Sciezka
 *
 * Plik zawiera definicję klasy reprezentującej sciezka robota
 */


class Przeszkoda : public ObiektGraficzny {

  /*!
 * \brief Modeluje pojęcie sciezki robota
 *
 * Klasa modeluje pojęcie sciezki ruchu robota
 * Jej atrybut to zbiór wektorów oznaczający ścieżke.
 */

  Zbior_Wierzcholkow ZW_lok;
  Wektor2D Srodek;
  int Kat;

public:
  /*!
   * /brief Konstruktor ścieżki inicjalizujący ją początkową współrzędną środka
   * robota.
   */

  Przeszkoda()
  {
  }

  Przeszkoda(double x, double y, double Wysokosc, double Szerokosc);
  Przeszkoda(double x, double y, double Wysokosc, double Szerokosc, int Obr);

  /*!
   * /brief Destruktor ścieżki 
   */
  
  ~Przeszkoda()
  {
  }

  virtual const char* NazwaTypu() const {return "Przeszkoda";}
  Wektor2D ZwrocPolozenie() const {return Polozenie;}
  Wektor2D Lok2Glob(Wektor2D in);
  void Przelicz(void);
  /*! 
   * Metoda pozwalająca na dodanie kolejnego wektora z miejsca w którym 
   * znajduje się robot.
   */
  
  void Dodaj (Wektor2D& W);

  /*! 
   * Metoda pozwalająca na przesuniecie sciezki o zadany wektor
   */

  void Przesun (const Wektor2D& W);
  void Obroc (int Obr);
  void ZmienRozmiar (double Szer, double Wys);

};


#endif
