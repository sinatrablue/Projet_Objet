// ça sert à rien

#include<iostream>
#include<string>
#include<list>
#include"centre.hpp"
#include"patient.hpp"
#include"examen.hpp"

using namespace std;

centre::centre(string nom_centre, string no_centre, string adresse, list<int> patients, list<int> examens)
{
    this->nom_centre=nom_centre;
    this->no_centre=no_centre;
    this->adresse=adresse;
    this->patients=patients;
    this->examens=examens;
}

string centre::get_NumCentre(){
    return this->no_centre;
}

string centre::get_NomCentre(){
    return this->nom_centre;
}

string centre::get_Adresse(){
    return this->adresse;
}

list<int> centre::get_Patients(){
    return this->patients;
}

list<int> centre::get_Examens(){
    return this->examens;
}

void centre::set_NumCentre(string no_centre){
    this->no_centre=no_centre;
}

void centre::set_NomCentre(string nom_centre){
    this->nom_centre=nom_centre;
}

void centre::set_Adresse(string adresse){
    this->adresse=adresse;
}

void centre::set_Patients(list<int> patients){
    this->patients=patients;
}

void centre::set_Examens(list<int> examens){
    this->examens=examens;
}

void centre::affiche(){
    cout<< "Nous somme le centre " << this->nom_centre << '\n' << "Identifié " << this->no_centre << '\n' << "Domicilié au : " << this->adresse << endl;
}

centre::~centre(){
    cout << "Destruction de centre effectuée." << endl;
}
