#include "Fabryka.hh"

shared_ptr<ObiektGraficzny> Fabryka::UtworzObiekt( TypObiektu  TypOb, double x, double y, double Wysokosc, double Szerokosc, int Obr ) const
    {
      switch (TypOb) {
       case TO_Robot: return make_shared<Robot>();
       case TO_Sciezka: return make_shared<Sciezka>();
       case TO_Przeszkoda: return make_shared<Przeszkoda>(x,y,Wysokosc,Szerokosc);
      }
      return make_shared<Przeszkoda>(); // To tylko po to, aby kompilator
                // nie twierdził, że metoda nic nie zwraca. Ta instrukcja 
                // i tak nigdy się nie wykona.
    }

shared_ptr<ObiektGraficzny> Fabryka::UtworzObiekt( TypObiektu  TypOb, double x, double y) const
    {
      switch (TypOb) {
       case TO_Robot: return make_shared<Robot>(Wektor2D(x,y));
       case TO_Sciezka: return make_shared<Sciezka>(Wektor2D(x,y));
       case TO_Przeszkoda: return make_shared<Przeszkoda>();
      }
      return make_shared<Przeszkoda>(); // To tylko po to, aby kompilator
                // nie twierdził, że metoda nic nie zwraca. Ta instrukcja 
                // i tak nigdy się nie wykona.
    }