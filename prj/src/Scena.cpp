#include "Scena.hh"

void Scena::TworzListy() {
  shared_ptr<Robot>  R1(new Robot(Wektor2D(100.0, -150.0)));
  shared_ptr<Robot>  R2(new Robot(Wektor2D(-100.0, -50.0)));
  shared_ptr<Robot>  R3(new Robot(Wektor2D(-200.0, 50.0)));

  shared_ptr<Sciezka>  S1(new Sciezka(Wektor2D(100.0, -150.0)));
  shared_ptr<Sciezka>  S2(new Sciezka(Wektor2D(-100.0, -50.0)));
  shared_ptr<Sciezka>  S3(new Sciezka(Wektor2D(-200.0, 50.0)));

  shared_ptr<Przeszkoda> P1(new Przeszkoda(0.0, 0.0, 50.0, 80.0));
  shared_ptr<Przeszkoda> P2(new Przeszkoda(200.0, 200.0, 100.0, 50.0));
  shared_ptr<Przeszkoda> P3(new Przeszkoda(-250.0, 270.0, 50.0, 20.0));
  shared_ptr<Przeszkoda> P4(new Przeszkoda(-280.0, -280.0, 150.0, 10.0));

  WR = R1;
  WS = S1;

  LOb.push_back(R1);
  LOb.push_back(R2);
  LOb.push_back(R3);
  LOb.push_back(S1);
  LOb.push_back(S2);
  LOb.push_back(S3);
  LOb.push_back(P1);
  LOb.push_back(P2);
  LOb.push_back(P3);
  LOb.push_back(P4);
  LR.push_back(R1);
  LR.push_back(R2);
  LR.push_back(R3);
  LP.push_back(P1);
  LP.push_back(P2);
  LP.push_back(P3);
  LP.push_back(P4);
}


/*!
 * \brief Metoda zapisujaca wspolrzedne robota do pliku
 * \param[in] *sNazwaPliku - nazwa pliku do ktorego zapisane beda wspolrzedne robota
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
  shared_ptr<Przeszkoda> P(new Przeszkoda(x, y, Szer, Wys, Obr));
  LP.push_back(P);
  LOb.push_back(P);
  ZapiszDoPliku();
}

void Scena::UsunPrzeszkode() {
  Wektor2D W,Wek;
  cout << "Dostepne przeszkody to:" << endl;
  for(const shared_ptr<Przeszkoda>  &wP : LP) {
    cout << wP->ZwrocPolozenie() << endl << endl; 
  }
  cout << "Wprowadz wspolrzedne przeszkody ktora chcesz usunac" << endl;
  cin >> W;
  for(const shared_ptr<Przeszkoda>  &wP : LP) {
    Wektor2D Tmp(wP->ZwrocPolozenie());
    if(Wek == Tmp) {
      LP.remove(wP);
      break;
    }
  }
  for(const shared_ptr<ObiektGraficzny>  &wOb : LOb) {
    std::string Typ = wOb->NazwaTypu();
      if(Typ == "Przeszkoda") {
        Wektor2D Tmp(wOb->ZwrocPolozenie());
        if(Wek == Tmp) {
          LOb.remove(wOb);
          break;
        }
      }
  }
  Lacze.UsunWszystkieNazwyPlikow();
  ZapiszDoPliku();
}

void Scena::SelekcjaRobota() {
  Wektor2D Wek, Tmp;
  cout << "Dostepne roboty to:" << endl;
  for(const shared_ptr<Robot>  &wR : LR) {
    cout << wR->ZwrocPolozenie() << endl << endl; 
  }
  cout << "Wprowadz wspolrzedne robota ktorym chcesz sterowac" << endl;
  cin >> Wek;
  for(const shared_ptr<Robot>  &wR : LR) {
    Tmp = wR->ZwrocPolozenie();
    if(Wek == Tmp) {
      WR = wR;
      break;
    } 
  }
  for(const shared_ptr<ObiektGraficzny> &wOb : LOb) {
    std::string Typ = wOb->NazwaTypu();
      if(Typ == "Sciezka") {
        if(Wek == Tmp) {
          WS = static_pointer_cast<Sciezka>(wOb);
          break;
        }
      }
  }
}

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

void Scena::Przesun(Wektor2D &W) {
  for(const shared_ptr<ObiektGraficzny> &wOb : LOb) {
    wOb->Przesun(W);
  }
}
 
