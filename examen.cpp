#include<iostream>
#include<string>
#include<list>
#include"examen.hpp"

using namespace std;

examen::examen(int no_exam, string type, string date, bool etat, list<int> cliches, list<int> rapports){
    this->no_exam=no_exam;
    this->type=type;
    this->date=date;
    this->etat=etat;
    this->cliches=cliches;
    this->rapports=rapports;
}

int examen::get_NoExam(){
    return this->no_exam;
}

string examen::get_Type(){
    return this->type;
}

string examen::get_Date(){
    return this->date;
}

bool examen::get_Etat(){
    return this->etat;
}

list<int> examen::get_Cliches(){
    return this->cliches;
}

list<int> examen::get_Rapports(){
    return this->rapports;
}

void examen::set_NoExam(int no_exam){
    this->no_exam=no_exam;
}

void examen::set_Type(string type){
    this->type=type;
}

void examen::set_Date(string date){
    this->date=date;
}

void examen::set_Etat(bool etat){
    this->etat=etat;
}

void examen::set_Cliches(list<int> cliches){
    this->cliches=cliches;
}

void examen::set_Rapports(list<int> rapports){
    this->rapports=rapports;
}

void examen::affiche(){
    if(this->etat){
        cout << "Examen numéro : " << this->no_exam << '\n' << "De type : " << this->type << '\n' << "Effectué en date du : " << this->date <<  endl;
    } else {
        cout << "Examen numéro : " << this->no_exam << '\n' << "De type : " << this->type << '\n' << "Sera réalisé en date du : " << this->date <<  endl;
    }
}

examen::~examen(){
    cout << "Examen supprimé de la base." << endl;
}