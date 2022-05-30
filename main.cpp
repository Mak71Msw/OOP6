#include <iostream>
#include "letter.h"
#include "letter1.h"

int CheckMenu()
{
    while (true)
    {
        std::cout << "___________Диалоговое окно:__________" << std::endl;
        std::cout << "1-----Показать таблицу с данными-----" << std::endl;
        std::cout << "2-----Добавить новое-----------------" << std::endl;
        std::cout << "3-----Поиск письма по отправителю----" << std::endl;
        std::cout << "4-----Сортировать по росту стоимости-" << std::endl;
        std::cout << "5-----Поиск письма по дате-----------" << std::endl;
        std::cout << "6-----Сохранить и выйти--------------" << std::endl;
        std::cout << "________Введите число от 1 до 6______" << std::endl;
        int c;
        std::cin >> c;

        if (std::cin.fail() or (c < 1) or (c > 6))
        {
            std::cout<<"Вы ввели фигню, надо вводить от 1 до 6. Давайте заново"<<std::endl;
            std::cin.clear();
            std::cin.ignore(32767,'\n');
        }
        else
            return c;
    }
}


int main() {

    letter letter_element;
    letter1 letter1_element;

    letter_element.readDataFromDisk();
    letter1_element.readDataFromDisk1();

    int c;
    do {
        c=CheckMenu();
        switch (c)
        {
            case 1:
                std::cout<<" "<<std::endl;
                std::cout<<"Table 1:"<<std::endl;
                letter_element.show_data();
                std::cout<<" "<<std::endl;
                std::cout<<"Table 2:"<<std::endl;
                letter1_element.show_data1();
                std::cout<<" "<<std::endl;
                break;

            case 2:
                int t;
                std::cout << "В какой класс хотите добавить, выбирите 1 или 2" << std::endl;
                std::cin >> t;
                if(t==1) {
                    std::cout << "Добавим в первый класс" << std::endl;
                    letter_element.new_data();
                }
                else if(t==2) {
                    std::cout << "Добавим во второй класс" << std::endl;
                    letter1_element.new_data1();
                }
                break;

            case 3:
                letter_element.find_by_sender();
                break;

            case 4:
                letter_element.sort();
                break;

            case 5:
                letter1_element.search();
                break;

            case 6:
                letter_element.saveDataOnDisk();
                letter1_element.saveDataOnDisk1();
                break;

        }
    } while (c != 6);

    return 0;
}