//
// Created by Jajecnik Marcell on 2023. 05. 04..
//

#include "MVM.h"

Company MVM::MVM_company = Company("MVM ZRT.",10760798244);

void MVM::addClient(Client* client_in) {
    clients.push_back(client_in);
}


void MVM::addContract(Contract* contract_in) {
    contract_in->getClient()->addContract(contract_in);
}

Client *MVM::getClient(const std::string name_in) {
    for (size_t i = 0; i < clients.size(); ++i) {
        if (name_in==clients[i]->getName()) return clients[i];
    }
    return nullptr;
}
