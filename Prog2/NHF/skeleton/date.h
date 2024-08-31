//
// Created by Jajecnik Marcell on 2023. 05. 04..
//

#ifndef SKELETON_DATE_H
#define SKELETON_DATE_H

#include <iostream>
#include <chrono>

class Date {
private:
    std::chrono::system_clock::time_point tp;

public:
    Date(int year, int month, int day): tp(into_date(year,month,day)) {}

    /**@brief Időponttá alakít egy dátumot
     *
     * @param year Bejövő év
     * @param month Bejövő hónap
     * @param day Bejövő nap
     * @return időponttá alakított dátum
     */
    std::chrono::system_clock::time_point into_date(int year, int month, int day);

    /**@brief Kiír egy időpontot
     *
     * @param date Kiirandó időpont
     */
    void print_date(std::chrono::system_clock::time_point date);

    bool operator==(Date in);

    bool operator<(const Date& in);

    bool operator>(const Date& in);

    bool operator<=(const Date& in);

    bool operator>=(const Date& in);

    std::ostream& operator>>(const Date&);

};

std::ostream& operator<<(std::ostream os, const Date&);



/**@brief Egy időpárt tárol
 * @param beging Az kezdeti időpont
 * @param end A végső időpont
 */
class Contract_date {
private:
    Date begin;
    Date end;

    
public:

    /**@brief Konstruktor
     *
     * @param year_begin Bejövő kezdeti év
     * @param month_begin Bejövő kezdeti hónap
     * @param day_begin Bejövő kezdeti nap
     * @param year_end Bejövő végzeti év
     * @param month_end Bejövő végzeti hónap
     * @param day_end Bejövő végzeti nap
     */
    Contract_date(int year_begin, int month_begin, int day_begin, int year_end, int month_end, int day_end)
        : begin(Date(year_begin, month_begin, day_begin)), end(Date(year_end, month_end, day_end))
    {}

    /**@brief Visszaadja a kezdeti időpontot
     *
     * @return kezdeti időpont
     */
    Date getBegin() const;

    /**@brief Visszaadja a végső időpontot
     *
     * @return Végső időpont
     */
    Date getEnd() const;

    /**@brief Beállítja a kezdeti időpontot
     *
     * @param year Beállítandó év
     * @param month Beállítandó hónap
     * @param day Beállítandó nap
     */
    void setBegin(int year, int month, int day);

    /**@brief Beállítja a végső időpontot
     *
     * @param year Beállítandó év
     * @param month Beállítandó hónap
     * @param day Beállítandó nap
     */
    void setEnd(int year, int month, int day);

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
