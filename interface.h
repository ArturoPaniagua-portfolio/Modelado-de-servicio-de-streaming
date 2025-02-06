#ifndef _INTERFACE_H
#define _INTERFACE_H
#include <iostream>
class Interface
{
public:
    virtual void print(std::ostream& os) const = 0;
    virtual Interface& operator+(double calUsuario) = 0;

    friend std::ostream& operator<<(std::ostream& os, const Interface& obj)
    {
        obj.print(os);
        return os;
    }
};
#endif