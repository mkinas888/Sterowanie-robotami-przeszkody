#ifndef ZBIOR_WIERZCHOLKOW_HH
#define ZBIOR_WIERZCHOLKOW_HH
#include <iostream>
#include <vector>
#include "Wektor2D.hh"

using namespace std;

/*!
 * \file Zbior_Wierzcholkow.hh
 * \brief Definicja klasy Zbior_Wierzcholkow
 *
 * Plik zawiera definicję klasy reprezentującej Zbior_Wierzcholkow
 */


class Zbior_Wierzcholkow {

 /*!
 * \brief Modeluje pojęcie Zbioru wierzchołków 
 *
 * Klasa modeluje pojęcie zbioru wierzchołków danych obiektów
 * Jej atrybut to szablon dynamicznej listy vector.
 */


  std::vector < Wektor2D > ZW;

public:

  /*!
   * \brief Konstruktor oraz destruktor zbioru wierzchołków
   */
  
  Zbior_Wierzcholkow()
  {
  }
  ~Zbior_Wierzcholkow()
  {
  };
 
   /*!
   * \brief Metoda pozwalająca na usuniecie elementow ze zbioru wierzcholkow
   */

  void Usun () {
    ZW.clear();
  }

   /*!
   * \brief Metoda pozwalająca na dodanie kolejnego wektora do zbioru
   */

  void Dodaj (const Wektor2D& W);
  int RozmiarZbioru () const
  {
    return ZW.size();
  }
  /*!
   * \brief Przeciążenie operatora indeksującego.
   */
  
  Wektor2D operator [ ](int i) const
  {
    return ZW[i];
  }
  
  Wektor2D& operator [ ](int i)
  {
    return ZW[i];
  }

  friend std::ostream& operator << (std::ostream& Strm,
				    const Zbior_Wierzcholkow& Zw);
  
};
/*!
 * \brief Przeciązenie pozwalające na bezpośrednie wyświetlanie tablicy
 * wierzchołków
 */

std::ostream& operator << (std::ostream& Strm, const Zbior_Wierzcholkow& Zw);

#endif
