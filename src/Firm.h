#ifndef FIRM_H
#define FIRM_H

#include <vector>

#include "SortingStation.h"

class Firm
{
private:
    vector<SortingStation> sortingStations;

public:
    Firm();

    SortingStation getSortingStation(int id);
    void addSortingStation(SortingStation ss);
    void removeSortingStation(int id);
    vector<SortingStation> getSortingStationsList();
};

#endif // !FIRM_H
