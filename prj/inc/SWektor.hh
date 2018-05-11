#ifndef SWEKTOR_HH
#define SWEKTOR_HH


/*!
 * \file
 * \brief  Definicja szablonu SWektor
 *
 *  Zawiera definicję szablonu SWektor. Pozwala on na
 *  stworzenie instancji klasy wektor o dowolnym wymiarze
 *  oraz typie pól reprezentujących jego współrzędne, dla 
 *  których zdefiniowane są podstawowe działania arytmetyczne.
 */



#include <iostream>

/*!
 * \brief Szablon klasy wektor parametryzowanej wymiarem i typem współrzędnych
 *
 *  Szablon umożliwiający tworzenie instancji typu, który modeluje 
 *  pojęcie wektora. 
 *   \param  STyp - typ pól repezentujących kolejne współrzędne wektora,
 *   \param  SWymiar - wymiar wektora.
 */
template <typename STyp, int SWymiar>
class SWektor {
   /*!
    * \brief Współrzędne wektora
    *
    *  Tablica zawiera kolejne współrzędne wektora.
    */
    static int LWszystkich, LObecnych;
    STyp  TabWektor[SWymiar];
  public:
   /*!
    * \brief Inicjaliuje obiek wartościami 0.
    *
    *  Inicjaluje wszystkie współrzędne wektora wartością 0.
    */
    SWektor() {
      for(int i = 0; i < SWymiar; i++) TabWektor[i] = 0;
      ++LWszystkich;
      ++LObecnych;
      }
    /*!
    * \brief Inicjaliuje obiek wartościami x i y
    */
    SWektor(double x, double y) {
      TabWektor[0] = x; TabWektor[1] = y;
      ++LWszystkich;
      ++LObecnych;
      }

    // ~SWektor() {
    //   LObecnych--;
    // }

    // SWektor(const SWektor &W) {*this = W;}


  static int WezLWszystkich() {
    return LWszystkich;
  }

  static int WezLObecnych() {
    return LObecnych;
  }

  
   /*!
    * \brief Dostęp poprzez indeks do współrzędnych wektora w trybie \e tylko \e do \e odczytu.
    *
    *  Umożliwia dostęp do współrzędnych poprzez indeks w trybie  \e tylko \e do \e odczytu.
    *  Nie jest sprawdzana poprawność wartości indeksu, czy mieści się we właściwym zakresie.
    *
    *  \param[in] i - indeks wybranej współrzędnej. ieksowanie tak jak w przypadku 
    *               tablicy, zaczyna się od 0.
    *  \pre Wartość parametru \e i musi być mniejsza niż \e SWymiar.
    *  \return Wartość indeksowanej współrzędnej.
    */
    STyp  operator [] (unsigned int i) const { return TabWektor[i]; }
   /*!
    * \brief Dostęp poprzez indeks do współrzędnych wektora w trybie \e modyfikacji.
    *
    *  Umożliwia dostęp do współrzędnych poprzez indeks w trybie modyfikacji.
    *  Nie jest sprawdzana poprawność wartości indeksu, czy mieści się we właściwym zakresie.
    *
    *  \param[in] i - indeks wybranej współrzędnej. ieksowanie tak jak w przypadku 
    *               tablicy, zaczyna się od 0.
    *  \pre Wartość parametru \e i musi być mniejsza niż \e SWymiar.
    *  \return Referencję do indeksowanej współrzędnej.
    */
    STyp &operator [] (unsigned int i)       { return TabWektor[i]; }
   /*!
    * \brief Odejmowanie dwóch wektorów.
    */
    SWektor<STyp,SWymiar> operator - (const SWektor<STyp,SWymiar> &W) const;
   /*!
    * \brief Dodanie dwóch wektorów.
    */
    SWektor<STyp,SWymiar> operator + (const SWektor<STyp,SWymiar> &W) const;
   /*!
    * \brief Mnoży wektor przez liczbę.
    */
    SWektor<STyp,SWymiar> operator * (double D) const;
    /*!
    * \brief Pozwala na przypisanie wartosci do wektora
    */
    SWektor<STyp,SWymiar> & operator = (const SWektor<STyp,SWymiar> &W);
    bool operator == (const SWektor<STyp,SWymiar> &W);

};


