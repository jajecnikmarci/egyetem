//
// Created by Jajecnik Marcell on 2023. 05. 04..
//

#include "clients.h"

std::string Client::getName() const{
    return name;
}

void Client::addContract(Contract* contract_in) {
    mycontracts.push_back(contract_in);
}

long Person::getID() const {
    return ID;
}

void Person::setID(long ID_in) {
    ID=ID_in;
}

Person::~Person() {

}

long Company::getID() const {
    return Tax_ID;
}

void Company::setID(long ID_in) {
    Tax_ID=ID_in;
}

Company::~Company() {

}