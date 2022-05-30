//
// Created by Максим Уланов on 24.05.2022.
//
#include "fio.h"

FIO::~FIO(){}

std::string FIO::show_full_fio() {
    std::string full_fio = person_surname + " " + person_name + " " + person_patronymic;
    return full_fio;
}
