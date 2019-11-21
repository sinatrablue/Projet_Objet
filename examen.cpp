#include<iostream>
#include<string>
#include<list>
#include"examen.hpp"

using namespace std;

Examen::Examen(int no_exam, string type, string date, bool etat, list<Cliche> cliches, list<Rapport> rapports){
    this->no_exam=no_exam;
    this->type=type;
    this->date=date;
    this->etat=etat;
    this->cliches=cliches;
    this->rapports=rapports;
}

int Examen::get_NoExam(){
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

list<int> Examen::get_Cliches(){
    return this->cliches;
}

list<int> Examen::get_Rapports(){
    return this->rapports;
}

void Examen::set_NoExam(int no_exam){
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

void Examen::set_Rapports(list<Rapport> rapports){
    this->rapports=rapports;
}

void Examen::affiche(){
    if(this->etat){
        cout << "Examen numéro : " << this->no_exam << '\n' << "De type : " << this->type << '\n' << "Effectué en date du : " << this->date <<  endl;
    } else {
        cout << "Examen numéro : " << this->no_exam << '\n' << "De type : " << this->type << '\n' << "Sera réalisé en date du : " << this->date <<  endl;
    }
}

Examen::~Examen(){
    cout << "Examen supprimé de la base." << endl;
}