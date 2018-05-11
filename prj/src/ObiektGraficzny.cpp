#include "ObiektGraficzny.hh"

/*!
 * \file
 * \brief Definicja metod klasy Obiekt_Graficzny
 * 
 * Zawiera definicję metod klasy Obiekt_Grafczny
 */

/*!
 * \brief Wirtualna metoda pozwalająca na dodanie wierzchołka do obiektu
 * \param[in] W - wektor który ma zostać dodany do tablicy
 * \param[out] Obiekt Graficzny z nowym wierzchołkiem
 */

Wektor2D ObiektGraficzny::Trans;

void ObiektGraficzny::DodajWierzcholek (const Wektor2D& W)
{
  ZW.Dodaj(W);
}

/*!
 * \brief Wirtualna metoda pozwalająca przesunąć obiekt graficzny o wektor
 * \param[in] W - wektor przesunięcia
 * \param[out] Obiekt Graficzny przesunięty o zadany wektor
 */


void ObiektGraficzny::Przesun (const Wektor2D& W)
{
  Trans = Trans + W;
}

/*!
 * \brief Metoda zapisujaca Obiekt Graficzny do strumienia
 * \param[in] s - strumien do zapisu danych
 */

bool ObiektGraficzny::Zapisz(std::ostream& s)
{
  Zbior_Wierzcholkow ZW_trans;

  for(int i = 0; i < ZW.RozmiarZbioru(); i++){
    ZW_trans.Dodaj(ZW[i] + Trans);
  }
  s << ZW_trans;
  std::flush(s);
  return true;
}
