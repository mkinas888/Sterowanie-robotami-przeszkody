#ifndef OBIEKTGRAFICZNY_HH
#define OBIEKTGRAFICZNY_HH

#include <iostream>
#include "Zbior_Wierzcholkow.hh"

/*!
 * \file Obiekt_Graficzny.hh
 * \brief Definicja klasy Obiekt_Graficzny
 *
 * Plik zawiera definicję klasy reprezentującej obiekt graficzny
 */



class ObiektGraficzny {

/*!
 * \brief Modeluje pojęcie obiektu graficznego
 *
 * Klasa modeluje pojęcie obiektu graficznego składającego się z tablicy
 * wierzchołków. Jej atrybut to tablica wierzchołków
 */

  static Wektor2D Trans;

protected:

  Zbior_Wierzcholkow ZW;
  
public:

  /*!
   * \brief Konstruktor i destruktor obiektu graficznego
   */
  
  ObiektGraficzny()
  {
    Trans = Wektor2D(0.0,0.0);
  }
  
  virtual ~ObiektGraficzny()
  {
  }
  
  /*!
   * /brief Metoda pozwalajaca przesunac Obiekt Graficzny o zadany wektor
   */
  
  static void Przesun (const Wektor2D& W);

  /*!
   * /brief Metoda dodac kolejny wierzcholek do Obiektu Graficznego
   */

  void DodajWierzcholek (const Wektor2D& W);

  /*!
   * /brief Metoda zapisac Obiekt Graficzny do strumienia
   */

  bool Zapisz(std::ostream &S);
};

#endif
