#include<iostream>
#include"cliche.hpp"

using namespace std;

cliche::cliche(int no_cliche){
    this->no_cliche=no_cliche;
}

int cliche::get_NoCliche(){
    return this->no_cliche;
}

void cliche::set_NoCliche(int cliche){
    this->cliche=cliche;
}

cliche::~cliche(){
    cout << "Cliché bien supprimé." << endl;
}
