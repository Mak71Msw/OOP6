//
// Created by Максим Уланов on 24.05.2022.
//
#pragma once
#include <iostream>
#include "fio.h"
#include "address.h"


class common {
protected:
    FIO recipient_fio;
    Address recipient_address;
public:

    virtual void show_data();
    virtual void show_data1();

    virtual void new_data();
    virtual void add_data();

    virtual void new_data1();
    virtual void add_data1();

    virtual void saveDataOnDisk();
    virtual void readDataFromDisk();

    virtual void saveDataOnDisk1();
    virtual void readDataFromDisk1();
};