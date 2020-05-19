#include "Vehicle.h"

#include "IdNumbers.h"

Vehicle::Vehicle(){
    id = IdNumbers::getNewId(*this); sizeX = 0; sizeY = 0; sizeZ = 0;
}

int Vehicle::getId(){
    return id;
}