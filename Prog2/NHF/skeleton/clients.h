//
// Created by Jajecnik Marcell on 2023. 05. 04..
//

#ifndef SKELETON_CLIENTS_H
#define SKELETON_CLIENTS_H

#include "date.h"
#include "myvektor.hpp"
#include "contracts.h"
#include <string>

class Contract;
/**@brief Ügyfél adatait tárolja
 * @param name Az ügyfél neve
 * @param mycontracts Az ügyfél szerződéseit tároló tömb
 */
class Client{
private:
    std::string name;
    MyVector<Contract *> mycontracts;
public:
    /**@brief Alapértékes kontruktor
     *
     * @param name_in Ügyfél neve
     */
    Client(std::string& name_in):name(name_in){}

    std::string getName() const;

    /**@brief Szerződés hozzáadása a mycontracts hez
     *
     * @param contract_in a hozzáadandó szerződésre mutató pointer.
     */
    void addContract(Contract* contract_in);

    /**@brief Virtuális destruktor
     *
     */
    virtual ~Client(){};
};

class Person: public Client{
private:
    long ID;

public:
    Person(std::string name_in="", long ID_in=0)
    : Client(name_in), ID(ID_in)
    {}
    void setID(long ID_in);
    long getID() const;
    ~Person();
};

class Company: public Client{
private:
    long Tax_ID;
public:
    Company(std::string name_in="", long ID_in=0)
    : Client(name_in), Tax_ID(ID_in)
    {}
    void setID(long ID_in);
    long getID() const;
    ~Company();
};

#endif //SKELETON_CLIENTS_H