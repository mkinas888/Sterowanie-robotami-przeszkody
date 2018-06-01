#ifndef FABRYKA_HH
#define FABRYKA_HH

#include <iostream>
#include <memory>
#include <cmath>
#include <unistd.h>
#include <list>
#include <string>
#include "Robot.hh"
#include "Sciezka.hh"
#include "ObiektGraficzny.hh"
#include "Przeszkoda.hh"

enum TypObiektu { TO_Robot, TO_Sciezka, TO_Przeszkoda };

class Fabryka {
    static Fabryka   _Fabryka;
  public:

    static shared_ptr<ObiektGraficzny> Zbuduj( TypObiektu  TypOb, double x, double y, double Wysokosc, double Szerokosc, int Obr )
    {
      return _Fabryka.UtworzObiekt(TypOb, x, y, Wysokosc, Szerokosc, Obr);
    }
    static shared_ptr<ObiektGraficzny> Zbuduj( TypObiektu  TypOb, double x, double y)
    {
      return _Fabryka.UtworzObiekt(TypOb, x, y);
    }

  private:
    Fabryka(){}

    shared_ptr<ObiektGraficzny> UtworzObiekt( TypObiektu  TypOb, double x, double y, double Wysokosc, double Szerokosc, int Obr ) const;
    shared_ptr<ObiektGraficzny> UtworzObiekt( TypObiektu  TypOb, double x, double y) const;
};

#endif