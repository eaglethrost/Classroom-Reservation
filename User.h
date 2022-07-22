#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User
{
private:
    std::string name;
    int id;
public:
    User();
    User(std::string Name, int ID);
    std::string get_name();
    int get_id();

    ~User();
};

#endif