//
// Created by OMAR DENILSON on 23/09/2025.
//

#ifndef TALLER1_RESERVA_H
#define TALLER1_RESERVA_H
#include "Cancha.h"
#include <iostream>
using namespace std;
class Reserva
{
    Cancha cancha;
    int time;
    int duration;
    double price;
    string clientName;
    int playerCount;
    bool includeHydration;
    int id;

public:
    Reserva();
    Reserva(Cancha c, int t, int d, string cn, int pc, bool h = false);
    Cancha getCancha();
    int getTime();
    int getDuration();
    double getPrice();
    string getClientName();
    int getPlayerCount();
    bool getIncludeHydration();
    int getId();

    void setCancha(Cancha c);
    void setTime(int t);
    void setDuration(int d);
    void setPrice(int p);
    void setClientName(string cn);
    void setPlayerCount(int pc);
    void setIncludeHydration(bool h);
    void setId(int id);

    void calculatePrice();
};

#endif // TALLER1_RESERVA_H