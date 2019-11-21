#include<iostream>
#include<string>
#include"rapport.hpp"

using namespace std;

Rapport::Rapport(string content, string mdp){
    this->content=content;
    this->mdp=mdp;
}

string Rapport::get_Rapport(){
    return this->content;
}

string Rapport::ask_Mdp(){
    return this->mdp;
}

void Rapport::set_Rapport(string content){
    this->content=content;
}

void Rapport::set_Mdp(string mdp){
    this->mdp=mdp;
}

Rapport::~Rapport(){}

/*
// surchage ==
bool Rapport::operator==(const Rapport &r)
{
    return(this->nom==p.nom && this->prenom==p.prenom && this->age==p.age);
}
*/