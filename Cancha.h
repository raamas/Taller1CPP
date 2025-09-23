//
// Created by OMAR DENILSON on 23/09/2025.
//

#ifndef TALLER1_CANCHA_H
#define TALLER1_CANCHA_H
#include <iostream>
using namespace std;
class Cancha {
    string groundType;
    double pricing;
    int capacity;
public:
    Cancha();
    Cancha(string gt, double p, int c);

    string getGroundType();
    double getPricing();
    int getCapacity();

    void setGroundType(string gt);
    void setPricing(double p);
    void setCapacity(int c);

};


#endif //TALLER1_CANCHA_H