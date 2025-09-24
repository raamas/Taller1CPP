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
    bool includeHydration;
    int id;

public:
    Reserva();
    Reserva(int i, string msg);
    Reserva(int id, Cancha c, int t, int d, string cn, bool h = false);

    Cancha getCancha();
    int getTime();
    int getDuration();
    double getPrice();
    string getClientName();
    bool getIncludeHydration();
    int getId();

    void setCancha(Cancha c);
    void setTime(int t);
    void setDuration(int d);
    void setPrice(int p);
    void setClientName(string cn);
    void setIncludeHydration(bool h);

    void setId(int id);
};

#endif // TALLER1_RESERVA_H