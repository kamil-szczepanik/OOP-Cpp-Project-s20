#include <iostream>
#include "Courier.h"
#include "Vehicle.h"
#include "IdNumbers.h"
#include <vector>
using namespace std;

int main(int, char**) {

    Vehicle v(1,2,3);
    Vehicle p;
    p = v;
    cout << p.getId() << endl;
    cout << v.getId() << endl;
    Courier c("asd","ad", v);
    cout << IdNumbers::getNewId(v) << endl;
    cout << IdNumbers::getNewId(v) << endl;
    cout << IdNumbers::getNewId(c) << endl;
    cout << IdNumbers::getNewId(c) << endl;
    return 0;
}
