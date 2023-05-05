    //
// Created by Jajecnik Marcell on 2023. 05. 04..
//

#ifndef SKELETON_DATE_H
#define SKELETON_DATE_H

#include <iostream>
#include <chrono>

class Contract_date {
private:
    std::chrono::system_clock::time_point begin;
    std::chrono::system_clock::time_point end;

public:
    Contract_date(const std::chrono::system_clock::time_point& start = std::chrono::system_clock::now(), const std::chrono::system_clock::time_point& end_in= std::chrono::system_clock::now())
    :begin(start), end(end_in) {}

    // Getter functions
    std::chrono::system_clock::time_point getBegin() const;

    std::chrono::system_clock::time_point getEnd() const;

    // Setter functions
    void setBegin(const std::chrono::system_clock::time_point& start);

    void setEnd(const std::chrono::system_clock::time_point& end_in);

    // Function to check if a given date is within the range
    bool contains(const std::chrono::system_clock::time_point& date) const;

    Contract_date& operator=( Contract_date& contractDate_in);
};


#endif //SKELETON_DATE_H
