#ifndef _FILEMANAGE_H_
#define _FILEMANAGE_H_

#include <iostream>
#include <fstream>
#include <string>

#include "personList.h"

class fileManage : public personList
{
private:
    std::string filename = "C:\\Users\\LEGION\\Desktop\\c++_project\\data\\database.txt";
    std::ifstream fin;
    std::ofstream fout;
    std::string line;
    std::string name, id, level;
    size_t work_hour, total_sales, salary;

public:
    void load()
    {
        // TODO: 修改读入文本匹配方式
        fin.open(filename);
        if (!fin.is_open())
        {
            std::cout << "open file failed!" << std::endl;
            exit(EXIT_FAILURE);
        }
        while (std::getline(fin, line))
        {
            //name: zlp; id: 1; level: manager; salary: 1000
            std::stringstream ss(line);
            std::string temp;
            ss >> temp >> name >> temp >> id >> temp >> level;
            if (level == "manager")
            {
                ss >> temp >> salary;
                append(new manager(name, id, level, salary));
            }
            else if (level == "salesPerson")
            {
                ss >> temp >> total_sales;
                append(new salesPerson(name, id, level, total_sales));
            }
            else if (level == "salesManager")
            {
                ss >> temp >> total_sales >> temp >> salary;
                append(new salesManager(name, id, level, total_sales, salary));
            }
            else if (level == "technician")
            {
                ss >> temp >> work_hour;
                append(new technician(name, id, level, work_hour));
            }

        }
    }

    void save()
    {
        fout.open(filename);
        if (!fout.is_open())
        {
            std::cout << "open file failed!" << std::endl;
            exit(EXIT_FAILURE);
        }
        else
        { fprint(fout); }
    }
};

#endif // _FILEMANAGE_H_