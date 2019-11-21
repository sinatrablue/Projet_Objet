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

list<Cliche> Examen::get_Cliches(){
    return this->cliches;
}

list<Rapport> Examen::get_Rapports(){
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

Examen::~Examen(){}

// surchage ==
bool Examen::operator==(const Examen &e)
{
    return(this->no_exam==e.no_exam);
}
/*
void Examen::ajouter_Cliche(list<Cliche> listCliche, Cliche clicheAjout){
    bool test=false;
    for(int i=0;i<listCliche.size();i++){
        if(listCliche[i].no_cliche==clicheAjout.no_cliche){
            test=true;
            cout << "Le cliché existe déjà" << endl;
        }
    }
    if(test==false){
        listCliche.push_back(clicheAjout);
    }
}

void Examen::ajouter_Rapport(list<Rapport> listRapport, Rapport rapportAjout){
    bool test=false;
    for(int i=0;i<listRapport.size();i++){
        if(listRapport[i].content==rapportAjout.content){
            test=true;
            cout << "Le rapport existe déjà" << endl;
        }
    }
    if(test==false){
        listRapport.push_back(rapportAjout);
    }
}

void supprimer_Cliche(list<Cliche> listCliche, Cliche clicheSuppr){
    for(int i=0;i<listCliche.size();i++){
        if(listCliche[i]==clicheSuppr){
            listCliche.remove(listCliche[i]);
            cout << "Cliché supprimé !" << endl;
        }
    }
}

void supprimer_Rapport(list<Rapport> listRapport, Cliche rapportSuppr){
    for(int i=0;i<listRapport.size();i++){
        if(listRapport[i]==rapportSuppr){
            listRapport.remove(listRapport[i]);
            cout << "Rapport supprimé !" << endl;
        }
    }
}
*/