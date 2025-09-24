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
    price = cancha.getPricing();
    clientName = "";
    playerCount = cancha.getCapacity();
    includeHydration = false;
};

Reserva::Reserva(int i, string msg)
{
    clientName = msg;
    id = i;
}

Reserva::Reserva(Cancha c, int t, int d, string cn, int pc, bool h)
{
    cancha = c;
    time = t;
    duration = d;
    price = c.getPricing();
    clientName = cn;
    playerCount = pc;
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
int Reserva::getPlayerCount()
{
    return playerCount;
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
void Reserva::setPlayerCount(int pc)
{
    playerCount = pc;
};
void Reserva::setIncludeHydration(bool h)
{
    includeHydration = h;
};

void Reserva::setId(int id)
{
    this->id = id;
}