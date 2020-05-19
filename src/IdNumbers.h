#ifndef IDNUMBERS_H
#define IDNUMBERS_H

#include <vector>
#include <iostream>

#include "Courier.h"
#include "Package.h"
#include "SortingStation.h"
#include "Vehicle.h"

using namespace std;



class IdNumbers{
    // Vector czterech vectorów
    static vector<vector<int>> IdNums;
  
public:
    template<typename T> static int getNewId(T o);
    static int addId(int typeId);
    // Customowe id
    template<typename T> static int setCustomId(T o, int id);
    static int addCustomId(int typeId, int id);
    // Do zastosowania w dekonstruktorze
    template<typename T> static int rmId(T o, int id);
    static int rmIdType(int typeId, int id);
};


#endif // !IDNUMBERS_H
