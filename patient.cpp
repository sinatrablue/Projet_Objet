#include<iostream>
#include<string>
#include<list>
#include"patient.hpp"
//#include"examen.hpp"
//#include "centre.hpp"
using namespace std;

Patient::Patient() {}

Patient::Patient(string nom, string prenom, int age, string sexe, list<Examen> examenss){
    this->nom=nom;
    this->prenom=prenom;
    this->age=age;
    this->sexe=sexe;
    this->examenss=examenss;
}

string Patient::get_Name(){
    return this->nom;
}

string Patient::get_FirstName(){
    return this->prenom;
}

int Patient::get_Age(){
    return this->age;
}

string Patient::get_Sexe(){
    return this->sexe;
}

//Examen Patient :: get_Examenss(){

//}
list<Examen> Patient::get_Examenss(){
    return this->examenss;
}
//list<Examen> Patient::get_Examenss(){
//    return this->examenss;
//}

void Patient::set_Name(string nom){
    this->nom=nom;
}

void Patient::set_Prenom(string prenom){
    this->prenom=prenom;
}

void Patient::set_Age(int age){
    this->age=age;
}

void Patient::set_Sexe(string sexe){
    this->sexe=sexe;
}

void Patient::set_Examenss(list<Examen> examenss){
   this->examenss=examenss;
}

//void Patient::set_Examenss(list<Examen> examenss){
//    this->examenss=examenss;
//}

void Patient::affiche(){
    if(this->sexe=="H"){
        cout << "Monsieur " << this->prenom << " " << this->nom << " ; " << this->age << " ans." << endl;
    } else {
        cout << "Madame " << this->prenom << " " << this->nom << " ; " << this->age << " ans." << endl;
    }
}

Patient::~Patient(){}

// surchage ==
bool Patient::operator==(const Patient &p)
{
    return(this->nom==p.nom && this->prenom==p.prenom && this->age==p.age);
}

void Patient::ajouter_Patient(list<Patient> &P){
    bool test=false;
    for(list<Patient>::iterator it=P.begin(); it!=P.end(); it++){
        if(it->prenom==this->prenom && it->nom==this->nom && it->age==this->age){
            test=true;
            cout << "Le patient existe déjà" << endl;
        }
    }
    if(test==false){
        Patient Pa = Patient(this->nom, this->prenom, this->age, this->sexe, this->examenss);
        P.push_back(Pa);
    }
}

void Patient::supprimer_Patient(list<Patient> &P){
    list<Patient>::iterator itr = P.begin();
    while(itr!=P.end()){
        if(itr->prenom==this->prenom && itr->nom==this->nom && itr->age==this->age){
            itr = P.erase(itr);
            cout << "Cliché supprimé !" << endl;
        } else {
            ++itr;
        }
        cout << "t1" << endl;
    }
    cout << "t2" << endl;
}

// Idem pour supprimer si besoin

