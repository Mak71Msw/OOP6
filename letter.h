//
// Created by Максим Уланов on 24.05.2022.
//
#pragma once
#include <iostream>
#include "address.h"
#include "common.h"
#include "fio.h"

class letter: public common {
private:
    Address sender_address;
    double price;

public:
    letter* letter_array;

    letter(){
        letter_array = nullptr;
        price = 0.0;
    }
    ~letter();

    void find_by_sender();
    void sort();

    void show_data() override;
    void add_data() override;
    void new_data() override;

    void saveDataOnDisk() override;
    void readDataFromDisk() override;

    letter& operator = (const letter &equal);
};