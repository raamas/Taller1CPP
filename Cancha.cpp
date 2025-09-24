//
// Created by OMAR DENILSON on 23/09/2025.
//

#include "Cancha.h"

Cancha::Cancha()
{
    groundType = "sintetica";
    pricing = 60.0;
    capacity = 5;
    isAvailable = true;
};
Cancha::Cancha(string gt, double p, int c, bool a)
{
    this->groundType = gt;
    this->pricing = p;
    this->capacity = c;
    this->isAvailable = a;
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

bool Cancha::getIsAvailable()
{
    return isAvailable;
}

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

void Cancha::setIsAvailable(bool a)
{
    this->isAvailable = a;
}