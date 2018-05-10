#ifndef SCIEZKA_HH
#define SCIEZKA_HH
#include <iostream>
#include <fstream>
#include "Zbior_Wierzcholkow.hh"
#include "Robot.hh"

/*!
 * \file Sciezka.hh
 * \brief Definicja klasy Sciezka
 *
 * Plik zawiera definicję klasy reprezentującej sciezka robota
 */


class Sciezka : public ObiektGraficzny {

  /*!
 * \brief Modeluje pojęcie sciezki robota
 *
 * Klasa modeluje pojęcie sciezki ruchu robota
 * Jej atrybut to zbiór wektorów oznaczający ścieżke.
 */

  Zbior_Wierzcholkow ZW_lok;

public:
  /*!
   * /brief Konstruktor ścieżki inicjalizujący ją początkową współrzędną środka
   * robota.
   */

  Sciezka()
  {
  }

  /*!
   * /brief Destruktor ścieżki 
   */
  
  ~Sciezka()
  {
  }
  /*! 
   * Metoda pozwalająca na dodanie kolejnego wektora z miejsca w którym 
   * znajduje się robot.
   */
  
  void Dodaj (Wektor2D& W);

  /*! 
   * Metoda pozwalająca na przesuniecie sciezki o zadany wektor
   */

  void Przesun (const Wektor2D& W);

};


#endif
