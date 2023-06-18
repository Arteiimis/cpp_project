#ifndef _SALESMANAGER_H_
#define _SALESMANAGER_H_

#include <iostream>
#include <string>
#include "salesPerson.h"
#include "manager.h"

class salesManager : public salesPerson, public manager
{
private:
    const double bonus_per_sale = 0.2;
    struct salery salesManagerSalery;

public:
    salesManager() = default;
    salesManager(const std::string &name, const std::string &id, const std::string &level = "salesManager")
            : person(name, id, level)
    { }
    salesManager(const std::string &name, const std::string &id, const std::string &level = "salesManager",
                 size_t total_sales = 0, size_t base_salary = 6000)
            : person(name, id, level)
    {
        salesManagerSalery.total_sales = total_sales;
        salesManagerSalery.base_salary = base_salary;
        set_bonus();
        set_salary();
    }

    explicit salesManager(const manager &manager)
            : person(manager.get_name(), manager.get_id(), manager.get_level())
    {
        salesManagerSalery.base_salary = manager.get_salary();
        set_bonus();
        set_salary();
    }

    explicit salesManager(const salesPerson &salesPerson)
            : person(salesPerson.get_name(), salesPerson.get_id(), salesPerson.get_level())
    {
        salesManagerSalery.total_sales = salesPerson.get_sales();
        set_bonus();
        set_salary();
    }
    ~salesManager() = default;

    void set_selas(size_t sales)
    {
        salesManagerSalery.total_sales = sales;
        set_bonus();
    }

    void set_bonus() override
    { salesManagerSalery.bonus = salesManagerSalery.total_sales * bonus_per_sale; }

    void set_salary() override
    { salesManagerSalery.total_salary = salesManagerSalery.base_salary + salesManagerSalery.bonus; }

    size_t get_sales() const override
    { return salesManagerSalery.total_sales; }

    size_t get_salary() const override
    { return salesManagerSalery.total_salary; }

    void show() const override
    {
        std::cout << "name: \t" << get_name() << std::endl;
        std::cout << "id: \t" << get_id() << std::endl;
        std::cout << "level: \t" << get_level() << std::endl;
        std::cout << "sales: \t" << salesManagerSalery.total_sales << std::endl;
        std::cout << "salary: \t" << salesManagerSalery.total_salary << std::endl;
    }

    void fprint(std::ostream &os) const override
    {
        os << "name: " << get_name() << " id: " << get_id() << " level: " << get_level() << " sales: "
           << salesManagerSalery.total_sales << " salary: " << salesManagerSalery.total_salary << std::endl;
    }

    void set_base_salary(size_t base_salary) override
    { salesManagerSalery.base_salary = base_salary; }
};

#endif // _SALESMANAGER_H_