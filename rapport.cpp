#include<iostream>
#include<string>
#include"rapport.hpp"

using namespace std;

rapport::rapport(string rapport, string mdp){
    this->rapport=rapport;
    this->mdp=mdp;
}

string rapport::get_Rapport(){
    return this->rapport;
}

string rapport::ask_Mdp(){
    return this->mdp;
}

void rapport::set_Rapport(string rapport){
    this->rapport=rapport;
}

void rapport::set_Mdp(string mdp){
    this->mdp=mdp;
}

rapport::~rapport(){
    cout << "Le rapport a été supprimé." << endl;
}