#include<iostream>
#include<string>
#include<list>
#include"examen.hpp"

using namespace std;

Examen::Examen() {}

Examen::Examen(string no_exam, string type, string date, bool etat, list<Cliche> cliches, Rapport rapp){
    this->no_exam=no_exam;
    this->type=type;
    this->date=date;
    this->etat=etat;
    this->cliches=cliches;
    this->rapp=rapp;
}

string Examen::get_NoExam(){
    return this->no_exam;
}

string Examen::get_Type(){
    return this->type;
}

string Examen::get_Date(){
    return this->date;
}

bool Examen::get_Etat(){
    return this->etat;
}

list<Cliche> Examen::get_Cliches(){
    return this->cliches;
}

Rapport Examen::get_Rapport(){
    return this->rapp;
}

void Examen::set_NoExam(string no_exam){
    this->no_exam=no_exam;
}

void Examen::set_Type(string type){
    this->type=type;
}

void Examen::set_Date(string date){
    this->date=date;
}

void Examen::set_Etat(bool etat){
    this->etat=etat;
}

void Examen::set_Cliches(list<Cliche> cliches){
    this->cliches=cliches;
}

void Examen::set_Rapport(Rapport rapp){
    this->rapp=rapp;
}

void Examen::affiche(){
    if(this->etat){
        cout << "Examen numéro : " << this->no_exam << '\n' << "De type : " << this->type << '\n' << "Effectué en date du : " << this->date <<  endl;
    } else {
        cout << "Examen numéro : " << this->no_exam << '\n' << "De type : " << this->type << '\n' << "Sera réalisé en date du : " << this->date <<  endl;
    }
}

Examen::~Examen(){}

// surchage ==
bool Examen::operator==(const Examen &e)
{
    return(this->no_exam==e.no_exam);
}

void Examen::ajouter_Examen(list<Examen> &E){
    bool test=false;
    for(list<Examen>::iterator it=E.begin(); it!=E.end(); it++){
        if(it->no_exam==this->no_exam){
            test=true;
            cout << "L'examen existe déjà" << endl;
        }
    }
    if(test==false){
        Examen ex = Examen(this->no_exam, this->type, this->date, this->etat, this->cliches, this->rapp);
        E.push_back(ex);
    }
}

void Examen::supprimer_Examen(list<Examen> &E){
    list<Examen>::iterator itr = E.begin();
    while(itr!=E.end()){
        if(itr->no_exam==this->no_exam){
            itr = E.erase(itr);
            cout << "Cliché supprimé !" << endl;
        } else {
            ++itr;
        }
    }
}