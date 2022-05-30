//
// Created by Максим Уланов on 24.05.2022.
//
#include <iostream>
#include <fstream>
#include "letter.h"
#include "StreamTable.h"

letter::~letter(){}

std::string CheckSenderCountry();
std::string CheckSenderCity();
std::string CheckSenderBuilding();

double CheckPrice();

std::string CheckRecipientCountry();
std::string CheckRecipientCity();
std::string CheckRecipientBuilding();

std::string CheckRecipientName();
std::string CheckRecipientSurname();
std::string CheckRecipientPatronymic();

int the_longest_Address;
int the_longest_FIO;
static int count_letter;


void letter::find_by_sender()
{

    std::string wantedCountry=CheckSenderCountry();
    std::string wantedCity=CheckSenderCity();
    std::string wantedBuilding=CheckSenderBuilding();

    StreamTable st(std::cout);
    st.AddCol(the_longest_Address+2);
    st.AddCol(the_longest_Address+2);
    st.AddCol(the_longest_FIO+2);
    st.AddCol(15);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');
    st.SetDelimCol(true, '|');

    st << "Recipient's address" << "Sender's address" << "Recipient's FIO" << "Price";

    bool no_any = true;


    for (int i = 0; i < count_letter; i++)
    {
        std::string Country1=letter_array[i].sender_address.country;
        std::string City1=letter_array[i].sender_address.city;
        std::string Building1=letter_array[i].sender_address.building_number;

        if ( (wantedCountry == Country1) and (wantedCity == City1) and (wantedBuilding == Building1))
        {
            st << letter_array[i].recipient_address.show_pretty_address() << letter_array[i].sender_address.show_pretty_address() << letter_array[i].recipient_fio.show_full_fio() << letter_array[i].price;
            no_any = false;
        }
    }

    if (no_any)
    {
        std::cout<<"Не найдено"<<std::endl<<std::endl;
    }
}

void letter::sort()
{
    for (int i = 0; i <  count_letter; i++)
    {
        for (int j = count_letter - 1; j > i; j--)
        {
            if (letter_array[j].price < letter_array[j - 1].price)
            {
                std::swap(letter_array[j], letter_array[j-1]);
            }
        }
    }
    StreamTable st(std::cout);
    st.AddCol(the_longest_Address+2);
    st.AddCol(the_longest_Address+2);
    st.AddCol(the_longest_FIO+2);
    st.AddCol(15);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');
    st.SetDelimCol(true, '|');

    st << "Address Recipient" << "Address Sender" << "FIO" << "Price";

    for (int i = 0; i < count_letter; i++)
    {
        {
            st << letter_array[i].recipient_address.show_pretty_address() << letter_array[i].sender_address.show_pretty_address() << letter_array[i].recipient_fio.show_full_fio() << letter_array[i].price;
        }
    }
}

letter &letter::operator=(const letter &equal) {
    if (this == &equal)
        return *this;

    sender_address.country=equal.sender_address.country;
    sender_address.city=equal.sender_address.city;
    sender_address.building_number=equal.sender_address.building_number;

    price=equal.price;

    recipient_address.country=equal.recipient_address.country;
    recipient_address.city=equal.recipient_address.city;
    recipient_address.building_number=equal.recipient_address.building_number;

    recipient_fio.person_name=equal.recipient_fio.person_name;
    recipient_fio.person_surname=equal.recipient_fio.person_surname;
    recipient_fio.person_patronymic=equal.recipient_fio.person_patronymic;

    return *this;
}

void letter::show_data() {

    StreamTable st(std::cout);
    st.AddCol(the_longest_Address+2);
    st.AddCol(the_longest_Address+2);
    st.AddCol(the_longest_FIO+2);
    st.AddCol(15);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');
    st.SetDelimCol(true, '|');

    st << "Address Recipient" << "Address Sender" << "FIO" << "Price";

    for (int i = 0; i < count_letter; i++)
    {
        {
            st << letter_array[i].recipient_address.show_pretty_address() << letter_array[i].sender_address.show_pretty_address() << letter_array[i].recipient_fio.show_full_fio() << letter_array[i].price;
        }
    }
}

