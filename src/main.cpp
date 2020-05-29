#include <iostream>
#include <vector>
#include <string>

//#include "Courier.h"
//#include "Vehicle.h"
//#include "IdNumbers.h"
#include "Package.h"

#define p(x) cout << #x << " ("<< sizeof(x) << ") = "  << x <<endl;

using namespace std;

int main(int, char**) {

    /*Vehicle v(1,2,3);
    Vehicle p;
    p = v;
    cout << p.getId() << endl;
    cout << v.getId() << endl;
    Courier c("asd","ad", v);
    cout << IdNumbers::getNewId(v) << endl;
    cout << IdNumbers::getNewId(v) << endl;
    cout << IdNumbers::getNewId(c) << endl;
    cout << IdNumbers::getNewId(c) << endl;*/

    //Package *w;
    //OversizePackage package1;


    double t[3] = {1, 3, 3};
    string a = "A";
    string b = "B";

    StandardPackage sp = StandardPackage(1, 15.0, t, a, "adr1", b, "ttt");

    Package* any = &sp;

    cout << any -> getPackageInfo() << endl;

 

    //w = &package1;


    cout << sp.getSize() << endl;

    double x[3] = {10, 10, 10};
    Package* q = makePackage(1, 5, x, a, "addr1", b, "ttt");
    cout << q -> getPackageInfo() << endl;
    cout << q -> getSize() << endl;

    Package* pc = makePackage(2, 5000, x, "sender", "add", "rec", "radd");

    vector<Package*> v;
    v.push_back(pc);
    v.push_back(q);

    cout << "Should be oversized package:" << endl;
    cout << pc -> getPackageInfo() << endl;
    cout << pc -> getWeight() << endl;
    p(pc -> getSize());

    p(v[0] -> getPackageInfo());
    p(v[1] -> getPackageInfo());
    
    delete q;
    system("pause");

    return 0;
}
