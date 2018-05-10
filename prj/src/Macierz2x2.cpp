#include "Macierz2x2.hh"

/*!
 * \file
 * \brief Definicja metod klasy Macierz2x2
 * 
 * Zawiera definicję metod klasy Macierz2x2
 */

/*!
 * \brief Przeciążenie standardowego wyjścia
 * To przciążenie pozwala na bezpośrednie wyświetlenie pól macierzy
 * \param[in] Strm - Strumień wyjściowy na który podajemy wartości pól
 * \param[in] Mac - Macierz2x2
 * \param[out] Strm - Strumień z wyświetlonymi współrzędnymi
 */


std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac) {
  Strm << Mac.TabMacierz[0][0] << "    " << Mac.TabMacierz[0][1] << endl
       << Mac.TabMacierz[1][0] << "    " << Mac.TabMacierz[1][1] << endl;
  return Strm;
}

/*!
 * \brief Przeciążenie operatora * dla wektora i macierzy
 * To przciążenie pozwala na bezposrednie mnozenie wektora razy macierz
 * \param[in] Wek - Wektor przez ktorego macierz zostanie pomnozona
 * \param[out] Wekt - Wektor wynikowy
 */

Wektor2D Macierz2x2::operator * (const Wektor2D& Wek) {
  Wektor2D Wekt;
  for(int i=0;i<ROZMIAR;i++) {
    Wekt[i] = Wek[0]*this->TabMacierz[i][0] + 
    Wek[1]*this->TabMacierz[i][1];
  }
  return Wekt;
}
