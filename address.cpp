//
// Created by Максим Уланов on 24.05.2022.
//
#include "address.h"

Address::~Address(){}

std::string Address::show_pretty_address() {
    std::string full_address = "Country: "+country+"; "+"City: "+city+"; "+"Building: "+building_number;
    return full_address;
}
