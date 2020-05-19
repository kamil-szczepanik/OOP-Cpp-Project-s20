#include "Courier.h"

#include "IdNumbers.h"

Courier::Courier(){
    id = IdNumbers::getNewId(*this);
    name = "";
    surname = "";
}

Courier::Courier(string n, string s, Vehicle v){
    id = IdNumbers::getNewId(*this);
    name = n;
    surname = s;
    vehicle = v;
}

// Używać tylko do debuggingu
Courier::Courier(int id, string n, string s, Vehicle v){
    // Uwaga brak kontroli błędów w customowym id
    this->id = IdNumbers::setCustomId(*this, id);
    name = n;
    surname = s;
    vehicle = v;
}

int Courier::getId(){
    return id;
}