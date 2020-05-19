#include "IdNumbers.h"

// Inicjalizacja vectora przechowującego numery Id
vector<vector<int>> IdNumbers::IdNums{{},{},{},{}};

// Dodawanie nowego numeru ID, numerowanie od 0
int IdNumbers::addId(int typeId){
    IdNums[typeId].push_back(IdNums[typeId].size());
    return IdNums[typeId][IdNums[typeId].size() - 1];
}

// Odpowiedni vector w zależności od typu
template<> int IdNumbers::getNewId(Courier o){
    return IdNumbers::addId(0);
}

template<> int IdNumbers::getNewId(Package o){
    return IdNumbers::addId(1);
}

template<> int IdNumbers::getNewId(SortingStation o){
    return IdNumbers::addId(2);
}

template<> int IdNumbers::getNewId(Vehicle o){
    return IdNumbers::addId(3);
}
