#include "Przeszkoda.hh"

/*!
 * \file
 * \brief Definicja metod klasy Sciezka
 * 
 * Zawiera definicję metod klasy Sciezka
 */

Przeszkoda::Przeszkoda(double x, double y, double Wysokosc, double Szerokosc) {
    Kat = 0;
    Polozenie = Wektor2D(x*(3/2),y/2);
    ZW_lok.Dodaj(Wektor2D(-(0.5*Szerokosc),-(0.5*Wysokosc)));
    ZW_lok.Dodaj(Wektor2D(0.5*Szerokosc, -(0.5*Wysokosc)));
    ZW_lok.Dodaj(Wektor2D(0.5*Szerokosc, 0.5*Wysokosc));
    ZW_lok.Dodaj(Wektor2D(-(0.5*Szerokosc), 0.5*Wysokosc));
    ZW_lok.Dodaj(Wektor2D(-(0.5*Szerokosc),-(0.5*Wysokosc)));
    for(int i = 0; i < ZW_lok.RozmiarZbioru(); i++) {
        ZW.Dodaj(Lok2Glob(ZW_lok[i]));
    }
  }

Przeszkoda::Przeszkoda(double x, double y, double Wysokosc, double Szerokosc, int Obr) {
    Kat = Obr;
    Polozenie = Wektor2D(x*(3/2),y/2);
    ZW_lok.Dodaj(Wektor2D(-(0.5*Szerokosc),-(0.5*Wysokosc)));
    ZW_lok.Dodaj(Wektor2D(0.5*Szerokosc, -(0.5*Wysokosc)));
    ZW_lok.Dodaj(Wektor2D(0.5*Szerokosc, 0.5*Wysokosc));
    ZW_lok.Dodaj(Wektor2D(-(0.5*Szerokosc), 0.5*Wysokosc));
    ZW_lok.Dodaj(Wektor2D(-(0.5*Szerokosc),-(0.5*Wysokosc)));
    for(int i = 0; i < ZW_lok.RozmiarZbioru(); i++) {
        ZW.Dodaj(Lok2Glob(ZW_lok[i]));
    }
  }

Wektor2D Przeszkoda::Lok2Glob(Wektor2D in)
{
  return Macierz2x2(Kat)*in + Polozenie;
}

void Przeszkoda::Przelicz(void)
{
  for(int i = 0; i < ZW_lok.RozmiarZbioru(); i++){
    ZW[i] = Lok2Glob(ZW_lok[i]);
  }
}

/*!
 * \brief Metoda pozwalajaca dodac wektor do ścieżki
 * \param[in] W - Wektor ktory chcemy dodac do sciezki.
 */


void Przeszkoda::Dodaj (Wektor2D& W)
{
  ZW.Dodaj(W);
}

/*!
 * \brief Metoda pozwalajaca przesunac sciezke o zadany wektor
 * \param[in] W - Wektor o ktory chcemy przesunac sciezke
 */

void Przeszkoda::Przesun (const Wektor2D& W) {
  Polozenie = Polozenie + W;
  Przelicz();
}

void Przeszkoda::Obroc (int Obr) {
  Kat = Kat + Obr;
  Przelicz();
}

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

