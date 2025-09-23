//
// Created by OMAR DENILSON on 23/09/2025.
//

#include "Cancha.h"

Cancha::Cancha()
{
    groundType = "sintetica";
    pricing = 60.0;
    capacity = 5;
};
Cancha::Cancha(string gt, double p, int c)
{
    this->groundType = gt;
    this->pricing = p;
    this->capacity = c;
};

string Cancha::getGroundType()
{
    return groundType;
};
double Cancha::getPricing()
{
    return pricing;
};
int Cancha::getCapacity()
{
    return capacity;
};

void Cancha::setGroundType(string gt)
{
    this->groundType = gt;
};
void Cancha::setPricing(double p)
{
    this->pricing = p;
};
void Cancha::setCapacity(int c)
{
    this->capacity = c;
};