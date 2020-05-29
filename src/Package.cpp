#include "Package.h"
#include "IdNumbers.h"
using namespace std;

// tworzenie paczki z odpowiednim wykrywaniem typu paczki, zwraca wskaźnik na obiekt paczki
// UWAGA wymaga usunięcia po zakończeniu korzystania lub wykorzystania inteligentnego wskaźnika
Package* makePackage(int id, double weight, double dims[3], string sender, string senderAddr,
    string recipient, string recipientAddr, bool prepaid, bool priority)
{
    double size = dims[0] * dims[1] * dims[2];

    if (size > Package::MAX_SIZE || weight > Package::MAX_WEIGHT)
        return new OversizePackage(id, weight, dims, sender, senderAddr, recipient, recipientAddr, prepaid, priority);
    return new StandardPackage(id, weight, dims, sender, senderAddr, recipient, recipientAddr, prepaid, priority);
}

// Package

Package::Package(int id, double weight, double dims[3], string sender, string senderAddr,
    string recipient, string recipientAddr, bool prepaid, bool priority)
{
    this -> id = id;
    this -> weight = weight;
    this -> dims[0] = dims[0];
    this -> dims[1] = dims[1];
    this -> dims[2] = dims[2];
    this -> size = dims[0] * dims[1] * dims[2];
    this -> sender = sender;
    this -> senderAddress = senderAddr;
    this -> recipient = recipient;
    this -> recipientAddress = recipientAddr;
    this -> prepaid = prepaid;
    this -> priority = priority;
}

int Package::getId() {
    return id;
}

void Package::setWeight(double w) {
    weight = w;
    autoSetCost();
}

double Package::getWeight() {
    return weight;
}

void Package::setDims(double dim1, double dim2, double dim3) {
    dims[0] = dim1;
    dims[1] = dim2;
    dims[2] = dim3;
    autoSetCost();
}

double* Package::getDims() {
    return dims;
}

double Package::getSize() {
    return size;
}

void Package::setCost(double c) {
    cost = c;
}

double Package::getCost() {
    return cost;
}



void Package::setSender(string s) {
    sender = s;
}

string Package::getSender() {
    return sender;
}

void Package::setSenderAddress(string a) {
    senderAddress = a;
}

string Package::getSenderAddress() {
    return senderAddress;
}

void Package::setRecipient(string r) {
    recipient = r;
}

string Package::getRecipient() {
    return recipient;
}

void Package::setRecipientAddress(string a) {
    recipientAddress = a;
}

string Package::getRecipientAddress() {
    return recipientAddress;
}

void Package::setPriority(bool p) {
    priority = p;
}

bool Package::getPriority() {
    return priority;
}

void Package::setPrepaid(bool p) {
    prepaid = p;
}

bool Package::getPrepaid() {
    return prepaid;
}

string Package::getPackageInfo() {
    return "Base Package";
}

// Standard Package

void StandardPackage::autoSetCost()
{
    setCost(BASE_COST + priority * PRIORITY_COST);
}

string StandardPackage::getPackageInfo() {
    return "Paczka standardowa";
}

// OversizePackage

void OversizePackage::autoSetCost()
{
    double base = BASE_COST + priority * PRIORITY_COST;
    double sizeOverLimit = size - MAX_SIZE;
    double weightOverLimit = weight - MAX_WEIGHT;

    double overCost = (sizeOverLimit > weightOverLimit ? sizeOverLimit*DM3_COST : weightOverLimit*KG_COST);

    setCost(base + overCost);
}

string OversizePackage::getPackageInfo() {
    return "Paczka ponadwymiarowa";
}

