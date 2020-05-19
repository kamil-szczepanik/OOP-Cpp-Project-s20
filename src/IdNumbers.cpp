#include "IdNumbers.h"

#include <algorithm>
#include <iostream>

// Inicjalizacja vectora przechowującego numery Id
vector<vector<int>> IdNumbers::IdNums{{},{},{},{}};

// Dodawanie nowego numeru ID, numerowanie od 0
int IdNumbers::addId(int typeId){
    IdNums[typeId].push_back(IdNums[typeId].size());
    return IdNums[typeId][IdNums[typeId].size() - 1];
}
// Usuwanie id obiektu który przestaje istnieć
int IdNumbers::rmIdType(int typeId, int id){
    
    //auto pos = find(IdNums[typeId].rbegin(), IdNums[typeId].rend(), id);
    //if(pos != IdNums[typeId].rend()) IdNums[typeId].erase(next(pos).base());
    //auto pos = find(IdNums[typeId].begin(), IdNums[typeId].end(), id);
    //if(pos != IdNums[typeId].end()) IdNums[typeId].erase(pos);
    return id;
}

// Uwaga brak kontroli duplikatów w customowym id
int IdNumbers::addCustomId(int typeId, int id){
    IdNums[typeId].push_back(id);
    return id;
}

// Zwykłe id
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

// Customowe id
template<> int IdNumbers::setCustomId(Courier o, int id){
    return IdNumbers::addCustomId(0, id);
}

template<> int IdNumbers::setCustomId(Package o, int id){
    return IdNumbers::addCustomId(1, id);
}

template<> int IdNumbers::setCustomId(SortingStation o, int id){
    return IdNumbers::addCustomId(2, id);
}

template<> int IdNumbers::setCustomId(Vehicle o, int id){
    return IdNumbers::addCustomId(3, id);
}

// Usuwanie id elementu który przestaje istnieć
template<> int IdNumbers::rmId(Courier o, int id){
    return IdNumbers::rmIdType(0, id);
}

template<> int IdNumbers::rmId(Package o, int id){
    return IdNumbers::rmIdType(1, id);
}

template<> int IdNumbers::rmId(SortingStation o, int id){
    return IdNumbers::rmIdType(2, id);
}

template<> int IdNumbers::rmId(Vehicle o, int id){
    return IdNumbers::rmIdType(3, id);
}