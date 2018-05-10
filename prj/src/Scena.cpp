#include "Scena.hh"


/*!
 * \brief Metoda zapisujaca wspolrzedne robota do pliku
 * \param[in] *sNazwaPliku - nazwa pliku do ktorego zapisane beda wspolrzedne robota
 * \param[out] false/true - w zaleznosci od sukcesu lub jego braku
 */

bool Scena::RZapiszDoPliku (const char  *sNazwaPliku)
{
  ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
	 << ":(  nie powiodla sie." << endl;
    return false;
  }

  R.Zapisz(StrmPlikowy);
  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

/*!
 * \brief Metoda zapisujaca wspolrzedne sciezki do pliku
 * \param[in] *sNazwaPliku - nazwa pliku do ktorego zapisane beda wspolrzedne robota
 * \param[out] false/true - w zaleznosci od sukcesu lub jego braku
 */

bool Scena::SZapiszDoPliku (const char  *sNazwaPliku)
{
  ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
	 << ":(  nie powiodla sie." << endl;
    return false;
  }

  S.Zapisz(StrmPlikowy);
  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}
