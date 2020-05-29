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
	double dims[3]; // wymiary x,y,z w dm
	double size; // rozmiar (objętość) w dm3
	double cost;

	string sender; // nadawca (imię i nazwisko)
	string senderAddress; // adres nadawcy
	string recipient; // odbiorca (imię i nazwisko)
	string recipientAddress; // adres odbiorcy

	bool priority; // przesyłka priorytetowa
	bool prepaid; // zapłacone z góry (false = płatność przy odbiorze)

	// bazowy konstruktor paczki, służy tylko do dziedziczenia, każda paczka musi być odpowiedniego typu
	Package(int id, double weight, double dims[3], string sender, string senderAddr,
    	string recipient, string recipientAddr, bool prepaid=false, bool priority=false);

	virtual void autoSetCost()=0; // automatyczne obliczanie ceny wysłania paczki w zależności od rodzaju

public:
	constexpr static double BASE_COST = 10.0; // bazowy koszt paczki - koszt paczki standardowej
	constexpr static double MAX_SIZE = 1000.0; // maksymalny rozmiar zwykłej paczki (w dm3)
	constexpr static double MAX_WEIGHT = 100.0; // maksymalna waga zwykłej paczki (w kg)
	constexpr static double DM3_COST = 10.0; // koszt 1 dm3 ponad maksymalny rozmiar
	constexpr static double KG_COST = 10.0; // koszt 1 kg ponad maksymalną wagę
	constexpr static double PRIORITY_COST = 10.0; // dodatkowy koszt paczki priorytetowej

	// metody get-set
	int getId();
	void setWeight(double w);
	double getWeight();
	void setDims(double dim1, double dim2, double dim3);
	double* getDims();
	double getSize();
	void setCost(double c);
	double getCost();

	void setSender(string s);
	string getSender();
	void setSenderAddress(string a);
	string getSenderAddress();
	void setRecipient(string r);
	string getRecipient();
	void setRecipientAddress(string a);
	string getRecipientAddress();

	void setPriority(bool p);
	bool getPriority();
	void setPrepaid(bool p);
	bool getPrepaid();

	virtual string getPackageInfo();
};

class StandardPackage : public Package
{
protected:
	virtual void autoSetCost(); // automatyczne obliczanie ceny dla paczek standardowych
	using Package::setCost; // ukrycie możliwości ręcznego ustawienia kosztu

public:
	// konstruktor paczki standardowej wykorzystujący konstruktor bazowy
	StandardPackage(int id, double weight, double dims[3], string sender, string senderAddr,
    	string recipient, string recipientAddr, bool prepaid=false, bool priority=false) :
		Package::Package(id, weight, dims, sender, senderAddr, recipient, recipientAddr, prepaid, priority) {};

	virtual string getPackageInfo();
};

class OversizePackage : public Package
{
protected:
	virtual void autoSetCost(); // automatyczne obliczanie ceny dla paczek ponadwymiarowych
	using Package::setCost; // ukrycie możliwości ręcznego ustawienia kosztu

public:
	// konstruktor paczki standardowej wykorzystujący konstruktor bazowy
	OversizePackage(int id, double weight, double dims[3], string sender, string senderAddr,
    	string recipient, string recipientAddr, bool prepaid=false, bool priority=false) :
		Package::Package(id, weight, dims, sender, senderAddr, recipient, recipientAddr, prepaid, priority) {};

	virtual string getPackageInfo();
};

// tworzenie paczki z automatycznym wykrywaniem odpowiedniego typu paczki
Package* makePackage(int id, double weight, double dims[3], string sender, string senderAddr,
	string recipient, string recipientAddr, bool prepaid=false, bool priority=false);

#endif //!PACKAGE_H
