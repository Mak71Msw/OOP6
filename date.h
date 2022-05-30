//
// Created by Максим Уланов on 24.05.2022.
//
#pragma once
#include <iostream>

class Date {
    friend class letter1;
private:
    int day;
    int month;
    int year;
public:
    std::string show_pretty_date();

    Date()
    {
        day = 1;
        month = 1;
        year = 1;
    }
    ~Date();
};