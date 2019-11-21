#include<iostream>
#include<string>
#include<list>
#include"patient.hpp"
//#include"examen.hpp"

using namespace std;

Patient::Patient(string nom, string prenom, int age, char sexe, list<Examen> examenss){
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

char Patient::get_Sexe(){
    return this->sexe;
}

list<Examen> Patient::get_Examenss(){
    return this->examenss;
}

void Patient::set_Name(string nom){
    this->nom=nom;
}

void Patient::set_Prenom(string prenom){
    this->prenom=prenom;
}

void Patient::set_Age(int age){
    this->age=age;
}

void Patient::set_Sexe(char sexe){
    this->sexe=sexe;
}

void Patient::set_Examenss(list<Examen> examenss){
    this->examenss=examenss;
}

void Patient::affiche(){
    if(this->sexe=='H'){
        cout << "Monsieur " << this->prenom << " " << this->nom << " ; " << this->age << " ans." << endl;
    } else {
        cout << "Madame " << this->prenom << " " << this->nom << " ; " << this->age << " ans." << endl;
    }
}

Patient::~Patient(){}


/*
void patient::ajouter(string nom, string prenom, int age, char sexe){
    new_patient=patient::patient(string nom, string prenom, int age, char sexe);
    return new_patient;
}
*/

// Idem pour supprimer si besoin