#ifndef __MODULO_H
#define __MODULO_H
#include <iostream>
class Modulo{
    public:
        Modulo(int modulo=10, int value=0, int offset=0);
        void set_nmsd(Modulo *nmsd);
        int value();
        Modulo& operator+=(int rhs);
        Modulo operator+(int rhs);
        Modulo& operator++(); //preincrement
        Modulo operator++(int); //post increment
        inline bool operator==(const int rhs);
        inline bool operator!=(const int rhs);
        inline bool operator<(const int rhs);
        inline bool operator<=(const int rhs);
        inline bool operator>(const int rhs);
        inline bool operator>=(const int rhs);
        friend std::ostream& operator <<(std::ostream& ost, const Modulo& m);
        friend std::istream& operator >>(std::istream& ost, Modulo& m);
    private:
        int _modulo;
        int _value;
        int _offset;
        Modulo* _nmsd;
        int compare(const int rhs);
};
#endif