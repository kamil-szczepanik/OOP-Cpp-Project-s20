#include <iostream>
#include <string>

using namespace std;

class Courier;

class Package
{
protected:
	int id;
	double weight;
	vector<double> size[3];
	double cost;

	string sender;
	string recipient;
	string address;

	bool priority;
	bool prepaid;

public:
	Package();
	Package(int id);

	int getId();
	void setWeight(double w);
	double getWeight();
	void setSize(double dim1, double dim2, double dim3);
	double[3] getSize();

};

class StandardPackage : public Package
{

};

class OversizePackage : public Package
{

};

class SpecialPackage : public Package
{
private:
	string description;
};
