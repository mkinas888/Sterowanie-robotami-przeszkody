#include "Scena.hh"

/*!
 * \brief Metoda tworzaca wszystkie listy obiektow uzywanych w tym programie
 */

void Scena::TworzListy() {

  shared_ptr<ObiektGraficzny>   WRob1 = Fabryka::Zbuduj(TO_Robot,100.0,-150.0);
  shared_ptr<ObiektGraficzny>   WRob2 = Fabryka::Zbuduj(TO_Robot,-100.0,-50.0);
  shared_ptr<ObiektGraficzny>   WRob3 = Fabryka::Zbuduj(TO_Robot,-200.0,50.0);

  shared_ptr<ObiektGraficzny>   WS1 = Fabryka::Zbuduj(TO_Sciezka,100.0,-150.0);
  shared_ptr<ObiektGraficzny>   WS2 = Fabryka::Zbuduj(TO_Sciezka,-100.0,-50.0);
  shared_ptr<ObiektGraficzny>   WS3 = Fabryka::Zbuduj(TO_Sciezka,-200.0,50.0);

  shared_ptr<ObiektGraficzny>   WP1 = Fabryka::Zbuduj(TO_Przeszkoda,0.0, 0.0, 50.0, 80.0,0);
  shared_ptr<ObiektGraficzny>   WP2 = Fabryka::Zbuduj(TO_Przeszkoda,200.0, 200.0, 100.0, 50.0,0);
  shared_ptr<ObiektGraficzny>   WP3 = Fabryka::Zbuduj(TO_Przeszkoda,-250.0, 270.0, 50.0, 20.0,0);
  shared_ptr<ObiektGraficzny>   WP4 = Fabryka::Zbuduj(TO_Przeszkoda,-230.0, -230.0, 150.0, 10.0,0);

  WR = static_pointer_cast<Robot>(WRob1);
  WS = static_pointer_cast<Sciezka>(WS1);

  LOb.push_back(WRob1);
  LOb.push_back(WRob2);
  LOb.push_back(WRob3);
  LOb.push_back(WS1);
  LOb.push_back(WS2);
  LOb.push_back(WS3);
  LOb.push_back(WP1);
  LOb.push_back(WP2);
  LOb.push_back(WP3);
  LOb.push_back(WP4);
  LR.push_back(static_pointer_cast<Robot>(WRob1));
  LR.push_back(static_pointer_cast<Robot>(WRob2));
  LR.push_back(static_pointer_cast<Robot>(WRob3));
  LP.push_back(static_pointer_cast<Przeszkoda>(WP1));
  LP.push_back(static_pointer_cast<Przeszkoda>(WP2));
  LP.push_back(static_pointer_cast<Przeszkoda>(WP3));
  LP.push_back(static_pointer_cast<Przeszkoda>(WP4));
  LS.push_back(static_pointer_cast<Sciezka>(WS1));
  LS.push_back(static_pointer_cast<Sciezka>(WS2));
  LS.push_back(static_pointer_cast<Sciezka>(WS3));
}


/*!
 * \brief Metoda zapisujaca wszystkie roboty do pliku
 * \param[out] false/true - w zaleznosci od sukcesu lub jego braku
 */

bool Scena::ZapiszRoboty () {
  bool wasSuccessful = true;
  int R = 0;
  if (wasSuccessful) {
     for(const shared_ptr<Robot>  &wR : LR) {
        ++R;
        std::string NazwaPliku;
        NazwaPliku = std::string("figury/Robot") + std::string(std::to_string(R)) + std::string(".dat");
        std::ofstream StrmPlikowy;
        
        StrmPlikowy.open(NazwaPliku);  
        if (!StrmPlikowy.is_open())  {
          cerr << ":(  Operacja otwarcia do zapisu \"" << NazwaPliku << "\"" << endl
        << ":(  nie powiodla sie." << endl;
          wasSuccessful = false;
        }
        wR->Zapisz(StrmPlikowy);
        StrmPlikowy.close();
        wasSuccessful = !StrmPlikowy.fail();
      }
    }
  Lacze.Rysuj();
  return wasSuccessful;
}

/*!
 * \brief Metoda zapisujaca wszystkie obiekty graficzne do pliku
 * \param[out] false/true - w zaleznosci od sukcesu lub jego braku
 */

