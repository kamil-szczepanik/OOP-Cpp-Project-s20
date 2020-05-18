#include <iostream>
#include "Package.h"

using namespace std;

Package::Package()
{
	this->id = 0;
}
Package::Package(int id)
{
	this->id = id;
}