#ifndef LOGGER_H_
#define LOGGER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

class logger
{
private:
    std::ofstream log_file;
    std::string log_file_name;
    std::string log_time;
    std::string log_content;
};


#endif // LOGGER_H_