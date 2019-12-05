#include<iostream>
#include<string>
#include<list>
#include"rapport.hpp"

using namespace std;

Rapport::Rapport() {}

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


// Ces deux méthodes probablement à changer parce qu'on n'utilise plus une liste
void Rapport::ajouter_Rapport(list<Rapport> &R){
    bool test=false;
    for(list<Rapport>::iterator it=R.begin(); it!=R.end(); it++){
        if(it->content==this->content){
            test=true;
            cout << "Le rapport existe déjà" << endl;
        }
    }
    if(test==false){
        Rapport rp = Rapport(this->content, this->mdp);
        R.push_back(rp);
    }
}

void Rapport::supprimer_Rapport(list<Rapport> &R){
    list<Rapport>::iterator itr = R.begin();
    while(itr!=R.end()){
        if(itr->content==this->content){
            itr = R.erase(itr);
            cout << "Rapport supprimé !" << endl;
        } else {
            ++itr;
        }
    }
}
