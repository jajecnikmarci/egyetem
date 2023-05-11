    //
// Created by Jajecnik Marcell on 2023. 05. 04..
//

#ifndef SKELETON_DATE_H
#define SKELETON_DATE_H

#include <iostream>
#include <chrono>

/**@brief Egy időpárt tárol
 * @param beging Az kezdeti időpont
 * @param end A végső időpont
 */
class Contract_date {
private:
    std::chrono::system_clock::time_point begin;
    std::chrono::system_clock::time_point end;

public:

    /**@brief Alapértékes konstruktor
     *
     * @param start Bejövő kezdeti időpont
     * @param end_in Bejövő végső időpont
     */
    Contract_date(const std::chrono::system_clock::time_point& start = std::chrono::system_clock::now(), const std::chrono::system_clock::time_point& end_in= std::chrono::system_clock::now())
    :begin(start), end(end_in) {}

    /**@brief Visszaadja a kezdeti időpontot
     *
     * @return kezdeti időpont
     */
    std::chrono::system_clock::time_point getBegin() const;

    /**@brief Visszaadja a végső időpontot
     *
     * @return Végső időpont
     */
    std::chrono::system_clock::time_point getEnd() const;

    /**@brief Beállítja a kezdeti időpontot
     *
     * @param start Bejövő kezdeti időpont
     */
    void setBegin(const std::chrono::system_clock::time_point& start);

    /**@brief Beállítja a végső időpontot
     *
     * @param start Bejövő végső időpont
     */
    void setEnd(const std::chrono::system_clock::time_point& end_in);

    /**@brief Ellenőrzi hogy a paraméterként kapott dátum a dátumpár között van-e
     *
     * @param date paraméterként kapott dátum
     * @return A dátumpár között van?
     */
    bool contains(const std::chrono::system_clock::time_point& date) const;


    /**@brief = operátor az = jel helyes működéséhez
     *
     * @param contractDate_in Bejövő contractDate
     * @return Visszaadandó contractDate
     */
    Contract_date& operator=( Contract_date& contractDate_in);
};


#endif //SKELETON_DATE_H
