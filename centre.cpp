// ça sert à rien

#include<iostream>
#include<string>
#include<list>
#include"centre.hpp"
//#include"patient.hpp"
//#include"examen.hpp"

using namespace std;

Centre::Centre(std::string nom_centre, std::string no_centre, std::string adresse, std::list<Patient> patients, std::list<Examen> examens)
{
    this->nom_centre=nom_centre;
    this->no_centre=no_centre;
    this->adresse=adresse;
    this->patients=patients;
    this->examens=examens;
}

std::string Centre::get_NumCentre(){
    return this->no_centre;
}

std::string Centre::get_NomCentre(){
    return this->nom_centre;
}

std::string Centre::get_Adresse(){
    return this->adresse;
}

std::list<Patient> Centre::get_Patients(){
    return this->patients;
}

std::list<Examen> Centre::get_Examens(){
    return this->examens;
}

void Centre::set_NumCentre(std::string no_centre){
    this->no_centre=no_centre;
}

void Centre::set_NomCentre(std::string nom_centre){
    this->nom_centre=nom_centre;
}

void Centre::set_Adresse(std::string adresse){
    this->adresse=adresse;
}

void Centre::set_Patients(std::list<Patient> patients){
    this->patients=patients;
}

void Centre::set_Examens(std::list<Examen> examens){
    this->examens=examens;
}

void Centre::affiche(){
    cout<< "Nous somme le centre " << this->nom_centre << '\n' << "Identifié " << this->no_centre << '\n' << "Domicilié au : " << this->adresse << endl;
}

Centre::~Centre(){
    cout << "Destruction de centre effectuée." << endl;
}
