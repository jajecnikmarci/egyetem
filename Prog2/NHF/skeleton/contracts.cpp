//
// Created by Jajecnik Marcell on 2023. 05. 05..
//

#include "contracts.h"

void Contract::setCtype(ContractType ctype_in) {
    contract_type = ctype_in;
}

void Contract::setTariff(double tariff_in) {
    tariff = tariff_in;
}

void Contract::setBalance(double balance_in) {
    balance = balance_in;
}

void Contract::addConsumption(double con_in) {
    consumption += con_in;
}

void Contract::setLast_invoicing(time_t last_in) {
    last_invoicing = last_in;
}

void Contract::setCtime(Contract_date ctime_in) {
    contract_time = ctime_in;
}

Client* Contract::getClient() {
    return client;
}

ContractType Contract::getCtype() const {
    return contract_type;
}

double Contract::getTariff() const {
    return tariff;
}

double Contract::getBalance() const {
    return balance;
}

double Contract::getConsumption() const {
    return consumption;
}

Contract_date Contract::getCtime() const {
    return contract_time;
}

time_t Contract::getLast_invoicing() const {
    return last_invoicing;
}

void Contract::pay(double amount) {
    balance += amount;
}

Contract::~Contract() {

}


