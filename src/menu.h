#ifndef _MENU_H_
#define _MENU_H_
#define CLEAR_OUTPUT system("cls") // 清空输出
#define PAUSE system("pause")      // 暂停

#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <string>
#include <vector>
#include "fileManage.h"

class menu
{
private:
    fileManage fm;

public:
    menu() { fm.load(); }
    ~menu() = default;

    static void show()
    {
        CLEAR_OUTPUT;
        std::cout << "1. add a new person" << std::endl;
        std::cout << "2. show all person" << std::endl;
        std::cout << "3. delete a person" << std::endl;
        std::cout << "4. modify a person" << std::endl;
        std::cout << "5. search a person" << std::endl;
        std::cout << "6. sort by name" << std::endl;
        std::cout << "7. upgrate a person" << std::endl;
        std::cout << "8. save and exit" << std::endl;
    }

    void choice()
    {
        int choice;
        person *p = nullptr;
        std::vector<person *> list;
        std::string id, confirm, info;
        std::cout << "input your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            CLEAR_OUTPUT;
            fm.add_new_person();
            PAUSE;
            break;
        }
        case 2:
        {
            CLEAR_OUTPUT;
            fm.show();
            PAUSE;
            break;
        }
        case 3:
        {
            CLEAR_OUTPUT;
            std::cout << "input an id or name: ";
            std::cin >> id;
            CLEAR_OUTPUT;
            std::cout << "please confirm information: " << std::endl;
            // TODO: show list infomation
            list = fm.find(id);
            std::cout << "all matched person: " << std::endl;
            for (auto &&i: list) { i->show(); }
            std::cout << "please choose one person by id: ";
            std::cin >> id;
            p = fm.find(id)[0];
            CLEAR_OUTPUT;
            p->show();
            std::cout << "are you sure to delete this person? (y/n): ";
            std::cin >> confirm;
            if (confirm == "y")
            {
                fm._delete(id);
                CLEAR_OUTPUT;
                std::cout << "delete successfully!" << std::endl;
            }
            else
            {
                CLEAR_OUTPUT;
                std::cout << "cancel delete!" << std::endl;
            }
            PAUSE;
            break;
        }
        case 4:
        {
            CLEAR_OUTPUT;
            std::cout << "input an id or name: ";
            std::cin >> id;
            list = fm.find(id);                 // 寻找所有匹配的人
            if (list.empty()) { std::cout << "no such person!" << std::endl; }
            else
            {
                std::cout << "all matched person: " << std::endl;
                for (auto &&i: list) { i->show(); }
                std::cout << "please choose one person by id: ";
                std::cin >> id;
                p = fm.find(id)[0];
                CLEAR_OUTPUT;
                std::cout << "please confirm information: " << std::endl;
                p->show();
                std::cout << "are you sure to modify this person? (y/n): ";
                std::cin >> confirm;
                CLEAR_OUTPUT;
                if (confirm == "y")
                {
                    // manager modify
                    if (p->get_level() == "manager")
                    {
                        std::cout << "you can modiy: base_salary, name" << std::endl;
                        std::cout << "input information you want to modify: ";
                        std::cin >> info;
                        if (info == "base salary")
                        {
                            size_t salary;
                            std::cout << "input new base salary: ";
                            std::cin >> salary;
                            dynamic_cast<manager *>(p)->set_base_salary(salary);
                            std::cout << "modify successfully!" << std::endl;
                        }
                        else if (info == "name")
                        {
                            std::string name;
                            std::cout << "input new name: ";
                            std::cin >> name;
                            p->set_name(name);
                            std::cout << "modify successfully!" << std::endl;
                        }
                        else { std::cout << "invalid input!" << std::endl; }
                    }
                    else if (p->get_level() == "salesPerson")
                    {
                        std::cout << "you can modiy: total_sales, name" << std::endl;
                        std::cout << "input information you want to modify: ";
                        std::cin >> info;
                        if (info == "total sales")
                        {
                            size_t sales;
                            std::cout << "input new total sales: ";
                            std::cin >> sales;
                            dynamic_cast<salesPerson *>(p)->set_sales(sales);
                            std::cout << "modify successfully!" << std::endl;
                        }
                        else if (info == "name")
                        {
                            std::string name;
                            std::cout << "input new name: ";
                            std::cin >> name;
                            p->set_name(name);
                            std::cout << "modify successfully!" << std::endl;
                        }
                        else { std::cout << "invalid input!" << std::endl; }
                    }
                    else if (info == "salesManager")
                    {
                        std::cout << "you can modiy: base_salary, total_sales, name" << std::endl;
                        std::cout << "input information you want to modify: ";
                        std::cin >> info;
                        if (info == "base salary")
                        {
                            size_t salary;
                            std::cout << "input new base salary: ";
                            std::cin >> salary;
                            dynamic_cast<salesManager *>(p)->set_base_salary(salary);
                            std::cout << "modify successfully!" << std::endl;
                        }
                        else if (info == "total sales")
                        {
                            size_t sales;
                            std::cout << "input new total sales: ";
                            std::cin >> sales;
                            dynamic_cast<salesManager *>(p)->set_sales(sales);
                            std::cout << "modify successfully!" << std::endl;
                        }
                        else if (info == "name")
                        {
                            std::string name;
                            std::cout << "input new name: ";
                            std::cin >> name;
                            p->set_name(name);
                            std::cout << "modify successfully!" << std::endl;
                        }
                        else { std::cout << "invalid input!" << std::endl; }
                    }
                }
                else { std::cout << "cancel modify!" << std::endl; }
            }
            PAUSE;
            break;
        }
        case 5:
        {
            CLEAR_OUTPUT;
            std::cout << "input an id or name: ";
            std::cin >> id;
            list = fm.find(id);
            if (list.empty()) { std::cout << "no such person!" << std::endl; }
            else
            {
                std::cout << "all matched person: " << std::endl;
                for (auto &&i: list) { i->show(); }
            }
            PAUSE;
            break;
        }
        case 6:
        {
            CLEAR_OUTPUT;
            fm.sort_by_name();
            std::cout << "sort successfully!" << std::endl;
            PAUSE;
            break;
        }
        case 7: { CLEAR_OUTPUT; }
        case 8:
        {
            fm.save();
            std::cout << "save successfully!" << std::endl;
            PAUSE;
            exit(0);
        }
        default:
        {
            CLEAR_OUTPUT;
            std::cout << "invalid input!" << std::endl;
            PAUSE;
            break;
        }
        }
    }
};

#endif // _MENU_H_