void letter::add_data() {
    bool b=true;
    while(b)
    {
        try
        {this->sender_address.country=CheckSenderCountry(); b=false;}

        catch(const std::exception &ex)
        {std::cout<<"Ошибка: "<<ex.what()<<std::endl; b=true;}
    }
    b=true;
    while(b)
    {
        try
        {this->sender_address.city=CheckSenderCity(); b=false;}

        catch(const std::exception &ex)
        {std::cout<<"Ошибка: "<<ex.what()<<std::endl; b=true;}
    }
    b=true;
    while(b)
    {
        try
        {this->sender_address.building_number=CheckSenderBuilding(); b=false;}

        catch(const std::exception &ex)
        {std::cout<<"Ошибка: "<<ex.what()<<std::endl; b=true;}
    }


    b=true;
    while(b)
    {
        try
        {this->recipient_address.country=CheckRecipientCountry(); b=false;}

        catch(const std::exception &ex)
        {std::cout<<"Ошибка: "<<ex.what()<<std::endl; b=true;}
    }
    b=true;
    while(b)
    {
        try
        {this->recipient_address.city=CheckRecipientCity(); b=false;}

        catch(const std::exception &ex)
        {std::cout<<"Ошибка: "<<ex.what()<<std::endl; b=true;}
    }
    b=true;
    while(b)
    {
        try
        {this->recipient_address.building_number=CheckRecipientBuilding(); b=false;}

        catch(const std::exception &ex)
        {std::cout<<"Ошибка: "<<ex.what()<<std::endl; b=true;}
    }


    b=true;
    while(b)
    {
        try
        {this->price=CheckPrice(); b=false;}

        catch(const std::exception &ex)
        {std::cout<<"Ошибка: "<<ex.what()<<std::endl; b=true;}
    }


    b=true;
    while(b)
    {
        try
        {this->recipient_fio.person_name=CheckRecipientName(); b=false;}

        catch(const std::exception &ex)
        {std::cout<<"Ошибка: "<<ex.what()<<std::endl; b=true;}
    }
    b=true;
    while(b)
    {
        try
        {this->recipient_fio.person_surname=CheckRecipientSurname(); b=false;}

        catch(const std::exception &ex)
        {std::cout<<"Ошибка: "<<ex.what()<<std::endl; b=true;}
    }
    b=true;
    while(b)
    {
        try
        {this->recipient_fio.person_patronymic=CheckRecipientPatronymic(); b=false;}

        catch(const std::exception &ex)
        {std::cout<<"Ошибка: "<<ex.what()<<std::endl; b=true;}
    }


    if ((this->sender_address.show_pretty_address()).length() > the_longest_Address)
    {
        the_longest_Address=(this->sender_address.show_pretty_address()).length();
    }
    if ((this->recipient_address.show_pretty_address()).length() > the_longest_Address)
    {
        the_longest_Address=(this->recipient_address.show_pretty_address()).length();
    }
    if ((this->recipient_fio.show_full_fio()).length() > the_longest_FIO)
    {
        the_longest_FIO = (this->recipient_fio.show_full_fio()).length();
    }
}

void letter::new_data() {
    letter *tmpletter;

    if (count_letter == 0)
    {
        letter_array = new letter[count_letter + 1];
        letter_array[count_letter].add_data();
        count_letter++;
    }
    else if(count_letter != 0)
    {
        int c = count_letter;
        tmpletter = new letter[count_letter+1];
        count_letter = c;

        for (int i = 0; i < count_letter; i++)
        {
            tmpletter[i] = letter_array[i];
        }

        delete[] letter_array;
        letter_array = tmpletter;

        letter_array[count_letter].add_data();

        count_letter++;
    }
    else{
        std::cout<<"Ошибка в letter.cpp--new_data()"<<std::endl;
    }

}

void letter::saveDataOnDisk() {
    std::ofstream record;
    record.open("OOP4.txt");
    record<<count_letter<<std::endl;

    for (int i=0; i < count_letter; i++)
    {

        record<<letter_array[i].recipient_fio.person_name<<" "<<letter_array[i].recipient_fio.person_surname<<" "<<letter_array[i].recipient_fio.person_patronymic<<" "
              <<letter_array[i].recipient_address.country<<" "<<letter_array[i].recipient_address.city<<" "<<letter_array[i].recipient_address.building_number<<" "
              <<letter_array[i].sender_address.country<<" "<<letter_array[i].sender_address.city<<" "<<letter_array[i].sender_address.building_number<<" "<<letter_array[i].price<<std::endl;
    }
    record.close();
}

void letter::readDataFromDisk() {
    std::ifstream read;
    read.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    try
    {
        if (std::filesystem::is_empty("OOP4.txt"))
        {
            std::cout<<"Ранее добавленных объектов не найдено"<<std::endl;
        }
        else
        {
            read.open("OOP4.txt");
           int current_count;

            read>>current_count;
            count_letter=current_count;

            letter_array = new letter[count_letter];

            for(int i=0; i<count_letter; i++)
            {
                std::string personName,personSurname,personPatronymic,country_recipient,city_recipient,building_recipient,country_sender,city_sender,building_sender;
                double price;
                read >>personName>>personSurname>>personPatronymic>>country_recipient>>city_recipient>>building_recipient>>country_sender>>city_sender>>building_sender>>price;

                letter_array[i].recipient_fio.person_name = personName;
                letter_array[i].recipient_fio.person_surname = personSurname;
                letter_array[i].recipient_fio.person_patronymic = personPatronymic;

                letter_array[i].recipient_address.country = country_recipient;
                letter_array[i].recipient_address.city = city_recipient;
                letter_array[i].recipient_address.building_number = building_recipient;

                letter_array[i].sender_address.country = country_sender;
                letter_array[i].sender_address.city = city_sender;
                letter_array[i].sender_address.building_number = building_sender;

                letter_array[i].price = price;


                if ((this->sender_address.show_pretty_address()).length() > the_longest_Address)
                {
                    the_longest_Address=(this->sender_address.show_pretty_address()).length();
                }
                if ((this->recipient_address.show_pretty_address()).length() > the_longest_Address)
                {
                the_longest_Address=(this->recipient_address.show_pretty_address()).length();
                }
                if ((this->recipient_fio.show_full_fio()).length() > the_longest_FIO)
                {
                    the_longest_FIO = (this->recipient_fio.show_full_fio()).length();
                }
            }
            read.close();
            std::cout<<"Количество считанных объектов: "<<count_letter<<std::endl;
        }
    }
    catch (const std::ifstream::failure &show)
    {
        std::cout<<"There is an error: "<<show.what()<<std::endl;
        std::cout<<"Error code: "<<show.code()<<std::endl;
    }
}
