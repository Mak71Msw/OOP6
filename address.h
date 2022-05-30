//
// Created by Максим Уланов on 24.05.2022.
//
#pragma once
#include <iostream>

class Address {
    friend class letter;
    friend class letter1;
private:
    std::string country;
    std::string city;
    std::string building_number;
public:
    std::string show_pretty_address();

    Address()
    {
        country = "country";
        city = "city";
        building_number = "building_number";
    }
    ~Address();
};