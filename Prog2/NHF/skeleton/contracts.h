//
// Created by Jajecnik Marcell on 2023. 05. 05..
//

#ifndef SKELETON_CONTRACTS_H
#define SKELETON_CONTRACTS_H
#include "clients.h"

class Client;

/** @enum ContractType
 * A szerződés fajtáját lehet beállítani vele
 */
enum ContractType {
    Regular,
    VIP,
    Premium,
    Corporate,
    Student,
    SeniorCitizen,
    Government,
    Onetime
};

/**
 * @class Contract
 * @brief Egy szerződést tárol
 * @param client Tárolja a szerződéstkötő adatait
 * @param contract_type A szerződés típusát tárolja
 * @param contract_time A szerződés időtartamát adja meg egy kezdő és egy végdátummal
 * @param last_invoicing Utolsó számlakibocsájtás ideje
 * @param tariff A KWh-kénti árat adja meg
 * @param balance Tárolja a szerződéshez tartozó számla egyenlegét
 * @param consumption Tárolja a fogyasztást a legutóbbi számlakibocsájtás óta
 */
class Contract {
private:

    Client* client;
    ContractType contract_type;
    Contract_date contract_time;
    time_t last_invoicing;
    double tariff;
    double balance;
    double consumption;

public:
    /**@brief Alapértékes konstruktor egy szerződéshez
     *
     * @param client_in Szerződést kötő ügyfél (kötelező)
     * @param ctype_in Szerződés típusa
     * @param ctime_in Szerződés időtartama
     * @param last_invoicing_in Utolsó számla kiállításának időpontja
     * @param tariff_in KWh-kénti ár
     * @param balance_in Jelenlegi egyenleg
     * @param consumption_in Jelenlegi fogyasztás
     */
    Contract(Client* client_in, ContractType ctype_in, int year_begin, int month_begin, int day_begin, int year_end, int month_end, int day_end, time_t last_invoicing_in = time(nullptr),double tariff_in=0.0, double balance_in=0.0, double consumption_in=0.0)
            :client(client_in), contract_type(ctype_in), contract_time(year_begin, month_begin, day_begin, year_end, month_end, day_end), last_invoicing(last_invoicing_in), tariff(tariff_in), balance(balance_in), consumption(consumption_in)
    {}

    // Setter functions
    /**@brief Beállítja a szerződés típusát
     *
     * @param ctype_in Beállítandó szerződéstípus
     */
    void setCtype(ContractType ctype_in);

    /**@brief Beállítja az új tarifát
     *
     * @param tariff_in Beállítandó tarifa
     */
    void setTariff(double tariff_in);

    /**@brief Beállítja a jelenlegi egyenleget
     *
     * @param balance_in Beállítandó egyenleg
     */
    void setBalance(double balance_in);

    /**@brief Hozzáad a fogyasztott mennyiséghez
     *
     * @param con_in Bejövő fogyasztás
     */
    void addConsumption(double con_in);

    /**@brief Beállítja a legutolsó számlázás idejét
     *
     * @param last_in Számlázás időpontja
     */
    void setLast_invoicing(time_t last_in);

    /**@brief Beállítja a szerződés időtartományát
     *
     * @param ctime_in Bejövő időtartomány
     */
    void setCtime(Contract_date ctime_in);

    /**@brief Visszaadja az ügyfél adatait
     *
     * @return Ügyfél adatai
     */
    Client* getClient();

    /**@brief Visszaadja a szerződés típusát
     *
     * @return Szerződés típusa
     */
    ContractType getCtype() const;

    /**@brief Visszaadja a tarifát
     *
     * @return Jelenlegi tarifa
     */
    double getTariff() const;

    /**@brief Visszaadja a jelenlegi egyenleget
     *
     * @return Jelenlegi egyenleg
     */
    double getBalance() const;

    /**@brief Visszaadja az eddigi fogyasztást a legutóbbi számla kiállítása óta
     *
     * @return Eddigi fogyasztás
     */
    double getConsumption() const;

    /**@brief Visszaadja a szerződés időtartományát
     *
     * @return Szerződés időtartománya
     */
    Contract_date getCtime() const;

    /**@brief Visszaadja a legutótóbbi számla kiállításának az időpontját
     *
     * @return Legutótóbbi számla kiállításának az időpontja
     */
    time_t getLast_invoicing() const;

    /**@brief Befizetés egyenlegrendezéshez
     *
     * @param amount Befizetett összeg
     */
    void pay(double amount);

    /**@brief Számla kiállítása fájlba
     *
     */
    void invoicing() {
        time_t now;
        time(&now);
        double consumption_since_last_invoice = consumption;
        if (last_invoicing != 0) {
            consumption_since_last_invoice -= (now - last_invoicing) / 3600.0 * consumption;
        }
        double invoice_amount = consumption_since_last_invoice * tariff;
        std::cout << "Invoice amount: " << invoice_amount << std::endl;
        balance -= invoice_amount;
        last_invoicing = now;
    }

    /**@brief Destruktor
     *
     */
    ~Contract();
};

#endif //SKELETON_CONTRACTS_H
