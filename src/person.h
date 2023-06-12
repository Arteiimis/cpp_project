#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>

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
    std::string id = 0;
    std::string level;

public:
    person() { }
    person(const std::string& name, const std::string& id, const std::string& level)
        : name(name), id(id), level(level) { }
    ~person() { }

    void set_name(const std::string& name)
    { this->name = name; }

    void set_id(const std::string& id)
    { this->id = id; }

    void set_level(const std::string& level)
    { this->level = level; }

    const std::string& get_name() const
    { return name; }

    const std::string& get_id() const
    { return id; }

    const std::string& get_level() const
    { return level; }

    virtual void show() const = 0;

    virtual void fprint(std::ostream& os) const = 0;

    virtual void set_base_salary(size_t base_salary) { }

    virtual void up_grade() { }
};

#endif // _PERSON_H_