#include<iostream>
#include<string>
#include<list>
#include"patient.hpp"

using namespace std;

patient::patient(string nom, string prenom, int age, char sexe, list<int> examenss){
    this->nom=nom;
    this->prenom=prenom;
    this->age=age;
    this->sexe=sexe;
    this->examenss=examenss;
}

string patient::get_Name(){
    return this->nom;
}

string patient::get_Prenom(){
    return this->prenom;
}

int patient::get_Age(){
    return this->age;
}

char patient::get_Sexe(){
    return this->sexe;
}

list<int> patient::get_Examenss(){
    return this->examenss;
}

void patient::set_Name(string nom){
    this->nom=nom;
}

void patient::set_Prenom(string prenom){
    this->prenom=prenom;
}

void patient::set_Age(int age){
    this->age=age;
}

void patient::set_Sexe(char sexe){
    this->sexe=sexe;
}

void patient::set_Examenss(list<int> examenss){
    this->examenss=examenss;
}

void patient::affiche(){
    if(this->sexe=='H'){
        cout << "Monsieur " << this->prenom << " " << this->nom << " ; " << this->age << " ans." << endl;
    } else {
        cout << "Madame " << this->prenom << " " << this->nom << " ; " << this->age << " ans." << endl;
    }
}

patient::~patient(){
    cout << "Patient supprimé de la base." << endl;
}


/*
void patient::ajouter(string nom, string prenom, int age, char sexe){
    new_patient=patient::patient(string nom, string prenom, int age, char sexe);
    return new_patient;
}
*/

// Idem pour supprimer si besoin