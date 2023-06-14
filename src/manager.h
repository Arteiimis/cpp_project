#ifndef _MANAGER_H_
#define _MANAGER_H_

#include <iostream>
#include <string>
#include "person.h"
#include "technician.h"

class manager : virtual public person
{
private:
    struct salery managerSalery;

public:
    manager() = default;
    manager(const std::string &name, const std::string &id, const std::string &level = "manager")
            : person(name, id, level)
    { }
    manager(const std::string &name, const std::string &id, const std::string &level = "manager",
            size_t base_salary = 0)
            : person(name, id, level)
    {
        managerSalery.base_salary = base_salary;
        set_salary();
    }

    explicit manager(const technician &technician)
            : person(technician.get_name(), technician.get_id(), technician.get_level())
    {
        managerSalery.base_salary = technician.get_salary();
        set_salary();
    }
    ~manager() = default;

    void set_salary()
    { managerSalery.total_salary = managerSalery.base_salary; }

    size_t get_salary() const
    { return managerSalery.total_salary; }

    void show() const override
    {
        std::cout << "name: \t" << get_name() << std::endl;
        std::cout << "id: \t" << get_id() << std::endl;
        std::cout << "level: \t" << get_level() << std::endl;
        std::cout << "salary: \t" << managerSalery.total_salary << std::endl;
    }

    void fprint(std::ostream &os) const override
    {
        os << "name: " << get_name() << " id: " << get_id() << " level: " << get_level() << " salary: "
           << managerSalery.total_salary << std::endl;
    }

    void set_base_salary(size_t base_salary) override
    { managerSalery.base_salary = base_salary; }
};


#endif // _MANAGER_H_
