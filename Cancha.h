//
// Created by OMAR DENILSON on 23/09/2025.
//

#ifndef TALLER1_CANCHA_H
#define TALLER1_CANCHA_H
#include <iostream>
using namespace std;
class Cancha
{
    string groundType;
    double pricing;
    int capacity;
    int id;

public:
    Cancha();
    Cancha(int i);
    Cancha(int i, string gt, double p, int c);

    string getGroundType();
    double getPricing();
    int getCapacity();
    int getId();

    void setGroundType(string gt);
    void setPricing(double p);
    void setCapacity(int c);
    void setId(int i);
};

#endif // TALLER1_CANCHA_H