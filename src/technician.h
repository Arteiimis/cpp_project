#ifndef _TECHNICIAN_H_
#define _TECHNICIAN_H_

#include <iostream>
#include <string>
#include "person.h"

class technician : public person
{
private:
    const double bonus_per_hour = 50;
    struct salery technicianSalery;

public:
    technician() = default;
    technician(const std::string &name, const std::string &id, const std::string &level = "technician")
            : person(name, id, level)
    { }
    technician(const std::string &name, const std::string &id, const std::string &level = "technician",
               size_t total_hours = 0, size_t base_salary = 0)
            : person(name, id, level)
    {
        technicianSalery.work_hour = total_hours;
        technicianSalery.base_salary = base_salary;
        set_bonus();
        set_salary();
    }
    ~technician() = default;

    void set_hours(size_t hours)
    {
        technicianSalery.work_hour = hours;
        set_bonus();
    }

    void set_bonus()
    { technicianSalery.bonus = technicianSalery.work_hour * bonus_per_hour; }

    void set_salary()
    { technicianSalery.total_salary = technicianSalery.base_salary + technicianSalery.bonus; }

    size_t get_hours() const
    { return technicianSalery.work_hour; }

    size_t get_salary() const
    { return technicianSalery.total_salary; }

    virtual void show() const
    {
        std::cout << "name: \t" << get_name() << std::endl;
        std::cout << "id: \t" << get_id() << std::endl;
        std::cout << "level: \t" << get_level() << std::endl;
        std::cout << "hours: \t" << technicianSalery.work_hour << std::endl;
        std::cout << "salary: \t" << technicianSalery.total_salary << std::endl;
    }

    virtual void fprint(std::ostream &os) const
    {
        os << "name: " << get_name() << " id: " << get_id() << " level: " << get_level() << " hours: "
           << technicianSalery.work_hour << " salary: " << technicianSalery.total_salary << std::endl;
    }
};

#endif // _TECHNICIAN_H_