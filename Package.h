#include <iostream>

using namespace std;

class Courier;

class Package
{
private:
	int id;
	friend class Courier;
public:
	Package();
	Package(int id);
};
