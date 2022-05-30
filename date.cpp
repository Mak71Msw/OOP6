//
// Created by Максим Уланов on 24.05.2022.
//
#include "date.h"

Date::~Date(){}

std::string Date::show_pretty_date() {

    int int_day=day;
    int int_year = year;
    int int_month = month;
    std::string string_day = std::to_string(int_day);
    std::string string_year = std::to_string(int_year);
    std::string string_month = std::to_string(int_month);
    std::string beautiful_date, beautiful_day, beautiful_year;

    int i = 0;
    while( string_day[i] != '\0' )
    {
        i++;
    }

    if (int_day==1)
    {
        beautiful_day="first";
    }
    else if (int_day==2)
    {
        beautiful_day="second";
    }
    else if (int_day==3)
    {
        beautiful_day="third";
    }
    else
    {
        beautiful_day=string_day+"th";
    }

    beautiful_date ="The "+ beautiful_day+" of "+string_month+", "+ string_year;

    return beautiful_date;
}
