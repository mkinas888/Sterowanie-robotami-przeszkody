#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH
#define PI 3.14159265


#include <iostream>
#include <cmath>
#include "Wektor2D.hh"

#define ROZMIAR 2
using namespace std;

/*!
 * \file Macierz2x2.hh
 * \brief Definicja klasy Macierz2x2
 *
 * Plik zawiera definicję klasy reprezentującej macierz 2x2
 */


class Macierz2x2 {
  /*!
   * \brief Klasa modeluje pojęcia macierz2x2 potrzebnej do obrotu robota.
   * Jej atrybuty to kolejne pola przechowywane w tablicy dwuwymiarowej.
   */
  
  double TabMacierz[ROZMIAR][ROZMIAR];
  
  public:

  /*!
   * \brief Konstruktor macierzy ktory zeruje jej pola
   */
  
  Macierz2x2()
  {
    for(int i=0;i<ROZMIAR;i++)
      {
      for(int j=0;j<ROZMIAR;j++)
        {
          TabMacierz[i][j] = 0;
        }
      }
  }
  /*!
   * \brief Konstruktor macierzy wypełniający jej pola zadaną wartością
   * zależną od zadanego kąta.
   */

  Macierz2x2(int Kat) {
    TabMacierz[0][0] = cos(PI*Kat/180);
    TabMacierz[0][1] = -sin(PI*Kat/180);
    TabMacierz[1][0] = sin(PI*Kat/180);
    TabMacierz[1][1] = cos(PI*Kat/180);
  }
  /*!
   * \brief Destruktor macierzy
   */
  
  ~Macierz2x2() {
  }
  

  /*!
   * \brief Przeciążenie operatorów indeksujących dla macierzy
   */
  
  double operator ( ) (int i, int j) const
  {
    return TabMacierz[i][j];
  }
  double & operator ( ) (int i, int j)
  {
    return TabMacierz[i][j];
  }

  /*!
   * \brief Metoda pozwalająca na bezpośredni dostęp do pól macierzy
   */
  
  double Wez (int i, int j) const {
    return TabMacierz[i][j];
  }

  /*!
   * \brief Przeciazenie operatora * dla macierzy i wektora
   */
  Wektor2D operator * (const Wektor2D& Wek);

  friend std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac);

};

/*!
 * \brief Przeciazenie operatora << dla standardowego wejscia
 * pozwalajace na poprawne wczytanie macierzy 
 */

std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac);

#endif