bool Scena::ZapiszDoPliku ()
{
  bool wasSuccessful = true;
  int R = 0, S = 0, P = 0;
  if (wasSuccessful) {
     for(const shared_ptr<ObiektGraficzny>  &wOb : LOb) {
        std::string NazwaPliku;
        std::string Typ = wOb->NazwaTypu();
        if(Typ == "Robot") {
          ++R;
          NazwaPliku = std::string("figury/Robot") + std::string(std::to_string(R)) + std::string(".dat");
        } else if (Typ == "Sciezka") {
          ++S;
          NazwaPliku = std::string("figury/Sciezka") + std::string(std::to_string(S)) + std::string(".dat");
        } else if(Typ == "Przeszkoda") {
          ++P;
          NazwaPliku = std::string("figury/Przeszkoda") + std::string(std::to_string(P)) + std::string(".dat");
        }
        std::ofstream StrmPlikowy;
        
        StrmPlikowy.open(NazwaPliku);
        const char * nazwa = NazwaPliku.c_str();
        Lacze.DodajNazwePliku(nazwa,PzG::RR_Ciagly,2);      
        if (!StrmPlikowy.is_open())  {
          cerr << ":(  Operacja otwarcia do zapisu \"" << NazwaPliku << "\"" << endl
        << ":(  nie powiodla sie." << endl;
          wasSuccessful = false;
        }
        wOb->Zapisz(StrmPlikowy);
        StrmPlikowy.close();
        wasSuccessful = !StrmPlikowy.fail();
      }
    }
  Lacze.Rysuj();
  return wasSuccessful;
}

/*!
 * \brief Metoda obracajaca przeszkode ktora uzytkownik wybiera na podstawie polozenia
 * kazdej z przeszkow i wprowadzeniu odpowiedniego kata obrotu
 */

void Scena::ObrocPrzeszkode() {
  Wektor2D W;
  int Obr;
  cout << "Dostepne przeszkody to:" << endl;
  for(const shared_ptr<Przeszkoda>  &wP : LP) {
    cout << wP->ZwrocPolozenie() << endl << endl; 
  }
  cout << "Wprowadz wspolrzedne przeszkody ktora chcesz obrocic" << endl;
  cin >> W;
  cout << "Wprowadz kat o jaki chcesz obrocic wybrana przeszkode:" << endl;
  cin >> Obr;
  for(const shared_ptr<Przeszkoda>  &wP : LP) {
    Wektor2D Tmp(wP->ZwrocPolozenie());
    if(W == Tmp) {
      wP->Obroc(Obr);
      ZapiszDoPliku();
    } 
  }
}

/*!
 * \brief Metoda przesuwajaca wybrana przez uzytkownika przeszkode o zadany wektor
 */

void Scena::PrzesunPrzeszkode() {
  Wektor2D Wek, P;
  cout << "Dostepne przeszkody to:" << endl;
  for(const shared_ptr<Przeszkoda>  &wP : LP) {
    cout << wP->ZwrocPolozenie() << endl << endl; 
  }
  cout << "Wprowadz wspolrzedne przeszkody ktora chcesz przesunac" << endl;
  cin >> Wek;
  cout << "Wprowadz wektor o jaki chcesz przesunac wybrana przeszkode:" << endl;
  cin >> P;
  for(const shared_ptr<Przeszkoda>  &wP : LP) {
    Wektor2D Tmp(wP->ZwrocPolozenie());
    if(Wek == Tmp) {
      wP->Przesun(P);
      ZapiszDoPliku();
    } 
  }
}

/*!
 * \brief Metoda zmieniajaca rozmiar wybranej przez uzytkownika przeszkody poprzesz podanie
 * nowej dlugosci i szerokoscie przeszkody
 */

void Scena::ZmienRozmiarPrzeszkody() {
  Wektor2D W;
  double Wys, Szer;
  cout << "Dostepne przeszkody to:" << endl;
  for(const shared_ptr<Przeszkoda>  &wP : LP) {
    cout << wP->ZwrocPolozenie() << endl << endl; 
  }
  cout << "Wprowadz wspolrzedne przeszkody ktora rozmiar chcesz zmienic" << endl;
  cin >> W;
  cout << "Wprowadz nowa szerokosc:" << endl;
  cin >> Szer;
  cout << "Wprowadz nowa wysokosc:" << endl;
  cin >> Wys;
  for(const shared_ptr<Przeszkoda>  &wP : LP) {
    Wektor2D Tmp(wP->ZwrocPolozenie());
    if(W == Tmp) {
      wP->ZmienRozmiar(Szer, Wys);
      ZapiszDoPliku();
    } 
  }
}

/*!
 * \brief Metoda tworzy przeszkode z podanymi przez uzytkownika parametrami oraz
 * dodaje ja do listy obiektow oraz listy przeszkod
 */

