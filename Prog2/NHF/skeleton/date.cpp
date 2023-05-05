//
// Created by Jajecnik Marcell on 2023. 05. 04..
//

#include "date.h"

std::chrono::system_clock::time_point Contract_date::getBegin() const {
    return begin;
}

std::chrono::system_clock::time_point Contract_date::getEnd() const {
    return end;
}

void Contract_date::setBegin(const std::chrono::system_clock::time_point &start) {
    begin = start;

}

void Contract_date::setEnd(const std::chrono::system_clock::time_point &end_in) {
    end = end_in;
}

bool Contract_date::contains(const std::chrono::system_clock::time_point &date) const {
    return (date >= begin && date <= end);
}

Contract_date &Contract_date::operator=(Contract_date &contractDate_in) {
    if (!(this->begin==contractDate_in.begin && this->end==contractDate_in.end)) {
        this->begin = contractDate_in.begin;
        this->end = contractDate_in.end;
    }
    return *this;
}
