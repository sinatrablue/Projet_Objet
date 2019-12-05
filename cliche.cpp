#include<iostream>
#include<list>
#include<string>
#include"cliche.hpp"

using namespace std;

Cliche::Cliche() {}

Cliche::Cliche(string no_cliche){
    this->no_cliche=no_cliche;
}

string Cliche::get_NoCliche(){
    return this->no_cliche;
}

void Cliche::set_NoCliche(string cliche){
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
    for(list<Cliche>::iterator it=C.begin(); it!=C.end(); it++){
        if(it->no_cliche==this->no_cliche){
            test=true;
            cout << "Le cliché existe déjà" << endl;
        }
    }
    if(test==false){
        Cliche cl = Cliche(this->no_cliche);
        C.push_back(cl);
    }
}

void Cliche::supprimer_Cliche(list<Cliche> &C){
    list<Cliche>::iterator itr = C.begin();
    while(itr!=C.end()){
        if(itr->no_cliche==this->no_cliche){
            itr = C.erase(itr);
            cout << "Cliché supprimé !" << endl;
        } else {
            ++itr;
        }
    }
}
