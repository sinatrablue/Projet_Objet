#include<iostream>
#include<list>
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

void Cliche::ajouter_Cliche(list<Cliche> &C){
    bool test=false;
    for(list<Cliche>::iterator i=C.begin();i!=C.end();i++){
        if(i->no_cliche==this->no_cliche){
            test=true;
            cout << "Le cliché existe déjà" << endl;
        }
    }
    if(test==false){
        Cliche cl = Cliche(this->no_cliche);
        C.push_back(cl);
    } 
}