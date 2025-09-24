//
// Created by OMAR DENILSON on 23/09/2025.
//

#include "Cancha.h"

Cancha::Cancha()
{
    id = 0;
    groundType = "";
    pricing = 0;
    capacity = 0;
};

Cancha::Cancha(int i)
{
    id = i;
};

Cancha::Cancha(int i, string gt, double p, int c)
{
    this->id = i;
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

int Cancha::getId()
{
    return id;
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


void Cancha::setId(int i)
{
    this->id = i;
}