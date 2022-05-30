//
// Created by Максим Уланов on 24.05.2022.
//
#pragma once
#include <iostream>
#include "common.h"
#include "date.h"

class letter1: public common{
private:
    Date when_get;

public:
    letter1* letter1_array;

    letter1(){
        letter1_array = nullptr;
    }
    ~letter1();

    void search();

    void show_data1() override;
    void new_data1() override;
    void add_data1() override;

    void saveDataOnDisk1() override;
    void readDataFromDisk1() override;

    letter1& operator = (const letter1 &equal);
};