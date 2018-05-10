#include "Zbior_Wierzcholkow.hh"

/*!
 * \file
 * \brief Definicja metod klasy Zbior_Wierzcholkow
 * 
 * Zawiera definicję metod klasy Zbior_Wierzcholkow
 */

/*!
 * \brief Przeciążenie standardowego wyjścia
 * To przciążenie pozwala na bezpośrednie wyświetlenie tablicy wierzcholkow
 * \param[in] Strm - Strumień wyjściowy na który podajemy tablice
 * \param[in] ZW - Zbiór który chcemy wyświetlić
 * \param[out] Strm - Strumień z wyświetlonymi wierzchołkamu
 */

std::ostream& operator << (std::ostream& Strm, const Zbior_Wierzcholkow& ZW)
{
  int i,j;
  j = ZW.RozmiarZbioru();
  for(i=0;i<j;i++) {
    Strm << ZW[i] << endl;
  }
  return Strm;
}

/*!
 * \brief Metoda pozwalająca na dodanie wierzchołka do tablicy.
 * \param[in] W - Wierzchołek który ma zostać dodany/
 * \param[out] ZW - Zbiór z dodanym wierzchołkiem
 */

void Zbior_Wierzcholkow::Dodaj (const Wektor2D& W)
{
  ZW.push_back(W);
}
