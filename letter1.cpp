//
// Created by Максим Уланов on 24.05.2022.
//
#include <iostream>
#include <fstream>
#include "letter1.h"
#include "StreamTable.h"

letter1::~letter1(){}

int CheckDay();
int CheckDay1();
int CheckDay2();
int CheckDay3();
int CheckYear();
int CheckMonth();

std::string CheckRecipientCountry();
std::string CheckRecipientCity();
std::string CheckRecipientBuilding();

std::string CheckRecipientName();
std::string CheckRecipientSurname();
std::string CheckRecipientPatronymic();

int the_longest_Address1;
int the_longest_FIO1;
static int count_letter1;

letter1 &letter1::operator=(const letter1 &equal) {
    if (this == &equal)
        return *this;

    recipient_address.country=equal.recipient_address.country;
    recipient_address.city=equal.recipient_address.city;
    recipient_address.building_number=equal.recipient_address.building_number;

    recipient_fio.person_name=equal.recipient_fio.person_name;
    recipient_fio.person_surname=equal.recipient_fio.person_surname;
    recipient_fio.person_patronymic=equal.recipient_fio.person_patronymic;

    when_get.day=equal.when_get.day;
    when_get.month=equal.when_get.month;
    when_get.year=equal.when_get.year;

    return *this;
}

void letter1::show_data1()
{
    StreamTable st(std::cout);
    st.AddCol(22);
    st.AddCol(the_longest_Address1+2);
    st.AddCol(the_longest_FIO1+2);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');
    st.SetDelimCol(true, '|');

    st << "Date" << "Recipient's address" << " Recipient's FIO" ;

    for (int i = 0; i < count_letter1; i++)
    {
        {
            st << letter1_array[i].when_get.show_pretty_date() << letter1_array[i].recipient_address.show_pretty_address() << letter1_array[i].recipient_fio.show_full_fio();
        }
    }
}

void letter1::add_data1()
{
    int a, b;
    a=CheckYear();
    this->when_get.year=a;
    b=CheckMonth();
    this->when_get.month=b;
    if(a%4==0 and b==2)
        this->when_get.day = CheckDay1();

    else if(b==1 or b==3 or b==5 or b==7 or b==8 or b==10 or b==12)
        this->when_get.day = CheckDay2();

    else if(a%4!=0 and b==2)
        this->when_get.day=CheckDay3();

    else
        this->when_get.day=CheckDay();




//    bool d=true;
//    while(d)
//    {
//        try
//        {this->when_get.year=CheckYear(); d=false;}
//
//        catch(const std::exception &ex)
//        {std::cout<<"Ошибка: "<<ex.what()<<std::endl; d=true;}
//    }
//    d=true;
//    while(d)
//    {
//        try
//        {this->when_get.month=CheckMonth(); d=false;}
//
//        catch(const std::exception &ex)
//        {std::cout<<"Ошибка: "<<ex.what()<<std::endl; d=true;}
//    }
//    d=true;
//    while(d)
//    {
//        try
//        {this->when_get.day=CheckDay(); d=false;}
//
//        catch(const std::exception &ex)
//        {std::cout<<"Ошибка: "<<ex.what()<<std::endl; d=true;}
//    }


    bool d=true;
    while(d)
    {
        try
        {this->recipient_address.country=CheckRecipientCountry(); d=false;}

        catch(const std::exception &ex)
        {std::cout<<"Ошибка: "<<ex.what()<<std::endl; d=true;}
    }
    d=true;
    while(d)
    {
        try
        {this->recipient_address.city=CheckRecipientCity(); d=false;}

        catch(const std::exception &ex)
        {std::cout<<"Ошибка: "<<ex.what()<<std::endl; d=true;}
    }
    d=true;
    while(d)
    {
        try
        {this->recipient_address.building_number=CheckRecipientBuilding(); d=false;}

        catch(const std::exception &ex)
        {std::cout<<"Ошибка: "<<ex.what()<<std::endl; d=true;}
    }

    d=true;
    while(d)
    {
        try
        {this->recipient_fio.person_name=CheckRecipientName(); d=false;}

        catch(const std::exception &ex)
        {std::cout<<"Ошибка: "<<ex.what()<<std::endl; d=true;}
    }
    d=true;
    while(d)
    {
        try
        {this->recipient_fio.person_surname=CheckRecipientSurname(); d=false;}

        catch(const std::exception &ex)
        {std::cout<<"Ошибка: "<<ex.what()<<std::endl; d=true;}
    }
    d=true;
    while(d)
    {
        try
        {this->recipient_fio.person_patronymic=CheckRecipientPatronymic(); d=false;}

        catch(const std::exception &ex)
        {std::cout<<"Ошибка: "<<ex.what()<<std::endl; d=true;}
    }


    if ((this->recipient_address.show_pretty_address()).length() > the_longest_Address1)
    {
        the_longest_Address1=(this->recipient_address.show_pretty_address()).length();
    }
    if ((this->recipient_fio.show_full_fio()).length() > the_longest_FIO1)
    {
        the_longest_FIO1 = (this->recipient_fio.show_full_fio()).length();
    }
}