void Scena::DodajPrzeszkode() {
  double x,y,Szer,Wys;
  int Obr;
  cout << "Podaj wspolrzedne x i y miejsca w ktorym ma sie znalezc przeszkoda:" << endl;
  cin >> x;
  cin >> y;
  cout << "Podaj szerokosc i wysokosc nowej przeszkody oraz kat o ktory bedzie obrocona:" << endl;
  cin >> Szer;
  cin >> Wys;
  cin >> Obr;
  shared_ptr<ObiektGraficzny>   WOb = Fabryka::Zbuduj(TO_Przeszkoda,x,y,Szer,Wys,Obr);
  LOb.push_back(WOb);
  LP.push_back(static_pointer_cast<Przeszkoda>(WOb));
  ZapiszDoPliku();
}

/*!
 * \brief Metoda usuwa przeszkode wybrana na podstawie polozenia oraz usuwa wybrany obiekt z 
 * listy obiektow graficznych oraz listy przeszkod
 */

void Scena::UsunPrzeszkode() {
  Wektor2D W;
  cout << "Dostepne przeszkody to:" << endl;
  for(const shared_ptr<Przeszkoda>  &wP : LP) {
    cout << wP->ZwrocPolozenie() << endl << endl; 
  }
  cout << "Wprowadz wspolrzedne przeszkody ktora chcesz usunac" << endl;
  cin >> W;
  for(const shared_ptr<Przeszkoda>  &wP : LP) {
    Wektor2D Tmp(wP->ZwrocPolozenie());
    if(W == Tmp) {
      LP.remove(wP);
      break;
    }
  }
  for(const shared_ptr<ObiektGraficzny>  &wOb : LOb) {
    std::string Typ = wOb->NazwaTypu();
      if(Typ == "Przeszkoda") {
        Wektor2D Tmp(wOb->ZwrocPolozenie());
        if(W == Tmp) {
          LOb.remove(wOb);
          break;
        }
      }
  }
  Lacze.UsunWszystkieNazwyPlikow();
  ZapiszDoPliku();
}

void Scena::DodajRobota () {
  double x,y;
  cout << "Podaj wspolrzedne x i y miejsca w ktorym ma sie znalezc robot:" << endl;
  cin >> x;
  cin >> y;
  shared_ptr<ObiektGraficzny>   WRob = Fabryka::Zbuduj(TO_Robot,x,y);
  shared_ptr<ObiektGraficzny>   WSc = Fabryka::Zbuduj(TO_Sciezka,x,y);
  LOb.push_back(WRob);
  LOb.push_back(WSc);
  LR.push_back(static_pointer_cast<Robot>(WRob));
  LS.push_back(static_pointer_cast<Sciezka>(WSc));
  ZapiszDoPliku();
}

void Scena::UsunRobota () {
  unsigned int Num = 0, rob;
  auto iterR = LR.begin();
  auto iterS = LS.begin();
  cout << "Dostepne roboty to:" << endl;
  for(const shared_ptr<Robot>  &wR : LR) {
    ++Num;
    cout << Num << ".  " << wR->ZwrocPolozenie() << endl << endl; 
  }
  Num = 0;
  cout << "Wprowadz numer robota ktorego chcesz usunac" << endl;
  cin >> rob;
  for(const shared_ptr<Robot> &wR : LR) {
    ++Num;
    if(Num == rob) {
      WR = *iterR;
      WS = *iterS;
    }
    ++iterR;
    ++iterS;
  }
  LR.remove(WR);
  LOb.remove(WR);
  LS.remove(WS);
  LOb.remove(WS);
  Lacze.UsunWszystkieNazwyPlikow();
  ZapiszDoPliku();
}

/*!
 * \brief Metoda selekcjonujaca robota na podstawie jego polozenia. Zmienia rowniez obecna
 * sciezke na sciezke przypisana do tego robota
 */

void Scena::SelekcjaRobota() {
  unsigned int Num = 0, rob;
  auto iterR = LR.begin();
  auto iterS = LS.begin();
  cout << "Dostepne roboty to:" << endl;
  for(const shared_ptr<Robot>  &wR : LR) {
    ++Num;
    cout << Num << ".  " << wR->ZwrocPolozenie() << endl << endl; 
  }
  Num = 0;
  cout << "Wprowadz numer robota ktorym chcesz sterowac" << endl;
  cin >> rob;
  for(const shared_ptr<Robot> &wR : LR) {
    ++Num;
    if(Num == rob) {
      WR = *iterR;
      WS = *iterS;
    }
    ++iterR;
    ++iterS;
  }
}

