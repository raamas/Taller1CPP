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
    bool isAvailable;

public:
    Cancha();
    Cancha(string gt, double p, int c, bool a = true);

    string getGroundType();
    double getPricing();
    int getCapacity();
    bool getIsAvailable();

    void setGroundType(string gt);
    void setPricing(double p);
    void setCapacity(int c);
    void setIsAvailable(bool a);
};

#endif // TALLER1_CANCHA_H