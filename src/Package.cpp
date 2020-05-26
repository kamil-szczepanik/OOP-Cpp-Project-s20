#include <iostream>
#include "Package.h"
#include "IdNumbers.h"
using namespace std;

Package::Package()
{
	id = IdNumbers::getNewId(*this);
	weight = 0;
	cost = 0;
	size = {0,0,0};
	sender = "";
	recipient = "";
	address = "";

	priority = false;
	prepaid = false;
}

int Package::getId()
{
	return id;
}

void Package::setWeight(double w)
{
	weight = w;
}

double Package::getWeight()
{
	return weight;
}

void Package::setSize(double dim1, double dim2, double dim3)
{
	size = { dim1, dim2, dim3 };
}

vector<double> Package::getSize()
{
	return size;
}

void Package::setCost(double c)
{
	cost = c;
}


double Package::getCost()
{
	return cost;
}

void Package::setSender(string s)
{
	sender = s;
}

string Package::getSender()
{
	return sender;
}

void Package::setRecipient(string r)
{
	recipient = r;
}

string Package::getRecipient()
{
	return recipient;
}

void Package::setAddress(string a)
{
	address = a;
}

string Package::getAddress()
{
	return address;
}

void Package::setPriority(bool p)
{
	priority = p;
}

bool Package::getPriority()
{
	return priority;
}

void Package::setPrepaid(bool p)
{
	prepaid = p;
}

bool Package::getPrepaid()
{
	return prepaid;
}

bool Package::operator==(const Package& p)
{
	if (p.id== this->id)
	{
		return true;
	}
	else return false;
}



