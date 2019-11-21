#include<iostream>
#include"cliche.hpp"

using namespace std;

Cliche::Cliche(int no_cliche){
    this->no_cliche=no_cliche;
}

int Cliche::get_NoCliche(){
    return this->no_cliche;
}

void Cliche::set_NoCliche(int cliche){
    this->no_cliche=no_cliche;
}

Cliche::~Cliche(){}

// surchage ==
bool Cliche::operator==(const Cliche &c)
{
    return(this->no_cliche==c.no_cliche);
}