/*!
 * \brief Metoda animujaca jazde robota. Nastepuje sprawdzenie wystapienia kolizji
 * z innymi robotami oraz przeszkodami, a takze zapis robota i sciezki do pliku
 * \param[in] Dlugosc - odcinek drogi ktory ma przejechac robot
 */

void Scena::AnimujJazde (double Dlugosc) {
  unsigned int microsec = 1000;
  double krok, predkosc;
  Wektor2D Polozenie;
  predkosc = WR->ZwrocSzybkosc();
  krok = Dlugosc/predkosc;
  if(predkosc < Dlugosc) {
    for(int i=0;i<krok;i++) {
    usleep(microsec);
    WR->Jedz(predkosc);
    if(CzyKolizjaZRobotem() || SprawdzCzyKolizjaZPrzeszkoda()){
      ZapiszRoboty();
      break;
    }
    ZapiszRoboty();
    }
  } else {
    WR->Jedz(Dlugosc);
    ZapiszRoboty();
  }
  Polozenie = WR->ZwrocPolozenie();
  WS->Dodaj(Polozenie);
  ZapiszDoPliku();
}

/*!
 * \brief Metoda przesuwajaca wszystkie obiekty na scenie o zadany wektor
 * \param[in] W - wektor przesuniecia
 */

void Scena::Przesun(Wektor2D &W) {
  for(const shared_ptr<ObiektGraficzny> &wOb : LOb) {
    wOb->Przesun(W);
  }
  ZapiszDoPliku();
}

/*!
 * \brief Metoda sprawdzajaca czy wystepuje kolizja z innymi robotem. Aproksymacja robota 
 * nastepuje przez okrag. Porownywane sa polozenia srodka kazdego robota
 * param[out] false/true - w zaleznosci od wystapienia kolizji
 */

bool Scena::CzyKolizjaZRobotem () {
  double d, r1, r2;
  Wektor2D P1, P2;
  for(const shared_ptr<Robot>  &wR : LR) {
    if(wR != WR) {
      d = 0;
      P1 = WR->ZwrocPolozenie();
      P2 = wR->ZwrocPolozenie();
      r1 = WR->ZwrocRozmiar();
      r2 = wR->ZwrocRozmiar();
      d = sqrt(pow((P2[0] - P1[0]),2) + pow((P2[1] - P1[1]),2));
      if(d < r1+r2) {
        return true;
        break;
      } 
    }
  }
  return false;
}

/*!
 * \brief Metoda sprawdzajaca czy wystepuje kolizja ze wszystkimi przeszkodami.
 * Meroda powieksza rozmiar sprawdzanej obecnie przeszkody o promien robota.
 * Kolizja lub jej brak okreslana jest na podstawie przeciec sprawdzanego punktu z 
 * bokami sprawdzanej przeszkody.
 * param[out] false/true - w zaleznosci od wystapienia kolizji
 */


bool Scena::SprawdzCzyKolizjaZPrzeszkoda()
{
  Zbior_Wierzcholkow ZW_tmp;
  Wektor2D PR, TMP;
  int j = 0;
  double Tabx[3], Taby[3], rozmiar;
  bool CzyKolizja = false;
  PR = WR->ZwrocPolozenie();
  rozmiar = WR->ZwrocRozmiar();
  for(const shared_ptr<ObiektGraficzny>  &wOb : LOb) {
    std::string Typ = wOb->NazwaTypu();
    if(Typ == "Przeszkoda") {
      ZW_tmp = wOb->ZwrocZbior();
      for(int x = 0; x < 4; x++) {
        TMP = ZW_tmp[x];
        if(x == 0) {
          Tabx[x] = TMP[0] - rozmiar -1;
          Taby[x] = TMP[1] - rozmiar -1;
        }
        else if(x == 1) {
          Tabx[x] = TMP[0] + rozmiar +1;
          Taby[x] = TMP[1] - rozmiar -1;
        } else if(x == 2) {
          Tabx[x] = TMP[0] + rozmiar +1;
          Taby[x] = TMP[1] + rozmiar +1;
        } else {
          Tabx[x] = TMP[0] - rozmiar -1;
          Taby[x] = TMP[1] + rozmiar +1;
        }
      }
      for(int i = 0; i < 4; i++){
        j++;
        if (j == 4)
          j = 0;
        if (Taby[i] < PR[1] && Taby[j] >= PR[1] || Taby[j] < PR[1] && Taby[i] >= PR[1])
        {
          if (Tabx[i] + (PR[1] - Taby[i]) / (Taby[j] - Taby[i]) *
            (Tabx[j] - Tabx[i]) < PR[0])
          {
            CzyKolizja = !CzyKolizja;
          }
        }
      }
    }
  }
  return CzyKolizja;
}
 
