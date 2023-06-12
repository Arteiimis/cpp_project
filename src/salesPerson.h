#ifndef _SALESPERSON_H_
#define _SALESPERSON_H_

#include <iostream>
#include <string>
#include "person.h"

class salesPerson : virtual public person
{
private:
    const double bonus_per_sale = 0.1;
    struct salery salesPersonSalery;

public:
    salesPerson() { }
    salesPerson(const std::string& name, const std::string& id, const std::string& level = "salesPerson")
        : person(name, id, level) { }
    salesPerson(const std::string& name, const std::string& id, const std::string& level = "salesPerson", size_t total_sales = 0)
        : person(name, id, level)
    {
        salesPersonSalery.total_sales = total_sales;
        set_bonus();
        set_salary();
    }
    ~salesPerson() { }

    void set_sales(size_t sales)
    {
        salesPersonSalery.total_sales = sales;
        set_bonus();
    }

    void set_bonus()
    { salesPersonSalery.bonus = salesPersonSalery.total_sales * bonus_per_sale; }

    void set_salary()
    { salesPersonSalery.total_salary = salesPersonSalery.base_salary + salesPersonSalery.bonus; }

    size_t get_sales() const
    { return salesPersonSalery.total_sales; }

    size_t get_salary() const
    { return salesPersonSalery.total_salary; }

    virtual void show() const
    {
        std::cout << "name: \t" << get_name() << std::endl;
        std::cout << "id: \t" << get_id() << std::endl;
        std::cout << "level: \t" << get_level() << std::endl;
        std::cout << "sales: \t" << salesPersonSalery.total_sales << std::endl;
        std::cout << "salary: \t" << salesPersonSalery.total_salary << std::endl;
    }

    virtual void fprint(std::ostream& os) const
    {
        os << "name: " << get_name()
            << " id: " << get_id()
            << " level: " << get_level()
            << " sales: " << salesPersonSalery.total_sales
            << " salary: " << salesPersonSalery.total_salary << std::endl;
    }

};

#endif // _SALESPERSON_H_