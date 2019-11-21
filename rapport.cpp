#include<iostream>
#include<string>
#include"rapport.hpp"

using namespace std;

Rapport::Rapport(string content, string mdp){
    this->content=content;
    this->mdp=mdp;
}

string Rapport::get_Rapport(){
    return this->rapport;
}

string Rapport::ask_Mdp(){
    return this->mdp;
}

void Rapport::set_Rapport(string rapport){
    this->rapport=rapport;
}

void Rapport::set_Mdp(string mdp){
    this->mdp=mdp;
}

Rapport::~Rapport(){
    cout << "Le rapport a été supprimé." << endl;
}