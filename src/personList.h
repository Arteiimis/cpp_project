#ifndef _PERSONLIST_H_
#define _PERSONLIST_H_

#define PAUSE system("pause")      // 暂停

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "person.h"
#include "salesPerson.h"
#include "manager.h"
#include "salesManager.h"
#include "technician.h"

class personList
{
private:
    std::vector<person *> list;

public:
    personList() = default;
    ~personList() = default;

    void append(person *p)
    {
        std::cout << "appending " << p->get_name() << std::endl;
        p->set_id(std::to_string(list.size() + 1));
        list.push_back(p);
    }

    void add_new_person()
    {
        std::string name, level, id = "0";
        std::cout << "input name: ";
        std::cin >> name;
        std::cout << "choose level: " << std::endl;
        std::cout << "1. manager, 2. salesPerson, 3. salesManager, 4. technician: ";
        int choice;
        std::cin >> choice;
        CLEAR_OUTPUT;
        switch (choice)
        {
        case 1:
        {
            size_t salary;
            std::cout << "input base salary: ";
            std::cin >> salary;
            append(new manager(name, id, "manager", salary));
            break;
        }
        case 2:
        {
            size_t sales;
            std::cout << "input total sales: ";
            std::cin >> sales;
            append(new salesPerson(name, id, "salesPerson", sales));
            break;
        }
        case 3:
        {
            size_t sales, salary;
            std::cout << "input total sales: ";
            std::cin >> sales;
            std::cout << "input base salary: ";
            std::cin >> salary;
            append(new salesManager(name, id, "salesManager", sales, salary));
            break;
        }
        case 4:
        {
            size_t work_hour, base_salary;
            std::cout << "input work hour: ";
            std::cin >> work_hour;
            std::cout << "input base salary: ";
            std::cin >> base_salary;
            append(new technician(name, id, "technician", work_hour, base_salary));
            break;
        }
        default:
        {
            std::cout << "invalid input" << std::endl;
            PAUSE;
            break;
        }
        }
        std::cout << "add new person successfully" << std::endl;
    }

    void up_grade(person *p)
    {
        std::string level = p->get_level();
        if (level == "manager")
        {
            std::cout << "A manager can only upgrate to a salesManager" << std::endl;
            std::cout << "pleas confirm: (y/n) ";
            char choice;
            std::cin >> choice;
            if (choice == 'y')
            {
                size_t sales;
                std::cout << "input total sales: ";
                std::cin >> sales;
                p = new salesManager(dynamic_cast<manager &>(*p));
            }
            else { std::cout << "cancel upgrate" << std::endl; }
        }
        else if (level == "salesPerson")
        {
            std::cout << "A salesPerson can only upgrate to a salesManager" << std::endl;
            std::cout << "pleas confirm: (y/n) ";
            char choice;
            std::cin >> choice;
            if (choice == 'y')
            {
                size_t salary;
                std::cout << "input base salary: ";
                std::cin >> salary;
                p = new salesManager(dynamic_cast<salesPerson &>(*p));
            }
            else { std::cout << "cancel upgrate" << std::endl; }
        }
    }

    bool isEmpty() const
    { return list.empty(); }

    size_t get_size() const
    { return list.size(); }

    person *get_person(size_t index) const
    { return list[index]; }

    void reSync_id()
    {
        for (size_t i = 0; i < list.size(); ++i) { list[i]->set_id(std::to_string(i + 1)); }
    }

    void _delete(const std::string &ni)
    {
        auto it = std::find_if(list.begin(), list.end(), [ni](person *p) { return p->get_id() == ni || p->get_name() == ni; });
        if (it != list.end()) { list.erase(it); }
        reSync_id();
    }

    void change_name(const std::string &id)
    {
        auto it = std::find_if(list.begin(), list.end(), [id](person *p) { return p->get_id() == id; });
        if (it != list.end())
        {
            std::string name;
            std::cout << "input new name: ";
            std::cin >> name;
            (*it)->set_name(name);
        }
        else { std::cout << "not found" << std::endl; }
    }

    void change_name(person *p)
    {
        std::string name;
        std::cout << "input new name: ";
        std::cin >> name;
        p->set_name(name);
        std::cout << "change name successfully" << std::endl;
    }

    void change_base_salary(person *p)
    {
        size_t base_salary;
        std::cout << "input new base salary: ";
        std::cin >> base_salary;
        p->set_base_salary(base_salary);
        std::cout << "change base salary successfully" << std::endl;
    }

    std::vector<person *> find(const std::string &ni)
    {
        std::vector<person *> res;
        for (auto &&it: list)
        {
            if (it->get_id() == ni || it->get_name() == ni) { res.push_back(it); }
        }
        return res;
    }

    void sort_by_id()
    {
        std::sort(list.begin(), list.end(), [](person *p1, person *p2) { return p1->get_id() < p2->get_id(); });
    }

    void sort_by_name()
    {
        std::sort(list.begin(), list.end(), [](person *p1, person *p2) { return p1->get_name() < p2->get_name(); });
        reSync_id();
    }

    void show() const
    {
        std::cout << "== show all person ==" << std::endl;
        for (auto &&p: list)
        {
            std::cout << "====================" << std::endl;
            p->show();
            if (p == list.back()) { std::cout << "====================" << std::endl; }
        }
    }

    void fprint(std::ostream &os) const
    {
        for (auto &&it: list) { it->fprint(os); }
    }
};

#endif // _PERSONLIST_H_