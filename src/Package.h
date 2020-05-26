#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Package
{
protected:
	int id;
	double weight;
	vector<double> size;
	double cost;

	string sender;
	string recipient;
	string address;

	bool priority;
	bool prepaid;

public:
	Package();

	int getId();
	void setWeight(double w);
	double getWeight();
	void setSize(double dim1, double dim2, double dim3);
	vector<double> getSize();
	void setCost(double c);
	double getCost();

	void setSender(string s);
	string getSender();
	void setRecipient(string r);
	string getRecipient();
	void setAddress(string a);
	string getAddress();

	void setPriority(bool p);
	bool getPriority();
	void setPrepaid(bool p);
	bool getPrepaid();

	bool operator==(const Package& p);

};

class StandardPackage : public Package
{
public:
	double MAX_SIZE = 1000.0;
	double MAX_WEIGHT = 100.0;

	StandardPackage();
};

class OversizePackage : public Package
{
public:
	OversizePackage();
};

class SpecialPackage : public Package
{
private:
	string description;

public:
	SpecialPackage();
};

#endif //!PACKAGE_H