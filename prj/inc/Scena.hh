#ifndef SCENA_HH
#define SCENA_HH

#include <iostream>
#include <memory>
#include <unistd.h>
#include <list>
#include <string>
#include "Robot.hh"
#include "Sciezka.hh"
#include "ObiektGraficzny.hh"
#include "Przeszkoda.hh"
#include "lacze_do_gnuplota.hh"


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
  std::list<shared_ptr<ObiektGraficzny>> LOb;
  std::list<shared_ptr<Robot>> LR;
  std::list<shared_ptr<Przeszkoda>> LP;

  shared_ptr<Robot> WR;
  shared_ptr<Sciezka> WS;

  PzG::LaczeDoGNUPlota  Lacze;
 
  
public:
  /*!
   * /brief Konstruktory oraz destruktor sceny
   */
  
  Scena(){
    Lacze.ZmienTrybRys(PzG::TR_2D);
  };

  ~Scena(){}

  void TworzListy();

  bool ZapiszDoPliku ();
  bool ZapiszRoboty ();

  void ObrocPrzeszkode();
  void PrzesunPrzeszkode();
  void ZmienRozmiarPrzeszkody();
  void DodajPrzeszkode();
  void UsunPrzeszkode();
  
  void SelekcjaRobota();

  void ZmienPredkosc (double Szybkosc) {
    WR->ZmienSzybkosc(Szybkosc);
  }

  void SkalujRobota (double Scale) {
    WR->ZmienRozmiarRobota(Scale);
    ZapiszDoPliku();
  }

  void AnimujObrot (int Obr) {
    for(int i = 0; i < Obr; i++) {
      WR->Obroc(1);
      ZapiszRoboty();
    }
    ZapiszDoPliku();
  }

  void AnimujJazde (double Droga);
  void Przesun (Wektor2D &W);
  Wektor2D PokazPolozenieRobota () {
    return WR->ZwrocPolozenie();
  }


  // /*!
  //  * \brief Metoda pozwalajaca na dostep do polozenia robota
  //  */

  // Wektor2D PokazPolozenie () const {
  //   return R.ZwrocPolozenie();
  // }

  // /*!
  //  * \brief Metoda zapisujaca obecne polozenie robota do sciezki
  //  */

  // void ZapiszSciezke () {
  //   Wektor2D Tmp = PokazPolozenie();
  //   S.Dodaj(Tmp);
  // }

  // /*!
  //  * \brief Metoda pozwalająca przesunąć całą scenę o zadany wektor
  //  * \param[in] W - wektor o który ma zostać przesunięta scena. 
  //  */

  // void Przesun (const Wektor2D& W)
  // {
  //   R.Przesun(W);
  //   S.Przesun(W);
  // }

  // /*!
  //  * \brief Metoda animujaca jazde robota
  //  */

  // void JazdaAnimuj (double Dlugosc)
  // {
  //   R.Jedz(Dlugosc);
  // }

  // /*!
  //  * \brief Metoda animujaca obrot robota
  //  */

  // void ObrotAnimuj (int Kat) {
  //     R.Obroc(Kat);
  // }

  // void ZmienPredkosc (double Szybkosc) {
  //   R.ZmienSzybkosc(Szybkosc);
  // }

  // void SkalujRobota (double Scale) {
  //   R.ZmienRozmiarRobota(Scale);
  // }

  
  
};

#endif
  
    
