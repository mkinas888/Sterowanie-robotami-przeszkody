#ifndef SCENA_HH
#define SCENA_HH

#include <iostream>
#include <memory>
#include <cmath>
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
 * Klasa modeluje pojęcie sceny z na ktorej znajduja sie wszystkie obiekty
 * Jej atrybuty to listy: obiektow, robotow, przeszkod, i sciezek,
 * oraz wskazniki na aktualnego robota i sciezke a takze lacze do gnuplota
 */
  std::list<shared_ptr<ObiektGraficzny>> LOb;
  std::list<shared_ptr<Robot>> LR;
  std::list<shared_ptr<Przeszkoda>> LP;
  std::list<shared_ptr<Sciezka>> LS;

  shared_ptr<Robot> WR, WRTmp;
  shared_ptr<Sciezka> WS;

  PzG::LaczeDoGNUPlota  Lacze;
 
  
public:
  /*!
   * /brief Konstruktor oraz destruktor sceny
   */
  
  Scena(){
    Lacze.ZmienTrybRys(PzG::TR_2D);
  };

  ~Scena(){}

   /*! 
   * Metoda tworzaca listy wszystkich obiektow dostepnych w programie
   */

  void TworzListy();

  /*! 
   * Metoda zapisujaca wszystkie roboty do pliku
   */

  bool ZapiszDoPliku ();

  /*! 
   * Metoda zapisujaca wszystkie obiekty graficzne do pliku
   */

  bool ZapiszRoboty ();

  /*! 
   * Metoda obracajaca wybrana przeszkode
   */

  void ObrocPrzeszkode();

  /*! 
   * Metoda przesuwajaca wybrana przeszkode
   */

  void PrzesunPrzeszkode();

  /*! 
   * Metoda zmieniejaca rozmiar wybranej przeszkody
   */

  void ZmienRozmiarPrzeszkody();

  /*! 
   * Metoda dodajaca nowa przeszkode
   */

  void DodajPrzeszkode();

  /*! 
   * Metoda usuwajaca wybrana przeszkode
   */

  void UsunPrzeszkode();

  /*! 
   * Metoda pozwalajaca na selekcje robota i jego sciezki
   */
  
  void SelekcjaRobota();

  /*! 
   * Metoda zmieniajaca predkosc robota
   * param[in] Szybkosc - nowa predkosc robota
   */

  void ZmienPredkosc (double Szybkosc) {
    WR->ZmienSzybkosc(Szybkosc);
  }

  /*! 
   * Metoda skalujaca robota
   * param[in] Scale - wartosc wspolczynnika skali robota
   */

  void SkalujRobota (double Scale) {
    WR->ZmienRozmiarRobota(Scale);
    ZapiszDoPliku();
  }

  /*! 
   * Metoda animujaca obrot robota o zadany kat
   * param[in] Obr - kat obrotu robota
   */

  void AnimujObrot (int Obr) {
    for(int i = 0; i < Obr; i++) {
      WR->Obroc(1);
      ZapiszRoboty();
    }
    ZapiszDoPliku();
  }

  /*! 
   * Metoda animujaca jazde robota
   */

  void AnimujJazde (double Droga);


  /*! 
   * Metoda przesuwajaca robota o zadany wektor
   * param[in] W - wektor przesuniecia
   */

  void Przesun (Wektor2D &W);
  Wektor2D PokazPolozenieRobota () {
    return WR->ZwrocPolozenie();
  }


  /*! 
   * Metoda sprawdzajaca kolizje robota z przeszkodami
   */

  bool SprawdzCzyKolizjaZPrzeszkoda ();


  /*! 
   * Metoda sprawdzajaca kolizje robota z innym robotem
   */

  bool CzyKolizjaZRobotem ();

};

#endif
  
    
