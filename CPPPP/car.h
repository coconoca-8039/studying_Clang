#ifndef _CAR_H_
#define _CAR_H_

#include <string>

class Car{
public:
    std::string name;
    double speed;
    void drive(double hour);
};

#endif