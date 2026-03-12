#include "skin.h"
using namespace std;

Skin::skin(string cname = "", string sname = "", int p = 0, int is_sold = 0); {
    Charactername = cname;
    Skinname = sname;
    price = p;
    is_sold = 0;

    string Skin::getcname() { return Charactername;}
    string Skin::getsname() { return Skinname;}
    int Skin::getprice() { return p;}
    int Skin::get_is_sold() { return is_sold;}

    void Skin::setcname() { return cname;}
    void Skin::setsname() { return sname;}
    void Skin::setprice() { return p;}
    void Skin::set_is_sold() { return is_sold;}
}
