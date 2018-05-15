#ifndef ROBOT_HH
#define ROBOT_HH

#include <iostream>
#include <fstream>

#include "Zbior_Wierzcholkow.hh"
#include "Wektor2D.hh"
#include "ObiektGraficzny.hh"

/*!
 * \file Robot.hh
 * \brief Definicja klasy Robot
 *
 * Plik zawiera definicję klasy reprezentującej mobilnego robota
 */


class Robot : public ObiektGraficzny {

/*!
 * \brief Modeluje pojęcie robota  moblinego
 *
 * Klasa modeluje pojęcia robota mobilnego. Jej atrybuty to zbiór wierzchołków
 * reprezentujący robota jego ustalona szybkość i obecny kąt na płaszczyźnie
 */
  
  Zbior_Wierzcholkow ZW_lok;
  double             Szybkosc;
  int                Kat;
  int                Rozmiar;

  Wektor2D Lok2Glob(Wektor2D in);
  void     Przelicz(void);

  
public:

  /*!
   * \brief Kosntruktor i destruktor robota
   */
  
  Robot();

  Robot (Wektor2D WekInit);

  ~Robot()
  {
  }

  virtual const char* NazwaTypu() const {return "Robot";}

  int ZwrocRozmiar () {int i = Rozmiar; return i;}

  /*!
   * \brief Metoda pozwalająca zmieniać szybkość robota
   * \param[in] NowaSzybkość - podana nowa szybkość
   */
  void ZmienSzybkosc (double NowaSzybkosc)
  {
    Szybkosc = NowaSzybkosc;
  }

   /*!
   * \brief Metoda zwracająca obecna szybkosc robota
   */

  double ZwrocSzybkosc () const {
    return Szybkosc;
  }
  /*!
   * \brief Metoda zwracająca wektor współrzędnych środka robota
   */
  Wektor2D ZwrocPolozenie () const
  {
    return Polozenie;
  }
  /*! 
   * \brief Metoda pozwalająca obracać robota o zadany kąt
   */
  void Obroc(int _Kat);
  /*!
   * \brief Metoda pozwalająca na przesunięcie robota o wektor
   */
  void Przesun (const Wektor2D& W);
   /*!
   * \brief Metoda przelicza dlugosc na wektor przesuniecia robota
   */
  void Jedz (double Dlugosc);

  /*!
   * \brief Metoda skalujaca robota
   */

  void ZmienRozmiarRobota(double Skala);
  
 
};


#endif
