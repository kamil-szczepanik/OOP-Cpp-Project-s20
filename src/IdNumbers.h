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

};


#endif // !IDNUMBERS_H
