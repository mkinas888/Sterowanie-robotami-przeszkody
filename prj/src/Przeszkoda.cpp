#include "Przeszkoda.hh"

/*!
 * \file
 * \brief Definicja metod klasy Sciezka
 * 
 * Zawiera definicję metod klasy Sciezka
 */

/*!
 * \brief Konstruktor przeszkody o zadanym polozeniu i parametrach
 * \param[in] x - wspolrzedna x polozenia przeszkody
 * \param[in] y - wspolrzedna y polozenia przeszkody
 * \param[in] Wysokosc - wysokosc przeszkody
 * \param[in] Szerokosc - szerokosc przeszkody
 */

Przeszkoda::Przeszkoda(double x, double y, double Wysokosc, double Szerokosc) {
    Kat = 0;
    Polozenie = Wektor2D(x*(3/2),y);
    ZW_lok.Dodaj(Wektor2D(-(0.5*Szerokosc),-(0.5*Wysokosc)));
    ZW_lok.Dodaj(Wektor2D(0.5*Szerokosc, -(0.5*Wysokosc)));
    ZW_lok.Dodaj(Wektor2D(0.5*Szerokosc, 0.5*Wysokosc));
    ZW_lok.Dodaj(Wektor2D(-(0.5*Szerokosc), 0.5*Wysokosc));
    ZW_lok.Dodaj(Wektor2D(-(0.5*Szerokosc),-(0.5*Wysokosc)));
    for(int i = 0; i < ZW_lok.RozmiarZbioru(); i++) {
        ZW.Dodaj(Lok2Glob(ZW_lok[i]));
    }
  }

  /*!
 * \brief Konstruktor przeszkody o zadanym polozeniu i parametrach
 * \param[in] x - wspolrzedna x polozenia przeszkody
 * \param[in] y - wspolrzedna y polozenia przeszkody
 * \param[in] Wysokosc - wysokosc przeszkody
 * \param[in] Szerokosc - szerokosc przeszkody
 * \param[in] Obr - poczatkowy kat obrotu przeszkody
 */

Przeszkoda::Przeszkoda(double x, double y, double Wysokosc, double Szerokosc, int Obr) {
    Kat = Obr;
    Polozenie = Wektor2D(x*(3/2),y);
    ZW_lok.Dodaj(Wektor2D(-(0.5*Szerokosc),-(0.5*Wysokosc)));
    ZW_lok.Dodaj(Wektor2D(0.5*Szerokosc, -(0.5*Wysokosc)));
    ZW_lok.Dodaj(Wektor2D(0.5*Szerokosc, 0.5*Wysokosc));
    ZW_lok.Dodaj(Wektor2D(-(0.5*Szerokosc), 0.5*Wysokosc));
    ZW_lok.Dodaj(Wektor2D(-(0.5*Szerokosc),-(0.5*Wysokosc)));
    for(int i = 0; i < ZW_lok.RozmiarZbioru(); i++) {
        ZW.Dodaj(Lok2Glob(ZW_lok[i]));
    }
  }

  /*!
 * \brief Metoda przeliczajaca wspolrzedne lokalne przeszkody na globalne
 */

Wektor2D Przeszkoda::Lok2Glob(Wektor2D in)
{
  return Macierz2x2(Kat)*in + Polozenie;
}

/*!
 * \brief Metoda przeliczajaca wszystkie wspolrzedne na globalne
 */

void Przeszkoda::Przelicz(void)
{
  for(int i = 0; i < ZW_lok.RozmiarZbioru(); i++){
    ZW[i] = Lok2Glob(ZW_lok[i]);
  }
}

/*!
 * \brief Metoda pozwalajaca dodac wektor do przeszkody
 * \param[in] W - Wektor ktory chcemy dodac do przeszkody
 */


void Przeszkoda::Dodaj (Wektor2D& W)
{
  ZW.Dodaj(W);
}

/*!
 * \brief Metoda pozwalajaca przesunac przeszkode o zadany wektor
 * \param[in] W - Wektor o ktory chcemy przesunac przeszkode
 */

void Przeszkoda::Przesun (const Wektor2D& W) {
  Polozenie = Polozenie + W;
  Przelicz();
}

/*!
 * \brief Metoda pozwalajaca obrocic przeszkode o zadany kat
 * \param[in] Obr - Kat o ktory chcemy obrocic przeszkode
 */

void Przeszkoda::Obroc (int Obr) {
  Kat = Kat + Obr;
  Przelicz();
}

/*!
 * \brief Metoda pozwalajaca zmienic rozmiar przeszkody
 * \param[in] Szer - nowa szerokosc przeszkody
 * \param[in] Wys - nowa wysokosc przeszkody
 */

void Przeszkoda::ZmienRozmiar(double Szer, double Wys) {
    ZW_lok.Usun();
    ZW.Usun();
    ZW_lok.Dodaj(Wektor2D(-(0.5*Szer),-(0.5*Wys)));
    ZW_lok.Dodaj(Wektor2D(0.5*Szer, -(0.5*Wys)));
    ZW_lok.Dodaj(Wektor2D(0.5*Szer, 0.5*Wys));
    ZW_lok.Dodaj(Wektor2D(-(0.5*Szer), 0.5*Wys));
    ZW_lok.Dodaj(Wektor2D(-(0.5*Szer),-(0.5*Wys)));
    for(int i = 0; i < ZW_lok.RozmiarZbioru(); i++) {
        ZW.Dodaj(Lok2Glob(ZW_lok[i]));
    }
}

