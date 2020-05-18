#ifndef SORTINGSTATION_H
#define SORTINGSTATION_H

#include <vector>
#include <string>

#include "Courier.h"
#include "Package.h"

class SortingStation
{
private:
    int id;
    vector<Courier> couriers;
    vector<Package> packages;
    vector<string> addresses;

public:
    SortingStation();

    Courier getCourier(int id);
    vector<Courier> getCouriersList();
    Package getPackage(int id);
    vector<Package> getPackagesList();

    bool checkAddress(string address);
    void addAddress(string address);
    void removeAddress(string address);
    vector<string> getAddressesList();

};

#endif // !SORTINGSTATION_H
