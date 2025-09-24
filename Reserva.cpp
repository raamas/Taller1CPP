//
// Created by OMAR DENILSON on 23/09/2025.
//

#include "Reserva.h"
#include <iostream>
using namespace std;

Reserva::Reserva()
{
    Cancha cancha;
    time = 20;
    duration = 1;
    price = cancha.getPricing()*duration;
    clientName = "";
    includeHydration = false;
};

Reserva::Reserva(int i, string msg)
{
    clientName = msg;
    id = i;
}

Reserva::Reserva(int i, Cancha c, int t, int d, string cn, bool h)
{
    id = i;
    cancha = c;
    time = t;
    duration = d;
    price = c.getPricing()*d + (h? 20:0);
    clientName = cn;
    includeHydration = h;
};

Cancha Reserva::getCancha()
{
    return cancha;
};
int Reserva::getTime()
{
    return time;
};
int Reserva::getDuration()
{
    return duration;
};
double Reserva::getPrice()
{
    return price;
};
string Reserva::getClientName()
{
    return clientName;
};

bool Reserva::getIncludeHydration()
{
    return includeHydration;
};

int Reserva::getId()
{
    return id;
}

void Reserva::setCancha(Cancha c)
{
    cancha = c;
};
void Reserva::setTime(int t)
{
    time = t;
};
void Reserva::setDuration(int d)
{
    duration = d;
};
void Reserva::setPrice(int p)
{
    price = p;
};
void Reserva::setClientName(string cn)
{
    clientName = cn;
};

void Reserva::setIncludeHydration(bool h)
{
    includeHydration = h;
};

void Reserva::setId(int id)
{
    this->id = id;
}