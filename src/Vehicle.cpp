#include "Vehicle.h"

#include "IdNumbers.h"

Vehicle::Vehicle() {
    id = IdNumbers::getNewId(*this); sizeX = 0; sizeY = 0; sizeZ = 0;
}

Vehicle::Vehicle(double x, double y, double z) {
    id = IdNumbers::getNewId(*this);
    sizeX = x; sizeY = y; sizeZ = z;
}

// U¿ywaæ tylko do debuggingu
Vehicle::Vehicle(int i, double x, double y, double z) {
    // Uwaga brak kontroli b³êdów w customowym id
    id = IdNumbers::setCustomId(*this, i);
    sizeX = x; sizeY = y; sizeZ = z;
}

int Vehicle::getId() {
    return id;
}

Vehicle& Vehicle::operator=(const Vehicle& v) {
    id = v.id;
    sizeX = v.sizeX;
    sizeY = v.sizeY;
    sizeZ = v.sizeZ;
    return *this;
}

double Vehicle::getCapacity()
{
    return capacity;
}
