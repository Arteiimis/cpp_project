#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>
#include <utility>

struct salery
{
    size_t work_hour = 0;       // technician工作时间
    size_t total_sales = 0;     // salesPerson销售额
    size_t bonus = 0;           // salesPerson销售提成 or technician工作提成
    size_t base_salary = 0;     // manager基本工资 or salesManager基本工资
    size_t total_salary = 0;    // 总工资
};

class person
{
    std::string name;
    std::string id = "0";
    std::string level;

public:
    person() = default;
    person(std::string name, std::string id, std::string level) : name(std::move(name)), id(std::move(id)), level(std::move(level))
    { }
    ~person() = default;

    void set_name(const std::string &n_name)
    { this->name = n_name; }

    void set_id(const std::string &n_id)
    { this->id = n_id; }

    void set_level(const std::string &n_level)
    { this->level = n_level; }

    const std::string &get_name() const
    { return name; }

    const std::string &get_id() const
    { return id; }

    const std::string &get_level() const
    { return level; }


    virtual void show() const = 0;

    virtual void fprint(std::ostream &os) const = 0;

    virtual void set_base_salary(size_t base_salary)
    { }

    virtual void up_grade()
    { }
};

#endif // _PERSON_H_