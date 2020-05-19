#include <iostream>
//#include "Courier.h"
#include "IdNumbers.h"
using namespace std;

int main(int, char**) {

    Vehicle v;
    Courier c;
    cout << IdNumbers::getNewId(v) << endl;
    cout << IdNumbers::getNewId(v) << endl;
    cout << IdNumbers::getNewId(c) << endl;
    return 0;
}
