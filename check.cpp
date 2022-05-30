//
// Created by Максим Уланов on 24.05.2022.
//
#include <iostream>
#include <exception>


int CheckDay()
{
    while (true)
    {
        std::cout << "День: ";
        int a;
        std::cin >> a;

        if (std::cin.fail() or (a <=0) or (a>30))
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            throw std::runtime_error("Нормально введите день");
        }
        else
            return a;
    }
}

int CheckDay1()
{
    while (true)
    {
        std::cout << "День: ";
        int a;
        std::cin >> a;

        if (std::cin.fail() or (a <=0) or (a>29))
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            throw std::runtime_error("Нормально введите день");
        }
        else
            return a;
    }
}

int CheckDay2()
{
    while (true)
    {
        std::cout << "День: ";
        int a;
        std::cin >> a;

        if (std::cin.fail() or (a <=0) or (a>31))
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            throw std::runtime_error("Нормально введите день");
        }
        else
            return a;
    }
}

int CheckDay3()
{
    while (true)
    {
        std::cout << "День: ";
        int a;
        std::cin >> a;

        if (std::cin.fail() or (a <=0) or (a>28))
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            throw std::runtime_error("Нормально введите день");
        }
        else
            return a;
    }
}

int CheckYear()
{
    while (true)
    {
        std::cout << "Год: ";
        int a;
        std::cin >> a;

        if (std::cin.fail() or (a <=0) or (a>2022))
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            throw std::runtime_error("Введите год от 1 до 2022");
        }
        else
            return a;
    }
}

int CheckMonth()
{
    while (true)
    {
        std::cout << "Месяц: ";
        int a;
        std::cin >> a;

        if (std::cin.fail() or (a <=0) or (a>12))
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            throw std::runtime_error("Введите месяц от 1 до 12");
        }
        else
            return a;
    }
}


double CheckPrice()
{
    while (true)
    {
        std::cout << "Цена письма: ";
        double a;
        std::cin >> a;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            throw std::runtime_error("Нормально введите цену письма");
        }
        else
            return a;
    }
}


std::string CheckRecipientCountry()
{
    int i;
    std::string str;
    do{
        std::cout<<"Страна получателя: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{'))
                break;
        }

        if( str[i])
        {
            throw std::runtime_error("Введите страну без посторонних символов");
        }

    }while(str[i]);

    return str;
}
std::string CheckRecipientCity()
{
    int i;
    std::string str;
    do{
        std::cout<<"Город получателя: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{'))
                break;
        }

        if( str[i])
        {
            throw std::runtime_error("Введите город без посторонних символов");
        }

    }while(str[i]);

    return str;
}
std::string CheckRecipientBuilding()
{
    int i;
    std::string str;
    do{
        std::cout<<"Строение получателя: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if( (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{') )
                break;
        }

        if( str[i])
        {
            throw std::runtime_error("Введите строение без посторонних символов");
        }

    }while(str[i]);

    return str;
}

std::string CheckSenderCountry()
{
    int i;
    std::string str;
    do{
        std::cout<<"Страна отправителя: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{'))
                break;
        }

        if( str[i])
        {
            throw std::runtime_error("Введите страну без посторонних символов");
        }

    }while(str[i]);

    return str;
}
std::string CheckSenderCity()
{
    int i;
    std::string str;
    do{
        std::cout<<"Город отправителя: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{'))
                break;
        }

        if( str[i])
        {
            throw std::runtime_error("Введите город без посторонних символов");
        }

    }while(str[i]);

    return str;
}
std::string CheckSenderBuilding()
{
    int i;
    std::string str;
    do{
        std::cout<<"Строение отправителя: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if( (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{') )
                break;
        }

        if( str[i])
        {
            throw std::runtime_error("Введите строение без посторонних символов");
        }

    }while(str[i]);

    return str;
}


std::string CheckRecipientName()
{
    int i;
    std::string str;
    do{
        std::cout<<"Имя получателя: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{'))
                break;
        }

        if( str[i])
        {
            throw std::runtime_error("Введите имя буквами");
        }

    }while(str[i]);

    return str;
}
std::string CheckRecipientSurname()
{
    int i;
    std::string str;
    do{
        std::cout<<"Фамилия получателя: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{'))
                break;
        }

        if( str[i])
        {
            throw std::runtime_error("Введите фамилию буквами");
        }

    }while(str[i]);

    return str;
}
std::string CheckRecipientPatronymic()
{
    int i;
    std::string str;
    do{
        std::cout<<"Отчество получателя: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{'))
                break;
        }

        if( str[i])
        {
            throw std::runtime_error("Введите отчество буквами");
        }

    }while(str[i]);

    return str;
}




//int CheckDay()
//{
//    while (true)
//    {
//        std::string buffer;
//        std::cout << "День: ";
//        int a;
//        in>>buffer;
//        std::cin >> a;
//
//        if (std::cin.fail() or (a <=0) or (a>30))
//        {
//            std::cin.clear();
//            std::cin.ignore(32767,'\n');
//            throw buffer;
//        }
//        else
//            return a;
//    }
//}
//void LOH()
//{
//    char* buffer;
//    cout<<"Enter name:"<<endl;
//    in>>buffer;
//    try
//    {
//        for(int i=0;i<strlen(buffer);i++)
//        {
//            if(isdigit(buffer[i])==true || isalnum(buffer[i])==false)
//            {
//                throw buffer;
//            }
//        }
//    }
//    catch(char*& exception)
//    {
//        bool b=false;
//        do
//        {
//
//            int counter=0;
//            cout<<"Incorrect input. There are numbers in name."<<endl<<"Enter name:\n";
//            in>>exception;
//            for(int i=0;i<strlen(buffer);i++)
//            {
//                if(isdigit(buffer[i])==true || isalnum(buffer[i])==false)
//                {
//                    counter+=1;
//                    break;
//                }
//            }
//            if(counter==0)
//            {
//                b=true;
//            }
//            continue;
//        }while(b==false);
//    }
//}