void letter1::search(){
    int YEAR=CheckYear();
    int MONTH=CheckMonth();
    int DAY=CheckDay();

    StreamTable st(std::cout);
    st.AddCol(22);
    st.AddCol(the_longest_Address1+2);
    st.AddCol(the_longest_FIO1+2);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');
    st.SetDelimCol(true, '|');

    st << "Date" << "Recipient's address" << " Recipient's FIO" ;

    bool no_any = true;


    for (int i = 0; i < count_letter1; i++)
    {
        int Year=letter1_array[i].when_get.year;
        int Month=letter1_array[i].when_get.month;
        int Day=letter1_array[i].when_get.day;

        if ( (YEAR == Year) and (MONTH == Month) and (DAY == Day))
        {
            st << letter1_array[i].when_get.show_pretty_date() << letter1_array[i].recipient_address.show_pretty_address() << letter1_array[i].recipient_fio.show_full_fio();
            no_any = false;
        }
    }

    if (no_any)
    {
        std::cout<<"Не найдено"<<std::endl<<std::endl;
    }
}

void letter1::new_data1() {
    letter1 *tmpletter1;

    if (count_letter1 == 0)
    {
        letter1_array = new letter1[count_letter1 + 1];
        letter1_array[count_letter1].add_data1();
        count_letter1++;
    }
    else if(count_letter1 != 0)
    {
        int c = count_letter1;
        tmpletter1 = new letter1[count_letter1+1];
        count_letter1 = c;

        for (int i = 0; i < count_letter1; i++)
        {
            tmpletter1[i] = letter1_array[i];
        }

        delete[] letter1_array;
        letter1_array = tmpletter1;

        letter1_array[count_letter1].add_data1();

        count_letter1++;
    }
    else{
        std::cout<<"Ошибка в letter1.cpp--new_data()"<<std::endl;
    }

}

void letter1::saveDataOnDisk1() {

    std::ofstream record;
    record.open("OOP4.1.txt");
    record<<count_letter1<<std::endl;

    for (int i=0; i < count_letter1; i++)
    {

        record<<letter1_array[i].recipient_fio.person_name<<" "<<letter1_array[i].recipient_fio.person_surname<<" "<<letter1_array[i].recipient_fio.person_patronymic<<" "
              <<letter1_array[i].recipient_address.country<<" "<<letter1_array[i].recipient_address.city<<" "<<letter1_array[i].recipient_address.building_number<<" "
              <<letter1_array[i].when_get.year<<" "<<letter1_array[i].when_get.month<<" "<<letter1_array[i].when_get.day<<std::endl;
    }

    record.close();
}

void letter1::readDataFromDisk1() {
    std::ifstream read;
    read.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    try
    {
        if (std::filesystem::is_empty("OOP4.1.txt")){std::cout<<"Ранее добавленных объектов1 не найдено"<<std::endl;}
        else
        {
                read.open("OOP4.1.txt");
                int current_count;

                read>>current_count;
                count_letter1=current_count;

            letter1_array = new letter1[count_letter1];

            for(int i=0; i<count_letter1; i++)
            {
                std::string personName1,personSurname1,personPatronymic1,country_recipient1,city_recipient1,building_recipient1;
                int year,month,day;
                read >>personName1>>personSurname1>>personPatronymic1>>country_recipient1>>city_recipient1>>building_recipient1>>year>>month>>day;

                letter1_array[i].recipient_fio.person_name = personName1;
                letter1_array[i].recipient_fio.person_surname = personSurname1;
                letter1_array[i].recipient_fio.person_patronymic = personPatronymic1;

                letter1_array[i].recipient_address.country = country_recipient1;
                letter1_array[i].recipient_address.city = city_recipient1;
                letter1_array[i].recipient_address.building_number = building_recipient1;

                letter1_array[i].when_get.year = year;
                letter1_array[i].when_get.month = month;
                letter1_array[i].when_get.day = day;


                if ((this->recipient_address.show_pretty_address()).length() > the_longest_Address1)
                {
                    the_longest_Address1=(this->recipient_address.show_pretty_address()).length();
                }
                if ((this->recipient_fio.show_full_fio()).length() > the_longest_FIO1)
                {
                    the_longest_FIO1 = (this->recipient_fio.show_full_fio()).length();
                }        }
            read.close();
            std::cout<<"Количество считанных объектов1: "<<count_letter1<<std::endl;
        }
    }
    catch (const std::ifstream::failure &show)
    {
        std::cout<<"There is an error: "<<show.what()<<std::endl;
        std::cout<<"Error code: "<<show.code()<<std::endl;
    }
}