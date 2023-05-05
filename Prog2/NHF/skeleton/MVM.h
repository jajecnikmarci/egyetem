//
// Created by Jajecnik Marcell on 2023. 05. 04..
//

#ifndef SKELETON_MVM_H
#define SKELETON_MVM_H

#include "clients.h"
#include "myvektor.hpp"
#include "date.h"
#include "contracts.h"
#include <iostream>
#include <chrono>

/**
 * @brief Ügyfeleket tároló class.
 */
class MVM {
private:
    /**
     * Kliensek heterogén kollekciója.
     */
    MyVector<Client *> clients;

    /**
     * Az MVM adatai
     */
    static Company MVM_company;
public:
    MVM() {}
    void addClient(Client* client_in);

    /**
     * @brief
     * @param contract_in
     */
    void addContract(Contract* contract_in);

    Client* getClient(const std::string name_in);

    /**
     * @brief
     * @return Az MVM adatait adja vissza.
     */
    const Company getCompanyDetails();
};

#endif //SKELETON_MVM_H
