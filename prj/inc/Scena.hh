#ifndef SCENA_HH
#define SCENA_HH

#include <iostream>
#include "Robot.hh"
#include "Sciezka.hh"

/*!
 * \file Scena.hh
 * \brief Definicja klasy Scena
 *
 * Plik zawiera definicję klasy reprezentującej scenę
 */


class Scena {

/*!
 * \brief Modeluje pojęcie sceny
 *
 * Klasa modeluje pojęcie sceny z robotem oraz jego ścieżką
 * Jej atrybuty to Robot oraz ścieżka.
 */

  Robot R;
  Sciezka S;
  
public:
  /*!
   * /brief Konstruktory oraz destruktor sceny
   */
  
  Scena(){}

  Scena (Wektor2D WekInit) : R(WekInit) {};

  ~Scena(){}
  
  /*!
   * \brief Metoda pozwalajaca na dostep do robota
   */

  Robot WezR () const {
    return R;
  }

  /*!
   * \brief Metoda pozwalajaca na dostep do sciezki
   */

  Sciezka WezS () const {
    return S;
  }

  /*!
   * \brief Metoda pozwalajaca na dostep do polozenia robota
   */

  Wektor2D PokazPolozenie () const {
    return R.ZwrocPolozenie();
  }

  /*!
   * \brief Metoda zapisujaca obecne polozenie robota do sciezki
   */

  void ZapiszSciezke () {
    Wektor2D Tmp = PokazPolozenie();
    S.Dodaj(Tmp);
  }

  /*!
   * \brief Metoda pozwalająca przesunąć całą scenę o zadany wektor
   * \param[in] W - wektor o który ma zostać przesunięta scena. 
   */

  void Przesun (const Wektor2D& W)
  {
    R.Przesun(W);
    S.Przesun(W);
  }

  /*!
   * \brief Metoda animujaca jazde robota
   */

  void JazdaAnimuj (double Dlugosc)
  {
    R.Jedz(Dlugosc);
  }

  /*!
   * \brief Metoda animujaca obrot robota
   */

  void ObrotAnimuj (int Kat) {
      R.Obroc(Kat);
  }

  void ZmienPredkosc (double Szybkosc) {
    R.ZmienSzybkosc(Szybkosc);
  }

  void SkalujRobota (double Scale) {
    R.ZmienRozmiarRobota(Scale);
  }

  /*!
   * \brief Metody zapisujaca robota do pliku
   */

  bool RZapiszDoPliku (const char  *sNazwaPliku);

  /*!
   * \brief Metoda zapisujaca sciezke do pliku
   */

  bool SZapiszDoPliku (const char  *sNazwaPliku);
  
};

#endif
  
    
