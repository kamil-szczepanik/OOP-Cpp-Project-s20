#include "Courier.h"

#include "IdNumbers.h"

Courier::Courier() {
    id = IdNumbers::getNewId(*this);
    name = "";
    surname = "";
}

Courier::Courier(string n, string s, Vehicle v) {
    id = IdNumbers::getNewId(*this);
    name = n;
    surname = s;
    vehicle = v;
}

// U�ywa� tylko do debuggingu
Courier::Courier(int id, string n, string s, Vehicle v) {
    // Uwaga brak kontroli b��d�w w customowym id
    this->id = IdNumbers::setCustomId(*this, id);
    name = n;
    surname = s;
    vehicle = v;
}

int Courier::getId() {
    return id;
}

string Courier::getName()
{
    return name;
}

string Courier::getSurname()
{
    return surname;
}

string Courier::getFullName()
{
    return name + " " + surname;
}

void Courier::addPackage(Package p)
{
    double volume = p.getSize()[0] * p.getSize()[1] * p.getSize()[2];
    if (volume <= vehicle.getCapacity())
    {
        packages.push_back(p);
        // vehicle.capacity -= volume;

    }
    //else throw "This package cannot fit in!";
    
}

void Courier::removePackage(Package p)
{
    for (unsigned int i = 0; i < packages.size(); i++)
    {
        if (p == packages[i])
        {
            packages.erase(packages.begin() + i);
            break;
        }
    }
}

vector<Package> Courier::getPackages()
{
    return packages;
}

Vehicle Courier::getVehicle()
{
    return vehicle;
}