#include "Sciezka.hh"

/*!
 * \file
 * \brief Definicja metod klasy Sciezka
 * 
 * Zawiera definicję metod klasy Sciezka
 */

/*!
 * \brief Metoda pozwalajaca dodac wektor do ścieżki
 * \param[in] W - Wektor ktory chcemy dodac do sciezki.
 */


void Sciezka::Dodaj (Wektor2D& W)
{
  Polozenie = W;
  ZW.Dodaj(W);
}

/*!
 * \brief Metoda pozwalajaca przesunac sciezke o zadany wektor
 * \param[in] W - Wektor o ktory chcemy przesunac sciezke
 */

void Sciezka::Przesun (const Wektor2D& W) {
  Polozenie = W;
  for(int i=0;i<ZW.RozmiarZbioru();++i) {
    ZW[i] = ZW[i] + W;
  }
}