/*!
 *  Realizuje operacje przypisania wartosci jednego wektora do drugiego
 *  \param[in] W - drugi argument operacji przypisania.
 *  \return Wynik operacji przypisania.
 */
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> & SWektor<STyp,SWymiar>::operator = (const SWektor<STyp,SWymiar> &W)
{
  for(unsigned int i = 0; i < SWymiar; i++){
      (*this)[i] = W[i];
  }
  return *this;
}

template <typename STyp, int SWymiar>
bool SWektor<STyp,SWymiar>::operator == (const SWektor<STyp,SWymiar> &W)
{
  for(unsigned int i = 0; i < SWymiar; i++){
    if((*this)[i] != W[i]) {
      return false;
    }
  }
  return true;
}

/*!
 *  Realizuje odejmowanie dwóch wektorów i zwraca wynik działania.
 *  \param[in] W - drugi argument operacji odejmownaia.
 *  \return Wynik operacji odejmowania.
 */
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator - (const SWektor<STyp,SWymiar> &W) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int i = 0; i < SWymiar; ++i) Wynik[i] = (*this)[i] - W[i];
  return Wynik;
}



/*!
 *  Realizuje dodawanie dwóch wektorów i zwraca wynik działania.
 *  \param[in] W - drugi argument operacji dodwania.
 *  \return Wynik operacji dodawania.
 */
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator + (const SWektor<STyp,SWymiar> &W) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int i = 0; i < SWymiar; ++i) Wynik[i] = (*this)[i] + W[i];
  return Wynik;
}



/*!
 *  Realizuje mnożenie wszystkie współrzędnych wektora przez liczbę.
 *  \param[in] D - wartość liczby, przez którą zostaną wymnożone wszystkie
 *                       współrzędne wektora.
 *  \return Wynik operacji mnożenia przez liczbę.
 */
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (double D) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (unsigned int i = 0; i < SWymiar; ++i) Wynik[i] = (*this)[i]*D;
  return Wynik;  
}

/*!
 * \brief Wypisuje kolejne współrzędne wektora
 *
 * Do strumienia wyjściowego w formie tekstowej wpisuje wszystkie wartości
 * współrzędnych wektora rozdzielając je spacją.
 * Przykład wyniku operacji
\verbatim
    12.5 1.23 4 6
\endverbatim
 *  \param[in,out]  StrmWyj - strumień wyjściowy, do którego zostają wpisane
 *                            w formie tekstowej wartości kolejnych współrzędnych.
 *  \param[in] W - wektor, którego współrzędne mają zostać wpisane do strumienia.
 *  \return Referencja do strumienia wyjściowego będącego parametrem wywołania
 *          niniejszego przeciążenia operatora <<.
 */
template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &StrmWyj, const SWektor<STyp,SWymiar>& W)
{
  for (unsigned int i = 0; i < SWymiar; ++i) {
    StrmWyj << " " << W[i];
  }  
  return StrmWyj;
}

/*!
 * \brief Przeciążenie standardowego wejścia
 * To przciążenie pozwala na bezpośrednie wczytanie wartości do kolejnych
 * atrybutów wektora.
 * \param[in] Strm - Strumień wejściowy z którego wczytujemy wartości do wektora
 * \param[in] W - Wektor do którego zapisujemy podane wartości
 * \param[out] Strm - Strumień z wczytanym wektorem
 */
  template <typename STyp, int SWymiar>
  int SWektor<STyp,SWymiar>::LWszystkich = 0;
  template <typename STyp, int SWymiar>
  int SWektor<STyp,SWymiar>::LObecnych = 0;

  template <typename STyp, int SWymiar>
  std::istream& operator >> (std::istream &Strm, SWektor<STyp,SWymiar> &W) {
    for (unsigned int i = 0; i < SWymiar; i++) {
      Strm >> W[i];     
    }
    return Strm;
  }


#endif
